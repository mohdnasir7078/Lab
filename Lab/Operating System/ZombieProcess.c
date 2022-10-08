#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int pid = fork();
    if (pid == 0)
    {
        printf("Child process id: %d has Parent id: %d\n", getpid(), getppid());
    }
    else if (pid > 0)
    {
        wait(NULL);
        sleep(60);
        printf("Parent process id: %d has Grand Parent id: %d\n", getpid(), getppid());
    }
    else
        printf("Process not created");
    return 0;
}