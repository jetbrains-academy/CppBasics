In C++, input/output (I/O) operations are performed using streams. A stream is a sequence of bytes that flow from a source (like a keyboard, a file, or a network connection) to a destination (like a screen, a file, or a network connection). The C++ Standard Library provides several classes for performing I/O operations. Their hierarchy is shown [here](https://en.cppreference.com/w/cpp/io#Hierarchy). 

The most basic stream types are the input stream type `istream` and the output stream type `ostream`, with corresponding `std::cin` and `std::cout` functions. The `istream` type provides an overloaded `>>` operator for input, and the `ostream` type provides an overloaded `<<` operator for output.

```cpp
// Standard output (console)
std::cout << "Hello, World!" << std::endl;

// Standard input (console)
int inputNumber;
std::cout << "Enter a number: ";
std::cin >> inputNumber;
std::cout << "You entered: " << inputNumber << std::endl;
```

In addition to console I/O, C++ provides the `fstream` library to handle file I/O. Input and output to/from a file are achieved through `ifstream` (input file stream) and `ofstream` (output file stream). These classes are derived from `istream` and `ostream`, respectively.
Here's a simple example of writing to and reading from a file:

```cpp
std::string inputFile = "input.txt";
std::string outputFile = "output.txt";

// Writing to a file
std::ofstream outFile(outputFile);
if (outFile.is_open()) {
    outFile << "Hello, File!" << std::endl;
    outFile.close();
}

// Reading from a file
std::ifstream inFile(inputFile);
std::string line;
if (inFile.is_open()) {
    while (getline(inFile, line)) {
        std::cout << line << '\n';
    }
    inFile.close();
}
```

Note that in order to access the file, it must be in the same directory as the program, or the full path to the file must be specified.

Another important stream type is `stringstream`. It allows you to perform input and output operations on memory-based strings, which can be useful for parsing and formatting text.  Here's an example of how to use `stringstream`:

```cpp
    std::string inputString = "Hello, World!";
    std::istringstream inputStream(inputString);
    std::string word;

    while (inputStream >> word) {
        std::cout << word << std::endl;
    }
    
    std::ostringstream outputStream;
    outputStream << "Hello, World!" << std::endl;

    std::cout << outputStream.str();
```

Moreover, standard library provides several methods for checking and handling I/O errors, such as `fail()`, `bad()`, `eof()`, and `good()`. These methods can be used to check the state of the stream and to clear error flags.

For instance, every stream has an associated *failbit*, *badbit*, *eofbit*, and *goodbit* that can be checked to determine the state of the stream. The *failbit* is set when a non-fatal I/O error occurs, such as when an attempted input operation fails to convert a character sequence to a valid value. The *badbit* is set when a fatal I/O error occurs, such as when an attempt to write to a file fails because the disk is full. The *eofbit* is set when an input operation reaches the end of an input sequence. The *goodbit* indicates that none of the other bits is set.
Here is how to check the state of the stream:

```cpp
std::ifstream file("input.txt");
if (file.good()) {
    std::cout << "File opened successfully" << std::endl;
} else {
    if (file.eof()) {
        std::cout << "End of file reached" << std::endl;
    } else if (file.fail()) {
        std::cout << "Non-fatal I/O error" << std::endl;
    } else if (file.bad()) {
        std::cout << "Fatal I/O error" << std::endl;
    }
}
```

In addition to checking the state of a stream, you can also clear the error state flags using the `clear()` function and set them using the `setstate()` function.

__Stream manipulators__ are special functions that modify the behavior of streams. For example, `std::endl` is a manipulator that inserts a newline character and flushes the output buffer. We can also use manipulators like `std::setw` to set the width of the output, `std::setprecision` to set the precision of floating-point numbers, and `std::fixed` to display floating-point numbers in a fixed notation. The full list of manipulators can be found [here](https://en.cppreference.com/w/cpp/io/manip).

Here are examples of a few:
```cpp
std::cout << std::setw(10) << std::left << "Top left" << std::setw(26) << std::right << "Top right" << std::endl;
std::cout << std::setw(10) << std::left << "Bottom left" << std::setw(25) << std::right << "Bottom right" << std::endl;

std::cout << std::fixed << std::setprecision(3) << M_PI << std::endl;
std::cout << std::scientific << std::setprecision(10) << M_PI << std::endl;

std::cout << std::hex << 123456 << std::endl;
std::cout << std::oct << 123456 << std::endl;
std::cout << std::dec << 123456 << std::endl;
```

The output of the program will be:
```
Top left                   Top right
Bottom left             Bottom right
3.142
3.1415926536e+00
1e240
361100
123456
```

You need to create a program that reads all input string by string, until the string "end" is read. After that, the program should output responses for each token in the following format:

 - If a number is read, the program should output "Got number: <number>" with a precision of 3 decimal places.
 - If a token is not a number, the program should output "Got string: <string>".
<div class="hint">
  We encourage you to use `stringstream` for parsing the input and collecting tokens, since it is the most efficient way to dynamically change a string.

  A number is a sequence of digits, optionally containing one decimal point and a minus sign at the beginning.
</div>

*Congratulations on finishing this module! We highly encourage you to get back to the [Scoreboard](course://ObjectOrientedProgramming/ClassesAndObjects/Scoreboard) task and extend Planet Game with new features!* 