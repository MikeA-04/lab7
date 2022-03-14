#include "helper.h"

void send_signal(int sig) {
    // TODO 5-1: send SIGTSTP signal to ./sender program
    // 1. find ./sender program's pid

    // 2. send SIGTSTP signal to its pid 

    // 3. call this function at the bottom of signal_handler 

}

// signal handler 
void signal_handler(int sig) {
    // TODO 1-2: define a behavior to react when SIGTSTP (ctrl+Z) or SIGINT (ctrl+C) is received
    // For instance, print a message that "SIGTSTP received" or "SIGINT received"

    // TODO 5-1 (continue): call this function if the received signal is SIGINT
    // send_signal(SIGTSTP);
}

int main() {
    char buff[256];
    // store current program's pid
    pid_t pid = getpid();
    // TODO 1-1: register signal handler for SIGTSTP and SIGINT
    while (1) {
        // just wait
        write(1, "Waiting to receive a singal. Type exit to terminate.\n", strlen("Waiting to receive a singal. Type exit to terminate.\n"));
        write(1, "> ", 2);
        scanf("%s", buff);
        if (strcmp(buff, "exit") == 0) {
            exit(0);
        } else if (strcmp(buff, "^C") == 0) {
            write(1, "Ctrl + C\n", 9);
        } else if (strcmp(buff, "^Z") == 0) {
            write(1, "Ctrl + Z\n", 9);
        }
        else {

        }
    }

    return 0;
}