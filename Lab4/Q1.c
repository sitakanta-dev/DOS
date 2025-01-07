#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
    	while (1)
        	printf("Child: Process ID = %d\n", getpid());
    }
    else {
    	while (1)
        	printf("Parent: Process ID = %d\n", getpid());
    }

    return 0;
}

