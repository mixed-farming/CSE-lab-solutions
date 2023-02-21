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
    LDR R0,=SRC
    LDR R2,=0x5;element to be inserted
    MOV R3,#3;position the element needs to be inserted
    MOV R4,#1;array index
    LDR R5,=DST
    MOV R6,#4;elements in the array initially
up  CMP R4,R3
    BEQ insert
    LDR R1,[R0],#4
    STR R1,[R5],#4
    ADD R4,#1;updating array index checker
    SUBS R6,#1
    BNE up
STOP B STOP
insert
    STR R2,[R5],#4
    ADD R4,#1
    B up
SRC DCD 0x1,0x3,0x7,0x9
    AREA mydata,DATA,READWRITE
DST DCD 0
    END
