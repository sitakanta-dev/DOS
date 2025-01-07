#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX_COUNT 10
sem_t sem_A, sem_B;
void* count_down(void* arg) {
    for (int i = MAX_COUNT; i >= 1; i--) {
        sem_wait(&sem_A);
        printf("Thread A (Countdown): %d\n", i);
        sem_post(&sem_B);
    }pthread_exit(NULL);
}
void* count_up(void* arg) {
    for (int i = 1; i <= MAX_COUNT; i++) {
        sem_wait(&sem_B);
        printf("Thread B (Countup): %d\n", i);
        sem_post(&sem_A);
    }pthread_exit(NULL);
}
void main() {
    pthread_t threadA, threadB;
    sem_init(&sem_A, 0, 1);
    sem_init(&sem_B, 0, 0); 
    pthread_create(&threadA, NULL, count_down, NULL);
    pthread_create(&threadB, NULL, count_up, NULL);
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    sem_destroy(&sem_A);
    sem_destroy(&sem_B);
}
