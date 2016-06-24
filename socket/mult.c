#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "amvnet.h"


void *PrintEnviar(){
  int i,k;
  printf("\nVai Levantar o Cliente\n");
  for(k=0;k<100000;k++) {
    for(i=0;i<100000;i++) {

    }
  }
//  enviar("127.0.0.1", "4200","isso funciona");
  printf("\nCliente no ar\n");
  pthread_exit(NULL);
}

void *PrintReceber(){
  //printf("\nVai levantar o servidor\n");
  receber("4200");
  //printf("\nServidor no ar\n");
  pthread_exit(NULL);
}

int main(int argc, char argv[2]){
  pthread_t *produtor,*consumidor;

  printf("\nDispara Thread Produtora\n");
  pthread_create(produtor,NULL,PrintReceber,NULL);  

  printf("\nDispara Thread Consumidora\n");
  //pthread_create(consumidor,NULL,PrintEnviar,NULL);
  pthread_exit(NULL);
  return 0;
}

