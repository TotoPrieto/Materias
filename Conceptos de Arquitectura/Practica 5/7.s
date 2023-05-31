;Escriba una subrutina que reciba como parámetros un número positivo M de 64 bits, la dirección del comienzo de una 
;tabla que contenga valores numéricos de 64 bits sin signo y la cantidad de valores almacenados en dicha tabla.
;La subrutina debe retornar la cantidad de valores mayores que M contenidos en la tabla.

.data
M:          .word 4
tabla:      .word 1,2,4,5
cant:       .word 4
RES:        .word 0

.text

daddi       $a0, $0, tabla
ld          $a1, M(r0)
ld          $a2, cant(r0)
jal         SUB_R
sd          $v0, RES(r0)
halt

    
SUB_R: ld   $s0, 0($a0)
slt         $t2, $a1, $s0; comparar M>num tabla

daddi       $a2, $a2, -1 ; restar cant 
dadd        $v0, $v0, $t2 ; sumo tot si encuentra
daddi       $a0, $a0, 8; incrementar tabla
bnez        $a2, SUB_R; comparar cant con 0 sino saltar
   



jr          $ra