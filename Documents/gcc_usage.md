# gcc usage

## The common usage of gcc 
```
Usage: gcc [options] file...
Options:
  -pass-exit-codes         Exit with highest error code from a phase.
  --help                   Display this information.
  --target-help            Display target specific command line options.
  --help={common|optimizers|params|target|warnings|[^]{joined|separate|undocumented}}[,...].
                           Display specific types of command line options.
  (Use '-v --help' to display command line options of sub-processes).
  --version                Display compiler version information.
  -dumpspecs               Display all of the built in spec strings.
  -dumpversion             Display the version of the compiler.
  -dumpmachine             Display the compiler's target processor.
  -print-search-dirs       Display the directories in the compiler's search path.
  -print-libgcc-file-name  Display the name of the compiler's companion library.
  -print-file-name=<lib>   Display the full path to library <lib>.
  -print-prog-name=<prog>  Display the full path to compiler component <prog>.
  -print-multiarch         Display the target's normalized GNU triplet, used as
                           a component in the library path.
  -print-multi-directory   Display the root directory for versions of libgcc.
  -print-multi-lib         Display the mapping between command line options and
                           multiple library search directories.
  -print-multi-os-directory Display the relative path to OS libraries.
  -print-sysroot           Display the target libraries directory.
  -print-sysroot-headers-suffix Display the sysroot suffix used to find headers.
  -Wa,<options>            Pass comma-separated <options> on to the assembler.
  -Wp,<options>            Pass comma-separated <options> on to the preprocessor.
  -Wl,<options>            Pass comma-separated <options> on to the linker.
  -Xassembler <arg>        Pass <arg> on to the assembler.
  -Xpreprocessor <arg>     Pass <arg> on to the preprocessor.
  -Xlinker <arg>           Pass <arg> on to the linker.
  -save-temps              Do not delete intermediate files.
  -save-temps=<arg>        Do not delete intermediate files.
  -no-canonical-prefixes   Do not canonicalize paths when building relative
                           prefixes to other gcc components.
  -pipe                    Use pipes rather than intermediate files.
  -time                    Time the execution of each subprocess.
  -specs=<file>            Override built-in specs with the contents of <file>.
  -std=<standard>          Assume that the input sources are for <standard>.
  --sysroot=<directory>    Use <directory> as the root directory for headers
                           and libraries.
  -B <directory>           Add <directory> to the compiler's search paths.
  -v                       Display the programs invoked by the compiler.
  -###                     Like -v but options quoted and commands not executed.
  -E                       Preprocess only; do not compile, assemble or link.
  -S                       Compile only; do not assemble or link.
  -c                       Compile and assemble, but do not link.
  -o <file>                Place the output into <file>.
  -pie                     Create a dynamically linked position independent
                           executable.
  -shared                  Create a shared library.
  -x <language>            Specify the language of the following input files.
                           Permissible languages include: c c++ assembler none
                           'none' means revert to the default behavior of
                           guessing the language based on the file's extension.

Options starting with -g, -f, -m, -O, -W, or --param are automatically
 passed on to the various sub-processes invoked by gcc.  In order to pass
 other options on to these processes the -W<letter> options must be used.

For bug reporting instructions, please see:
```

## the process of making a program

### There are few steps that A program from C source code to an executable file. 

1. Write source code (编写源代码阶段)    
sample.c   
```c
#include <stdio.h>

#define PI 3.14f

float circleArea(float radius);

int main(int argc, char * argv[])
{
	printf("The area of circle is : %f\n", circleArea(2.4f));
	return 0;
}

float circleArea(float radius)
{
	return PI * radius * radius;
}
```

2. Preprocess (预处理阶段)   
The option `-E` means that Preprocess only; do not compile, assemble or link.    
run `gcc -E sample.c -o sample.afterpreprocess` to preprocess source file, then we can check the file sample.afterpreprocess after Preprocess.   
`cat sample.afterpreprocess`, we can see the PI was replace with 3.14f.   
The some of sample.c as below：    
```c
# 5 "sample.c"
float circleArea(float radius);

int main(int argc, char * argv[])
{
 printf("The area of circle is : %f\n", circleArea(2.4f));
 return 0;
}

float circleArea(float radius)
{
 return 3.14f * radius * radius;
}
```

3. Compile (编译阶段)
The option `-S` means that Compile only; do not assemble or link.   
run `gcc -S sample.c -o sample.aftercompile` to preprocess and compile file, then we can check the file sample.aftercompile after compiling.     
`cat sample.aftercompile`, we can see the soure file has been complied to assembly langauge code.    

```
	.file	"sample.c"
	.text
	.section	.rodata
.LC1:
	.string	"The area of circle is : %f\n"
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
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movss	.LC0(%rip), %xmm0
	call	circleArea
	cvtss2sd	%xmm0, %xmm0
	leaq	.LC1(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	circleArea
	.type	circleArea, @function
circleArea:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	%xmm0, -4(%rbp)
	movss	-4(%rbp), %xmm1
	movss	.LC2(%rip), %xmm0
	mulss	%xmm1, %xmm0
	mulss	-4(%rbp), %xmm0
	popq	%rbp
```

4. Assemble (汇编阶段)
The option `-c` means that Compile and assemble, but do not link.    
run `gcc -c sample.c -o sample.afterassemble` to compile and assemble file, then we can check the file sample.afterassemble after assembling.      
`hexdump -C sample.afterassemble`, we can see the soure file has been complied and assembled to machine code(The binary code).     
The some of sample.afterassembel.    
```
00000000  7f 45 4c 46 02 01 01 00  00 00 00 00 00 00 00 00  |.ELF............|
00000010  01 00 3e 00 01 00 00 00  00 00 00 00 00 00 00 00  |..>.............|
00000020  00 00 00 00 00 00 00 00  10 04 00 00 00 00 00 00  |................|
00000030  00 00 00 00 40 00 00 00  00 00 40 00 0e 00 0d 00  |....@.....@.....|
00000040  f3 0f 1e fa 55 48 89 e5  48 83 ec 10 89 7d fc 48  |....UH..H....}.H|
00000050  89 75 f0 f3 0f 10 05 00  00 00 00 e8 00 00 00 00  |.u..............|
00000060  f3 0f 5a c0 48 8d 3d 00  00 00 00 b8 01 00 00 00  |..Z.H.=.........|
00000070  e8 00 00 00 00 b8 00 00  00 00 c9 c3 f3 0f 1e fa  |................|
00000080  55 48 89 e5 f3 0f 11 45  fc f3 0f 10 4d fc f3 0f  |UH.....E....M...|
00000090  10 05 00 00 00 00 f3 0f  59 c1 f3 0f 59 45 fc 5d  |........Y...YE.]|
000000a0  c3 00 00 00 54 68 65 20  61 72 65 61 20 6f 66 20  |....The area of |
000000b0  63 69 72 63 6c 65 20 69  73 20 3a 20 25 66 0a 00  |circle is : %f..|
000000c0  9a 99 19 40 c3 f5 48 40  00 47 43 43 3a 20 28 55  |...@..H@.GCC: (U|
000000d0  62 75 6e 74 75 20 39 2e  33 2e 30 2d 31 30 75 62  |buntu 9.3.0-10ub|
000000e0  75 6e 74 75 32 29 20 39  2e 33 2e 30 00 00 00 00  |untu2) 9.3.0....|
000000f0  04 00 00 00 10 00 00 00  05 00 00 00 47 4e 55 00  |............GNU.|
00000100  02 00 00 c0 04 00 00 00  03 00 00 00 00 00 00 00  |................|
00000110  14 00 00 00 00 00 00 00  01 7a 52 00 01 78 10 01  |.........zR..x..|
00000120  1b 0c 07 08 90 01 00 00  1c 00 00 00 1c 00 00 00  |................|
00000130  00 00 00 00 3c 00 00 00  00 45 0e 10 86 02 43 0d  |....<....E....C.|
00000140  06 73 0c 07 08 00 00 00  1c 00 00 00 3c 00 00 00  |.s..........<...|
00000150  00 00 00 00 25 00 00 00  00 45 0e 10 86 02 43 0d  |....%....E....C.|
00000160  06 5c 0c 07 08 00 00 00  00 00 00 00 00 00 00 00  |.\..............|
00000170  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00000180  01 00 00 00 04 00 f1 ff  00 00 00 00 00 00 00 00  |................|
00000190  00 00 00 00 00 00 00 00  00 00 00 00 03 00 01 00  |................|
000001a0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
000001b0  00 00 00 00 03 00 03 00  00 00 00 00 00 00 00 00  |................|
000001c0  00 00 00 00 00 00 00 00  00 00 00 00 03 00 04 00  |................|
000001d0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
000001e0  00 00 00 00 03 00 05 00  00 00 00 00 00 00 00 00  |................|
000001f0  00 00 00 00 00 00 00 00  00 00 00 00 03 00 07 00  |................|
00000200  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00000210  00 00 00 00 03 00 08 00  00 00 00 00 00 00 00 00  |................|
00000220  00 00 00 00 00 00 00 00  00 00 00 00 03 00 09 00  |................|
00000230  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00000240  00 00 00 00 03 00 06 00  00 00 00 00 00 00 00 00  |................|
00000250  00 00 00 00 00 00 00 00  0a 00 00 00 12 00 01 00  |................|
00000260  00 00 00 00 00 00 00 00  3c 00 00 00 00 00 00 00  |........<.......|
00000270  0f 00 00 00 12 00 01 00  3c 00 00 00 00 00 00 00  |........<.......|
00000280  25 00 00 00 00 00 00 00  1a 00 00 00 10 00 00 00  |%...............|
00000290  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
000002a0  30 00 00 00 10 00 00 00  00 00 00 00 00 00 00 00  |0...............|
000002b0  00 00 00 00 00 00 00 00  00 73 61 6d 70 6c 65 2e  |.........sample.|
000002c0  63 00 6d 61 69 6e 00 63  69 72 63 6c 65 41 72 65  |c.main.circleAre|
000002d0  61 00 5f 47 4c 4f 42 41  4c 5f 4f 46 46 53 45 54  |a._GLOBAL_OFFSET|
000002e0  5f 54 41 42 4c 45 5f 00  70 72 69 6e 74 66 00 00  |_TABLE_.printf..|
000002f0  17 00 00 00 00 00 00 00  02 00 00 00 05 00 00 00  |................|
00000300  18 00 00 00 00 00 00 00  1c 00 00 00 00 00 00 00  |................|
00000310  04 00 00 00 0b 00 00 00  fc ff ff ff ff ff ff ff  |................|
00000320  27 00 00 00 00 00 00 00  02 00 00 00 05 00 00 00  |'...............|
00000330  fc ff ff ff ff ff ff ff  31 00 00 00 00 00 00 00  |........1.......|
00000340  04 00 00 00 0d 00 00 00  fc ff ff ff ff ff ff ff  |................|
00000350  52 00 00 00 00 00 00 00  02 00 00 00 05 00 00 00  |R...............|
00000360  1c 00 00 00 00 00 00 00  20 00 00 00 00 00 00 00  |........ .......|
00000370  02 00 00 00 02 00 00 00  00 00 00 00 00 00 00 00  |................|
00000380  40 00 00 00 00 00 00 00  02 00 00 00 02 00 00 00  |@...............|
00000390  3c 00 00 00 00 00 00 00  00 2e 73 79 6d 74 61 62  |<.........symtab|
000003a0  00 2e 73 74 72 74 61 62  00 2e 73 68 73 74 72 74  |..strtab..shstrt|
000003b0  61 62 00 2e 72 65 6c 61  2e 74 65 78 74 00 2e 64  |ab..rela.text..d|
000003c0  61 74 61 00 2e 62 73 73  00 2e 72 6f 64 61 74 61  |ata..bss..rodata|
000003d0  00 2e 63 6f 6d 6d 65 6e  74 00 2e 6e 6f 74 65 2e  |..comment..note.|
000003e0  47 4e 55 2d 73 74 61 63  6b 00 2e 6e 6f 74 65 2e  |GNU-stack..note.|
000003f0  67 6e 75 2e 70 72 6f 70  65 72 74 79 00 2e 72 65  |gnu.property..re|
00000400  6c 61 2e 65 68 5f 66 72  61 6d 65 00 00 00 00 00  |la.eh_frame.....|
00000410  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
```

5. Link (链接阶段)
The gcc can automatically link program without giving an explicit option.    
run `gcc sample.c`, then we can the a executable file named a.out.    
```
❯ ./a.out
The area of circle is : 18.086403
```
