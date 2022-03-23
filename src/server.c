/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:00:41 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/23 12:31:16 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	signal_handler(int sig, siginfo_t *info, void *smth)
{
	static char	cur;
	static int	i;
	static int	client;

	(void) info;
	(void) smth;
	if (info->si_pid)
		client = info->si_pid;
	if (i == 0)
		cur = 0xFF;
	if (sig == SIGUSR1)
		cur ^= 0x200 >> i;
	else if (sig == SIGUSR2)
		cur |= 0x200 >> i; //0x80
	i++;
	if (i == 32) // 8
	{
		if (cur)
			write(1, &cur, 1);
		i = 0;
	}

	kill(client, SIGUSR1);
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

	//ft_printf("%d\n", getpid());
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
