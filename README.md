# Library Manager
This program is designed to simulate a library, allowing to add books, users and so on.

## Build
```bash
mkdir -p build
cmake -S . -B build
cmake --build build
```


## Usage
After building the project, run the executable located in the `build` directory:
```bash
./build/LibraryManager
```
Then you can start to interact with the library with the provided commands.

## Example Session
***Coming soon...***

## Commands
- **ADD [book_type] [title] [author] [number_of_pages]**: Adds a new book to the library. *book_type* can be *NOVEL* or *TEXTBOOK*.
- **DISPLAY**: Displays all books in the library.
- **BORROW [book_id]**: Allows a user to borrow a book from the library.
- **RETURN [book_id]**: Allows a user to return a borrowed book to the library.
- **DELETE [book_id]**: Deletes a book from the library.
- **LOGIN [username]**: Logs in a user to the library system.
- **LOGOUT**: Logs out the current user.
- **HELP \<command\>**: Displays the list of available commands. You can specify a command to get more details about it.
- **QUIT**: Quits the program.


## How to add my custom command ?
***Coming soon...***


## Why This Project Exists
During a seminar on clean architecture, I realised the importance and the benefits of well-structured code. This project was created to practice and implement these principles in a test application.


## Rules Followed (or trying to follow)
- **Layers Separation**: The project is divided into distinct layers (e.g. repositories, interfaces, services) to ensure clear separation of needs.
- **SOLID Principles**: Each class and module has a single responsibility, making the codebase easier to maintain and extend.
