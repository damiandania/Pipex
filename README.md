<p>
<img src="https://github.com/damiandania/damiandania/blob/main/Pics/Pipex.png"
    alt="Project pic" width="150" height="150"/>
</p>

# Pipex 🔗

**Pipex** is a project that aims to recreate the functionality of the Unix pipe (`|`) operator. The goal is to understand and implement the mechanics of process creation and inter-process communication using pipes.

## Features

- **Command Execution:** Execute commands in a pipeline.
- **Input/Output Redirection:** Redirect input and output between commands.
- **Error Handling:** Handle errors gracefully and provide meaningful messages.

## Technologies Used

- **C:** The project is implemented in C.

## Installation

1. **Clone this repository:**
    ```bash
    git clone https://github.com/damiandania/Pipex.git
    ```

2. **Navigate to the project directory:**
    ```bash
    cd Pipex
    ```

3. **Build the project:**
    ```bash
    make
    ```

## Usage

Once the project is built, you can use the `pipex` executable to create pipelines between commands. For example:

```sh
$ ./pipex infile "ls -l" "grep pipex" outfile
