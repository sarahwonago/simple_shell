# Simple Shell Project

This is a simple UNIX command-line interpreter (shell) implemented in C, adhering to the specified requirements and tasks.

## Table of Contents
- [Introduction](#introduction)
- [File Structure](#file-structure)
- [Building and Running](#building-and-running)


## Introduction

This project aims to create a basic shell that follows the specified guidelines and requirements. The shell supports executing simple commands, handling PATH, implementing the exit and env built-ins,and displaying the prompt.

## File Structure

The project is organized into several files, each serving a specific purpose:

- `main.c`: Contains the main entry point of the shell and the main loop.
- `shell.h`: Header file with function declarations and necessary includes.
- `read_command.c`: Implements the functionality to read commands from the user.
- `prompt.c`: Displays the shell prompt.
- `exec_command.c`: Executes a given command, handling PATH and built-ins.
- `env_builtin.c`: Implements the env built-in to print the current environment.

## Building and Running

To compile the shell, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
