.name ""#hola primoh
.comment "just a basic living prog"

l2:	sti	r99, r12,%0
	and	r1,%0,r1
live:	live	%1
	zjmp	%:live;holaaa
