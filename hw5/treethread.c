// Also, submit a file treethread.c that is like hello.c (Figure 12.13), except that
// it creates and reaps 2**N - 2 joinable threads, where N is a positive command-line argument.
// These threads should be created as a binary tree rooted in the main thread. Each
// thread should have a number in the range 0 .. 2**N - 2, where the main thread's number
// is 0 and each non-leaf thread T has two children numbered 2*T + 1 and 2*T + 2. The 2**(N - 1)
// leaf threads should simply print "Thread T done\n" (where T is the leaf thread's number) and return;
// the non-leaf threads should create and reap their two children before printing "Thread T done\n" then returning.
// The main thread counts as a thread and so should print too. If N=1, the main thread is a leaf.


// In main func, create two threads and each thread recursively takes in it's
// threads.  
//
// Thread takes in two arguments, one for maximum thread number and one for it's
// thread number.  


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void *thread(void *vargp);

typedef struct{
    int num_level;
    int thread_num;
} thread_args;

int main(int argc, char* argv[]){

    int levels = atoi(argv[1]);
    if(levels > 1){
        pthread_t *tid = malloc(2); //Allocate 2 tids

        thread_args *struct1 = malloc(sizeof *struct1);
        struct1->num_level = levels - 1;
        struct1->thread_num = 1;

        thread_args *struct2 = malloc(sizeof *struct2);
        struct2->num_level = levels - 1;
        struct2->thread_num = 2;

        pthread_create(&tid[0], NULL, thread, struct1); //Create first thread
        pthread_create(&tid[1], NULL, thread, struct2); //Create second thread

        pthread_join(tid[0], NULL); //Join thread 0
        pthread_join(tid[1], NULL); //Join thread 1

        free(struct2); //free memory allocated for struct2
        free(struct1); //free memory allocated for struct1
        free(tid); //free memory allocated by tid
    }

    printf("Thread 0 done\n"); //Main thread done.  This always prints no matter what
    exit(0); //Done with program
}

void *thread(void *vargp){
    thread_args *args = vargp;
    int levels = args->num_level;
    if(levels > 1){
        pthread_t *tid = malloc(2); //Allocate 2 tids

        thread_args *struct1 = malloc(sizeof *struct1);
        struct1->num_level = levels - 1;
        struct1->thread_num = (args->thread_num * 2) + 1;

        thread_args *struct2 = malloc(sizeof *struct2);
        struct2->num_level = levels - 1;
        struct2->thread_num = (args->thread_num * 2) + 2;

        pthread_create(&tid[0], NULL, thread, struct1); //Create first thread
        pthread_create(&tid[1], NULL, thread, struct2); //Create second thread

        pthread_join(tid[0], NULL); //Join thread 0
        pthread_join(tid[1], NULL); //Join thread 1

        free(struct2); //free memory allocated for struct2
        free(struct1); //free memory allocated for struct1
        free(tid); //free memory allocated by tid
    }
    printf("Thread %d done\n", args->thread_num);

    return NULL;
}

