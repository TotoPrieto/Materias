;Escribir un programa que cuente la cantidad de veces que un determinado caracter aparece en una cadena de texto. Observar 
;cómo se almacenan en memoria los códigos ASCII de los caracteres (código de la letra “a” es 61H). Utilizar la instrucción lbu 
;(load byte unsigned) para cargar códigos en registros

.data
cadena:    .asciiz "adbdcdedfdgdhdid" ; cadena a analizar
car:       .asciiz "d" ; caracter buscado
cant:      .word 0 ; cantidad de veces que se repite el caracter car en cadena


.code
lbu        r2, car(r0)
daddi      r5, r0, 17
ld         r6, 1(r0)


lbu        r1, cadena(r0)
loop: daddi  r5, r5, -1
daddi       r3, r3, 1
bne        r1, r2, NONO
nop
NONO: daddi       r6, r6, 1
bnez   r5, loop
lbu        r1, cadena(r6)


sd         r3, cant(r0)
halt

;con forwarding y dilay slot tiene 0 atascos
