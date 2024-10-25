#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    pid = getpid();
    int signal;
    int ret_kill;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <signal number>\n", argv[0]);
        return 1;
    }

    // convert input signal to integer
    errno = 0;
    signal = strtol(argv[1], NULL, 10);

    if (errno != 0) {
        fprintf(stderr, "ERROR: failed to covert the input value to integer number: %s\n", strerror(errno));
        return 2;
    }

    // check if the signal number is within the supported signal range
    if (signal <= 0 || signal >= NSIG) {
        fprintf(stderr, "ERROR: signal number %d is not a supported signal number\n", signal);
        return 3;
    }

    // print current process ID and input signal number
    printf("Current PID: %d\n", pid);
    printf("Signal Number: %d\n", signal);
    printf("Signal Name: %s\n", strsignal(signal));

    // send signal to the current calling process
    errno = 0;
    ret_kill = kill(0, signal);
    if (ret_kill == -1) {
        fprintf(stderr, "ERROR: kill() call is failed: %s\n", strerror(errno));
        return 4;
    }

    return 0;
}
