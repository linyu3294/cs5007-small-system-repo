# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
					# (1) What are we setting up here?
					# Ans: We are setting up a framepointer/basepointer in %rbp.
	pushq %rbp			# The basepointer denotes the starting point in the stack's mememory.
	movq  %rsp, %rbp		# After the base pointer is established, we will then set the stackpointer to
					# to the same register as the base pointer. In effect, the stackpointer will start 
					# at the same place as the basepointer.

					# (2) What is going on here
					# Ans: Here, we are writting the number 1 literally into registers, %rax and %rdi.
					# 
	movq $1, %rax			#      leaq - loads address of .hello.str into %rsi.
	movq $1, %rdi			#
	leaq .hello.str,%rsi		#


					# (3) What is syscall? We did not talk about this
					# in class.
					# Ans: A syscall is a method that runs the command. It basically provides a way for the stack to
					#      communicate with the operating system. Whenever a program needs 
					#      a service on the operating system, syscall will need to specified.
	syscall				# Which syscall is being run?
					# Ans: This syscall is handling writting function. It's handling writting the 
					#      values to %rax and %rdi. The literal 1 represents the writing function.

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans: We can alternatively use 0X80 which would achieve the same task.
					#      0X80 is essencially the same thing as syscall.

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans: This syscall performs exits. If a literal 60 is moved into %rax, a call
					#      will be made request the program to exit.
						While a literal 0 is moved to %rax causes the program to read the value.
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans:	ASCII and Unicode defines 12 as the carriage return. 
					# This command returns the cursor to beginning of the current line.
					
					
