#include <unistd.h>
#include <stdio.h>

int mystrlen (char *str)
{
    if (!str)
        return 0;
    int i = 0;
    while (str[i])
        i++;
    return i;
}

void myputchar(char c)
{
	write (1, &c, 1);
}

void myputstr(char *str, int nl)
{
	write (1, str, mystrlen(str));
    if (nl == 1)
	    write (1, "\n", 1);
}

void	myputnbr(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			myputstr("-2147483648", 0);
			return ;
		}
		myputchar('-');
		n = -n;
	}
	if (n / 10)
	{
		myputnbr(n / 10);
		myputnbr(n % 10);
	}
	else
		myputchar('0' + n);
}

int is_exist(char *input, char *buffer, int pos)
{
	int i = 0;
	while (buffer[i])
	{
		if (buffer[i] == input[pos])
			return 1;
		i++;
	}
	return 0;
}
void perm(char *input, char *buffer, int head, int len, int *per)
{

    int i;
    int j;
    if (head == len)
    {
        *per += 1;
        myputstr(buffer, 1);
        buffer[head - 1] = 0;
        return ;
    }
    i = 0;
    while (i < len)
    {
        if (head == 0)
        {
            buffer[head] = input[i];
            buffer[head + 1] = 0;
            perm(input, buffer, head + 1, len, per);
        }
        else
        {
			if (is_exist(input, buffer, i) == 0)
			{
				buffer[head]= input[i];
				buffer[head + 1] = 0;
            	perm(input, buffer, head + 1, len, per);
			}
        }
        i++;
    }
	buffer[head] = 0;
	return ;

}

int main (int ac, char **av)
{
    if (ac != 2)
    {
        myputstr("the number of argumnets is not correct", 1);
        return 1;
    }
    int len = mystrlen(av[1]);
    if (len == 0)
    {
        myputstr("empty string!", 1);
        return 1;
    }
    char buffer[len + 1];
    int per = 0;
    buffer[len] = 0;
    buffer[0] = 0;
    perm(av[1], buffer, 0, len, &per);
    myputstr("solutions are : ", 0);
    myputnbr(per);
    myputstr("\n", 0);

}
