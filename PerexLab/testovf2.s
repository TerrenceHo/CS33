	.file	"testovf.c"
	.text
	.p2align 4,,15
	.globl	testovf
	.type	testovf, @function
testovf:
.LFB0:
	.cfi_startproc
	movabsq	$9223372036854775807, %rax
	addq	%rdi, %rax
	cmpq	%rax, %rdi
	setg	%al
	ret
	.cfi_endproc
.LFE0:
	.size	testovf, .-testovf
	.ident	"GCC: (GNU) 6.3.0"
	.section	.note.GNU-stack,"",@progbits
