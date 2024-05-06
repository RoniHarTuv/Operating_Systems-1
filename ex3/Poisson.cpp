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
long double poisson(float lambda, int k){
    return ((pow(lambda,k)) / factorial(k)) * expf(-lambda);
}
