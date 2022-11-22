all: q1 q2
q1: Q1.c
	gcc Q1.c -o q1
q2: Q2.c
	gcc Q2.c -o q2
