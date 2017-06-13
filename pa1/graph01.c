//Garrett Stoll gstoll
#include "intList.h"
//#include "intList.c"
#include <stdio.h>
#include <stdlib.h>

typedef struct
   {
   int from;
   int to;
   double weight;
   } Edge;

IntList*	initEdges(int n){
      int i;
      //allocate space for the intlist
      //initialize each location to be intNil.
		IntList*	adjVertices = calloc (1, sizeof(IntList));
		for (i = 1; i <= n; i ++){
			adjVertices[i] = intNil;
		}

		return adjVertices;
		}
		 
Edge parseEdge(char line[]){

     Edge newElm;
     int numF;
     //check to see
     numF = sscanf(line, " %d %d %lf %*s", &newElm.from, &newElm.to, &newElm.weight);
     if (numF < 2 || numF > 3){
        printf("Bad edge: %s", line);
        exit(1);
        }
     if (numF == 2)
        newElm.weight = 0.0;
        return newElm;
     }
		
int	loadEdges(FILE *inbuf, IntList* adjVertices){
      //creates int list edges by parsing the line
		int	num;
      char line[2000];
		num = 0;
	   char* fgetsret;
		fgetsret = fgets(line, 2000, inbuf);
		while (fgetsret == line)
			{
			Edge e;	
			e = parseEdge(line); //parse the line
			adjVertices[e.from] = intCons(e.to, adjVertices[e.from]);
			num ++;
			fgetsret = fgets(line, 2000, inbuf);
			}
			
		return num;
		}		


     
int   parseN(char* line){
 //parse the first line of input to determine and return the number 
 // of edges in the graph.
		 int numF;
		 numF = sscanf(line, "%s %*s", line);
		 if (numF != 1){
			printf("Bad line1: %s\n", line);
			exit(1);
			}
		int n = atoi(line);	

		return n;
		}


int main (int argc, char **argv) {
      
      int	m, n;
		IntList*	adjVertices;
		if (argc>1){		
			char inbuff[2000];
			char* fgetsret;
	      FILE *file;
	      if(strcmp(argv[1],"-")==0){ //if first input is "-" read stdin
	         file = stdin;
	      }
	      else{ //else read filename and open file.
	      file = fopen (argv[1], "r");
	      }
	      printf("Opened %s for input.\n", argv[1]);
	      //read the first line and fill temporary buffer	
	      fgetsret = fgets(inbuff, 2000, file);       
	      n = parseN(inbuff);
		   printf("n = %d\n", n);
		   adjVertices = initEdges(n);
		   m = loadEdges(file, adjVertices);
		   printf("m = %d\n", m);
         int i = 1;
         
		   for (i; i <= n; i++){
		      //if the list is not empty print elements
		      if(adjVertices[i] != intNil){
			         printf("\n%d     [%d]", i, intFirst(adjVertices[i]));
			         //print first element
			         IntList temp = intRest(adjVertices[i]);
			         while(temp != intNil)
			         {
            //if other elements are present repeatedly print until next is null
			            printf("[%d]",  intFirst(temp));//	  
			            temp = intRest(temp);   
			         }
			         
			         }
			         //if the list is the empty list print "NULL".
			     else{
			          printf("\n%d     NULL", i);
			     }
		   }
		   printf("\n");
		 return;
		}
		

}


