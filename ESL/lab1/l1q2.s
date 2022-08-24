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
	LDR R3, [R0]
	STR R3, [R1]
STOP 
	B STOP
	AREA mydata1,DATA,READONLY
SRC DCD 8
	AREA mydata2,DATA,READWRITE
DST DCD 0
	END