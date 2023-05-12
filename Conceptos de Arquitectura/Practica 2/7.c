;Escribir un programa que efectúe la resta de dos números (de un dígito cada uno) ingresados por teclado y muestre el resultado en la 
;pantalla de comandos. Antes de visualizarlo el programa debe verificar si el resultado es positivo o negativo y anteponer al valor el 
;signo correspondiente.

org 1000h
num DB ?
num2 DB ?
nega DB 45
numre DB ?
; variables 

org 2000h
MOV BX, OFFSET num
MOV AL, 1
INT 6
MOV BX, OFFSET num2
INT 6
MOV BX, OFFSET num
MOV CL, [BX]
MOV BX, OFFSET num2
MOV DL, [BX]
CMP CL, DL
JS NEGA
SUB CL,DL
JMP SIGO
NEGA: SUB DL,CL
MOV CL, DL
MOV BX, OFFSET nega
MOV AL, 1
INT 7
SIGO:MOV BX, OFFSET numre
ADD CL, 30H
MOV [BX],CL
MOV AL,1
INT  7
hlt
end
