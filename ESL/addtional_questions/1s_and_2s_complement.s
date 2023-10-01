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
    LDR R1,=STORE
    LDR R0,=0xAAAAAAAA
    MOV R2,R0
    ;MVN R0,R0;mvn(move negative) gives the 1s complement
    ;ADD R0,#1
    ;STR R0,[R1]
    RSB R3,R2,#0; r3 = 0 - r2  ->  gives 2s complement of r2
    STR R3,[R1]
    AREA mydata,DATA,READWRITE
STORE DCD 0
    END
