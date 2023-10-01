    AREA RESET,CODE,READONLY
    EXPORT __Vectors

__Vectors
    DCD 0X10001000
    DCD Reset_Handler
    ALIGN
    AREA mycode,CODE,READONLY
    EXPORT Reset_Handler
    ENTRY

Reset_Handler
    LDR R0,=NUMS
    LDM R0,{R1-R10}
    STMIA R13,{R1-R10}
    MOV R5,#10
    MOV R6,#0
    MOV R7,#0
    MOV R8,R6
    MOV R12,#4
    MOV R9,R13

OUTER_LOOP
    CMP R6,#8
    BHI STORE
    MOV R8,R6
    ADD R7,R6,#1
    B INNER_LOOP

INNER_LOOP
    MLA R10,R7,R12,R9
    MLA R11,R8,R12,R9
    LDR R1,[R10]
    LDR R2,[R11] 
    CMP R1,R2
    BCS L
    MOV R8,R7

L ADD R7,R7,#1
    CMP R7,#9
    BLS INNER_LOOP
    MLA R10,R6,R12,R9
    MLA R11,R8,R12,R9
    LDR R3,[R10]
    LDR R4,[R11]
    STR R4,[R10]
    STR R3,[R11]
    ADD R6,R6,#1
    B OUTER_LOOP

STORE
    LDM R13,{R1-R10}

STOP B STOP
NUMS DCD 1,4,3,2,6,5,8,9,7,10
END