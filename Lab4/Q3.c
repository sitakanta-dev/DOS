#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    pid_t pid1, pid2, pid3;

    if ((pid1 = fork()) == 0) {
        printf("\nFirst child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("I am the first child, copying file1.txt to file2.txt\n");

        execl("/bin/cp", "cp", "file1.txt", "file2.txt", (char *)NULL);
        perror("execl failed for cp");
        exit(1);
    }

    sleep(1);  

    if ((pid2 = fork()) == 0) {
        printf("\nSecond child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("I am the second child, displaying content of file2.txt\n");

        execl("/bin/cat", "cat", "file2.txt", (char *)NULL);
        perror("execl failed for cat");
        exit(1);
    }

    sleep(1); 
    if ((pid3 = fork()) == 0) {
        printf("\nThird child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("I am the third child, displaying sorted content of file2.txt in reverse order \n");

        execl("/bin/sort", "sort", "-r", "file2.txt", (char *)NULL);
        perror("execl failed for sort and rev");
        exit(1);
    }

    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("Parent process: PID = %d, All child processes completed.\n", getpid());
    printf("I am the parent, all child processes have completed.\n");

    return 0;
}

