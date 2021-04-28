#include <stdio.h>

int main(int argc, char * argv[])
{
	int i=2;
	int j = -i++;
	printf("i=%d, j=%d\n", i, j);
	return 0;
}
