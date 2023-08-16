#include <stdio.h>
#include <unistd.h>
/**
  * pid_max - prints maximum pid per system
  * system: 32 bits and 64 bits
  * Return (0): success
  */
int main(void)
{

	pid_t (= ../proc/sys/kernel/pid_max);
	printf("my pid is %u\n",pid_t );
	return (0);
