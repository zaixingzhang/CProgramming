/*
 * Name: calcloan.c
 * Purpose: Calculate the amount of loan after paying.
 * Author: Jason Zhang
 */

#include <stdio.h>

#define MONTHS_OF_YEAR 12

int main(int argc, char * argv[])
{
	float loan, rate, monthly_payment;

	printf("Enter amount of loan: ______\b\b\b\b\b\b");
	scanf("%f", &loan);

	printf("Enter interest rate: ______\b\b\b\b\b\b");
	scanf("%f", &rate);
	rate = rate / 100;

	printf("Enter monthly payment: ______\b\b\b\b\b\b");
	scanf("%f", &monthly_payment);
	
	for (int i=1; i <= MONTHS_OF_YEAR; i++)
	{
		loan = loan * (rate / 12) + loan - monthly_payment; 
		printf("Balance remaining after %2dth payment: $%.2f\n", i, loan);
	}
	
	

	return 0;
}
