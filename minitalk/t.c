#include <stdio.h>
#include <stdlib.h>

char    *char_to_binary(int n)
{
	int i;
    char *word;

    i = -1;
    word = (char*)malloc(sizeof(char) * 9);
    while(++i < 8)
        word[i] = '0';
    word[i] = 0;
    i = -1;
	while(n)
	{
		word[7 - (++i)] = '0' + n % 2;
		n /= 2; 
	}
	return (word);	
}

int main()
{
    
    printf("%s\n", char_to_binary(' '));
    return (0);
}