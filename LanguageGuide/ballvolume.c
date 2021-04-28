/*
 * Name: ballvolume.c
 * Purpose: Compute the volume of a ball.
 * Author: Jason Zhang
 * description: formula  (v = 4/3 * PI * r^3)
 */

#include <stdio.h>

#define PI 3.141592

int main(int argc, char * argv[])
{
	float radius, volume;

	printf("Enter the radius of ball: ");
	scanf("%f", &radius);

	volume = 4.0f/3.0f * PI * radius * radius * radius;
	
	printf("The radius of ball: %f\n", radius);
	printf("The volume of ball: %f\n", volume);
	
	return 0;
}
