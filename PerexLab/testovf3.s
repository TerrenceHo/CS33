	.file	"testovf.c"
	.data
	.align 2
	.type	.Lubsan_type0, @object
	.size	.Lubsan_type0, 15
.Lubsan_type0:
	.value	0
	.value	13
	.string	"'long int'"
	.section	.rodata
.LC0:
	.string	"testovf.c"
	.data
	.align 16
	.type	.Lubsan_data0, @object
	.size	.Lubsan_data0, 24
.Lubsan_data0:
	.quad	.LC0
	.long	4
	.long	14
	.quad	.Lubsan_type0
	.text
	.globl	testovf
	.type	testovf, @function
testovf:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movabsq	$9223372036854775807, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rbx
	addq	%rax, %rbx
	jno	.L2
	movq	-24(%rbp), %rax
	movabsq	$9223372036854775807, %rdx
	movq	%rax, %rsi
	movl	$.Lubsan_data0, %edi
	call	__ubsan_handle_add_overflow
.L2:
	movq	%rbx, %rax
	cmpq	-24(%rbp), %rax
	setl	%al
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	testovf, .-testovf
	.ident	"GCC: (GNU) 6.3.0"
	.section	.note.GNU-stack,"",@progbits
