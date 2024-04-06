# filewatch

A lightweight macOS file watcher.

This is a friendly simplified fork of Nicholas Simmons' [node-native-osx-filewatcher](https://github.com/nsimmons/node-native-osx-filewatcher) with the following changes:

- removed node-related code
- added Makefile was added 
- added code and conditional compilation logic address deprecated api

To build:

```bash
make
```


The following slightly edited text is from his README:

Native file watcher implementation for Mac OS X. Uses Mac OS X FSEvents API to monitor a directory.

Based on https://github.com/alandipert/fswatch.

Why bother? Because by using OS level events we can remove the burden of constantly checking each file being watched for changes.

End result? CPU usage drops to an insignificant factor when watching a large number of files.
