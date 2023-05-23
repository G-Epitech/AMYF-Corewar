	.name "Abel"
	.comment "L'amer noir."

	sti r80, %:hi, %1
	
hi:	live %234
	ld %0, r99336
	zjmp %:hi
