	AREA RESET,DATA,READONLY
	EXPORT __Vectors

__Vectors
	DCD 0x10001000 ; stack pointer when stack is emtpy
	DCD Reset_Handler ; reset vector
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler

Reset_Handler
	MOV R3,#10
	LDR R0,=SRC
	LDR R1,=DST
	
loop1
	LDR R2,[R0]
	STR R2,[R1]
	ADD R0,R0,#4
	ADD R1,R1,#4
	SUBS R3,R3,#1
	BNE loop1

	MOV R5,#5
	LDR R0,=DST
	LDR R1,=DST
	ADD R1,R1,#36

loop2
	LDR R2,[R0]
	LDR R3,[R1]
	STR R3,[R0]
	STR R2,[R1]
	ADD R0,#4
	SUB R1,#4
	SUBS R5,#1
	BNE loop2

STOP
	B STOP

	AREA mydata1,DATA,READONLY
SRC DCD 0x10,0x9,0x8,0x7,0x6,0x5,0x4,0x3,0x2,0x1
	AREA mydata2,DATA,READWRITE
DST DCD 0
	END