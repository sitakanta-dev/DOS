#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX_NUM 20
sem_t sem_odd, sem_even;
void* print_odd(void* arg) {
    for (int i = 1; i <= MAX_NUM; i += 2) {
        sem_wait(&sem_odd);
        printf("Thread A (Odd): %d\n", i);
        sem_post(&sem_even);
    }
    pthread_exit(NULL);
}
void* print_even(void* arg) {
    for (int i = 2; i <= MAX_NUM; i += 2) {
        sem_wait(&sem_even);
        printf("Thread B (Even): %d\n", i);
        sem_post(&sem_odd);
    }
    pthread_exit(NULL);
}
void main() {
    pthread_t threadA, threadB;
    sem_init(&sem_odd, 0, 1);
    sem_init(&sem_even, 0, 0);
    pthread_create(&threadA, NULL, print_odd, NULL);
    pthread_create(&threadB, NULL, print_even, NULL);
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    sem_destroy(&sem_odd);
    sem_destroy(&sem_even);
}