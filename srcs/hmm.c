#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
void	ft_putchar(char c)
{
	write(1,&c,1);
}

int	ft_stricmp(char *s1, int c)
{
	while (*s1 != '\0')
	{
		if (*s1 == c)
			return(1);
		s1++;
	}
	return(0);
}

char progress(char *s1, int a)
{
	while (*s1 != '\0') 
	{
		if (ft_stricmp && *s1 == a)
		{return (*(char *)s1);
		s1++;}
	}
	return(0);
}

char esketit(char *s1)
{
	char x;
	char y;

x = 0;
y = 0;
while(s1)
	{
	x++;
	y++;
	}i
return(0);
}


t_bool	valid_1(char *str, int bytes)
{
	int n;
	int i;
	int count1;
	int count2;

	n = 0;
	while (n < bytes)
	{
		i = -1;
		count1 = 0;
		count2 = 0;
		while (++i < 19)
		{
			if (str[n + i] == '#')
				count1++;
			if (str[n + i] == '.')
				count2++;
		}
		if (count1 != 4)
			return (false);
		if (count2 != 12)
			return (false);
		n += 21;
	}
	return (true);
}

int main (void)
{
	char *s = ".........######...........######";
	int c = '.';
	int a = '.';
	printf("%c",t_bool(s, 21));
}


