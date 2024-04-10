#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <CoreServices/CoreServices.h>
#if __MAC_OS_X_VERSION_MAX_ALLOWED >= 1300
#include <Availability.h>
#endif

void watchFiles(const char *path, void (*cb)(int, char **));