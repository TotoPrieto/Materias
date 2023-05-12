;Escribir un programa que implemente un conteo regresivo a partir de un valor ingresado desde el
;teclado. El conteo debe comenzar al presionarse la tecla F10. El tiempo transcurrido debe 
;mostrarse en pantalla, actualizándose el valor cada segundo

TIMER EQU 10H
PIC EQU 20H
N_CLK EQU 10
N_F10 EQU 9

ORG 1000H 
ACT DB 0
SEG DB ?
FIN_S DB ?

SUB_TIMER:CMP ACT, 1
JNZ CHAU
DEC SEG
CHAU: MOV BX, OFFSET SEG
MOV AL, 1
INT 7
MOV AL, 0
OUT TIMER, AL
MOV AL, 20H
OUT PIC, AL
IRET

SUB_F10:MOV ACT, 1
MOV AL, 20H
OUT PIC, AL
IRET


ORG 2000H

CLI

MOV BX, 36
MOV AX, SUB_F10
MOV [BX],AX

MOV BX, 40
MOV AX, SUB_TIMER
MOV [BX],AX

MOV AL, 11111100b
OUT PIC+1, AL; ACTIVO TIMER Y F10

MOV AL, N_CLK
OUT PIC+5, AL; TIMER

MOV AL, N_F10
OUT PIC+4,AL; F10

MOV AL, 2
OUT TIMER+1, AL

MOV AL,0
OUT TIMER, AL

MOV BX, OFFSET SEG
INT 6
MOV AL, 1
INT 7;IMPRIMO EL NUMERO INGRESADO


STI

LAZO:CMP SEG, 30H
JNZ LAZO
INT 0
END
