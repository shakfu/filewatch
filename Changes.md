# Changes to filewatch

This is a modification to Shakeeb Alireza's [version](https://github.com/shakfu/filewatch), which is in turn a copy of a copy.

The main change is to replace two deprecated functions:

* `FSEventStreamScheduleWithRunLoop` with `FSEventStreamSetDispatchQueue`
* `CFRunLoopRun` with a `while (true)` loop.
