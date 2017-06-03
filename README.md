# plugin-app
Template for an application with plugin usage.

## Build

Call in the *plugin-app* directory:
```bash
$ qmake
$ make all
```

## Description

The app loads all *\*.so* files (printer plugins) from the *bin* directory and calls function (print function) for each of them.   
