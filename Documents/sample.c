#include <stdio.h>

#define PI 3.14f

float circleArea(float radius);

int main(int argc, char * argv[])
{
	printf("The area of circle is : %f\n", circleArea(2.4f));
	return 0;
}

float circleArea(float radius)
{
	return PI * radius * radius;
}
