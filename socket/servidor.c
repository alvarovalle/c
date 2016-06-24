#include <stdio.h>
#include "amvnet.h"

int main(int argc, char argv[2]){
  int msg;
  msg=receber("4200");
  printf("\n resposta enviada %d\n",msg);
  return 0;
}
