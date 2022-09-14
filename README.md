# Minitalk

## About

This project is part of program in [School 21](https://21-school.ru/) ([Ecole 42](42.fr)).
The purpose of this project is to code a small data exchange program
using UNIX signals.


## Requirements

- GNU GCC
- GNU Make

## Installation and usage

1. Download/Clone this repo

   > git clone https://github.com/shalfbea/Minitalk

2. Get into the root directory of project and run make command

   > cd Minitalk
   > make

3. Now you can run ./server in first terminal session and ./client <ServerPort> <Message> in an other
	Example:
//PIC
Note: Client will notify for every signal received by server

## Technical task

The full task can be found here: [minitalk_subject](https://github.com/shalfbea/Minitalk/blob/main/minitalk_subject.pdf)

### Quick summary:

- Only using c language is allowed
- Code-style should respect the [The Norm](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf)
- No memory leaks, segmentation faults, undefined behavior
- Only allowed functions: write, sigemptyset, sigaddset, sigaction ,
getpid, kill, malloc, free, pause, sleep, usleep, exit
- Can also use [libft](https://github.com/shalfbea/libft) (own implementation of part of the library functions)
and [ft_printf](https://github.com/shalfbea/ft_printf) (own implementation of printf function)
### Bonus (enabled by default)

- The server acknowledges every message received by sending back a signal to the client.
- Unicode characters support

### Evaluation result:
