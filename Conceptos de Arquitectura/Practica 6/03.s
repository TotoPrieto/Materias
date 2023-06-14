;Escriba un programa que realice la suma de dos números enteros (de un dígito cada uno) utilizando dos subrutinas: La 
;denominada ingreso del ejercicio anterior (ingreso por teclado de un dígito numérico) y otra denominada 
;resultado, que muestre en la salida estándar del simulador (ventana Terminal) el resultado numérico de la suma de 
;los dos números ingresados

  .data
CONTROL:        .word32 0x10000
DATA:           .word32 0x10008
NUM1:           .word32 0
NUM2:           .word32 0
ERROR:         .asciiz "Numero ingresado erroneo"


  .text
lwu            $s0, DATA(r0) ; $s0 = dirección de DATA. 
jal            INGRESO
lwu            $s1, CONTROL(r0) ; $s1 = dirección de CONTROL. 
jal            RESULTADO
nop
j		           FIN
FINMALO:
daddi          $t0, $t1, ERROR ; carga el mensaje de error en DATA
sd             $t0, 0($s0)
FIN:
halt


INGRESO:
daddi           $t0, $0, 8
sd              $t0, 0($s1); Control lee un entero sin signo


ld              $v0, 0($s0); Guardo el dato de DATO
sd              $v0, NUM1($0)

slti            $t3, $v0, 10 ; Si es mas chico que diez todo joya
beqz            $t3, FINMALO ; Sino imprime mensaje de error 
nop

sd              $t0, 0($s1); Control lee un entero sin signo
ld              $v1, 0($s0); Guardo el dato de DATO


slti            $t3, $v0, 10 ; Si es mas chico que diez todo joya
beqz            $t3, FINMALO ; Sino imprime mensaje de error 
nop

jr		          $ra# jump to $ra
sd              $v1, NUM2($0)


RESULTADO:
dadd            $t1, $v0, $v1
sd              $t1, 0($s0)

daddi           $t0, $0, 1
jr		          $ra
sd              $t0, 0($s1) ; CONTROL recibe 1 , imprime
