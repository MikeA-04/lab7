#include "helper.h"

void send_signal(int sig) {
    // TODO 5-1: send SIGTSTP signal to ./sender program
    // 1. find ./sender program's pid
    long int pid = find_pid("./sender");
    // 2. send SIGTSTP signal to its pid 
    kill(pid, SIGTSTP);
    // 3. call this function at the bottom of signal_handler 

}

// signal handler 
void signal_handler(int sig) {
    // TODO 1-2: define a behavior to react when SIGTSTP (ctrl+Z) or SIGINT (ctrl+C) is received
    // For instance, print a message that "SIGTSTP received" or "SIGINT received"
    if (sig == SIGINT) {
        write(1, "SIGINT recieved.\n", 17);
        // TODO 5-1 (continue): call this function if the received signal is SIGINT
        send_signal(SIGTSTP);
    } else if (sig == SIGTSTP) {
        write(1, "SIGTSTP recieved.\n", 18);
        send_signal(sig);
    } else {
        write(1, "No signal recieved.\n", 20);
    }
}

int main() {
    char buff[256];
    // store current program's pid
    pid_t pid = getpid();
    // TODO 1-1: register signal handler for SIGTSTP and SIGINT
    signal(SIGINT, signal_handler);
    signal(SIGTSTP, signal_handler);
    while (1) {
        // just wait
        write(1, "Waiting to receive a singal. Type exit to terminate.\n", strlen("Waiting to receive a singal. Type exit to terminate.\n"));
        write(1, "> ", 2);
        scanf("%s", buff);
        if (strcmp(buff, "exit") == 0) {
            exit(0);
        }
    }

    return 0;
}