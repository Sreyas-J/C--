C--: obj/arithmetic.o obj/condition.o obj/interpreter.o obj/main.o obj/print.o obj/variable.o	#the dependencies of the executable file
#explaining how to create C--(executable file) from its' dependencies
	gcc obj/arithmetic.o obj/condition.o obj/interpreter.o obj/main.o obj/print.o obj/variable.o -o C--		
#creating .o file from .c file and storing it in "obj" folder
obj/arithmetic.o: src/arithmetic.c	
	gcc -c src/arithmetic.c -o obj/arithmetic.o

obj/condition.o: src/condition.c
	gcc -c src/condition.c -o obj/condition.o

obj/interpreter.o: src/interpreter.c
	gcc -c src/interpreter.c -o obj/interpreter.o

obj/main.o: src/main.c
	gcc -c src/main.c -o obj/main.o

obj/print.o: src/print.c
	gcc -c src/print.c -o obj/print.o

obj/variable.o: src/variable.c
	gcc -c src/variable.c -o obj/variable.o
#clearing any previously existing files that will be created by the makefile
clean:
	rm obj/*.o C--