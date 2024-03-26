#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void wait_for_completion(int num_commands) {
    int i;
    int status;

    for (i = 0; i < num_commands; i++) {
        wait(&status);
    }
}


void add_command(int *num_commands, const char *cmd) {
    pid_t pid = fork();
    if (pid == 0) { // child process
        if (system(cmd) == -1) { // error occured while running command
            printf("Error occured during running command: %s\n", cmd);
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } else if (pid < 0) { // error occured while forking
        perror("fork");
        exit(EXIT_FAILURE);
    } else { // mother process
        (*num_commands)++;
    }
}


int main() {
    int num_commands = 0;

    add_command(&num_commands, "wget https://code.jquery.com/jquery-3.6.0.min.js");
    add_command(&num_commands, "ping -c 5 enauczanie.pg.edu.pl");
    add_command(&num_commands, "sleep 10");
    add_command(&num_commands, "ls -lrA");

    wait_for_completion(num_commands);

    return 0;
}
