#include "minitalk.h"

void	ft_putnbr(int nb)
{
	if (nb >= 0 && nb <= 9)
	{
		nb = nb + '0';
		write(1, &nb, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_print_pid(int pid)
{
	int		i;
	char	*str;

	i = 0;
	str = "Server is ready, PID: ";
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	ft_putnbr(pid);
	write(1, "\n", 1);
}

static void	ft_print_mess(int signal)
{
	static int	check;
	static int	symbol;
	static int	count;

	if (check == 0)
		check = 128;
	if (signal == SIGUSR1)
	{
		check = check / 2;
		count++;
	}
	else
	{
		symbol = symbol + check;
		check = check / 2;
		count++;
	}
	if (count == 8)
	{
		write(1, &symbol, 1);
		check = 0;
		symbol = 0;
		count = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_print_pid(pid);
	while (1)
	{
		signal(SIGUSR2, ft_print_mess);
		signal(SIGUSR1, ft_print_mess);
		pause();
	}
}
