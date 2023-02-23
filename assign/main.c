#include <stdio.h>

// Assignments are expressions that have a value of the left hand side
// of the assignment, i.e. (c = getchar()) has the value of c after the
// assignment.

void counts()
{
	char c;
	long nb, nt, nn;

	nb = nt = nn = 0;
	while ((c = getchar()) != EOF)
		if (c == ' ')
			++nb;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nn;

	printf("%ld blank spaces, %ld tabs and %ld new lines\n", 
		nb, nt, nn);	
}

void oneblank()
{
	char c;
	long nb;
	while ((c = getchar()) != EOF)
		if (c == ' ' && ++nb == 1)
			putchar(c);
		else if (c != ' ')
		{
			putchar(c);
			if (nb > 0)
				nb = 0;			
		}
}

void explicitabs()
{
	char c;
	while ((c = getchar()) != EOF)
		if (c == '\t')
		{
			putchar('\\');
			putchar('t');
		}
		else if (c == '\b')
		{
			putchar('\\');
			putchar('b');
		}
		else if (c == '\\')
			putchar('\\');
		else
			putchar(c);
}

#define IN 1
#define OUT 0

void wordcount()
{
	int c, nl, nw, nc, state;
	
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}

int main()
{
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
			putchar('\n');
		else
			putchar(c);
	}	
}