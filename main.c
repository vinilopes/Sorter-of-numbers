#include <stdio.h>
#include <stdlib.h>
#define MAX_INDICE 7

int i,z,aux,num_changes_quicksort=0,index_vt;

int main(int argc, char *argv[])
{
  index_vt = rand()%MAX_INDICE+1;
  int vector1[index_vt],vector2[index_vt],vector3[index_vt],choise=1;
  while(choise != 0){
      for(i=0;i<index_vt; i++){
         vector1[i] = rand()%100;
         vector2[i] = rand()%100;
         vector3[i] = rand()%100;
         while(check(vector1,i)){
            vector1[i] = rand()%100;
         }
         while(check(vector2,i)){
            vector2[i] = rand()%100;
         }
         while(check(vector3,i)){
            vector3[i] = rand()%100;
         }
      }

      printf("*******/ SORTER OF NUMBERS \\********\n\n");
      printVectorInitial(vector1);
      printVectorInitial(vector2);
      printVectorInitial(vector3);

      bubbleSortMethod(vector1);
      SelectionSortMethod(vector2);
      QuickSortMethod(vector3,0,index_vt);

      char method_name[25] = "Quick Sort";
      printVector(vector3, num_changes_quicksort, &method_name);
      printf("\n Enter a non-zero number to generate new numbers: ");
      scanf("%d",&choise);
      system("cls");
      num_changes_quicksort=0;
  }

  system("PAUSE");
  return 0;
}

int check(int * vector, int index){
        for(z=0;z<index;z++){
            if(vector[z]==vector[index]){
                return 1;
            }
        }
        return 0;
  }

void printVectorInitial(int * vector){
  printf("\nInitial vector: ");
  for(i=0;i<index_vt; i++){
       printf("%d",vector[i]);
       if(i < (index_vt-1)){
           printf(", ");
       }
  }
  printf("\n");
}

void bubbleSortMethod(int * vector){
    char method_name[25] = "Bubble Sort";
    int num_chages=0;
    for(i=index_vt-1;i>=0; i--){
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

void QuickSortMethod(int * vector, int index_initial, int Index_max){
    if (index_initial >= Index_max) return;
    int half = split(vector, index_initial, Index_max);
    QuickSortMethod(vector, index_initial, (half-1));
    QuickSortMethod(vector, (half+1), Index_max);
}

int split(int * vector, int index_initial, int Index_max)
{
    int element = vector[index_initial];

    for (;;) {
        while (index_initial < Index_max && element <= vector[Index_max]) {
            Index_max--;
        }
        if (index_initial >= Index_max) break;
        vector[index_initial++] = vector[Index_max];
        num_changes_quicksort++;

        while (index_initial < Index_max && vector[index_initial] <= element) {
            index_initial++;
        }
        if (index_initial >= Index_max) break;
        vector[Index_max--] = vector[index_initial];
    }
    vector[Index_max] = element;
    return Index_max;
}

void SelectionSortMethod(int * vector){
     char method_name[25] = "Selection Sort";
     int num_chages=0;
     int less;
     for(i=0;i<index_vt-1; i++){
        less=i;
        for(z=i+1;z<index_vt; z++){
            if(vector[z]<vector[less]){
                less = z;
            }
        }
        if(less!=i){
            aux = vector[less];
            vector[less] = vector[i];
            vector[i] = aux;
            num_chages++;
        }
    }
    printVector(vector, num_chages, &method_name);
}

void printVector(int * vector, int num_chages, char * method_name){
     printf("\n\nVector ordered by the method: %s \n",method_name);
     printf("Number of exchanges: %d \n",num_chages);
     printf("Sorted vector: ");
     for(i=0;i<=index_vt-1; i++){
         printf("%d, ",vector[i]);
     }
     printf("\n");
}

