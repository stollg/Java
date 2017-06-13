//Garrett Stoll gstoll
#include "intList.h"
#include <stdio.h>
#include <stdlib.h>
 
struct IntListNode {
     int element;
     IntList next;
     };

const IntList intNil = NULL;

int intFirst(IntList oldL)
{
   //printf("element in first index is %d", oldL->element);
    return oldL->element;
}

IntList intRest(IntList oldL){
      return oldL->next;
}

IntList intCons(int newE, IntList oldL){
      IntList this = calloc (1, sizeof (struct IntListNode));
      this->element = newE;
		this->next = oldL;
		return this;
}
