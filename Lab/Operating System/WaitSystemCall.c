#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int pid = fork();
    if (pid == 0)
    {
        sleep(5);
        printf("Child process id: %d has parent id: %d\n", getpid(), getppid());
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("Parent process id: %d has grand parent id: %d\n", getpid(), getppid());
    }
    else
        printf("Process not created");
    return 0;
}