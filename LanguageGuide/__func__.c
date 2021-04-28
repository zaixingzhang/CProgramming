#include <stdio.h>
#include <stdlib.h>

#define FUNCTION_CALLED() printf("%s called\n", __func__)
#define FUNCTION_RETURN() printf("%s returns\n", __func__)

void f(void);

int main(int argc, char * argv[])
{
	f();	
	return 0;
}

void f(void)
{
	FUNCTION_CALLED();
	printf("Running function f() ....\n");
	FUNCTION_RETURN();
}
