global	_ft_strlen

section .text
	_ft_strlen:
		xor		rax, rax

	_loop:
		cmp		byte [rdi + rax], 0
		je		_out
		inc		rax
		jmp		_loop

	_out:
		ret
