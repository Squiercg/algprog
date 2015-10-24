void *child(void *arg) {
	printf("child\n");
	/*how to indicate we are done?*/
	return NULL;
}
6

int main(int argc, char *argv[]) {
	printf("parent: begin\n");
	pthread_t c;
	Pthread_create(&c, NULL, child, NULL); // create child
	/* how to wait for child? */
	printf("parent: end\n");
	return 0;
}
