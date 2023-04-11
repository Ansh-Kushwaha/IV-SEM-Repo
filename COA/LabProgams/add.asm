;<Add two 8 bit numbers>

MVI B, 00001010b  ; B <- 10 
MVI C, 00001011b  ; C <- 11
ADD B		      ; A <- A + B
ADD C		      ; C <- A + C
STA 10		      ; M[10] <- A

HLT		          ; Halt