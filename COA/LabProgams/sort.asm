;<Swap two numbers in place>

LDA 10	    ; A <- M[10]
MOV B, A    ; B <- A
LDA 11	    ; A <- M[11]
STA 10	    ; M[10] <- A
MOV A, B    ; A <- B
STA 11	    ; M[11] <- B

HLT	    ; Halt