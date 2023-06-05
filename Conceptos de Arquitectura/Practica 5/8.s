;Escriba una subrutina que reciba como parámetros las direcciones del comienzo de dos cadenas terminadas en cero y 
;retorne la posición en la que las dos cadenas difieren. En caso de que las dos cadenas sean idénticas, debe retornar -1.

.data
CADENA1:       .word 3,5,7,9,0
CADENA2:       .word 3,5,7,9,0
DIFIEREN:      .word 0


.text

daddi         $a0, $0, CADENA1
jal           SUB_DIF
daddi         $a1, $0, CADENA2 ;delay slot activado

sd            $v0, DIFIEREN(r0)
halt

    
SUB_DIF: ld   $s0, 0($a0)
ld            $s1, 0($a1) 
daddi         $t0, $t0, 1 ; Seria la cantidad de posicion que avanzo, para saber donde se frena
NOP                       ;No esta bien su uso, pero solo con eso no genera RAWS
bne           $s0, $s1, DIF; Si no son iguales salta
daddi         $a0, $a0, 8; incrementar cadena1
bnez          $s0, SUB_DIF; Cuando llega a 0 la cadena1 termina
daddi         $a1, $a1, 8; incrementar cadena2; aprovecho delay slot

jr            $ra
daddi         $v0, $0, -1; Como termino sin errores, devuelve -1. Delay Slot

DIF: jr       $ra; No es necesario aca el delay slot, pero ya fue
dadd          $v0, $0, $t0; Paso como parametro donde se detuvo 



;0 ATASCOS
;52 CICLOS
;48 INSTRUCCIONES 
;1.083 CPI