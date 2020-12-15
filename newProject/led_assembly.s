#include "led.h"	
	
	.arch msp430g2553
	.p2align 1,0

	.data
count:
	.word 6 		;Global variable count for dimming

	.text 			;jt is constant
jt:
	.word reset	 	;jt[0]
	.word green_off		;jt[1]
	.word green_off		;jt[2]
	.word green_off		;jt[3]
	.word green_off		;jt[4]
	.word green_off		;jt[5]
	.word greenLED_on		;jt[6]

	.data
	.global dim
dim:	
	mov.b #0, red_on	;red led off
	mov &count, r12 	;moving count into r12 
	cmp #5, r12  		;r12 - 6
	jc greenLED_on		;jmp if r12 > 5

	add r12, r12		;r12 = count *2
	mov jt(r12), r0 	;jmp jt[count]
	
greenLED_on:
	mov.b #1, &green_on	;green_on = 1
	sub #1, &count		;count--
	mov.b #1, &led_changed	;led_changed = 1
	call #led_update 	;led_update()
	jmp end 		;end switch state
	
reset:
	mov #6, &count		;count = 6
	jmp end			;end switch state
	
green_off:
	mov.b #0, &green_on 	;green_on = 0
	sub #1, &count 		;count--
	mov.b #1, &led_changed 	;led_changed = 1
	call #led_update	;led_update()

end:
	pop r0 			;return
