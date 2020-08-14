/*
Generate the order of the regulatory meetings.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int random_number(int lower, int upper);
void populate(int *list, int length);
void swap(int *list, int a, int b);
void shuffle(int *list, int length);
void sabotage(int *list, int length, int first, int second);
void print_order(int *list, int length);


int random_number(int lower, int upper){
    // Generates random numbers in range [lower, upper]. 
    int rnum = (rand() % (upper - lower + 1)) + lower;
    return rnum;
}


void populate(int *list, int length){
    // Populate an array with indices corresponding to place number.
    int i = 0;
    for(i=0;i<length;i++){
        list[i] = i;
    }
}


void swap(int *list, int a, int b){
    // Swap elements at indices a and b in an array.
    int temp = list[a];
    list[a] = list[b];
    list[b] = temp;
}


void print_order(int *list, int length){
    // Print the order of the shuffled array.
    int i = 0;
    printf("The order is:\n");
    for(i=0;i<length;i++){
        switch(list[i]){
            case 0:
                printf("\t%d. Nicky\n", i + 1);
                break;
            case 1:
                printf("\t%d. Shane\n", i + 1);
                break;
            case 2:
                printf("\t%d. Jimmy\n", i + 1);
                break;
            case 3:
                printf("\t%d. Vanessa\n", i + 1);
                break;
            case 4:
                printf("\t%d. Zan\n", i + 1);
                break;
            case 5:
                printf("\t%d. David\n", i + 1);
                break;
            default:
                printf("Default\n");
                break;
        }
    }
}


void shuffle(int *list, int length){
    // Shuffle an array.
    int i = 0, j = 0;
    
    // Seed random generator with current time
    srand(time(0));
    
    for(i=0;i<length;i++){
        j = random_number(0, length - 1);
        swap(list, i, j);
    }
}


void sabotage(int *list, int length, int first, int second){
    // Ensures that element at index first precedes element at index second.
    int i = 0, a = 0, b = 0, temp = 0;
    for(i=0;i<length;i++){
        if(list[i] == first){
            a = i;
        }else if(list[i] == second){
            b = i;
        }else{
            continue;
        }
    }
    
    if(a > b){
        swap(list, a, b);
    }
}


int main(){ 
    int length = 6, list[length];
    
    populate(list, length);
    shuffle(list, length);
    sabotage(list, length, 0, 5); // 0 - Nicky, 5 - David
    print_order(list, length);
    
    return 0; 
}