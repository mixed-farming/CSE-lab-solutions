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
	MOV R5, #4
	LDR R0,=NUM
	LDR R3,=RESULT
UP LDRB R1,[R0], #1 ; load BCD number into register R1
	AND R2,R1,#0x0F ; mask upper 4 bits
	 ADD R2,#0x30 ; Add 30H to the number, Ascii value of first digit 
	STR R2,[R3], #4
	AND R4,R1,#0xF0 ; Mask the second digit
	MOV R4,R4,LSR#04 ; Shift right by 4 bits
	ADD R4,#0x30 ; Ascii value of second digit
	STR R4,[R3], #4
	SUBS R5, #1
	BNE UP ;Repeat 4 times
STOP B STOP
NUM DCD 0x12345678
	AREA data, DATA, READWRITE
RESULT DCD 0
	 END
