/*
 * Name：leastbill.c 
 * Purpose: Given an amount of dollar, use the least number of bill to pay.
 * Author: Jason Zhang
 */

#include <stdio.h>

#define TWENTY 20
#define TEN 10
#define FIVE 5
#define ONE 1

#define NUM_OF_DENO 4

int main(int argc, char * argv[])
{
	int bill[NUM_OF_DENO] = {TWENTY, TEN, FIVE, ONE};
	int bill_num[NUM_OF_DENO] = {0, 0, 0, 0};
	int amount;
	
	printf("Enter a dollar amount: __\b\b");
	scanf("%d", &amount);

	for (int i=0; i < NUM_OF_DENO; i++)
	{
		bill_num[i] = amount / bill[i];
		amount -= bill_num[i] * bill[i];
	}
	
	for (int i=0; i < NUM_OF_DENO; i++)
	{
		printf("$%2d bills: %d\n", bill[i], bill_num[i]);
	}	

	return 0;
}
