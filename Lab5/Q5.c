#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX_COUNT 20
sem_t sem_A, sem_B, sem_C;
void* print_A(void* arg) {
    for (int i = 1; i <= MAX_COUNT; i += 3) {
        sem_wait(&sem_A);
        printf("A%d\n", i);
        sem_post(&sem_B);
    }pthread_exit(NULL);
}
void* print_B(void* arg) {
    for (int i = 2; i <= MAX_COUNT; i += 3) {
        sem_wait(&sem_B);
        printf("B%d\n", i);
        sem_post(&sem_C);
    }pthread_exit(NULL);
}
void* print_C(void* arg) {
    for (int i = 3; i <= MAX_COUNT; i += 3) {
        sem_wait(&sem_C);
        printf("C%d\n", i);
        sem_post(&sem_A);
    }pthread_exit(NULL);
}
void main() {
    pthread_t threadA, threadB, threadC;
    sem_init(&sem_A, 0, 1);  
    sem_init(&sem_B, 0, 0);  
    sem_init(&sem_C, 0, 0);  
    pthread_create(&threadA, NULL, print_A, NULL);
    pthread_create(&threadB, NULL, print_B, NULL);
    pthread_create(&threadC, NULL, print_C, NULL);
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);
    sem_destroy(&sem_A);
    sem_destroy(&sem_B);
    sem_destroy(&sem_C);
}
