#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

    int n1 = fork(); // parent p

    if (n1 > 0) // parent p copy
    {
        printf("\n[%d] This is Root parent p\n", getpid());

        int n2 = fork();
        if (n2 == 0) // child c2
        {
            // sleep(10);
            printf("[%d] This is Child 2 having parent %d\n", getpid(), getppid());

            int n3 = fork();
            if (n3 == 0) // child c5
            {
                printf("[%d] This is Child 5 having parent %d\n", getpid(), getppid());

                int n4 = fork();

                if (n4 > 0) // child c5 copy
                {
                    int n5 = fork();
                    if (n5 == 0) // child c8
                    {
                        printf("[%d] This is Child 8 having parent %d\n", getpid(), getppid());
                    }
                }
                if (n4 == 0) // child c7
                {
                    printf("[%d] This is Child 7 having parent %d\n", getpid(), getppid());
                }
            }
            if (n3 > 0) // child c2 copy
            {
                int n6 = fork();
                if (n6 == 0) // child 6
                {
                    printf("[%d] This is Child 6 having parent %d\n", getpid(), getppid());
                }
            }
        }
        sleep(20);
    }

    if (n1 == 0) // c1
    {
        printf("[%d] This is Child 1 having parent %d\n", getpid(), getppid());

        int n7 = fork();

        if (n7 > 0) // child c1 copy
        {
            int n8 = fork();
            if (n8 == 0) // child c4
            {
                printf("[%d] This is Child 4 having parent %d\n", getpid(), getppid());
            }
        }
        if (n7 == 0) // child c3
        {
            printf("[%d] This is Child 3 having parent %d\n", getpid(), getppid());
        }
        sleep(10);
    }
    return 0;
}