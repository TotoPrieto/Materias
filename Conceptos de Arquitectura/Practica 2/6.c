;Escribir un programa que efectúe la suma de dos números (de un dígito cada uno) ingresados por teclado y muestre el resultado en la 
;pantalla de comandos. Recordar que el código de cada caracter ingresado no coincide con el número que representa y que el resultado
;puede necesitar ser expresado con 2 dígitos.

org 1000h
num DB ?
num2 DB ?
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
SUB CL,30H
SUB DL,30H
ADD CL, DL




hlt
end
