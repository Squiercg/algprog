int done = 0;

void *child(void *arg) {
	printf("child\n");
	
	/* Do its job */
	/* ... */

	done = 1;
}

int main(int argc, char *argv[]) {
	printf("parent: begin\n");
	pthread_t c;
	Pthread_create(&c, NULL, child, NULL); // create child
	while (done == 0); // spin
	printf("parent: end\n");
	return 0;
}
