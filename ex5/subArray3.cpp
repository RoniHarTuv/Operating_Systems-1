#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int maxSubArray3(vector<int> array, int size)
{
    int best = 0;
    for (int a = 0; a < size; a++)
    {
        for (int b = a; b < size; b++)
        {
            int sum = 0;
            for (int k = a; k <= b; k++)
            {
                sum += array[k];
            }
            best = max(best, sum);
        }
    }
    return best;
}

int main(int argc, char *argv[])
{
    int random_seed = atoi(argv[1]);
    int size_of_arr = atoi(argv[2]);
    int lower_bound = -25;
    int upper_bound = 30;
    srand(random_seed);
    vector<int> arr(size_of_arr);
    for (int i = 0; i < size_of_arr; i++)
    {
        int random_number = rand() % (upper_bound - lower_bound + 1) + lower_bound;
        arr[i] = random_number;
    }
    cout << "max subArray sum:" << maxSubArray3(arr, size_of_arr);
    return 0;
}