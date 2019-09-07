# Contributing to Smooth

Hello and thank you for you interest in this framework. To keep things in order, please adhere to the following rules when contributing to the project.

## Tests

- Please write unit test for new code. We use Catch2 as the test framework. Have a look at the existing [unit tests](https://github.com/PerMalmberg/Smooth/tree/master/test/unit_tests) for examples if you are not previosuly familiar with it.
- Write integration tests for code that can't be fully tested using unit tests. Have a look at those found in the [test folder](https://github.com/PerMalmberg/Smooth/tree/master/test). Also take note of how the integration tests are structured; folder and namespace naming is an important part.

## Multi-platform

A major goal of Smooth is to ease development, which it does by allowing projects to be compiled for, and run on, Linux prior to targeting the ESP32 device. All new code must support this dual platform capability by using (and expanding) mocks such as [mock-idf](https://github.com/PerMalmberg/Smooth/tree/master/mock-idf) or other abstractions. Hardware mocks should pretend to be functioning (e.g. return success-values), but are not expected to be full simulators. They are however expected to not cause crashes at runtime.

## Code

### Modern C++

- Use modern C++ features, i.e. smart pointers over raw pointers, `std::array` instead of C-arrays, RAII etc.

### Formatting

- Run [Uncrustify](https://github.com/uncrustify/) on your code for general formatting, a configuration is [found in the root of the project](https://github.com/PerMalmberg/Smooth/blob/master/uncrustify.cfg).
- Follow the same code formatting as the rest of the project, such as:
  - Variables, class members, functions and methods shall use `snake_case` naming.
  - Do __not__ use Hungarian notation for variables, i.e. warts `m_` 
  - Classes shall be named using [UpperCamelCase](https://en.wikipedia.org/wiki/Camel_case) using characters a-z or A-Z. Digits are rarely used.
  - No multiple `return`-statements.
  - No switch, goto, jmp-statements.
  - Prefer positive logic, e.g. `if (ready) {...} else {...}` over  `if (!ready) {...} else {...}`
  - Do not use exceptions for code flow, i.e. use exceptions only for exceptional __uncrecoverable__ situations. That said, prefer error codes over exceptions.
  - Don't mix condition types without parentheses to avoid unintentional logic errors, e.g. `if(a && (b || c))` vs. `if(a && b || c)`
  - Don't call multiple methods in a condition statement; this avoids unintentional short circuits.
  - Place chained `&&` and `||` in if-statements at a new line.

## Source file header

Each source file shall have a copy of the [LICENSE](LICENSE) at the top of the file, adjusted to appropiately reflect the copyright of the original author. When changing an existing file, do not change the copyright of the file; the copyright remains with the original author.

## Code reviews

All pull requests will be critically reviewed before being accepted so please expect request for changes. Feel free to comment on other's pull requests, but keep things friendly. Code review is about improving code and learning from others, not berating the contributor.

## Contribution credit

Contributors will be given credit by being listed in the [CONTRIBUTORS.md](CONTRIBUTORS.md) file. Feel free to update this file when appropiate, it eases the acceptance of a contribution and ensures credit is given.

# WiP

This document is a work in progress and updated as needed.