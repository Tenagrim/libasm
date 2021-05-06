;char		*ft_strcpy(char *dest, const char *src);
;                      rdi         rsi

			global	_ft_strcpy

			section	.text
_ft_strcpy:	xor		rcx, rcx
			mov		rax, rdi
.loop		mov		dl, byte [rsi + rcx]
			mov		[rdi + rcx], dl
			inc		rcx
			cmp		dl, 0
			jz		.ret
			jmp		.loop

.ret		ret
