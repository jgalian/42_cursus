global	_ft_strcpy

section .text
; rdi = dst string
; rsi = src string

	_ft_strcpy:
		xor		rax, rax				; set counter to 0

	_loop:
		cmp		byte [rsi + rax], 0		; check if it is the end of the string
		je		_out					; if it is go to _out label
		mov		cl, byte [rsi + rax]	; copy src # char to 8 bits cl register
		mov		byte [rdi + rax], cl	; copy char in cl register to dst # char in rdi
		inc		rax						; add one to counter
		jmp		_loop					; go to _loop label

	_out:
		mov		byte [rdi + rax], 0		; set end of string signal to dst # char in rdi
		mov		rax, rdi				; copy dst string to return register rax
		ret
