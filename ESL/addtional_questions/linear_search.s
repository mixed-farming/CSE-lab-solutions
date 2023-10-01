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
    LDR R1,=ELE
    LDR R2,[R1];element to be searched
    LDR R3,=STORE
    MOV R4,#0;store 1 if element found else 0
    MOV R5,#0;array index
    MOV R6,10;no of elements in the array
   
up    LDR R7,[R0],#4
    CMP R7,R2
    BEQ found
    ADD R5,#1
    SUBS R6,#1
    BNE up
   
    STR R4,[R3],#4
    MOV R5,#0
    STR R5,[R3]
STOP
    B STOP
   
found
    ADD R4,#1
    STR R4,[R3],#4
    STR R5,[R3]
   
ARRAY DCD 9,8,7,6,5,4,3,2,1,0
ELE DCD 1
    AREA mydata,DATA,READWRITE
STORE DCD 0;stores the index of element if found else 0
    END
