all: hw2.c functions.c my_functions.c structure.c
	gcc hw2.c functions.c my_functions.c structure.c -std=c90 -Wno-incompatible-pointer-types -Wno-discarded-qualifiers -Wall -Wextra -fno-common -o hw2.exe

test: hw2test.c functions.c my_functions.c structure.c
	gcc hw2test.c functions.c my_functions.c structure.c -std=c90 -Wno-incompatible-pointer-types -Wno-discarded-qualifiers -Wall -Wextra -fno-common -o hw2test.exe

clean:
	rm -f hw2.exe

clean_test:
	rm -f hw2test.exe
