C--: obj/arithmetic.o obj/condition.o obj/interpreter.o obj/main.o obj/print.o obj/variable.o
	gcc obj/arithmetic.o obj/condition.o obj/interpreter.o obj/main.o obj/print.o obj/variable.o -o C--

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

clean:
	rm obj/*.o C--