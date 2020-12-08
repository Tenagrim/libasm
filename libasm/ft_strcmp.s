;int		ft_strcmp(const char *string1, const char *string2);
			global	_ft_strcmp

			section	.text
_ft_strcmp:	xor		rcx, rcx
.loop		mov		dl, byte [rdi + rcx]
			mov		bl, byte [rsi + rcx]
			cmp		dl, 0
			jz		.ne
			cmp		bl, 0
			jz		.ne
			cmp		dl, bl
			jne		.ne
			inc		rcx
			jmp		.loop
.zero		xor		rax, rax
			ret
.ne			cmp		dl, bl
			jl		.less
			jz		.zero
			mov		rax, 1
			ret
.less		mov		rax, -1
.ret		ret
