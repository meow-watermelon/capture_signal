# capture_signal

## Intro

When debugging whether a host system allows users to generate core dumps, I needed a simple way to trigger a core dump based on a signal. To facilitate this, I created a small program that sends a specified signal to the calling process, causing it to terminate and potentially generate a core dump.

## Compilation

To compile the program, use the following command:

```
$ gcc -g -Wall -Wextra -Wpedantic -o capture_signal capture_signal.c
```

## Usage

```
$  ./capture_signal 
usage: ./capture_signal <signal number>
```

If the provided signal number cannot be converted to an integer, the program will exit with an error message.

If the signal number is not supported by the system, the program will exit with an error message.

## Example

```
$ ./capture_signal 1000
ERROR: signal 1000 is not a supported signal number

$ ./capture_signal 6
Current PID: 30926
Signal Number: 6
Signal Name: Aborted
Aborted (core dumped)
```
