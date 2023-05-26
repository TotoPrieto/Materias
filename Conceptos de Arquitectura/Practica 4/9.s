;while a > 0 do
;  begin
;   x := x + y;
;   a := a - 1;
;  end;

.data
a:        .word 3
x:        .word 10
y:        .word 3

.code
ld        r1, a(r0)
ld        r2, x(r0)
ld        r3, y(r0)

while:    daddi     r1, r1, -1
bnez      r1, while
dadd r2, r2, r3

sd        r2, x(r0)
halt

