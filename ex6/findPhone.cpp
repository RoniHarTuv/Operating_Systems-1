#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
/*in this class we will use the pipe method from unistd.h.
this function will hold int array with size of 2.
the dup2 nethod will determine that all the stdout data of the child will be pushed into the
pipe. then the chid will run an execlp with a command that was given to write the phone
number in to the stdout that is passed into the pipe as written above. then in the parent side
the data will be written into a buffer and then will be printed in the cout of the parent
program.
*/
int main(int argc, char *argv[])
{
    int pipefds[2];
    if (pipe(pipefds) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    int pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    { // Child
        close(pipefds[0]);
        dup2(pipefds[1], STDOUT_FILENO);
        close(pipefds[1]);
        string name = argv[1];
        if (argc == 3)
        {
            name += " ";
            name += argv[2];
        }
        string command = "cat phone_book.txt | grep '" + name + "' | sed 's/ /#/g' | sed 's/,/ /' | awk '{print $2}'";
        execlp("bash", "bash", "-c", command.c_str(), NULL);
        exit(EXIT_FAILURE);
    }
    else
    { // Parent
        close(pipefds[1]);
        wait(nullptr);
        char buffer[1024] = {0};
        read(pipefds[0], buffer, sizeof(buffer));
        cout << buffer;
        close(pipefds[0]);
    }
    return 0;
}
