#include <stdio.h>

int main() {

    int arr[] = {1,2,3,5,6,7,9};
    
    int number;

    printf("Enter the number you want to search for: ");

    int k = scanf("%i", &number);

    for (int i = 0; i <sizeof(arr)/sizeof(arr[0]);i++){

        if (arr[i] == number){

            printf("YES, %i is in the array\n", number);

            return 0;
        }
    }

    printf("NO, %i is NOT in the array\n", number);

    return 1;

}