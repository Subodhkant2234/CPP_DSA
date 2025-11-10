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
If it’s not the thread’s turn, the thread still keeps looping, acquiring and releasing the mutex repeatedly.
This is called busy-waiting.
Problem: CPU cycles are wasted while the thread waits, especially if N is large.
On a single-core system, it can starve the other thread or make the program inefficient.
*/

/*
Potential improvements:
Avoid busy-waiting:
Currently, if a thread’s turn hasn’t come, it repeatedly locks and unlocks the mutex, wasting CPU
Better: Use a pthread_cond_t (condition variable) to wait for the turn.
*/


#include <stdio.h>
#include <pthread.h>

#define N 10

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int counter = 1;
int oddTurn = 1; // 1: odd thread's turn, 0: even thread's turn

void* printOdd(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        while (!oddTurn && counter <= N)          // Wait until it's odd's turn
            pthread_cond_wait(&cond, &lock);
        if (counter > N) {                        // Exit condition
            pthread_mutex_unlock(&lock);
            pthread_cond_broadcast(&cond);        // Wake up even thread if waiting
            break;
        }
        printf("%d ", counter);
        counter++;
        oddTurn = 0;                              // Switch turn to even
        pthread_cond_signal(&cond);               // Wake up even thread
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* printEven(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        while (oddTurn && counter <= N)           // Wait until it's even's turn
            pthread_cond_wait(&cond, &lock);
        if (counter > N) {
            pthread_mutex_unlock(&lock);
            pthread_cond_broadcast(&cond);       // Wake up odd thread if waiting
            break;
        }
        printf("%d ", counter);
        counter++;
        oddTurn = 1;                              // Switch turn to odd
        pthread_cond_signal(&cond);               // Wake up odd thread
        pthread_mutex_unlock(&lock);
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
Correct synchronization – uses mutex to protect shared variables.
Efficient waiting – uses condition variables, so threads wait instead of busy-spinning.
Simple and clear – easy to explain in 1–2 minutes.
Alternates correctly – odd and even numbers are printed in order.
Shows understanding of thread coordination and termination.
*/

Solution Approach:
Use a mutex to protect shared variables (counter and oddTurn).
Use a turn flag (oddTurn) to indicate which thread’s turn it is.
Use a condition variable so a thread waits efficiently until it’s its turn.
Alternate threads after each number until counter > N.


Step by step:
Odd Thread:
Lock mutex → protect shared variables.
Wait while it’s not the odd thread’s turn.
pthread_cond_wait releases the mutex while waiting.
When signaled, it reacquires the mutex.
Exit if counter > N.
Print the number.
Increment counter.
Switch turn → odd thread done, even thread’s turn.
Signal the other thread using pthread_cond_signal.
Unlock mutex.

Even Thread
Mirror of odd thread, waits for oddTurn == 0.
Switches turn back to odd after printing.
