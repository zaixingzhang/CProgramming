/*
 * Name: calctax.c
 * Purpose: calculate the total money with 5% tax rate.
 * Author: Jason Zhang
 * description: total_money = base_money * ( 1 + 5%)
 */

#include <stdio.h>

int main(int argc, char * argv[])
{
	float base_money, total_money;
	
	printf("Enter an amount: ________\b\b\b\b\b\b\b");
	scanf("%f", &base_money);

	total_money = base_money * ( 1 + 0.05);
	
	printf("With tax added: $%.2f\n", total_money);

	return 0;
}
