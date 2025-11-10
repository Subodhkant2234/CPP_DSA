#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // for sleep, optional

#define N 10

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int counter = 1;
int oddTurn = 1; // 1: odd thread's turn, 0: even thread's turn

void* printOdd(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        if (counter > N) {
            pthread_mutex_unlock(&lock);
            break;
        }
        if (oddTurn) {
            printf("%d ", counter);
            counter++;
            oddTurn = 0;
        }
        pthread_mutex_unlock(&lock);
        // optional small sleep to reduce CPU spinning
        // usleep(100);
    }
    return NULL;
}

void* printEven(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        if (counter > N) {
            pthread_mutex_unlock(&lock);
            break;
        }
        if (!oddTurn) {
            printf("%d ", counter);
            counter++;
            oddTurn = 1;
        }
        pthread_mutex_unlock(&lock);
        // optional small sleep to reduce CPU spinning
        // usleep(100);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, printOdd, NULL);
    pthread_create(&t2, NULL, printEven, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("\n");
    return 0;
}

/*
Mutex protects shared variables (counter and oddTurn), preventing race conditions
Correctly alternates printing between odd and even threads.
Properly checks counter > N to exit loops.
pthread_create and pthread_join are used correctly.
*/

/*
Potential improvements:
Avoid busy-waiting:
Currently, if a thread’s turn hasn’t come, it repeatedly locks and unlocks the mutex, wasting CPU
Better: Use a pthread_cond_t (condition variable) to wait for the turn.
*/
