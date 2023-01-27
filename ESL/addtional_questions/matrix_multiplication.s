	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x40001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R0, #4						;	R0 = Constant 4, as MUL needs both reg arguments
	LDR R2, =N
	LDR R1, [R2]					;	R1 = Size of Array
	MUL R2, R0, R1					;	R2 = 4*size of array, ie, offset for rows
	LDR R3, =MAT_A					;	R3 = Base address of matrix A
	LDR R4, =MAT_B					;	R4 = Base address of matrix B
	
			LDR R12, =0x10000500	;	Base address of product matrix (Provided in question)
			MOV R5, #0				;	R5 is our index i
MUL_I_LOOP	CMP R5, R1
			BGE MUL_DONE
			
			MOV R6, #0				;	R6 is our index j
MUL_J_LOOP	CMP R6, R1
			BGE MUL_J_DONE
			
			MOV R7, #0				;	R7 is our index k
			MOV R8, #0				;	R8 is sum term set to 0
MUL_K_LOOP	CMP R7, R1
			BGE MUL_K_DONE
			MUL R9, R5, R2			;	Getting row offset(i*n*4) and storing in R9
			MLA R9, R7, R0, R9		;	Adding column offset(k*4) to row offset to get relative address of A[i][k]
			LDR R10, [R3, R9]		;	Getting A[i][k] element
			MUL R9, R7, R2			;	Getting row offset(k*n*4) and storing in R9
			MLA R9, R6, R0, R9		;	Adding column offset(j*4) to row offset to get relative address of B[k][j]
			LDR R11, [R4, R9]		;	Getting B[k][j] element
			MLA R8, R10, R11, R8	;	A[i][k]*B[k][j]
			ADD R7, #1				;	k = k+1
			B MUL_K_LOOP
			
MUL_K_DONE	MUL R9, R5, R2			;	Getting row offset(i*n*4) and storing in R9
			MLA R9, R6, R0, R9		;	Adding column offset(j*4) to row offset to get relative address of C[i][j]
			STR R8, [R12, R9]		;	Store product sum in C[i][j]
			ADD R6, #1				;	j = j+1
			B MUL_J_LOOP
			
MUL_J_DONE	ADD R5, #1				;	i = i+1
			B MUL_I_LOOP

MUL_DONE	NOP

			LDR R12, =0x10000600	;	Base address of transpose matrix (Provided in question)
			MOV R5, #0				;	R5 is our index i
TRA_I_LOOP	CMP R5, R1
			BGE TRA_DONE
			
			MOV R6, #0				;	R6 is our index j
TRA_J_LOOP	CMP R6, R1
			BGE TRA_J_DONE
			MUL R9, R5, R2			; Getting row offset(i*n*4)
			MLA R9, R6, R0, R9		; Adding column offset(j*4) to row offset to get address of A[i][j]
			LDR R10, [R3, R9]		; R10 = A[i][j]
			MUL R9, R6, R2			; Getting row offset(j*n*4)
			MLA R9, R5, R0, R9		; Adding column offset(i*4) to row offset to get address of A[j][i]
			STR R10, [R12, R9]		; Stor element A[i][j] into A[j][i]
			ADD R6, #1
			B TRA_J_LOOP

TRA_J_DONE	ADD R5, #1
			B TRA_I_LOOP
			
TRA_DONE	NOP

STOP B STOP

N		DCD 3
MAT_A	DCD 1, 2, 3, 4, 5, 6, 7, 8, 9
MAT_B	DCD 9, 8, 7, 6, 5, 4, 3, 2, 1
	
	AREA mydata, DATA, READWRITE
MEM DCD 0x0
	END