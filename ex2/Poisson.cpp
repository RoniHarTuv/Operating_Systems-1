#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;

float factorial(int a){
    if(a == 0){
        return 1;
    }
    return a* factorial(a-1);
}
int main(int argc, char *argv[]){
    if(argc !=3){
        cout << "Error" << endl;
        exit(1); 
    }
    float lambda= atof(argv[1]);
    int k = atoi(argv[2]);
    cout<< (pow(lambda,k) / factorial(k)) * expf(-lambda) << endl;
    return 0;
}