#include <stdio.h>

char	**ft_split(char const *s, char c);

int main()
{
	char **test;
	int i = 0;
	
	test = ft_split (" wc", ' ');
	
	while (test[i])
	{
		printf( "%s\n", test[i]); 
		i++;
	}
	return 0;
} 

