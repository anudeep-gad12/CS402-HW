.data
prompt1: .asciiz "Enter value of x: \n"
prompt2: .asciiz "Enter value of y: \n"                
messageNegative: .asciiz "Enter an integer greater than 0 \n"
answer: .asciiz "Ackermann: "

.text               
.globl main         
main: 
   addu $s0, $ra, $0 #   save $31 in $16
# Prompt first integer
valuex:
li $v0, 4           # print string syscall
la $a0, prompt1     # load address of prompt in $a0
syscall             

# Get integer value
li $v0, 5           # read integer syscall
syscall

#Store in $t0
move $t0, $v0       # store read integer value in $t0

blt $t0, 0, branchX  # If (x<0) goto branchX  
    j valuey         # jump to valuey branch

valuey:
# Prompt second integer
li $v0, 4          # print string syscall
la $a0, prompt2    # load address of prompt in $a0
syscall

# Get integer value
li $v0, 5           # read integer syscall
syscall

#Store in $t1
move $t1, $v0       # store read integer value in $t0


# answer prompt
li $v0, 4           # print string syscall
la $a0, answer      # load address of prompt in $a0
syscall    

blt $t1, 0, branchY # If(y < 0) goto branchY

move $a0, $t0       # store x in $a0
move $a1, $t1       # store y in $a1


    jal Ackermann       # calling Ackermann(x, y) procedure with arguments $a0, $a1
    move $a0,$v0        # store the result of function in $a0

    li $v0,1            # system call to print integer
    syscall         

    li $v0,10           # system call to exit
    syscall             

Ackermann:
    subu $sp,$sp,8      # Creating a stack of 8 bytes to fit values of 4 bytes each
    sw $ra,0($sp)       # Store previous address in stack
    sw $s0,4($sp)       # store previous value in stack
    bgtz $a0,Ackermann_condition_1      # if x > 0, Go to condition 1
    addi $v0,$a1,1      # result = n+1
    j terminate         # Goto end terminate

Ackermann_condition_1:  # for x>0 and y=0
    bgtz $a1,Ackermann_condition_2      # if y > 0, Go to condition 2
    sub $a0,$a0,1       # x= x-1
    li $a1,1            # y = 1
    jal Ackermann       # calling Ackermann(x, y) procedure with new arguments $a0, $a1
    j terminate         # Goto end terminate  
Ackermann_condition_2:  # for x>0 and y>0
    move $s0,$a0       # Store the x value in $s0
    sub $a1,$a1,1      # y = y-1
    jal Ackermann      # calling Ackermann(x, y) procedure with new arguments $a0, $a1
    move $a1,$v0       # store value of $v0 in $a1
    sub $a0,$s0,1      # x = x-1
    jal Ackermann      # calling Ackermann(x, y) procedure with new arguments $a0, $a1
                    

terminate:         
    lw $s0,4($sp)       # get $s0 from stack
    lw $ra,0($sp)       # get the last address into $ra
    addi $sp,$sp,8      # pop from the stack
    jr $ra              # return    


# if input value of x or y is less zero goto branchX / branchY    
branchX:
    li $v0, 4           # print string syscall
    la $a0, messageNegative  # load address of prompt in $a0
    syscall
    j valuex            # jump to valuex

branchY:
    li $v0, 4           # print string syscall
    la $a0, messageNegative  # load address of prompt in $a0
    syscall
    j valuey            # jump to valuey