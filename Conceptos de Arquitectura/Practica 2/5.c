;Escribir un programa que solicite el ingreso de un número (de un dígito) por teclado y muestre en pantalla dicho número expresado en 
;letras. Luego que solicite el ingreso de otro y así sucesivamente. Se debe finalizar la ejecución al ingresarse en dos vueltas 
;consecutivas el número cero.

org 1000h
num0 DB "CERO  "
num1 DB "UNO___"
num2 DB "DOS___"
num3 DB "TRES__"
num4 DB "CUATRO"
num5 DB "CINCO_"
num6 DB "SEIS__"
num7 DB "SIETE_"
num8 DB "OCHO__"
num9 DB "NUEVE_"
num DB ?
; variables 

org 3000h
SUBS: MOV BX, OFFSET num
MOV CL, [BX]
SUB CL, 30H
MOV CH, 0
LAZO: CMP CH,CL
JZ SIGO
ADD DX, 6
INC CH
JMP LAZO
SIGO:MOV BX, OFFSET num0
ADD BX, DX
MOV AL,6
INT 7
ret

org 2000h
MOV BX, OFFSET num
MOV AL, 1
INT 6
CALL SUBS


hlt
end
