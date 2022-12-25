#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int n1 = fork();

    if (n1 > 0) //parent copy
    {
        printf("\n[%d] This is Root parent p\n", getpid());
        int n2 = fork();
        sleep(20);
        if (n2 == 0) //c2
        {
            printf("[%d] This is Child 2 having parent %d\n", getpid(), getppid());
        }
        
    }
    if (n1 == 0) //c1
    {
        printf("[%d] This is Child 1 having parent %d\n", getpid(), getppid());
    }
    return 0;
}