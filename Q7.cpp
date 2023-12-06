#include <iostream>

using namespace std;

// Structure to represent a process
struct Process
{
    int id;          // Process ID
    int arrivalTime; // Arrival time of the process
    int burstTime;   // Burst time of the process
};

// Function to calculate waiting time and turnaround time for each process
void calculateTimes(Process processes[], int n, int waitingTime[], int turnaroundTime[])
{
    // Waiting time for the first process is always 0
    waitingTime[0] = 0;

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++)
    {
        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
    }
}

int main()
{
    int n; // Number of processes
    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];  // Array to store the processes
    int waitingTime[n];    // Array to store waiting times
    int turnaroundTime[n]; // Array to store turnaround times

    // Input the process details
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "Enter arrival time for Process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for Process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
    }

    // Calculate waiting time and turnaround time
    calculateTimes(processes, n, waitingTime, turnaroundTime);

    // Display the results
    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t" << processes[i].arrivalTime << "\t\t" << processes[i].burstTime << "\t\t"
             << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
    }

    return 0;
}
