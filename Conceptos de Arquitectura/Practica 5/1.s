.data

  n1:   .double 9.13
  n2:   .double 6.58
  res1: .double 0.0
  res2: .double 0.0


.code

  l.d   f1, n1(r0)
  l.d   f2, n2(r0)
  add.d f3, f2, f1
  mul.d f1, f2, f1 
  mul.d f4, f2, f1
  s.d   f3, res1(r0)
  s.d   f4, res2(r0)

halt

;Solo con forwardin:
;       16 ciclos
;       7 instrucciones
;       2.286 CPI
;       4 RAW
;       2 Atascos Estructurales
;Los raws se deben a que el sd, que tienen que esperar a que se termine de realizar el calculo 
;El estructural es porque en los sd se debe hacer un desplazamiento (nulo), y que no puede concretarse debido a 
;los calculos de add y mul que estan terminando de calcualrse, y acceden por prioridad a la memoria para guardarlos
;El WAR aparece porque el f1 se esta usando en lectura en el add, y aca se lo necesita para escribirlo. Por eso previene 
;el programa un atasco. 
;El nop soluciona el WAR porque hace que no se produzca el RAW en la suma, seprando un ciclo el ld f1, y gracias al 
;fowarding el registro f1 entre el add y el mul se comparte