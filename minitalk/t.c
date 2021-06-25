#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int     ft_power(int i, int j)
{
    int n;

    n = 1;
    while(j--)
        n *= i;
    return (n);    
}

void     binary_to_char(char *msg)
{
    int n;
    int i;
    int signe;

    while(*msg)
    {
        n = 0;
        i = 7;
        if (*msg++ > 0)
            signe = 1;
        else
            signe = -1;
        while (*msg && --i > 0)
        {
            printf("[%d]%c\n",n, *msg);
            if (*msg == '1')
                n += ft_power(2, i);
            msg++;
        }
        n *= signe;
        printf("%d", n);
    }
}

int main()
{
    // char *a = strdup("abcdefjhi");
    // while(*a) 
    //     binary_to_char(char_to_binary(*a++));
    //binary_to_char("01100001");
    printf("%d", ft_power(2,5));
    return (0);
}