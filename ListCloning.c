#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int *list = malloc(3*sizeof(int));
    if (list == NULL) {
        return 1;
    }

    *list = 1;
    *(list + 1) = 2;
    *(list + 2) = 3;

    for (int i = 0; i <= (sizeof(list)/sizeof(list[0])) ; i++ ){
        // printf("%i\n",list[i]);
    }

    int *temp = malloc(4*sizeof(int));
    if (temp == NULL) {
        free(list);
        return 1;
    }
    for (int i =0 ; i < (3); i++){
        temp[i]=list[i];}
    temp[3] = 4;
        for (int i = 0; i <= (3) ; i++ ){
        // printf("%i\n",temp[i]);
    }

    list = temp;
    
        for (int i = 0; i <= (3) ; i++ ){
        printf("%i\n",list[i]);
    }

    free(list);




    return 0;
}