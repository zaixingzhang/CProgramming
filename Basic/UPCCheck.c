#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int d, i1, i2, i3, i4, i5, j1, j2, j3,j4, j5, c1;
	int first_sum, second_sum, total, check_code;
	printf("Please input the UPC: ");

	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3,&j4, &j5, &c1);
	
	first_sum = d + i2 + i4 + j1 + j3 + j5;
	second_sum = i1 + i3 + i5 + j2 + j4;
	total = 3 * first_sum + second_sum;

	check_code = 9 - ((total - 1) % 10);

	if (check_code != c1){
		fprintf(stderr, "ERROR: Your UPC is invalid!\n");
		exit(EXIT_FAILURE);
	}

	printf("You enter a valid UPC!\n");
	return 0;
}
