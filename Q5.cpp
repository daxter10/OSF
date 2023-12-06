#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);

    if (GlobalMemoryStatusEx(&memInfo))
    {
        cout << "Total RAM: " << memInfo.ullTotalPhys / (1024 * 1024) << " MB" << endl;
        cout << "Free RAM: " << memInfo.ullAvailPhys / (1024 * 1024) << " MB" << endl;
        cout << "Used RAM: " << (memInfo.ullTotalPhys - memInfo.ullAvailPhys) / (1024 * 1024) << " MB" << endl;
    }
    else
    {
        cerr << "Error getting memory information. Error code: " << GetLastError() << endl;
        return 1;
    }

    return 0;
}
