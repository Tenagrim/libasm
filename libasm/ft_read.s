;ssize_t				ft_read(int fildes, const void *buf, size_t nbytes);
;
; syscall table
; https://github.com/opensource-apple/xnu/blob/master/bsd/kern/syscalls.master
			global	_ft_read
			extern	___error

			section	.text
_ft_read:	mov		rax, 0x2000003
			syscall
			jc		.err
			ret

.err		push	rax
			call	___error
			pop		qword [rax]
			mov		rax, -1
			ret

