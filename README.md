# C-Contact-Book

A small project to learn the fundamentals of C.

## Overview

This is a simple contact book application written in C. It allows you to add, list, save, and load contacts using a dynamically resizing array. The project demonstrates basic file I/O, dynamic memory management, and struct usage in C.

## Features

- Add new contacts
- List all saved contacts
- Save contacts to a file (`contacts.txt`)
- Load contacts from a file
- Simple menu-driven interface

## File Structure

```
.
├── contact-book      # Compiled executable
├── contact.c         # Contact management implementation
├── contact.h         # Contact management header
├── contacts.txt      # Saved contacts data
├── main.c            # Main program logic and menu
└── Makefile          # Build instructions
```

## Getting Started

### Prerequisites

- GCC or any C compiler
- Make (optional, for using the Makefile)

### Build

To compile the project, run:

```sh
make
```

This will produce an executable named `contact-book`.

### Run

To start the contact book:

```sh
./contact-book
```

### Usage

Follow the on-screen menu to add, list, save, or load contacts.

## Example Menu

```
Welcome to the contact book

1. Add contact
2. List Contacts
3. Save Contacts
4. Load Contacts
0. Exit
```

## License

This project is for educational purposes. 