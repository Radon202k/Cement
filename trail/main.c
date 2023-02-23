#include <stdio.h>

#define MAXLINE 1000
#define INWHITESPACE 1
#define OUTWHITESPACE 0

int main()
{
	int n, i, state;
	char c, temp[MAXLINE];

	state=OUTWHITESPACE;
	while ((c = getchar()) != EOF)
		if (c == '\n')
		{
			if (n>0)
			{
				for (i=0; i<n; ++i)
				{
					if (temp[i] != '\t' && temp[i] != ' ')
					{
						putchar(temp[i]);
						state=OUTWHITESPACE;
					}
					else if (state==OUTWHITESPACE)
					{
						putchar(' ');
						state=INWHITESPACE;
					}
				}
				putchar('\n');
				n=0;
			}
		}
		else
			temp[n++] = c;
}