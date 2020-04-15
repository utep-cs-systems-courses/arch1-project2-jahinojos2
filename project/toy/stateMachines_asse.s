	.arch msp430g2553
	.file "switches.h"
	.text
	.extern s1_down, s2_down, s3_down, s4_down, x
	

JT:
	.word default
	.word case1
	.word case2
	.word case3
	.word case4

	.global switch_advance
switch_advance:
	cmp #4, &x
	jc default
	mov &x, r12
	add r12, r12
	mov JT(r12), r0

case1:
	mov.b #1, &s1_down
	jmp out

case2:
	mov.b #1, &s2_down
	jmp out

case3:
	mov.b #1, &s3_down
	jmp out

case4:
	mov.b #1, &s4_down
	jmp out

default:
	jmp out

out:
	ret

	
