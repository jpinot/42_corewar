.name    "sebc"
.comment "sebc"

	ld	%4, r3
l1:	live	%1
l1:	ldi	%:l1, r2, r4
	add	r2, r3, r2
	xor	r4, r4, r4
	zjmp	%:l1
l1:
