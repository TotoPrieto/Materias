.data

valor1: .word 16
valor2: .word 4
result: .word 0

.text
ld $a0, valor1($0)
ld $a1, valor2($0)
jal a_la_potencia
sd $v0, result($0)
halt


a_la_potencia: daddi $v0, $0, 1; eleva 16 a la 4ta

lazo: slt $t1, $a1, $0;cuando se haya elevado hasta el valor2, termina 
bnez $t1, terminar
daddi $a1, $a1, -1
dmul $v0, $v0, $a0
j lazo

terminar: jr $ra

;d) Se usaria la pila para guardar las direcciones de varias subrutinas