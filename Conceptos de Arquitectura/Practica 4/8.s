;Escribir un programa que multiplique dos números enteros utilizando sumas repetidas (similar al Ejercicio 7 de la Práctica 1). 
;El programa debe estar optimizado para su ejecución con la opción Delay Slot habilitada
.data
X:    .word 9
Y:    .word 15
RES:  .word 0

.code

ld    r2, X(r0)
ld    r3, Y(r0)
daddi r3, r3, -1

LOOP: dadd  r1, r1, r2
bnez  r3, LOOP
daddi r3, r3, -1



FIN:  sd    r1, RES(r0)

halt