.name "PACIFIER"
.comment " \/                    __/   .::::.-'-(/-/)
                     _/:  .::::.-' .-'\/\_`*******          __ (_))
        \/          /:  .::::./   -._-.  d\|               (_))_(__))
                     /: (''''/    '.  (__/||           (_))__(_))--(__))
                      \::).-'  -._  \/ \\/\|
              __ _ .-'`)/  '-'. . '. |  (i_O
          .-'      \       -'      '\|
     _ _./      .-'|       '.  (    \\                         % % %
  .-'   :      '_  \         '-'\  /|/      @ @ @             % % % %
 /      )\_      '- )_________.-|_/^\      @ @ @@@           % %\/% %
 (   .-'   )-._-:  /        \(/\'-._ `.     @|@@@@@            ..|........
  (   )  _//_/|:  /          `\()   `\_\     |/_@@             )'-._.-._.-
   ( (   \()^_/)_/             )/      \\    /                /   /
    )  _.-\\.\(_)__._.-'-.-'-.//_.-'-.-.)\-'/._              /
.-.-.-'   _o\ \\\     '::'   (o_ '-.-' |__\'-.-;~ ~ ~ ~ ~ ~~/   /\
          \ /  \\\__          )_\    .:::::::.-'\          '- - -|
     :::''':::::^)__\:::::::::::::::::'''''''-.  \                '- - - 
    :::::::  '''''''''''   ''''''''''''':::. -'\  \     PACIFIER
_____':::::_____________________________________\__\______________________"


live:	live	%1
unicorn:ld		%92,r10;char
		aff		r10
		ld		%10,r9;new line
		aff		r9					#1 line
		ld		%32,r11;space
		aff		r11
		aff		r10
		aff		r9					#2 line
		ld		%92,r10;char
		aff		r11
		ld		%47,r10;char
		aff		r10
		ld		%46,r10;char
		aff		r10
		ld		%40,r10;char
		aff		r10
		aff		r10
		aff		r10
		aff		r9					#4 line
		aff		r10
		ld		%44,r10;char
		aff		r10
		ld		%47,r10;char
		aff		r10
		ld		%34,r10;char
		aff		r10
		ld		%40,r10;char
		aff		r10
		aff		r10
		aff		r10
		ld		%95,r10;char
		aff		r10
		aff		r10
		ld		%44,r10;char
		aff		r10
		ld		%45,r10;char
		aff		r10
		aff		r10
		ld		%46,r10;char
		aff		r10
		aff		r9					#4 line
		aff		r11
		aff		r11
		aff		r11
		aff		r11
		ld		%92,r10;char
		aff		r10
		aff		r11
		ld		%41,r10;char
		aff		r10
		aff		r11
		ld		%95,r10;char
		aff		r10
		ld		%40,r10;char
		aff		r10
		aff		r11
		aff		r11
		ld		%47,r10;char
		aff		r10
		ld		%123,r10;char
		aff		r10
		aff		r9					#5 line
		aff		r11
		aff		r11
		aff		r11
		aff		r11
		ld		%33,r10;char
		aff		r10
		ld		%124,r10;char
		aff		r10
		aff		r10
		aff		r11
		aff		r11
		aff		r11
		ld		%58,r10;char
		aff		r10
		ld		%124,r10;char
		aff		r10
		aff		r10
		aff		r9					#6 line
		aff		r11
		aff		r11
		aff		r11
		aff		r11
		ld		%33,r10;char
		aff		r10
		ld		%124,r10;char
		aff		r10
		aff		r10
		aff		r11
		aff		r11
		aff		r11
		ld		%58,r10;char
		aff		r10
		ld		%124,r10;char
		aff		r10
		aff		r10
		aff		r9					#7 line
		aff		r11
		aff		r11
		aff		r11
		aff		r11
		ld		%39,r10;char
		aff		r10
		aff		r10
		aff		r10
		aff		r11
		aff		r11
		aff		r11
		ld		%39,r10;char
		aff		r10
		aff		r10
		aff		r10
		aff		r9					#8 line
		and		r2,r2,r2
		zjmp	%:live
