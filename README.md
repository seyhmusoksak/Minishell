# 42-Minishell

## Project Overview

Minishell is a shell application that simulates command-line functionality in a UNIX-like terminal environment. The project aims to replicate the core functionalities of modern shells by adopting a modular approach to various functionalities. It includes command processing, environment variable management, and the implementation of various shell features.

## Features

- **Basic Shell Functionality:**
  - Displays a prompt while waiting for a new command from the user.
  - Manages command history.
  - Finds and executes the correct executable file based on the PATH variable or using absolute/relative paths.

- **Redirections:**
  - `<` redirects input.
  - `>` redirects output.
  - `<<` reads input until a line containing the delimiter is found, but does not update the history.
  - `>>` redirects output in append mode.

- **Pipes:**
  - Handles pipes (`|`) by connecting the output of each command in the pipeline to the input of the next.

- **Quoting:**
  - Handles single quotes (`'`) and double quotes (`"`). Double quotes prevent the shell from interpreting metacharacters in the quoted sequence, except for the `$` (dollar sign) character.

- **Environment Variables & Special Variables:**
  - Expands environment variables prefixed with `$`.
  - Expands `$?` to the exit status of the most recently executed foreground pipeline.

- **User Interactions:**
  - `ctrl-C` displays a new prompt on a new line.
  - `ctrl-D` exits the shell.
  - `ctrl-\` does nothing.

- **Builtin Commands:**
  - `echo` - with the `-n` option.
  - `cd` - with only a relative or absolute path.
  - `pwd` - with no options.
  - `export` - with no options.
  - `unset` - with no options.
  - `env` - with no options or arguments.
  - `exit` - with no options.

## Folder Structure

- **BUILTIN:** Implementations of the builtin commands.
- **ERROR:** Error handling functions.
- **EXECUTOR:** Command execution logic.
- **GNL:** Line-by-line reading functionality.
- **INCLUDES:** Header files.
- **LEXER:** Functionality for tokenizing commands.
- **PARSER:** Command analysis and execution logic.
- **UTILS:** Utility functions and tools.
- **Makefile:** Rules for compiling the project.

## Responsibilities and Tasks

### Text Processing and Control (Parser)
- **Text Parsing:** Processing and structuring input from the command line into appropriate data structures. This includes separating commands, arguments, and redirections.
- **Parser Control:** Implementing control mechanisms to ensure the correctness of parser functions. This involves handling erroneous inputs or unexpected conditions.

### Environment Variable Handling
- **Environment Variable Management:** Proper management and processing of user environment variables (e.g., PATH, HOME, PWD). This includes retrieving the values of these variables and integrating them into shell commands.
- **Variable Substitution:** Correctly processing and substituting environment variables within commands. This ensures that variables like `$USER` and `$PWD` are replaced with their actual values.

### Signal Handling
- **Signal Handling:** Managing and processing signals for processes running within the shell. This includes handling signals sent by the user (e.g., SIGINT, SIGQUIT) and responding appropriately to these signals.

## Functions Implemented by [e-kose](https://github.com/e-kose)

### Redirection Operations
- **Description:** Implementing output redirection (`>`, `>>`) and input redirection (`<`). This function allows the redirection of command outputs or inputs to files.

### Heredoc Processing
- **Description:** Heredoc is used to handle multiline inputs within commands. The input provided by the user is read until a specified delimiter is encountered, and it is used as input for the command.

### User Commands
- **`echo:`** Prints text to the screen. The `-n` option suppresses the newline character at the end of the output.
- **`cd:`** Changes the current directory. The directory can be changed using relative or absolute paths.
- **`pwd:`** Displays the current working directory.
- **`export:`** Defines environment variables and displays current environment variables.
- **`unset:`** Removes the specified environment variable from the environment.
- **`env:`** Lists environment variables and executes commands within this environment.
- **`exit:`** Exits the program.

### Processing Executable Files
- **Description:** Processing executable files located under `bin/`. This function ensures that various executable files in the `bin/` directory are correctly processed and executed.

## Benefits of Group Work

Throughout this project, we learned the importance of effective collaboration and teamwork. Working in a group allowed us to divide tasks according to each member's strengths, leading to a more efficient development process. Each member contributed their expertise, enhancing the quality and functionality of the final product. A special thank you to [e-kose](https://github.com/e-kose) for their invaluable contributions and collaboration.
  
## Installation Instructions

Clone the project to your computer:

```bash
git clone https://github.com/menasy/42-Minishell.git
cd minishell
```
## Build the Library

To compile the library:

```bash
make
```
## Usage
### Run The Project
```bash
./minishell
```

