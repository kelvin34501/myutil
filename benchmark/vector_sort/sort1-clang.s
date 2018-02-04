	.text
	.file	"sort1.c"
	.globl	cmp                     # -- Begin function cmp
	.p2align	4, 0x90
	.type	cmp,@function
cmp:                                    # @cmp
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Lcfi0:
	.cfi_def_cfa_offset 16
.Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Lcfi2:
	.cfi_def_cfa_register %rbp
	movl	%edi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-8(%rbp), %esi
	cmpl	-12(%rbp), %esi
	jge	.LBB0_2
# BB#1:
	movl	$-1, -4(%rbp)
	jmp	.LBB0_5
.LBB0_2:
	movl	-8(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jne	.LBB0_4
# BB#3:
	movl	$0, -4(%rbp)
	jmp	.LBB0_5
.LBB0_4:
	movl	$1, -4(%rbp)
.LBB0_5:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
.Lfunc_end0:
	.size	cmp, .Lfunc_end0-cmp
	.cfi_endproc
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Lcfi3:
	.cfi_def_cfa_offset 16
.Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Lcfi5:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	leaq	-24(%rbp), %rdi
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	movl	$0, -28(%rbp)
	callq	vector_int_init
	movl	$0, -32(%rbp)
.LBB1_1:                                # =>This Inner Loop Header: Depth=1
	cmpl	$10000000, -32(%rbp)    # imm = 0x989680
	jge	.LBB1_4
# BB#2:                                 #   in Loop: Header=BB1_1 Depth=1
	callq	rand@PLT
	leaq	-24(%rbp), %rdi
	movl	%eax, %esi
	callq	vector_int_push
# BB#3:                                 #   in Loop: Header=BB1_1 Depth=1
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	jmp	.LBB1_1
.LBB1_4:
	movl	-24(%rbp), %ecx
	leaq	cmp(%rip), %rsi
	leaq	-24(%rbp), %rax
	xorl	%edx, %edx
	movq	%rax, %rdi
	movq	%rax, -40(%rbp)         # 8-byte Spill
	callq	vector_int_quicksort
	movq	-40(%rbp), %rdi         # 8-byte Reload
	callq	vector_int_free
	movl	-28(%rbp), %eax
	movq	%fs:40, %rsi
	movq	-8(%rbp), %rdi
	cmpq	%rdi, %rsi
	movl	%eax, -44(%rbp)         # 4-byte Spill
	jne	.LBB1_6
# BB#5:
	movl	-44(%rbp), %eax         # 4-byte Reload
	addq	$48, %rsp
	popq	%rbp
	retq
.LBB1_6:
	callq	__stack_chk_fail@PLT
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function vector_int_init
	.type	vector_int_init,@function
vector_int_init:                        # @vector_int_init
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Lcfi6:
	.cfi_def_cfa_offset 16
.Lcfi7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Lcfi8:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$32, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movl	$0, (%rdi)
	movq	-8(%rbp), %rdi
	movl	$8, 4(%rdi)
	movq	%rcx, %rdi
	callq	malloc@PLT
	movq	-8(%rbp), %rcx
	movq	%rax, 8(%rcx)
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end2:
	.size	vector_int_init, .Lfunc_end2-vector_int_init
	.cfi_endproc
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function vector_int_push
	.type	vector_int_push,@function
vector_int_push:                        # @vector_int_push
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Lcfi9:
	.cfi_def_cfa_offset 16
.Lcfi10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Lcfi11:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rdi
	movl	(%rdi), %esi
	movq	-8(%rbp), %rdi
	cmpl	4(%rdi), %esi
	jne	.LBB3_2
# BB#1:
	movq	-8(%rbp), %rax
	movl	4(%rax), %ecx
	shll	$1, %ecx
	movl	%ecx, 4(%rax)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	-8(%rbp), %rdx
	movslq	4(%rdx), %rdx
	shlq	$2, %rdx
	movq	%rax, %rdi
	movq	%rdx, %rsi
	callq	realloc@PLT
	movq	-8(%rbp), %rdx
	movq	%rax, 8(%rdx)
.LBB3_2:
	movl	-12(%rbp), %eax
	movq	-8(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	-8(%rbp), %rdx
	movl	(%rdx), %esi
	movl	%esi, %edi
	addl	$1, %edi
	movl	%edi, (%rdx)
	movslq	%esi, %rdx
	movl	%eax, (%rcx,%rdx,4)
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end3:
	.size	vector_int_push, .Lfunc_end3-vector_int_push
	.cfi_endproc
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function vector_int_quicksort
	.type	vector_int_quicksort,@function
vector_int_quicksort:                   # @vector_int_quicksort
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Lcfi12:
	.cfi_def_cfa_offset 16
.Lcfi13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Lcfi14:
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movl	%ecx, -24(%rbp)
	movl	-24(%rbp), %ecx
	subl	-20(%rbp), %ecx
	cmpl	$2, %ecx
	jge	.LBB4_2
# BB#1:
	jmp	.LBB4_17
.LBB4_2:
	callq	rand@PLT
	movl	-24(%rbp), %ecx
	subl	-20(%rbp), %ecx
	cltd
	idivl	%ecx
	addl	-20(%rbp), %edx
	movl	%edx, -28(%rbp)
# BB#3:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movslq	-28(%rbp), %rcx
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, -40(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movl	-24(%rbp), %edx
	subl	$1, %edx
	movslq	%edx, %rcx
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, -48(%rbp)
	movq	-40(%rbp), %rax
	cmpq	-48(%rbp), %rax
	jne	.LBB4_5
# BB#4:
	jmp	.LBB4_6
.LBB4_5:
	movq	-40(%rbp), %rax
	movl	(%rax), %ecx
	movl	%ecx, -52(%rbp)
	movq	-48(%rbp), %rax
	movl	(%rax), %ecx
	movq	-40(%rbp), %rax
	movl	%ecx, (%rax)
	movl	-52(%rbp), %ecx
	movq	-48(%rbp), %rax
	movl	%ecx, (%rax)
.LBB4_6:
	movl	-20(%rbp), %eax
	movl	%eax, -60(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -56(%rbp)
.LBB4_7:                                # =>This Inner Loop Header: Depth=1
	movl	-56(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jge	.LBB4_16
# BB#8:                                 #   in Loop: Header=BB4_7 Depth=1
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	8(%rcx), %rcx
	movslq	-56(%rbp), %rdx
	movl	(%rcx,%rdx,4), %edi
	movq	-8(%rbp), %rcx
	movq	8(%rcx), %rcx
	movl	-24(%rbp), %esi
	subl	$1, %esi
	movslq	%esi, %rdx
	movl	(%rcx,%rdx,4), %esi
	callq	*%rax
	cmpl	$0, %eax
	jg	.LBB4_14
# BB#9:                                 #   in Loop: Header=BB4_7 Depth=1
	jmp	.LBB4_10
.LBB4_10:                               #   in Loop: Header=BB4_7 Depth=1
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movslq	-56(%rbp), %rcx
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, -72(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movl	-60(%rbp), %edx
	movl	%edx, %esi
	addl	$1, %esi
	movl	%esi, -60(%rbp)
	movslq	%edx, %rcx
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, -80(%rbp)
	movq	-72(%rbp), %rax
	cmpq	-80(%rbp), %rax
	jne	.LBB4_12
# BB#11:                                #   in Loop: Header=BB4_7 Depth=1
	jmp	.LBB4_13
.LBB4_12:                               #   in Loop: Header=BB4_7 Depth=1
	movq	-72(%rbp), %rax
	movl	(%rax), %ecx
	movl	%ecx, -84(%rbp)
	movq	-80(%rbp), %rax
	movl	(%rax), %ecx
	movq	-72(%rbp), %rax
	movl	%ecx, (%rax)
	movl	-84(%rbp), %ecx
	movq	-80(%rbp), %rax
	movl	%ecx, (%rax)
.LBB4_13:                               #   in Loop: Header=BB4_7 Depth=1
	jmp	.LBB4_14
.LBB4_14:                               #   in Loop: Header=BB4_7 Depth=1
	jmp	.LBB4_15
.LBB4_15:                               #   in Loop: Header=BB4_7 Depth=1
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
	jmp	.LBB4_7
.LBB4_16:
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movl	-20(%rbp), %edx
	movl	-60(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %ecx
	callq	vector_int_quicksort
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movl	-60(%rbp), %edx
	movl	-24(%rbp), %ecx
	callq	vector_int_quicksort
.LBB4_17:
	addq	$96, %rsp
	popq	%rbp
	retq
.Lfunc_end4:
	.size	vector_int_quicksort, .Lfunc_end4-vector_int_quicksort
	.cfi_endproc
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function vector_int_free
	.type	vector_int_free,@function
vector_int_free:                        # @vector_int_free
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Lcfi15:
	.cfi_def_cfa_offset 16
.Lcfi16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Lcfi17:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movl	$0, (%rdi)
	movq	-8(%rbp), %rdi
	movl	$0, 4(%rdi)
	movq	-8(%rbp), %rdi
	movq	8(%rdi), %rdi
	callq	free@PLT
	movq	-8(%rbp), %rdi
	movq	$0, 8(%rdi)
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end5:
	.size	vector_int_free, .Lfunc_end5-vector_int_free
	.cfi_endproc
                                        # -- End function

	.ident	"clang version 5.0.1 (tags/RELEASE_501/final)"
	.section	".note.GNU-stack","",@progbits
