.data 0x10010000
my_array: .space 40  # 10 elements each element = 4 bytes  10x4 = 40
message: .asciiz "array reading done"
newLine: .asciiz "\n"


.text
.globl main
main: addu $s0, $ra, $0 # save $31 in $16

# i and j for reading values into the array

addi $t0, $0, 0    # i = 0 
addi $t1, $0, 0    # j = 0

# k and l for printing values from array to the screen

addi $t2, $0, 0	   # k = 0	
addi $t3, $0, 0    # l = 0

while: 
    bgt $t0, 9, close      # branch to exit while ( i > 9) 
    sw $t0, my_array($t1)  # store j value in my_array(j)
    addi $t1, $t1,4        # increment j value by 4 bytes 
    addi $t0, $t0,1        # increment i by 1 i=i+1
    j while                # jump to check while condition

close:
    li $v0, 4              # print string syscall
    la $a0, message        # load address of message in $a0  
    syscall
    
    li, $v0, 4             # print string syscall
    la $a0, newLine        # load address of newLine in $a0
    syscall

while_print:
    bgt $t2, 9, exit       # branch to exit while ( k > 10) 
    lw $t2, my_array($t3)  # store j value in my_array(j)

    li, $v0, 1             # print integer system call,  printing element of my_array 
    move $a0, $t2          # load address of $t2 in $a0
    syscall

    li, $v0, 4              # print string syscall
    la $a0, newLine         # load address of newLine in $a0
    syscall

    addi $t3, $t3,4         # increment l value by 4 bytes 
    addi $t2, $t2,1         # increment k by 1 k=k+1
    j while_print           # jump to check while condition


exit: 
# restore now the return address in $ra and return from main
addu $ra, $0, $s0 # return address back in $31
jr $ra # return from main
