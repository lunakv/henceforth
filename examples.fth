\ hello world
: HELLO ." Hello world!" ;

\ find the greatest element on the stack
: GREATEST BEGIN DEPTH 1 > WHILE MAX REPEAT ;

\ compute the factorial of n
: FACT ( n -- n )
	DUP 2 < IF DROP 1 EXIT THEN 			\ handle small values
	1 SWAP 1+ 1 							\ set up loop parameters
	?DO I * LOOP							\ run loop
;

\ produce a sequence of numbers 1..n
: SEQUENCE ( n -- i*n )	BEGIN DUP WHILE DUP 1- REPEAT ;

\ checks if a number is a square
: SQUARE ( n -- f )
    DUP 0< IF DROP FALSE EXIT THEN  \ filter negative numbers
	0 DO			                \ loop setup
	  DUP I I * =	                \ check input against I*I
	  IF DROP TRUE UNLOOP EXIT THEN \ return TRUE if equal
	LOOP DROP FALSE                 \ return false if end reached
;

\ compute the factorial of n, but now recursively
: FACTR ( n -- n )
	DUP 2 < IF DROP 1 EXIT THEN
	DUP 1- RECURSE *
;

\ produces n-th Fibonacci number, recursively
: FIB ( n -- n )
	DUP 3 < IF DROP 1 EXIT THEN
	1- DUP 1-
	RECURSE SWAP RECURSE + 
;


