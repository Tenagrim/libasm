;char		*ft_strdup(const char *str);

			global	_ft_strdup
			extern	_malloc
			extern	_ft_strlen
			extern	_ft_strcpy

			section	.text
_ft_strdup:	xor		rax, rax
			push	rdi
			call	_ft_strlen
			inc		rax
			mov		rdi, rax
			call	_malloc
			cmp		rax, 0
			jz		.ret
			pop		rdi
			mov		rsi, rdi
			mov		rdi, rax
			call	_ft_strcpy
.ret		ret
			
