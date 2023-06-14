;Escriba un programa que utilice sucesivamente dos subrutinas: La primera, denominada ingreso, debe solicitar el 
;ingreso por teclado de un número entero (de un dígito), verificando que el valor ingresado realmente sea un dígito. La 
;segunda, denominada muestra, deberá mostrar en la salida estándar del simulador (ventana Terminal) el valor del 
;número ingresado expresado en letras (es decir, si se ingresa un ‘4’, deberá mostrar ‘CUATRO’). Establezca el pasaje 
;de parámetros entre subrutinas respetando las convenciones para el uso de los registros y minimice las detenciones 
;del cauce.

  .data
CONTROL:       .word32 0x10000
DATA:          .word32 0x10008
NUM:           .word32 0
CERO:          .asciiz "CERO "
UNO:           .asciiz "UNO  "
DOS:           .asciiz "DOS  "
TRES:          .asciiz "TRES "
CUATRO:        .asciiz "CUATRO "
CINCO:         .asciiz "CINCO "
SEIS:          .asciiz "SEIS "
SIETE:         .asciiz "SIETE "
OCHO:          .asciiz "OCHO "
NUEVE:         .asciiz "NUEVE "
ERROR:         .asciiz "Numero ingresado erroneo"

  .text
lwu            $s0, DATA(r0) ; $s0 = dirección de DATA. 
jal            INGRESO
lwu            $s1, CONTROL(r0) ; $s1 = dirección de CONTROL. 
jal            MUESTRA
daddi          $t2, $0, 8; Lo uso para calcular la direccion mas adelante

halt


INGRESO:
daddi          $t0, $0, 8
sd             $t0, 0($s1); Control lee un entero sin signo

ld             $v0, 0($s0); Guardo el dato de DATO

jr		         $ra# jump to $ra
sd             $v0, NUM($0)
;No hago la corroboracion aca para que en la muestra pueda compartir el comando de ingresar, porque sino lo tenia que hacer dos veces


MUESTRA:
slti           $v1, $v0, 10 ; Si es mas chico que diez todo joya
beqz           $v1, FINMALO ; Sino imprime mensaje de error
nop       ; Para que no entre al calculo con el daly slot


dmul	         $t1, $v0, $t2 ;Calculo la direccion en donde esta el nombre del numero. 8 veces el numero 			

daddi          $t0, $t1, CERO; sumo desde la primera direccion
sd             $t0, 0($s0); Carga texto en data
j	           	 FIN	

FINMALO:

daddi          $t0, $0, ERROR ; carga el mensaje de error en DATA
sd             $t0, 0($s0)

FIN:
daddi          $t0, $0, 4 
jr		         $ra
sd             $t0, 0($s1) ; CONTROL recibe 4 , imprime


;6 raws si se ingresa bien el numero
;1 raw si no se ingresa bien el numero