;Escribir un programa que calcule la superficie de un triángulo rectángulo de base 5,85 cm y altura 13,47 cm


.data
AREA:     .double 0
BASE:     .double 5.85
ALTURA:   .double 13.47

.code
l.d        f0, BASE(r0)
l.d        f1, ALTURA(r0)
daddi      r1, r1, 2
mtc1       r1, f4


mul.d      f2, f1, f0
div.d      f3, f2, f4
s.d        f3, AREA(r0)

halt
