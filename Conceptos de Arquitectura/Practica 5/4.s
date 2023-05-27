;El índice de masa corporal (IMC) es una medida de asociación entre el peso y la talla de un individuo.
;Se calcula a partir del peso (expresado en kilogramos, por ejemplo: 75,7 kg) y la estatura (expresada en metros,
;por ejemplo 1,73 m).
;De acuerdo al valor calculado con este índice, puede clasificarse el estado nutricional de una persona en:
;Infrapeso (IMC < 18,5), Normal (18,5 ≤ IMC < 25), Sobrepeso (25 ≤ IMC < 30) y Obeso (IMC ≥ 30).
;Escriba un programa que dado el peso y la estatura de una persona calcule su IMC y lo guarde en la dirección 
;etiquetada IMC

.data
IMC:      .word 0
PESO:     .double 62.4
TALLA:    .double 1.73
DIECI:    .double 18.5
VEINTI:   .double 25
TREINTA:  .double 30

.code
l.d       f3, TALLA(r0)
l.d       f2, PESO(r0)
l.d       f4, DIECI(r0)
   
mul.d     f3, f3, f3; lo pongo en medio de los load para aprovechar ciclos
l.d       f5, VEINTI(r0)
l.d       f6, TREINTA(r0)
div.d     f1, f2, f3
c.le.d    f1, f4; mas chico, FP=1
bc1t      FIN
daddi     r1, r1, 1
c.le.d    f1, f5; mas chico, FP=1
bc1t      FIN
daddi     r1, r1, 1
c.le.d    f1, f6; mas chico, FP=1
bc1t      FIN
daddi     r1, r1, 1
daddi     r1, r1, 1


FIN: sd   r1, IMC(r0)
halt

;Infrapeso: daddi r1, r1, 1
;j         FIN


;Normal:   daddi r1, r1, 2
;j         FIN


;Sobrepeso: daddi r1, r1, 3
;j         FIN


;Obeso:    daddi r1, r1, 4
;j         FIN