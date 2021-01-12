#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int length;

	length = 0;
	while (*(str++) != '\0')
	{
		length++;
	}
	return (length);
}

int		len(long nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char *str;
	long	n;
	int		i;

	n = nb;
	i = len(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

int	main(void)
{
	int i;

	i = 1;

	while (i <= 100)
	{
		if (i % 15 == 0) {
			write(1,"FizzBuzz\n",10);
		} else if (i % 3 == 0) {
			write(1,"Fizz\n",6);
		} else if (i % 5 == 0){
			write(1,"Buzz\n",6);
		} else {
			write(1,ft_itoa(i),ft_strlen(ft_itoa(i)));
			write(1,"\n",1);
		}

		i++;
	}
	return 0;
}
