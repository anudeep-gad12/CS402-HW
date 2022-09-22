.data 0x10010000
prompt: .asciiz "Enter an integer : \n"  
message1: .asciiz "I'm far away"
message2: .asciiz "I'm nearby"


.text
.globl main
main: addu $s0, $ra, $0 # save $31 in $16

# Prompt first integer
li, $v0, 4          # print string syscall
la, $a0, prompt     # load address of prompt in $a0
syscall

# Get integer value
li $v0, 5           # read integer syscall
syscall

#Store in $t0
move $t0, $v0       # store read integer value in $t0


# Prompt second integer
li, $v0, 4          # print string syscall
la, $a0, prompt     # load address of prompt in $a0
syscall

# Get integer value
li $v0, 5           # read integer syscall
syscall

#Store in $t1
move $t1, $v0       # store read integer value in $t0


bne $t0, $t1, close # if($t0 != $t1 ) PC goto close,  comparing two entered integers
li $v0, 4           # print string syscall
la $a0, message1    # load address of message1 in $a0
syscall
j exit              # PC goto exit 


close: 
li $v0, 4           # print string syscall
la $a0, message2    # load address of message2 in $a0
syscall


# restore now the return address in $ra and return from main
exit:
addu $ra, $0, $s0 # return address back in $31
jr $ra # return from main

