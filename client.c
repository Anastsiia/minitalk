#include<signal.h>

void	ft_error(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	write(1, '\0', 1);
}

void	ft_send_mess(char *str, int pid)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		j = 128;
		while (j != 0)
		{
			usleep(100);
			if (j & str[i])
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR2);
			j = j / 2;
		}
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	count;
	int	result;

	i = 0;
	count = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' 
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count = -count;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * count);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_send_mes(argv[2], pid);
	}
	else
		ft_error("Error");
}
