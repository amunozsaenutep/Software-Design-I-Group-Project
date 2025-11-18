project: mainProjectCode.o
		gcc -o project mainProjectCode.o

mainProjectCode.o: mainProjectCode.c	mainFunctions.h
		gcc -c mainProjectCode.c

clean:
	    	rm project mainProjectCode.o
