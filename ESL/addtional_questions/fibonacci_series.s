    AREA RESET,DATA,READONLY
    EXPORT __Vectors
__Vectors
    DCD 0X10001000
    DCD Reset_Handler
    ALIGN
    AREA MYCODE,CODE,READONLY
    ENTRY
    EXPORT Reset_Handler
Reset_Handler
    LDR R1,=DST
    MOV R2,#0
    MOV r3,#1
    MOV R4,#5
    STR r2,[r1],#4
    STR R3,[r1],#4
    MOV R5,#0
up    ADD r5,R2,R3
    STR R5,[R1],#4
    MOV R2,R3
    MOV R3,R5
    SUBS R4,#1
    BNE up
STOP B STOP
    AREA mydata,DATA,READWRITE
DST DCD 0
    END
