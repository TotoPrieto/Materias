.data
VECTOR: .word 1234,2345,3456,4567,5678
NUEVO:  .word 0


.code

daddi   $t0, $0, 5; la cant de veces que entra al loop
dadd    $t1, $0, $0 ; inicializo en 0

loop:
ld     $t2, VECTOR($t1); agarro el numero
daddi  $t2, $t2, 1; lo incremento 
daddi  $t0, $t0, -1; decremento la cant de iteracciones
sd     $t2, NUEVO($t1); guardo en nuevo
bnez   $t0, loop
daddi  $t1, $t1, 8; incremento la posicion donde se guarda el proximo


fin:
halt