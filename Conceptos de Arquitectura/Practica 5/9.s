;subrutina que calcule en forma recursiva el factorial de un número entero
.data

valor:            .word 3
result:           .word 0


.text

daddi             $sp, $0, 0x400 ; Inicializa el puntero al tope de la pila (1)
ld                $a0, valor($0)
jal               factorial
sd                $v0, result($0)
halt



factorial: daddi  $sp, $sp, -16; desplazo el sp para guardar el ra y el valor
sd                $ra, 0($sp)
sd                $a0, 8($sp)

beqz              $a0, UNO;  Cuando llega al 0 tiene que ponerlo en 1

daddi             $a0, $a0, -1
jal               factorial
daddi             $a0, $a0, 1; porque va a estar corrido
nop
dmul              $v0, $v0, $a0
nop
nop
nop
nop
nop
nop
nop
ld                $ra, 0($sp)
ld                $a0, 8($sp)
daddi             $sp, $sp, 16
jr                $ra

UNO: daddi        $v0, $0, 1
ld                $ra, 0($sp)
ld                $a0, 8($sp)
daddi             $sp, $sp, 16
jr                $ra
