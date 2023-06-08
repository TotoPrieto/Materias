.data

CONTROL:    .word32 0x10000
DATA:       .word32 0x10008
cadena:     .byte0

.text
ld          $s0, CONTROL(r0) ; $s1 = dirección de CONTROL
ld          $s1, DATA(r0); $s0 = direccion de DATA

 
daddi       $t0, $0, 9 ; $t0 = 9 -> función 9:lee data desde teclado
sd          $t0, 0($s0) ; CONTROL = 9 
lbu         $t1, 0($s1) ;toma el caracter de control y lo pone en $t1

sb          $t1, cadena($0) ;carga en cadena el caracter

daddi       $s3,$s0,cadena

sd          $

sd          $t3, 0($s0); Guarda mensaje en DATA
daddi       $t0, $0, 6 ; $t0 = 6 -> función 6: limpiar pantalla alfanumérica
sd          $t0, 0($s1) ; CONTROL recibe 6 y limpia la pantalla
daddi       $t0, $0, 4 ; $t0 = 4 -> función 4:lee data desde teclado
sd          $t0, 0($s1) ; CONTROL recibe 4 y produce la salida del mensaje
sd          $t1, 0($s0)

halt
