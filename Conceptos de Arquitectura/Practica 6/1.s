  .data
CONTROL:        .word32 0x10000
DATA:           .word32 0x10008
cadena:         .byte 0

  .text
lwu             $s0, DATA(r0) ; $s0 = dirección de DATA
lwu             $s1, CONTROL(r0) ; $s1 = dirección de CONTROL
daddi           $s2, $zero, 46 ; $s2 valor del punto
daddi           $s3, $zero, cadena

LOOP:
daddi           $t0, $0, 9 ; $t0 = 9 -> función 9: espera por un ASCII
sb              $t0, 0($s1) ; CONTROL recibe 9 y espera por el ASCII (el cual es almacenado en DATA)

lbu             $t1, 0($s0) ;$t1 -> caracter de control 

beq             $t1, $s2, fin ; Termina cuando se ingresa '.'

dadd            $t0, $0, $s3 ; obtengo direccion donde guardo
sb              $t1, 0($t0); almaceno

dadd            $t0, $0, $s3 ; $t0 = dirección del mensaje a mostrar
sd              $t0, 0($s0) ; DATA recibe el direccion del mensaje

daddi           $t0, $0, 4 ; $t0 = 4 -> caracter ASCII
sd              $t0, 0($s1) ; CONTROL recibe 4 , imprime
daddi           $s3, $s3, 8; Siguiente direccion donde se guarda letra por letra

j               LOOP

fin: halt



