
# BF-Interpreter

I wrote an interpreter for the [BF-language](https://en.wikipedia.org/wiki/Brainfuck).

## Installation

First, clone the repository, then create a build directory and call `cmake`.

Or in other words, run the following lines in your favorite terminal:

```
$ git clone https://github.com/cjordan7/BF-Interpreter.git
$ cd path/to/clone/bf/interpreter/
$ mkdir build
$ cd build
$ cmake ..
```


## Use

After building the interpreter, launch it with a *bf program*:

```
cd path/to/clone/bf/interpreter/build/
$ ./bfInterpreter path/to/bfFile
```

