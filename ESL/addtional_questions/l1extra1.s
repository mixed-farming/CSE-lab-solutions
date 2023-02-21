    AREA RESET,DATA,READONLY
    EXPORT __Vectors
   
__Vectors
    DCD 0x10001000 ;stack pointer value when stack is empty
    DCD Reset_Handler ;reset vector
    ALIGN
    AREA mycode,CODE,READONLY
    ENTRY
    EXPORT Reset_Handler
   
Reset_Handler
    LDR R0, =SRC
    LDR R1, =DST
    MOV R2, #10
    sub r0,#4
    sub r1,#4
up LDR R3,[R0,#4]!
    ;add r0,#4
    STR R3,[R1,#4]!
    ;add r1,#4
    SUBS R2,#1
    BNE up
STOP
    B STOP
SRC DCD 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x10
    AREA mydata, DATA, READWRITE
DST DCD 0
    END
