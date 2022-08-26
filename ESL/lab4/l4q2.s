	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x10001000 ; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R5,=SRC
	LDR R0,[R5]
	LDR R6,=DST
	MOV R1,#0
	MOV R2,#0
	MOV R3,#0
UP  CMP R0,#10
	BCC STO
	SUB R0,#10
	ADD R1,#1
	B UP
STO LSL R0,R2
	ADD R2,#4
	ORR R3,R0
	MOV R0,R1
	MOV R1,#0
	CMP R0,#0
	BHI UP
	STR R3,[R6]
STOP 
	B STOP
SRC DCD 0x0081
	AREA mydata,DATA,READWRITE
DST DCD 0
	END