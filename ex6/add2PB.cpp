#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>
using namespace std;

void add_new(string s)
{
    std::ofstream outfile;
    outfile.open("phone_book.txt", std::ios_base::app);
    outfile << s ;
    outfile << endl;
}

int main()
{
    cout << "enter name and  phone number splited with ','" << endl;
    string s;
    getline(cin, s);
    add_new(s);
    return 0;
}