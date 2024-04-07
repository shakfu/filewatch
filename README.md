# filewatch

A lightweight macOS file watcher.

This is a friendly fork of Nicholas Simmons' [node-native-osx-filewatcher](https://github.com/nsimmons/node-native-osx-filewatcher) with the following changes:

- Simplified codebase

- Removed node-related code

- Added Makefile

- Added cmake support

- Replaced deprecated apis.


## Building

Easiest is just:

```bash
make
```

Cmake works as well via the usual build sequence or `make cmake`



## Original README

The following slightly edited text is from the original README:

Native file watcher implementation for Mac OS X. Uses Mac OS X FSEvents API to monitor a directory.

Based on https://github.com/alandipert/fswatch.

Why bother? Because by using OS level events we can remove the burden of constantly checking each file being watched for changes.

End result? CPU usage drops to an insignificant factor when watching a large number of files.
