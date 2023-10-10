#include <pthread.h>
#include <stdio.h>

int saldo;

void * holaHilo(){
    for(int i=0; i<100; i++){
        printf("Hola desde un hilo\n");
    }
    pthread_exit(NULL);
}
void * incrementaSaldo(){
    printf("El saldo anterior es: %d\n", saldo);
    saldo += 100;
    printf("El saldo actual es: %d\n", saldo);
}
int main(){
    pthread_t t;
    saldo = 0;
    for(int i=0; i<100; i++){
        pthread_create(&t, NULL, incrementaSaldo, NULL);
    }
    pthread_exit(NULL);
}