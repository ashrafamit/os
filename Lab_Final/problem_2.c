#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void t_sum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += i;
    }
    printf("\nSum of %d = %d", n, sum);
}

void t_fact(int n)
{
    unsigned long long fact = 1;
    if (n < 0)
        printf("\nError! Factorial of a negative number doesn't exist.");
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            fact *= i;
        }
        printf("\nFactorial of %d = %llu", n, fact);
    }
}
int main()
{
    int num;
    printf("input : ");
    scanf("%d",&num);

    int n1 = fork();

    if (n1 > 0) // parent copy
    {
        printf("\n[%d] This is Root parent p\n", getpid());
        int n2 = fork();
        sleep(2);
        if (n2 == 0) // c2
        {
            t_fact(num);
            printf("\n[%d] This is Child 2 having parent %d\n", getpid(), getppid());
        }
        if(n2>0)
        {
            sleep(5);
            printf("\nDone\n");
        }
        
    }
    if (n1 == 0) // c1
    {
        t_sum(num);
        printf("\n[%d] This is Child 1 having parent %d\n", getpid(), getppid());
    }
    
    return 0;
}

