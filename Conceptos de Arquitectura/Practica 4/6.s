;Escribir un programa que lea tres números enteros A, B y C de la memoria de datos y determine cuántos de ellos son iguales 
;entre sí (0, 2 o 3). El resultado debe quedar almacenado en la dirección de memoria D.


;USO ACTIVO SOLO FORWADING

.data

A:     .word 2
B:     .word 4
C:     .word 1
D:     .word 0
CANT:  .word 3
Cero:  .word 0

.code

ld      r1, A (r0)
ld      r2, B (r0)
ld      r3, C (r0)
ld      r4, CANT (r0)
ld      r5, Cero (r0)


bne     r1, r3, loop
daddi   r5, r5, 2
j       loop

suma: bnez    r5, normal

daddi r5,r5, 2
j       resta

normal: daddi r5, r5, 1

resta:  daddi r4,r4, -1
beqz    r4, fin
daddi   r2,r2, 8
loop:   bne r1, r2, resta
j       suma


fin:    sd r5, D(r0)
halt

;5 RAW
;5 Branch Taquen