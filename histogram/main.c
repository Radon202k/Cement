#include <stdio.h>

void wordlengths()
{
	char c;
	long length;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
			putchar('\n');
		else
			putchar('#');

	}
}

void charfrequencies()
{
	int nalpha[('Z'-'A')+1 + ('z'-'a')+1], i;
	char c;

	for (c = 'A'; c <= 'Z'; c++)
		nalpha[c-'A'] = 0;
	for (c = 'a'; c <= 'z'; c++)
		nalpha[c-'a' + ('Z'-'A')] = 0;

	while ((c = getchar()) != EOF)
		if (c >= 'A' && c <= 'Z')
			++nalpha[c-'A'];
		else if (c >= 'a' && c <= 'z')
			++nalpha[c-'a' + ('Z'-'A')+1];
		else if (c == '\n')
		{
			for (c = 'A'; c <= 'Z'; c++)
			{
				putchar(c);
				for (i = 0; i < nalpha[c-'A']; i++)
					putchar('#');
				putchar('\n');
			}
			for (c = 'a'; c <= 'z'; c++)
			{
				putchar(c);
				for (i = 0; i < nalpha[c-'a' + ('Z'-'A')+1]; i++)
					putchar('#');
				putchar('\n');
			}
		}
}

int main()
{
	charfrequencies();
}