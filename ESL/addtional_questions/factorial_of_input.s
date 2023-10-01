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
    LDR R0,=Number
    LDR R1,[R0]
    MOV R2,#1 ; factorial
   
up    MUL R2,R1
    SUBS R1,#1
    BNE up
   
    LDR R3,=RESULT
    STR R2,[R3]
Number DCD 5
    AREA mydata,DATA,READWRITE
RESULT DCD 0;stores the index of element if found else 0
    END
