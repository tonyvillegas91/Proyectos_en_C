#include <unistd.h>

void	ft_str_write(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		ft_str_write(argv[argc - 1]);
	ft_str_write("\n");
}
