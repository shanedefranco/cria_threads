#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

// Função executada por cada thread
void* thread_function(void* arg) {
    // Obtém o TID usando pthread_self() e syscall(SYS_gettid)
    pthread_t tid = pthread_self();
    pid_t sys_tid = syscall(SYS_gettid);
    
    printf("Eu sou a thread com TID %lu e %d\n", (unsigned long)tid, sys_tid);
    
    return NULL;
}

int main()
{
    int n;
    printf("Digite o número de threads: ");
    scanf("%d", &n);

    pthread_t threads[n];
    int i;

    for(i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    for(i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}


