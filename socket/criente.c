#include <stdio.h>
#include "amvnet.h"

int main(int argc, char argv[2]){
  int msg;
  msg=enviar("127.0.0.1", "4200","isso funciona");
  printf("\n resposta obtida %d\n",msg);
  return 0;
}
