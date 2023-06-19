# Doubly Linked List in C++

## Description
This repository contains the implementation of a generic Doubly Linked List in C++, along with comprehensive unit tests.

## Features

- **Generic list**: The List class is a template class, allowing the list to hold elements of any data type.
- **Iterator support**: The ListItr class acts as an iterator over the List, providing easy navigation through the list.
- **Copy semantics**: The List supports both deep copy (via copy constructor) and assignment operation (via assignment operator).
- **Comprehensive methods**: The List supports a variety of operations, including insertion (at any position), deletion, finding an element, printing the list, etc.
- **Detailed testing**: The repository also includes a robust suite of unit tests, demonstrating usage and verifying correctness of the List and ListItr classes.

## Structure

The repository is structured as follows:

- `src/`: This directory contains the C++ source files.
    - `List.h`: This file contains the List class.
    - `ListItr.h`: This file contains the ListItr class.
    - `ListNode.h`: This file contains the ListNode class.
- `test/`: This directory contains the test files.
    - `test.cpp`: This file contains the unit tests for the List and ListItr classes.
- `external/`: This directory contains external dependencies, such as the Doctest framework used for the unit tests.

## Dependencies

- This project uses the Doctest C++ testing framework. It's included in the `external/` directory.
- The project requires a modern C++ compiler supporting the C++14 standard or later.