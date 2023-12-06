#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

void sameProgramSameCode()
{
    int forkId = fork();
    if (forkId < 0)
    {
        cerr << "Fork command does not execute successfully" << endl;
        exit(-1);
    }
    else
    {
        cout << "Hello world!!" << endl;
    }
}

void sameProgramDifferentCode()
{
    int forkId = fork();
    if (forkId < 0)
    {
        cerr << "Fork command does not execute successfully" << endl;
        exit(-1);
    }
    else if (forkId == 0)
    {
        cout << "Child process is running with pid " << getpid() << endl;
    }
    else
    {
        cout << "Parent process is running with pid " << getpid() << endl;
    }
}

void parentWaitForChild()
{
    int forkId = fork();
    if (forkId < 0)
    {
        cerr << "Fork command does not execute successfully" << endl;
        exit(-1);
    }
    else if (forkId == 0)
    {
        cout << "Child process is running with pid " << getpid() << endl;
    }
    else
    {
        wait(NULL);
        cout << "Parent process is running with pid " << getpid() << endl;
    }
}

int main()
{
    int choice;
    cout << "Select an option:" << endl;
    cout << "1. Run sameProgramSameCode" << endl;
    cout << "2. Run sameProgramDifferentCode" << endl;
    cout << "3. Run parentWaitForChild" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        sameProgramSameCode();
        break;
    case 2:
        sameProgramDifferentCode();
        break;
    case 3:
        parentWaitForChild();
        break;
    default:
        cerr << "Invalid choice. Please enter a valid option." << endl;
    }

    return 0;
}
