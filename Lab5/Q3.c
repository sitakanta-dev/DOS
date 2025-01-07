#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX_COUNT 20
sem_t sem_A, sem_B;
void* print_A(void* arg) {
    for (int i = 0; i < MAX_COUNT; i++) {
        sem_wait(&sem_A);
        printf("A");
        sem_post(&sem_B);
    }
    pthread_exit(NULL);
}
void* print_B(void* arg) {
    for (int i = 0; i < MAX_COUNT; i++) {
        sem_wait(&sem_B);
        printf("B");
        sem_post(&sem_A);
    }
    pthread_exit(NULL);
}
void main() {
    pthread_t threadA, threadB;
    sem_init(&sem_A, 0, 1);
    sem_init(&sem_B, 0, 0);
    pthread_create(&threadA, NULL, print_A, NULL);
    pthread_create(&threadB, NULL, print_B, NULL);
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    sem_destroy(&sem_A);
    sem_destroy(&sem_B);
}
