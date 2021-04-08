#include "../pg2.h"

int main(int argc, char **argv) {
    if(argc < 3 || argc > 4)
        return -1;

    int lowerBound = atoi(argv[1]);
    int upperBound = atoi(argv[2]);
    int step = 1;

    if(argc == 4)
        step = atoi(argv[3]);
    
    if(upperBound <= lowerBound){
        cout << "upperBound <= lowerBound" << endl;
        return -1;
    }

    if(step < 1) {
        cout << "step < 1" << endl; 
        return -1;
    }

    for(int i = lowerBound; i <= upperBound; i += step) {
        cout << i << endl; 
    }
}
