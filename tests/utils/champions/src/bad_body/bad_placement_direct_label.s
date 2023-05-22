	.name "Abel"
	.comment "L'amer noir."

	sti %:hi, %:hi, %1
	
hi:	live %234
	ld %0, r3
	zjmp %:hi
