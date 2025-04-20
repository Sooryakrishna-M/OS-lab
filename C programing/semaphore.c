#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5  // max items in the buffer

int buffer = 0;  // single integer buffer to keep it simple

sem_t full;      // counts filled slots
sem_t empty;     // counts empty slots
pthread_mutex_t mutex;  // mutual exclusion

void produce() {
    sem_wait(&empty); // wait for empty slot
    pthread_mutex_lock(&mutex); // enter critical section

    buffer++;
    printf("Produced 1 item. Buffer = %d\n", buffer);

    pthread_mutex_unlock(&mutex); // exit critical section
    sem_post(&full); // signal that buffer has a new item
}

void consume() {
    sem_wait(&full); // wait for filled slot
    pthread_mutex_lock(&mutex); // enter critical section

    buffer--;
    printf("Consumed 1 item. Buffer = %d\n", buffer);

    pthread_mutex_unlock(&mutex); // exit critical section
    sem_post(&empty); // signal that buffer has space
}

int main() {
    int choice;

    // Initialize semaphores and mutex
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);
    pthread_mutex_init(&mutex, NULL);

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (buffer == BUFFER_SIZE)
                    printf("Buffer full! Cannot produce.\n");
                else
                    produce();
                break;
            case 2:
                if (buffer == 0)
                    printf("Buffer empty! Cannot consume.\n");
                else
                    consume();
                break;
            case 3:
                printf("Exiting...\n");
                sem_destroy(&full);
                sem_destroy(&empty);
                pthread_mutex_destroy(&mutex);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
