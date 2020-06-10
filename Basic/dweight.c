/*
 * Name: dweight.c
 * Purpose: Computes the dimesional weight of a 12" x 10" x 8" box
 * Author: Jason Zhang
 */

#include <stdio.h>

#define INCHES_PER_POUND 166

int main(int argc, char * argv[])
{
	int height, length, width, volume, weight;
	
	printf("Enter height of box: ");
	scanf("%d", &height);
	
	printf("Enter length of box: ");
	scanf("%d", &length);

	printf("Enter width of box: ");
	scanf("%d", &width);

	volume = height * length * width;
	weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;

	printf("Dimesions: %dx%dx%d\n", length, width, height);
	printf("Volume (cubic inches): %d\n", volume);
	printf("Dimesional weight (pounds): %d\n", weight);

	return 0;
}
