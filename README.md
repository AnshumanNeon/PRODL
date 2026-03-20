# Programmed Deallocation

Here i have implemented the memory model described by Antonio Kreczmar, University of Warsaw, in 1983 that aims to be memory safe and act as an alternative to garbage collection.

The project is work in progress, contributions are welcome.

## Installation

Clone the repo and run the Makefile by running `make` command.

The project by default uses the gcc-9 compiler. If you'd like to use some other compiler, then change the `compiler` variable in the Makefile.

## References

- Programmed Deallocation without Dangling Reference, Gianna Cioni and Antonio Kreczmar
- Explicit Deallocation without Dangling References II, Andrzej Zadrozny and Andrzej Salwicki
- Report on the LOGLAN 82 Programming Language, Andrzej Salwicki, Antonio Kreczmar, et al.
