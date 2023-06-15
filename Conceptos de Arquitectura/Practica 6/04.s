;Escriba un programa que solicite el ingreso por teclado de una clave (sucesión de cuatro caracteres) utilizando la 
;subrutina char de ingreso de un carácter. Luego, debe comparar la secuencia ingresada con una cadena almacenada
;en la variable clave. Si las dos cadenas son iguales entre si, la subrutina llamada respuesta mostrará el texto 
;“Bienvenido” en la salida estándar del simulador (ventana Terminal). En cambio, si las cadenas no son iguales, la 
;subrutina deberá mostrar “ERROR” y solicitar nuevamente el ingreso de la clave.

  .data
CONTROL:      .word32 0x10000
DATA:         .word32 0x10008
ERROR:        .asciiz "ERROR "
BIENVENIDO:   .asciiz "Bienvenido "
CLAVE:        .asciiz "0aaaa"
TEXTO:        .asciiz "Ingrese clave: "
ACTUAL:       .asciiz 0

  .text
lwu           $s0, DATA(r0) ; $s0 = dirección de DATA. 
lwu           $s1, CONTROL(r0) ; $s1 = dirección de CONTROL. 

loop:
;sd            $0, ACTUAL($0)
;escribo el ingresar clave
daddi         $t4, $0, TEXTO
sd            $t4, 0($s0)
daddi         $t4, $0, 4
sd            $t4, 0($s1)
daddi         $a0, $0, 4
daddi         $a1, $0, ACTUAL
jal           INGRESAR; Ingresa la clave

;comprar

daddi         $t1, $0, CLAVE
daddi         $t2, $0, ACTUAL
lw            $v0, 0($t1)
lw            $v1, 0($t2)  
beq		        $v0, $v1, RESPUESTA

;Si malio sal, hace loop

daddi         $t3, $0, ERROR
sd            $t3, 0($s0)
daddi         $t4, $0, 4
sd            $t4, 0($s1)

j         		loop				

RESPUESTA:
daddi         $t4, $0, BIENVENIDO
sd            $t4, 0($s0)
daddi         $t4, $0, 4
sd            $t4, 0($s1)
   
halt

INGRESAR:
daddi         $sp, $sp, -8; desplazo el sp para guardar el ra y el valor
sd            $ra, 0($sp)

daddi         $t0, $0, 9 ; $t0 = 9 -> función 9: espera por un ASCII
sd            $t0, 0($s1) ; CONTROL recibe 9 y espera por el ASCII (el cual es almacenado en DATA)

lbu           $t1, 0($s0) ;$t1 -> caracter de control 
sb            $t1, 0($a1); almaceno

dadd          $t0, $0, $s3 ; $t0 = dirección del mensaje a mostrar
sd            $t0, 0($s0) ; DATA recibe el direccion del mensaje

daddi         $t0, $0, 4 ; $t0 = 4 -> caracter ASCII
sd            $t0, 0($s1) ; CONTROL recibe 4 , imprime


daddi         $a0, $a0, -1; resto la cantidad de veces que entro

daddi         $a1, $a1, 1

bnez          $a0, INGRESAR ;si no llega a 0 repite

ld            $ra, 0($sp) ; desencolo ra
daddi         $sp, $sp, 8

jr          	$ra

