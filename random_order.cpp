/**
# Random Order Generator

Shuffle an array of strings into a random order.
*/


#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>


using namespace std;


int random_int(int lower, int upper);
void shuffle(string *strings, int length);
void print_strings(string *strings, int length);


int random_int(int lower, int upper){

    return rand() % (upper - lower + 1) - lower;
}


void shuffle(string *strings, int length){
    string temp = "";
    int random = 0;
    
    srand(time(0));
    
    for(int i=0;i<length;i++){
        random = random_int(0, length - 1);
        if(random == i){
            continue;
        }else{
            temp = strings[i];
            strings[i] = strings[random];
            strings[random] = temp;
        }
    }
}


void print_strings(string *strings, int length){
    cout << "The order is:\n";
    for(int i=0;i<length;i++){
        cout << "\t" << i + 1 << ". " << strings[i] << "\n";
    }
}


int main(void){
	int length = 10;
	string a[length] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
	shuffle(a, length);
    print_strings(a, length);

    return 0;
}
