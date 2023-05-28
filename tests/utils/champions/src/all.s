	.name "All"
	.comment "In this file, we can found all commands."

	sti r1, %:hi, %1

hi:	live %234
	ld %0, r3
    st r3, r8
    add r2, r3, r8
    sub r2, r3, r5
    and r2, %0, r3
    or r2, %0, r3
    xor r2, %0, r3
    ldi 3, %4, r1
    fork %:ok
    lld %0, r3
    lldi 3, %4, r1
    lfork %:ok
ok: aff r1
	zjmp %:hi
