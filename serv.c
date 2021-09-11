#include<signal.h>
#include<unctrl.h>
#include<unistd.h>

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

void ft_print_pid(int pid)
{
    int i;
    char *str;

    i = 0;
    str = "Server is ready, PID: ";
    while (str[i] != '\0')
        write(1, &str[i++], 1);
    ft_putnbr(pid);
}



int main()
{
    int pid;


    pid = getpid();
    ft_print_pid(pid);
      
}
