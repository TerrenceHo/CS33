	.file	"testovf.c"
	.text
	.p2align 4,,15
	.globl	testovf
	.type	testovf, @function
testovf:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movabsq	$9223372036854775807, %rdx
	movq	%rdi, %rbp
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	addq	%rdx, %rbp
	jo	.L6
.L2:
	cmpq	%rbp, %rbx
	setg	%al
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore_state
	movq	%rdi, %rsi
	movl	$.Lubsan_data0, %edi
	call	__ubsan_handle_add_overflow
	jmp	.L2
	.cfi_endproc
.LFE0:
	.size	testovf, .-testovf
	.section	.rodata.str1.1,"aMS",@progbits,1
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
	.align 2
	.type	.Lubsan_type0, @object
	.size	.Lubsan_type0, 15
.Lubsan_type0:
	.value	0
	.value	13
	.string	"'long int'"
	.ident	"GCC: (GNU) 6.3.0"
	.section	.note.GNU-stack,"",@progbits
