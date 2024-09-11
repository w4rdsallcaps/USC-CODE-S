#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

int main(){
    srand(time(0));
    for (int i = 0; i < 1; i++) 
        cout << rand() % 11 + 1 << " ";
    
    return 0;
}

