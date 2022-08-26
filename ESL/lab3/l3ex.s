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
	LDR R0, =VAL1 ;pointer to the first value1
	LDR R1,=VAL2 ;pointer to the second value
	LDR R2,[R0]
	LDR R3,[R1]
	UMULL R4,R5,R2,R3;Multiply the values from R1 and R2 and store 
	;least significant 32 bit number into R3 and most
	;significant 32 bit number into R4.
	LDR R6,=RESULT
	STR R4, [R6],#4
	STR R5,[R6]; store result in memory
STOP
	B STOP
VAL1 DCD 0x12346789 ; First 32 bit number
VAL2 DCD 0x456789AB ; Second 32 bit number 
	AREA data, DATA, READWRITE
RESULT DCD 0
	END
