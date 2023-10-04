# Simple Shell

This is a UNIX Shell program implemented with the C Programming language.It provides a basic command-line interface where users can enter commands and have them executed by the shell.

## Functional Requirements

- Display a prompt and wait for the user to type a command.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition `(Ctrl+D)`
- Handle command lines with arguments
- Handle the `PATH`
- Implement the `exit` built-in, that exits the shell
- Implement the `env` built-in, that prints the current environment
- Implement the `setenv` and `unsetenv` builtin commands
- Implement the builtin command `cd`


## Non-Functional Requirements

- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Codes should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/alx-tools/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/alx-tools/Betty/blob/master/betty-doc.pl)
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Write a `README` with the description of your project
- You should have an `AUTHORS` file at the root of your repository, listing all individuals having contributed content to the repository.

## Using the Simple Shell program

To get started with the Simple Shell, follow these steps:

1. Clone the repository:
`git clone https://github.com/Dprof-code/simple_shell.git`

2. Compile the source code:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`


## Testing

- Run in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

- Run in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## License

This project is licensed under the [MIT License](LICENSE).


## Acknowledgements

This project was developed as a collaboration between [Adedamola Olawale](https://github.com/dprof-code) and []() in the [ALX Software Engineering Program](https://www.alxafrica.com/software-engineering/). We would like to acknowledge the joint effort and contributions made by both team members in creating this Simple Shell.
