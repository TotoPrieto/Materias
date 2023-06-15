.data

coorX: .byte 24 ; coordenada X de un punto
coorXaux: .byte 0
coorY: .byte 24 ; coordenada Y de un punto
coorYaux: .byte 0 ;
color: .byte 255, 0, 255, 0 ; color: máximo rojo + máximo azul => magenta
coloraux: .byte 0, 0, 0, 0 ;
CONTROL: .word32 0x10000
DATA: .word32 0x10008

.text

lwu $s6, CONTROL(r0) ; $s6 = dirección de CONTROL
lwu $s7, DATA(r0) ; $s7 = dirección de 


daddi $t0, $0, 7 ; $t0 = 7 -> función 7: limpiar pantalla gráfica
sd $t0, 0($s6) ; CONTROL recibe 7 y limpia la pantalla gráfica

daddi $t0, $0, 8; voy a leer los valor
sd $t0, 0($s6); CONTROL recibe 8 para leer

lwu $t1, 0($s7); Guardo l oque hay en DATA.
sd $t1, coorXaux($0); guardo coordenada X

sd $t0, 0($s6); CONTROL recibe 8 para leer
lwu $t1, 0($s7); Guardo l oque hay en DATA.
sd $t1, coorYaux($0); guardo coordenada Y


dadd $t2, $0, $0
sd $t0, 0($s6); CONTROL recibe 1 para leer
lwu $t1, 0($s7); Guardo l oque hay en DATA.
sb $t1, coloraux($0); guardo red

daddi $t2, $t2, 1
sd $t0, 0($s6); CONTROL recibe 1 para leer
lwu $t1, 0($s7); Guardo l oque hay en DATA.
sb $t1, coloraux($t2); guardo green

daddi $t2, $t2, 1
sd $t0, 0($s6); CONTROL recibe 1 para leer
lwu $t1, 0($s7); Guardo l oque hay en DATA.
sb $t1, coloraux($t2); guardo blue



lbu $s0, coorXaux(r0) ; $s0 = valor de coordenada X
sb $s0, 5($s7) ; DATA+5 recibe el valor de coordenada X

lbu $s1, coorYaux(r0) ; $s1 = valor de coordenada Y
sb $s1, 4($s7) ; DATA+4 recibe el valor de coordenada Y

lwu $s2, coloraux(r0) ; $s2 = valor de color a pintar
sw $s2, 0($s7) ; DATA recibe el valor del color a pintar

daddi $t0, $0, 5 ; $t0 = 5 -> función 5: salida gráfica
sd $t0, 0($s6) ; CONTROL recibe 5 y produce el dibujo del punto
halt