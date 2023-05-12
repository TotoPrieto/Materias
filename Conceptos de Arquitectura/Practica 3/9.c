
;Escribir un programa que solicite el ingreso de cinco caracteres por teclado y los almacene 
;en memoria. Una vez ingresados, que los envíe a la impresora a través del HAND-SHAKE, en primer
;lugar tal cual fueron ingresados y a continuación en sentido inverso. Implementar dos versiones
; una por consulta de estado y otra por interrupción, en lo que se refiere a la comunicación
;entre el HAND-SHAKE y el microprocesador.

PIC EQU 20H 
HND_DATO EQU 40H 
HND_ESTADO EQU 41H 
N_HND EQU 11

ORG 1000H 
CAR DB ?
DB ?
DB ?
DB ?
DB ?
FIN_C DB ?

ORG 3000H

LEER: PUSH AX
PUSH BX
PUSH CX
PUSH DX

LOP:INT 6
INC BX
DEC CL
CMP CL, 0
JNZ LOP

POP DX
POP CX
POP BX
POP AX
RET

SUB_HND:CMP CL,0
JZ CHAO
MOV AL, [BX]
OUT HND_DATO, AL
INC BX
DEC CL

CHAO: MOV AL, 20H
OUT PIC, AL
IRET


ORG 2000H


CLI

MOV AL, 11111011b
OUT PIC+1, AL

MOV AX, SUB_HND
MOV BX, 44
MOV [BX], AX

MOV AL, N_HND
OUT PIC+6, AL

MOV AL, 80H
OUT HND_ESTADO, AL


MOV BX, OFFSET CAR
MOV CL, OFFSET FIN_C - OFFSET CAR

CALL LEER

PUSH BX
PUSH CX

STI 

LAZO:CMP CL, 0
JNZ LAZO

IN AL, HND_ESTADO
AND AL, 07FH
OUT HND_ESTADO, AL

POP CX
POP BX
MOV BX, OFFSET FIN_C-1

REPITO:IN AL, HND_ESTADO
AND AL, 1
JNZ REPITO
MOV AL, [BX]
OUT HND_DATO, AL
DEC BX
DEC CL

CMP CL, 0
JNZ REPITO


INT 0
END

