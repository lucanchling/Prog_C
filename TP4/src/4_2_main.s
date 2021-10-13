	.file	"4_2_main.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Quel fichier voulez-vous ouvrir ?"
.LC1:
	.string	"%s"
	.align 8
.LC2:
	.string	"Dans le fichier, il y a actuellement :"
	.align 8
.LC3:
	.string	"Que voulez-vous ajouter dedans :"
	.align 8
.LC4:
	.string	"Apr\303\250s ajout de votre message, dans le fichier, il y a actuellement :"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$176, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	leaq	-176(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	lire_fichier@PLT
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	-112(%rbp), %rdx
	leaq	-176(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	ecrire_dans_fichier@PLT
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	lire_fichier@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
