#include <stdio.h>

int main()
{
	int fahr, earlyTrunc, celsius;
	int lower, upper, step;
	float ffahr, fcelsius;

	lower = 0;
	upper = 300;
	step = 20;

	printf("F to C\n");
	fahr = lower;
	while (fahr <= upper)
	{
		earlyTrunc = 5/9 * (fahr-32);
		celsius = 5 * (fahr-32) / 9;
		fcelsius = 5.0/9.0 * (fahr-32);
		printf("%3d %3d %3d %3.1f\n", 
			fahr, earlyTrunc, celsius, fcelsius);
		fahr = fahr + step;
	}

	lower = 0;
	upper = 100;
	step = 10;

	printf("C to F\n");
	celsius = lower;
	while (celsius <= upper)
	{
		earlyTrunc = 9/5 * celsius + 32;
		fahr = (9*celsius) / 5 + 32;
		ffahr = 9.0/5.0 * celsius + 32;
		printf("%3d %3d %3d %3.1f\n", 
			celsius, earlyTrunc, fahr, ffahr);
		celsius = celsius + step;
	}
}