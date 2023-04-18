;<Multiply two 8 bit number>

LHLD 2000   ; H <- M[2000], L <- M[2001]
XCHG        ; D <- H, E <- L

loop: nop
ADD D       ; A <- A + D
DCR E       ; E <- E - 1
JNZ loop    ; Jump on non-zero

sta 2002    ; M[2002] <- A

HLT         ; Halt