	AREA RESET, CODE, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	AREA myCode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =DST
	MOV R1, #0x5AB
	MOV R2, #0
	MOV R3, #10
Up CMP R1, #0xA
	BCC Sto
	SUB R1, #0xA
	ADD R2, #1
	B Up
Sto ADD R1, #0x30
	STRB R1, [R0], #1
	MOV R1, R2
	MOV R2, #0
	CMP R1, #0xA
	BCS Up
	ADD R1,#0x30
	STRB R1,[R0]
STOP B STOP
	AREA MYDATA, DATA, READWRITE
DST DCD 0x0
	END