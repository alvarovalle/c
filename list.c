/*
  Sample program which shows a linked list 
  Author: Alvaro Maia do Valle 
  04/10/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//01-defines a structure called person
typedef struct person
{
  int id;
  char name[50];
  struct person *next;
} person;

int main()
{
  //02-we are going to use two variables for a person
   struct person *current, *first;
   int counter = 1;
    
   //03-first of all, we alloc memory for the first person
   current = (struct person*)malloc(sizeof(struct person));
   //04-and then we keep its position in pointer 'first'
   first = current;
   //05-reads the data from keyboard inside a loop, until user types 'exit'
   do
   {
     current->id = counter;//keeps a counter inside the structure
     scanf("\n%s",current->name);//reads name from the keyboard
     //06-when the user types 'exit' the application moves toward out of the while
     if(strcmp(current->name, "exit")==0) break;
     //07-every time alloc memory for the next element
     current->next = (struct person*)malloc(sizeof(struct person));
     current = current->next;//points to the next element in the list and make him current
     counter = counter + 1;//increases counter
   }while(1);

   //02-prints the data 
   do
   {
     current = first;
     printf("%d\n",current->id);
     printf("%s\n",current->name);
     free(current);
     first = first->next;

   }while(strcmp(first->name, "exit")!=0);
   free(first);
}
