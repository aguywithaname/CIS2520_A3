all: ques1 ques2
ques1: q1.c
	gcc -Wall -std=c99 -pedantic q1.c -o q1
ques2: q2.c
	gcc -Wall -std=c99 -pedantic q2.c -o q2
clean: rm *.o
