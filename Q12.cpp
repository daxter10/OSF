#include <iostream>

using namespace std;

// Structure to represent a memory block
struct MemoryBlock
{
    int id;         // Block ID
    int size;       // Block size
    bool allocated; // Is block allocated or not
};

// Function to perform first-fit memory allocation
void firstFit(MemoryBlock memory[], int numBlocks, int processSize)
{
    for (int i = 0; i < numBlocks; i++)
    {
        if (!memory[i].allocated && memory[i].size >= processSize)
        {
            // Allocate the process in the first available block
            memory[i].allocated = true;
            cout << "Allocated process in block " << memory[i].id << endl;
            return;
        }
    }

    cout << "No suitable block found for the process." << endl;
}

// Function to perform best-fit memory allocation
void bestFit(MemoryBlock memory[], int numBlocks, int processSize)
{
    int bestFitIndex = -1;
    for (int i = 0; i < numBlocks; i++)
    {
        if (!memory[i].allocated && memory[i].size >= processSize)
        {
            if (bestFitIndex == -1 || memory[i].size < memory[bestFitIndex].size)
            {
                bestFitIndex = i;
            }
        }
    }

    if (bestFitIndex != -1)
    {
        // Allocate the process in the best-fit block
        memory[bestFitIndex].allocated = true;
        cout << "Allocated process in block " << memory[bestFitIndex].id << endl;
    }
    else
    {
        cout << "No suitable block found for the process." << endl;
    }
}

// Function to perform worst-fit memory allocation
void worstFit(MemoryBlock memory[], int numBlocks, int processSize)
{
    int worstFitIndex = -1;
    for (int i = 0; i < numBlocks; i++)
    {
        if (!memory[i].allocated && memory[i].size >= processSize)
        {
            if (worstFitIndex == -1 || memory[i].size > memory[worstFitIndex].size)
            {
                worstFitIndex = i;
            }
        }
    }

    if (worstFitIndex != -1)
    {
        // Allocate the process in the worst-fit block
        memory[worstFitIndex].allocated = true;
        cout << "Allocated process in block " << memory[worstFitIndex].id << endl;
    }
    else
    {
        cout << "No suitable block found for the process." << endl;
    }
}

int main()
{
    const int numBlocks = 5;
    MemoryBlock memory[numBlocks] = {{1, 100, false}, {2, 50, false}, {3, 200, false}, {4, 80, false}, {5, 120, false}};

    int processSize;
    cout << "Enter the size of the process: ";
    cin >> processSize;

    cout << "\nFirst-Fit Allocation:\n";
    firstFit(memory, numBlocks, processSize);

    cout << "\nBest-Fit Allocation:\n";
    bestFit(memory, numBlocks, processSize);

    cout << "\nWorst-Fit Allocation:\n";
    worstFit(memory, numBlocks, processSize);

    return 0;
}
