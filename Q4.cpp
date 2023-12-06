#include <Windows.h>
#include <stdio.h>

int main() {
    // Using GetSystemInfo to retrieve information about the current system
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    printf("Processor Architecture: %u\n", systemInfo.wProcessorArchitecture);
    printf("Number of Processors: %u\n", systemInfo.dwNumberOfProcessors);
    printf("Page Size: %u bytes\n", systemInfo.dwPageSize);

    // Using GetVersionEx to retrieve information about the operating system
    OSVERSIONINFOEX osInfo;
    ZeroMemory(&osInfo, sizeof(OSVERSIONINFOEX));
    osInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (GetVersionEx((OSVERSIONINFO*)&osInfo)) {
        printf("Operating System Version: %u.%u\n", osInfo.dwMajorVersion, osInfo.dwMinorVersion);
        printf("Build Number: %u\n", osInfo.dwBuildNumber);
        printf("Platform ID: %u\n", osInfo.dwPlatformId);
    }

    return 0;
}
