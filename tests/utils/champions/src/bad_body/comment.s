	.name "Abel"
	.comment "L'amer noir."

	sti r1, %:hi, %1
    #test
hi:	live %234#test



test: 
    ld %0, r3
	zjmp %:hi
