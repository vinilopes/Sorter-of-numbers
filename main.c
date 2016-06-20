#include <stdio.h>
#include <stdlib.h>
#define MAX_VECTOR_INDICE 7

 int i,z,aux,num_trocas=0;


int main(int argc, char *argv[])
{
  int vetor[7] ={1,4,2,6,5,4,3};
  printf("*******/ SORTER OF NUMBERS \\********\n\n");
  printf("Vetor inicial: ");
  for(i=0;i<MAX_VECTOR_INDICE; i++){
       printf("%d",vetor[i]);
       if(i < (MAX_VECTOR_INDICE-1)){
           printf(", ");
       }
  }
  printf("\n");
  bubbleSortMethod(&vetor);
  SelectionSortMethod(&vetor);



  system("PAUSE");
  return 0;
}


void bubbleSortMethod(int * vetor){
    char method_name[25] = "Bubble Sort";
    for(i=MAX_VECTOR_INDICE-1;i>=0; i--){
        for(z=0;z<i; z++){
            if(vetor[z+1]<vetor[z]){
            aux =  vetor[z];
            vetor[z]=vetor[z+1];
            vetor[z+1]=aux;
            num_trocas++;
           }
         }
    }
      imprimeVetorOrdenado(vetor, num_trocas, &method_name);
}

void QuickSortMethod(){
//TODO
}

void SelectionSortMethod(int * vetor){
     char method_name[25] = "Selection Sort";
     int menor;
     for(i=0;i<MAX_VECTOR_INDICE; i++){
        menor=i;
        for(z=i;z<MAX_VECTOR_INDICE; z++){
            if(vetor[z]<vetor[i]){
                menor = z;
            }
        }
        aux =  vetor[i];
        vetor[i]=vetor[menor];
        vetor[menor]=aux;
        num_trocas++;
    }
    imprimeVetorOrdenado(vetor, num_trocas, &method_name);
}


void imprimeVetorOrdenado(int * vetor, int num_trocas, char * method_name){
     printf("\n\nVetor ordenado pelo metodo: %s \n",method_name);
     printf("Numero de trocas: %d \n",num_trocas);
     printf("Vetor ordenado: ");
     for(i=0;i<=MAX_VECTOR_INDICE-1; i++){
         printf("%d, ",vetor[i]);

     }
     printf("\n");
}

