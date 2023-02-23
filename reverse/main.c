#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[], int len)
{
	int max;

	max = len;
	for ( ; len>max/2; len--)
	{
		char temp = s[len-1];
		s[len-1] = s[max-len];
		s[max-len] = temp;
	}
}

void testreverse(char *s)
{
	reverse(s, strlen(s));
	printf("%s\n", s);
}

void tests()
{
	testreverse("ABC");
	testreverse("ABCD");
	testreverse("A1234B1234C1234");
}

int main()
{
	char c, temp[MAXLINE];
	int n;

	n=0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
		{
			temp[n]='\0';
			reverse(temp, n);
			printf("%s\n", temp);
			n=0;
		}
		else
			temp[n++]=c;
}