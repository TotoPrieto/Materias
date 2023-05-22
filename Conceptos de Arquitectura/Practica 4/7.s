;Escribir un programa que recorra una TABLA de diez números 
;enteros y determine cuántos elementos son mayores que X. El 
;resultado debe almacenarse en una dirección etiquetada CANT.
;El programa debe generar además otro arreglo llamado RES 
;cuyos elementos sean ceros y unos. Un ‘1’ indicará que el 
;entero correspondiente en el arreglo TABLA es mayor que X, 
;mientras que un ‘0’ indicará que es menor o igual.

.data

TABLA:    .word 2, 6, 8, 0, 6, 81, 71, 26, 34, 42
X:        .word 10
LONG:     .word 10
CANT:     .word 0
RES:      .word 0

.code

ld        r6, X(r0)
dadd      r4, r0, r0
ld        r3, CANT(r0)
ld        r2, LONG(r0)
dadd      r5, r0, r0

loop:     ld r1, TABLA(r4)
daddi     r2, r2, -1; resto la cantidad recorrida
daddi     r4, r4, 8 ; Aumento la posicion a avanzar en los vectores
slt       r5, r6, r1  ;compara valor de tabla con X. Pone 1 si es mayor 
dadd     r3, r3, r5  ; incremento la cantidad mayor a X
bnez      r2, loop  ; si la cantidad es 0 se termina
sd        r5, RES(r4); aprovecho el delay slot para poner el 1 o 0 en el nuevo arreglo. Aprovecho el r5 para no calcular de vuelta


sd        r3, CANT(r0); almaceno en memoria la cantidad mayor

halt

;delay slot activo 
;funciona tambien con branch taken si le muevo el sd r5, RES(r4) adentro del loop

; 0 atascos totales (locuras)
