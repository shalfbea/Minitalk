/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:00:41 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/18 19:41:34 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *smth)
{
	static char	cur;
	static int	i;
	static int client;
	//static char	end;
	//ft_putstr_fd("received sig:", 1);
	//ft_putnbr_fd(sig, 1);
	//ft_putstr_fd("\n", 1);

	//ft_putnbr_fd(client, 0);
	(void) info;
	(void) smth;
	if (info->si_pid)
		client = info->si_pid;
	if (i == 0)
		cur = 0xFF;
	if (sig == SIGUSR1)
		cur^= 0x80 >> i;
	else if (sig == SIGUSR2)
		cur|= 0x80 >> i;
	i++;
	//cur = 'c'q;
	if (i == 8)
	{
		if (cur)
			write(0, &cur, 1);
		i = 0;
		cur = 0xFF;
	}
	kill(client, SIGUSR1);
	//usleep(3);
}

int	main(void)
{
	t_sigacton	sigs;
	sigset_t	set;

	memset(&sigs, 0, sizeof(sigs));
	sigs.sa_sigaction = signal_handler;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sigs.sa_mask = set;
	sigaction(SIGUSR1, &sigs, 0);
	sigaction(SIGUSR2, &sigs, 0);

	ft_putnbr_fd(getpid(), 1);
	while (1)
		pause();
	return (0);
}
