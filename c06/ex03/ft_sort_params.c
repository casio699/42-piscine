
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char	*temp;

	i = 1;
	j = 0;
	while (i < argc - 1)
	{
		if (argv[i][0] > argv[i + 1][0])
		{
			temp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = temp;
			i = 0;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
