	.name "Abel"
	.comment "L'amer noir."

	sti r1, %:hi, %1
	
hi:	live %234, %254
	ld %0, r3
	zjmp %:hi
