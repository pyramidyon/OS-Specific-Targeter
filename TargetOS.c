#include <stdio.h>
#include <windows.h>
#include "ntdll.h"

#if defined(_WIN64)
__inline PPEB GetPeb(VOID) {
    return (PPEB)__readgsqword(0x60);
}
#elif defined(_WIN32)
__inline xPPEB GetPeb(VOID) {
    return (xPPEB)__readfsdword(0x30);
}
#endif

ULONG GetOsMinorVersionFromPeb(VOID) {
    return GetPeb()->OSMinorVersion;
}

ULONG GetOsMajorVersionFromPeb(VOID) {
    return GetPeb()->OSMajorVersion;
}

ULONG GetOsBuildNumberFromPeb(VOID) {
    return GetPeb()->OSBuildNumber;
}

VOID UseApiDependingOnOsVersion(VOID) {
    ULONG majorVersion = GetOsMajorVersionFromPeb();
    ULONG minorVersion = GetOsMinorVersionFromPeb();
    ULONG buildNumber = GetOsBuildNumberFromPeb();

    printf("OS Version: %lu.%lu (Build %lu)\n", majorVersion, minorVersion, buildNumber);

    if (majorVersion > 10 || (majorVersion == 10 && buildNumber >= 22000)) {
        printf("Using API for Windows 11 (Build 22000) and later.\n");
        // SomeApiAvailableInWin11();
        // SomeLPEExploit();
    }
    else if (majorVersion == 10 && buildNumber >= 19044) {
        printf("Using API for Windows 10 version 21H2 and later but before Windows 11.\n");
        // SomeApiAvailableInWin10V21H2();
    }
    else if (majorVersion == 10 && buildNumber >= 18362) {
        printf("Using API for Windows 10 version 1903 and later but before 21H2.\n");
        // SomeApiAvailableInWin10V1903();
    }
    else if (majorVersion == 10 && buildNumber >= 15063) {
        printf("Using API for Windows 10 version 1703 and later but before 1903.\n");
        // SomeApiAvailableInWin10V1703();
    }
    else if (majorVersion == 10 && buildNumber >= 10240) {
        printf("Using API for Windows 10 version 1507 and later but before 1703.\n");
        // SomeApiAvailableInWin10V1507();
    }
    else if (majorVersion == 6 && minorVersion == 3 && buildNumber >= 9600) {
        printf("Using API for Windows 8.1 (Build 9600) and later.\n");
        // SomeApiAvailableInWin81();
        // BSODStartup(); //worst OS, whoever uses this deserves it!
    }
    else if (majorVersion == 6 && minorVersion == 2 && buildNumber >= 9200) {
        printf("Using API for Windows 8 (Build 9200) and later.\n");
        // SomeApiAvailableInWin8();
        // BSODStartup(); //worst OS, whoever uses this deserves it!
    }
    else if (majorVersion == 6 && minorVersion == 1 && buildNumber >= 7601) {
        printf("Using API for Windows 7 SP1 (Build 7601) and later.\n");
        // SomeApiAvailableInWin7SP1();
    }
    else if (majorVersion == 6 && minorVersion == 1 && buildNumber < 7601) {
        printf("Using API for Windows 7 RTM (Build 7600).\n");
        // SomeApiAvailableInWin7RTM();
    }
    else if (majorVersion == 6 && minorVersion == 0 && buildNumber >= 6002) {
        printf("Using API for Windows Vista SP2 (Build 6002) and later.\n");
        // SomeApiAvailableInVistaSP2();
    }
    else if (majorVersion == 6 && minorVersion == 0 && buildNumber < 6002) {
        printf("Using API for Windows Vista RTM (Build 6000).\n");
        // SomeApiAvailableInVistaRTM();
    }
    else {
        printf("Using legacy API for older versions.\n");
        // SomeLegacyApi();
        // MS08-067(); //still works, trust me bro!
    }
}

int main() {
    UseApiDependingOnOsVersion();
    return 0;
}
