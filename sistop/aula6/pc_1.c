int buffer;
int count = 0; // initially, empty

void put(int value) {
	while(count == 0);
	count = 1;
	buffer = value;
}

int get() {
	while(count == 1);
	count = 0;
	return buffer;
}

void *producer(void *arg) {
	int i;
	int loops = (int) arg;
	for (i = 0; i < loops; i++) {
		put(i);
	}
}

void *consumer(void *arg) {
	int i;
	int loops = (int) arg;
	for (i = 0; i < loops; i++) {
		get(i);
	}
}

