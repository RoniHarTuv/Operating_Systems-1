#include "Poisson.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    int k[] = {1, 10, 2, 3, 3};
    float lambda[] = {2, 2, 2, 3, 100};
    for (int i = 0; i < 5; i++)
    {
        long double ans = poisson(lambda[i],k[i]);
        cout << "K=" << k[i] << ", lambda=" << lambda[i] << ", Poisson dist= " << ans << endl;
    }
    return 0;
}