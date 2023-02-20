#include <stdio.h>

int main()
{
	int fahr, earlyTrunc, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper)
	{
		earlyTrunc = 5/9 * (fahr-32);
		celsius = 5 * (fahr-32) / 9;
		printf("%d\t%d\t%d\n", fahr, earlyTrunc, celsius);
		fahr = fahr + step;
	}
}