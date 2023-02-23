#include <stdio.h>

#define MAXLINE 1000

int main()
{
	int n;
	char c;

	char temp[MAXLINE];
	n=0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
		{
			temp[n] = '\0';
			if (n >= 80)
				printf("%s\n", temp);
			n = 0;
		}
		else
			temp[n++] = c;

	return 0;
}


int getline(char line[], int maxline);
void copy(char to[], char from[]);

void printlongestline()
{
	int len, max;
	char line[MAXLINE], longest[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%3d - %s", max, longest);
}

int getline(char s[], int lim)
{
	int c, i;

	for (i=0; (c=getchar())!=EOF && c!='\n'; ++i)
		if (i<lim-1)
			s[i] = c;
		else if (i==lim-1)
			s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}