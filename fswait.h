#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <CoreServices/CoreServices.h>
#include <dispatch/dispatch.h>

void watchFiles(const char *path, void (*cb)(int, char **));