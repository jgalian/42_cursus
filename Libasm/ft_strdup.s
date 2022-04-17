global	_ft_strdup
extern	_malloc
extern	_ft_strlen
extern	_ft_strcpy

section .text
; rdi = str

	_ft_strdup:
		push	rdi					; aligne to 16-byte boundary and save str in stack
		call	_ft_strlen			; get str size
		mov		rdi, rax			; put size in rdi to pass it to malloc function
		inc		rdi					; add 1 byte to reserve space for \0 termination
		call	_malloc				; allocate memory in heap memory in order to copy the string passed
		mov		rdi, rax			; put allocated memory address in rdi in order to pass it as destiny to ft_strcpy
		pop		rsi					; restore original string in rsi register to pass it as second parameter
		call	_ft_strcpy			; copy the string from orign to destiny
		mov		rax, rdi			; copy the addres of the new string in rax in order to return it to caller function
		ret
