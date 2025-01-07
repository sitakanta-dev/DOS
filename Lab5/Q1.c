#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define BUFFER_SIZE 10
#define ITERATIONS 20
int buffer[BUFFER_SIZE];
int count = 0;
sem_t empty, full;
pthread_mutex_t mutex;
void* producer(void* arg) {
    for (int i = 1; i <= 100; i++) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[count++] = i;
        printf("Producer produced: %d\n", i);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        if (i % 5 == 0)
            sleep(1); 
    }
    pthread_exit(NULL);
}
void* consumer(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[--count];
        printf("Consumer consumed: %d\n", item);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        sleep(1); 
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t prod, cons;
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    return 0;
}
