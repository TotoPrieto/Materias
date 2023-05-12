;Modificar el programa anterior para que también cuente minutos (00:00 - 59:59), pero que actualice la visualización en 
;pantalla cada 10 segundos

TIMER EQU 10H
PIC EQU 20H
EOI EQU 20H
N_CLK EQU 10;id de vector a usar
ORG 40;sin h siempre
IP_CLK DW RUT_CLK;no se usa, sino que se usa para decir que pertenece. tiene que ser 
;el id por cuatro 

;Modificar el programa anterior para que también cuente minutos (00:00 - 59:59), 
;pero que actualice la visualización en pantalla cada 10 segundos.

ORG 1000H
SEG DB 30H
DB 30H
FIN DB ?

ORG 3000H
RUT_CLK: PUSH AX
INC SEG+1
CMP SEG+1, 3AH
JNZ RESET
MOV SEG+1, 30H
INC SEG
INT 7
CMP SEG, 36H
JNZ RESET
MOV SEG, 30H
RESET: MOV AL, 0
OUT TIMER, AL
MOV AL, EOI
OUT PIC, AL
POP AX
IRET

ORG 2000H
CLI
MOV AL, 0FDH
OUT PIC+1, AL ; PIC: registro IMR
MOV AL, N_CLK 
OUT PIC+5, AL ; PIC: registro INT1
MOV AL, 1
OUT TIMER+1, AL ; TIMER: registro COMP
MOV AL, 0
OUT TIMER, AL ; TIMER: registro CONT
MOV BX, OFFSET SEG
MOV AL, OFFSET FIN-OFFSET SEG
STI
LAZO: JMP LAZO
END
