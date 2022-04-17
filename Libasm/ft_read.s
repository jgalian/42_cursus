global	_ft_read
extern	___error

section .text
; rdi = fd
; rsi = buf
; rdx = count

	_ft_read:
		mov		rax, 0x02000003		; set syscall type
		syscall						; write syscall returns negative number if error in read function
		jc		_error				; MacOs set carry flag on if error
		jmp		_out				; if not go to _out label

	_error:
		push	rdx					; save rdx caller saved register and aligne the stack to 16-byte boundary
		mov		rdx, rax			; save return write syscall value
		call	___error			; call a extern function to get the adress ...
		mov		[rax], rdx			; ... where we can set error type
		mov		rax, -1				; set the return value to -1 (error)
		pop		rdx					; restore rdx value

	_out
		ret
