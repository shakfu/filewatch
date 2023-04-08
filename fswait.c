#include "fswait.h"

static void (*callback_func)(int, char **) = NULL;

static void callback(
    ConstFSEventStreamRef streamRef,
    void *clientCallBackInfo,
    size_t numEvents,
    void *eventPaths,
    const FSEventStreamEventFlags eventFlags[],
    const FSEventStreamEventId eventIds[])
{
   callback_func(numEvents, (char **)eventPaths);
}

void watchFiles(const char *path, void (*cb)(int, char **)) {
  printf("STARTING\n");
  callback_func = cb;
  CFStringRef mypath = CFStringCreateWithCString(NULL, path, kCFStringEncodingUTF8);
  CFArrayRef pathsToWatch = CFStringCreateArrayBySeparatingStrings (NULL, mypath, CFSTR(":"));

  void *callbackInfo = NULL;
  FSEventStreamRef stream;
  CFAbsoluteTime latency = 1.0;

  stream = FSEventStreamCreate(NULL,
    &callback,
    callbackInfo,
    pathsToWatch,
    kFSEventStreamEventIdSinceNow,
    latency,
    kFSEventStreamCreateFlagFileEvents
  );

  printf("CREATED stream\n");

  FSEventStreamScheduleWithRunLoop(stream, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode);
  FSEventStreamStart(stream);
  CFRunLoopRun();
}
