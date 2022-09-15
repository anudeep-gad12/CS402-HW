.data 0x10010000
var1: .word 0x55
var2: .word 0x66
var3: .word 0x77
var4: .word 0x88

first: .byte 'A'
last:  .byte  'G'

.text
.globl main
main: addu $s0, $ra, $0# save $31 in $16
lui $t8, 0x1001      
lw $t0, 0($t8)      #lw $t0, var1,   set $t0 to contents of displaced address 0($t8) i.e.., var1
    # $t0 <- 0($t8)
              
lw $t1, 4($t8)      #lw $t1, var2,   set $t1 to contents of displaced address 4($t8) i.e.., var2 
    # $t1 <- 4($t8)
      
lw $t2, 8($t8)       #lw $t2, var3,  set $t2 to contents of displaced address 8($t8) i.e.., var3 
    # $t2 <- 8($t8)

lw $t3, 12($t8)      #lw $t3, var4,  set $t3 to contents of displaced address 12($t8) i.e.., var4
    # $t3 <- 12($t8)


lb $t4, 16($t8)      #lb $t4, first,  set $t4 to contents of displaced address 16($t8) i.e.., first 
    # $t4 <- 16($t8)

lb $t5, 17($t8)       #lb $t5, last,  set $t5 to contents of displaced address 17($t8) i.e.., last 
    # $t5 <- 17($t8)

sw $t3, 0($t8)       #sw $t3, var1, store contents of $t3 to the displaced address 0($t8) i.e.., var1
    #var4 -> var1

sw $t2, 4($t8)        #sw $t2, var2, store contents of $t2 to the displaced address 0($t8) i.e.., var2
    #var3 -> var2

sw $t1, 8($t8)       #sw $t1, var3,  store contents of $t1 to the displaced address 0($t8) i.e.., var3
    #var2 -> var3

sw $t0, 12($t8)      #sw $t0, var4,  store contents of $t0 to the displaced address 0($t8) i.e.., var4   
    #var1 -> var4

# restore now the return address in $ra and return from main
addu $ra, $0, $s0 # return address back in $31
jr $ra                #jr $ra # return from main
add $0, $0, $0    #nop to stall 