all: start

start: i_node
	./i_node 

i_node: i_node.o
	gcc i_node.o -lm -o i_node

i_node.o: i_node.c
	gcc -c i_node.c

clean:
	rm i_node.o i_node