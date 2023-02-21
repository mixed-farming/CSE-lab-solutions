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
    LDR R0,=ARRAY
    LDR R2,=DELETE
    LDR R3,[R2];element to be deleted
    LDR R5,=STORE
    MOV R6,#4;elements in the array initially
up
    LDR R1,[R0],#4
    CMP R1,R3
    BEQ delete
    STR R1,[R5],#4
    SUBS R6,#1
    BNE up
STOP B STOP
delete
    B up
ARRAY DCD 2,4,6,8,10
DELETE DCD 8
    AREA mydata,DATA,READWRITE
STORE DCD 0
    END
