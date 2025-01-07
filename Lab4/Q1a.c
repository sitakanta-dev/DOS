#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork(); 
    if(pid==-1){
        perror("fork failed");
        return 1;
    }else if (pid==0){
        while(1){
            printf("child process : PID =%d\n",getpid());
            sleep(1);
        }
    }
    else{
        while(1){
            printf("parent process: PID = %d\n",getpid());
            sleep(1);
        }
    }
    return 0;
}

