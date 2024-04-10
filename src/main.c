#include "fswait.h"

void callback(int length, char **paths) {
    printf("length: %d path: %s\n", length, paths[0]);
}

int main(void)
{
    watchFiles(".", callback);
    // ctrl-c to break
    
    // FIXME: catch signal and run below
    // CFRunLoopRef ref = CFRunLoopGetCurrent();
    // CFRunLoopStop(ref);
    // return 0;
}
