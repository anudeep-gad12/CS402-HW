.data 0x10010000
var1: .word 0x0000000c  #value of 12 in hexadecimal
var2: .word 0x0000000a  #value of 10 in hexadecimal
.extern ext1 4 #size 4 bytes  
.extern ext2 4 #size 4 bytes

.text
.globl main
main: addu $s0, $ra, $0# save $31 in $16

lw $t0, var1  # set $t0 to contents of var1 
lw $t1, var2  # set $t0 to contents of var2
sw $t0, ext2  # store contents of $t0 to ext2
sw $t1, ext1  # store contents of $t1 to ext1


# restore now the return address in $ra and return from main
addu $ra, $0, $s0 # return address back in $31
jr $ra # return from main