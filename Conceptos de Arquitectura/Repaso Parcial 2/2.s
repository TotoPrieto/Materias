  .data
tabla1:   .double 1.0, 2.0, 3.0, 4.0, 5.0, 1.0, 2.0, 3.0, 4.0, 5.0, 1.0, 2.0
tabla2:   .double 0, 0, 0, 0
N:        .word 11
N12:      .word 11
DOS:      .double 0.5
CONTROL:  .word  0x10000
DATA:     .word  0x10008
  .code

ld        $s0, CONTROL($0)
ld        $s1, DATA($0)
dadd      $a0, $0, $0; este se va a sumar hasta llegar a a1
daddi     $a1, $0, 1;
l.d       f2, DOS($0)
ld        $a3, N($0)



jal		    CALCULO				
nop
daddi     $s3, $0, tabla2
daddi     $a1, $0, 11
dadd      $a2, $0, $0;
dadd      $a3, $0, $0;
jal       IMPRIMIR

halt


CALCULO: 
l.d        f0, tabla1($a0);Agarro el primero
l.d        f1, tabla1($a1); Agarro el siguiente
add.d      f3, f0, f1; Los sumo
mul.d      f3, f3, f2; Divido entre dos
s.d        f3, tabla2($a0); Lo guardo

beqz       $a3, sale; Si acaba de calcular el prom con el 5to como siguiente, sale
nop
daddi      $a0, $a0, 8
daddi      $a1, $a1, 8
daddi      $a3, $a3, -1
j          CALCULO
nop
sale:
 jr    		$ra					


IMPRIMIR: 
dadd      $t1, $s3, $a3
l.d       f1, 0($t1)
s.d       f1, 0($s1)
daddi     $t0, $0, 3
sd        $t0, 0($s0)
daddi     $a2, $a2, 1
daddi     $a3, $a3, 8
beq       $a1, $a2, termino
nop
j	        IMPRIMIR

termino:
jr        $ra