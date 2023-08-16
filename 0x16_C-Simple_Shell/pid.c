#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	int a = 5;
	int b = 6;
	int sum = a+b;
	pid_t my_pid;
	pid_t pid_max;
	pid_max = getpid ();
	my_pid = getpid();
	printf("sum is %d\n", sum);
	printf("%u\n", my_pid);
	printf("%u\n", pid_max);
	return (0);
}
