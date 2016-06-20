#include <stdio.h>
#include <stdlib.h>
#define MAX_INDICE 7

int i,z,aux,num_chages=0;

int main(int argc, char *argv[])
{
  int vector[7] ={1,4,2,6,5,4,3};
  printf("*******/ SORTER OF NUMBERS \\********\n\n");
  printf("Initial vector: ");
  for(i=0;i<MAX_INDICE; i++){
       printf("%d",vector[i]);
       if(i < (MAX_INDICE-1)){
           printf(", ");
       }
  }
  printf("\n");
  bubbleSortMethod(&vector);
  SelectionSortMethod(&vector);

  system("PAUSE");
  return 0;
}

void bubbleSortMethod(int * vector){
    char method_name[25] = "Bubble Sort";
    for(i=MAX_INDICE-1;i>=0; i--){
        for(z=0;z<i; z++){
            if(vector[z+1]<vector[z]){
            aux =  vector[z];
            vector[z]=vector[z+1];
            vector[z+1]=aux;
            num_chages++;
           }
         }
    }
      printVector(vector, num_chages, &method_name);
}

void QuickSortMethod(){
//TODO
}

void SelectionSortMethod(int * vector){
     char method_name[25] = "Selection Sort";
     int less;
     for(i=0;i<MAX_INDICE; i++){
        less=i;
        for(z=i;z<MAX_INDICE; z++){
            if(vector[z]<vector[i]){
                less = z;
            }
        }
        aux =  vector[i];
        vector[i]=vector[less];
        vector[less]=aux;
        num_chages++;
    }
    printVector(vector, num_chages, &method_name);
}


void printVector(int * vector, int num_chages, char * method_name){
     printf("\n\nVector ordered by the method: %s \n",method_name);
     printf("Number of exchanges: %d \n",num_chages);
     printf("Sorted vector: ");
     for(i=0;i<=MAX_INDICE-1; i++){
         printf("%d, ",vector[i]);
     }
     printf("\n");
}

