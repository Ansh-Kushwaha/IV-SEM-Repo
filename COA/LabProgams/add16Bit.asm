;<Add two 16 bit numbers>

LXI B, 0000000011001000b    ;
LXI D, 0000000011001000b
MVI A, 0
ADD C
ADD E
STA 2001
MVI A, 0

JNC nocarry
MVI A, 1

nocarry: nop
ADD B
ADD D
STA 2000
HLT