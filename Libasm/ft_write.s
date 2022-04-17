global	_ft_write
extern	___error

section .text
; rdi = fd
; rsi = buf
; rdx = count

	_ft_write:
		mov		rax, 0x02000004		; set syscall type
		syscall						; write syscall returns negative number if error
		jc		_sys_error			; MacOs set carry flag on if error in write function
		jmp		_out				; if not go to _out label

	_sys_error:
		push	rdx					; save value on caller saved register and aligne stack to 16-byte boundary
		mov		rdx, rax			; save return write syscall value
		call	___error			; call a extern function to get the adress ...
		mov		[rax], rdx			; ... where we can set error type
		pop		rdx					; restore original value to rdx register
		mov		rax, -1				; set the return value to -1 (error)

	_out:
		ret
