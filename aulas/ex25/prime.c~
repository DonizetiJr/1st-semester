#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

// 100
//
// 2 - 1/4 100
// 1/4 100 +1 --- 2/4 100
// 2/4 100 +1 --- 3/4 100
// 3/4 100 +1 ---  100

typedef struct {
	long long number;
	long long start;
	long long end;
} THREAD_PARAM;

long isPrime(THREAD_PARAM *args) {
	long long i;
	long counter = 0;

	printf("Thread running...\n");

	for (i = args->start; i <= args->end; i++) {
		if (args->number % i == 0) {
			counter++;
		}
	}

	printf("Thread terminated...\n");

	return counter;
}

enum {
	PROGNAME,
	NUMBER,
	NCORES,
	NARGS
};

int main(int argc, char *argv[]) {

	if (argc != NARGS) {
		printf("usage: %s number ncores\n", argv[PROGNAME]);
		return -1;
	}

	int ncores, i;
	long long number, counter, start, range;
	long ret;
	pthread_t *thread;
	void *(*start_routine) (void *);
	THREAD_PARAM *args;

	number = atoll(argv[NUMBER]);
	ncores = atoi(argv[NCORES]);

	// utilizar multiplos cores do meu processador
	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
	//                           void *(*start_routine) (void *), void *arg);
	
	thread = (pthread_t *) malloc(sizeof(pthread_t) * ncores);
	args = (THREAD_PARAM *) malloc(sizeof(THREAD_PARAM) * ncores);

	// void *(*start_routine) (void *)
	// long isPrime(struct THREAD_PARAM *args) {
	start_routine = (void * (*) (void *)) &isPrime;

	range = (int) round(((number - 2 + 1) / ncores));

	start = 2;
	for (i = 0; i < ncores; i++) {
		args[i].number = number;
		args[i].start = start;
		args[i].end = start + range;

		if (args[i].end > number) args[i].end = number;

		pthread_create(&thread[i], NULL, start_routine, (void *) &args[i]);
		start += range;
	}

	counter = 0;
	for (i = 0; i < ncores; i++) {
		pthread_join(thread[i], (void **) &ret);
		counter += ret;
	}

	//counter = isPrime(number, 2, number);

	if (counter > 1) 
		printf("it is not prime...\n");
	else
		printf("it is prime...\n");

	return 0;
}








