;size_t				ft_strlen(const char *str);

			global	_ft_strlen

			section	.text
_ft_strlen:	xor		rax, rax				; rax = 0
.loop		cmp		byte [rdi + rax], 0		; if(rdi[rax] == 0)
			jz		.ret					; return (rax)
			inc		rax						; rax++
			jmp		.loop
.ret		ret
