.name "zork"
.comment "just a basic living prog"  #hola
l2: sti r9,r12,%0#asdf
	and r1,%0,r10#asdf
live:	live	%1#asdf
	zjmp	%:live#asdf
