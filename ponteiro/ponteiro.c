#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Item{
  char name[9];
  int id;
  struct Item *prior;
  struct Item *next;
};

struct Item * first, * last;


int item_index;

void setName(int id, char name[9]);
char *getName(int id);
int insere(char name[9]);
void apaga(int id);

void apaga(int id){
  struct Item * aux, *pontaA, *pontaB, *meio;
  int _item_index;
  

  aux = first;
  for(_item_index=1;_item_index<=item_index;_item_index++){
    if(aux->id == id-1){
      pontaA=aux;
      printf("\nA aux %d prior %d next %d\n",aux, aux->prior,aux->next);
    }

    if(aux->id == id+1){
      pontaB=aux;
      printf("\nB aux %d prior %d next %d\n",aux, aux->prior,aux->next);

    }

    if(aux->id == id){
      printf("\nMEIO aux %d prior %d next %d\n",aux, aux->prior,aux->next);
      meio=aux;
    }
    if(_item_index<item_index){
      aux = aux->next;
    }
  }

  pontaA->next = meio->next;
  pontaB->prior = meio->prior;
 printf("\n depois fica assim A  %d prior %d next %d \n B %d prior %d next %d\n",pontaA, pontaA->prior,pontaA->next, pontaB, pontaB->prior,pontaB->next);
 item_index--; 

}


int insere(char name[9]){
  struct Item  * aux;
  
  aux = last;
  last = (struct Item *)malloc(sizeof(struct Item *));

  if(aux){
    aux->next = last;
  }
  last->prior = aux; 

  item_index++;
  
  last->id = item_index;
  strncpy(last->name,name,9);  
  //caso seja o primeiro registro
  if(!first){
    first = last;
  }
}

void setName(int id, char name[9]){
  struct Item * aux;
  aux = first;
  while(aux){
    if(aux->id == id){
      strncpy(aux->name,name,9);
      break;
    }
    aux = aux->next;
  }
}

void mostra(){
  struct Item * aux;
  int _item_index;
  aux = first;
  for(_item_index=1;_item_index<=item_index;_item_index++){
    printf("\n%d %d %s  %d \n",aux, aux->id,aux->name, aux->next);
    aux = aux->next;
  }
}

char *getName(int id){
  struct Item * aux;
  int _item_index;
  aux = first;
  for(_item_index=1;_item_index<=item_index;_item_index++){
    if(aux->id == id){
      break;
    }
    aux = aux->next;
  }
  return aux->name;
}


int main(int argc,char **argv){
  char valor1[9] = {'a','l','v','a','r','o','m','v','\0'};
  char valor2[9] = {'c','o','e','l','h','o','v','c','\0'};
  char valor3[9] = {'t','e','r','c','e','i','r','o','\0'};
  int x;
  item_index = 0;

  insere(valor1);
  insere(valor2);
  insere(valor3);
  insere(valor2);
  insere(valor3);

  mostra();
  apaga(2);
  mostra();
   
//  setName(2,valor3);
//  mostra();

  return 0;
}

