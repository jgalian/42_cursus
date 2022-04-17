global	_ft_strcmp

section .text
; rdi = str1
; rsi = str2

	_ft_strcmp:
		xor		rax, rax				; rax = 0

	_loop:
		movzx	cx, byte [rdi + rax]	; copy str1 # char to 16 bits cx register (0x80... be converted to -128d)
		movzx	dx, byte [rsi + rax]	; copy str2 # char to 16 bits dx register (0x80... be converted to -128d)
		cmp		cx, dx					; compare both chars
		jne		_no_equal				; if they are different go to _no_equal label
		cmp		cx, 0					; if they are equal ckeck if it is the end of the string
		je		_end_equal				; if it is go to _equal label
		inc		rax						; if it is not the end of the string add one to counter
		jmp		_loop					; start the loop again

	_end_equal:
		mov		rax, 0					; set return register rax to 0
		jmp		_out					; go to the _out label

	_no_equal:
		cmp		cx, dx					; compare both chars
		jge		_possitive				; if str1 char is bigger go to _possitive label
		jmp		_negative				; if str2 char is bigger go to _negative label

	_possitive:
		sub		cx, dx					; substract ascii code in dl register from ascii code in cl
		xor		rax, rax				; set return register rax to 0
		mov		ax, cx					; copy substraction result to lower part of the rax register
		jmp		_out					; go to the _out label

	_negative:
		sub		dx, cx					; substract ascii code in cl register from ascii code in dl
		xor		rax, rax				; set return register rax to 0
		mov		ax, dx					; copy substraction result to lower part of the rax register
		neg		rax						; change result to negative

	_out:
		ret
