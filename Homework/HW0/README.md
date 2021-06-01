# HW0: Hello World!

## Overview

Welcome to your first C++ program! The main goal of this homework is to get you familiar with the developer tools (Visual Studio Code, Terminal, etc) as well as to code, compile, and execute your first program. Let's go ahead and break down the structure of [this](./main.cpp) program.

### main

Just before the `main` function, we have a few lines of code `#include <iostream>` and `using namespace std`. For now we can glance over these and continue to the `main` function.

Recall from class that all programs entry point start in the `main` function. Up to this point we do not need to worry about `int argc, char** argv`. All we care about for now is the contents inside of `main` which is what is between the curly-braces. Inside here, the program executes sequentially. It is standard practice at the end of the program to `return 0`. Notice that this return statement is returning an integer 0. This is known as an exit code and means that the program ran successfully. Also, note that right before `main` we have `int`. This represents an integer and is saying that main will give back an integer.

### cout

This assignment has you printing to the terminal. In C++ we do this by writing to "standard output". We do this with the use of `cout`. An example, is shown below.

```c++
int main(int argc, char** argv){
    cout << "Hello, World!" << '\n';
    return 0;
}
```

`cout` is used here to print "Hello, World!" to the terminal. This was done by first using `cout` followed by what is called the "insertion operator". You can think of this as whatever I have after this operator is being inserted into standard output, which in turn prints the contents to the terminal. Notice that "Hello, World!" is surrounded by quotations. This means that the literal text "Hello, World!" is being printed. If there were non quotations, then the compiler would be looking for variables with these names. Ultimately, this program will just print "Hello, World!" and return a successful exit code.

### Compiling and Executing

For easier learning, we have provided cmake files for you to compile and run your programs. To do this, we need to change to the directory where the program is located. This can be done with `cd` command in the terminal. Once in the correct directory, we then use the `cmake` to build a make file. Once the make file is made, our program can then be compiled with `make`. Finally, we can run the code we compiled with `./a.out`. An example of this shown below.

```bash
cd Homework
cd HW1
cmake .
make
./a.out
```

Once these first steps are complete, you will **ONLY** need to compile and re-execute the program if you make changes to the program. i.e. `make` and then `./a.out`.

## Your Task

Everyone loves a good Marvel movie. Your task for this assignment is to print to the terminal your favorite Marvel superhero (mines Spider-Man personally, I mean that technology is bananas). You only need to write one.

## Requirements

1. Write to standard output with your favorite Marvel superhero.
2. Submit your zip file in the following format `LastName-HW0.zip`.
