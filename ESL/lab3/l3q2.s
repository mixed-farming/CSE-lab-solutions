	 AREA RESET, DATA, READONLY
	 EXPORT __Vectors
__Vectors 
	DCD 0x40001000 ; stack pointer value when stack is empty
	 DCD Reset_Handler ; reset vector
	 ALIGN
	 AREA mycode, CODE, READONLY
	 ENTRY
	 EXPORT Reset_Handler
Reset_Handler
	LDR R0,=SRC
	LDR R1,=DST
	LDR R2,[R0]  ;R2=n
	ADD R3,R2,#1 ; R3=(n+1)
	MUL R4,R2,R3 ; n(n+1)
	MOV R5,#2 ;divisor i.e /2
	MOV R6,#0 ;final result
UP  CMP R4,R5
	BCC Store
	SUBS R4,R5
	ADD R6,#1;Quo
	B UP
Store 
	STR R6,[R1] ;storing result at destination
STOP B STOP
SRC DCD 0x00000009
	AREA MYDATA, DATA, READWRITE 
DST DCD 0
	END