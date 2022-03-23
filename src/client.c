/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:00:18 by shalfbea          #+#    #+#             */
/*   Updated: 2022/03/23 12:33:23 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		send_zero(int server)
{
	static int	i;

	while (++i < 33)
	{
		kill(server, SIGUSR1);
		return (1);
	}
	return (0);
}

char	bit_sender(int orig_serverid, char	*orig_msg)
{
	static int	serverid;
	static char	*msg;
	static int	bits;

	if (orig_msg)
		msg = ft_strdup(orig_msg);
	if (orig_serverid)
		serverid = orig_serverid;
	if (msg[bits / 32])
	{
		if (msg[bits / 32] & (0x200 >> (bits % 32)))
		{
			if (kill(serverid, SIGUSR2) == -1)
				exit(0);
		}
		else
		{
			if (kill(serverid, SIGUSR1) == -1)
				exit(0);
		}
		bits++;
		return (0);
	}
	if (send_zero(serverid))
		return (0);
	return (1);
}

void	signal_handler_client(int sig, siginfo_t *info, void *smth)
{
	(void) info;
	(void) smth;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("byte received\n", 1);
		if (bit_sender(0, 0))
			exit(0);
	}
	else if (sig == SIGUSR2)
	{
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_sigacton	sigs;
	sigset_t	set;

	if (argc != 3)
		exit(0);
	memset(&sigs, 0, sizeof(sigs));
	sigs.sa_sigaction = signal_handler_client;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sigs.sa_mask = set;
	sigaction(SIGUSR1, &sigs, 0);
	sigaction(SIGUSR2, &sigs, 0);
	bit_sender(ft_atoi(argv[1]), argv[2]);
	while (1)
		//usleep(1);
		pause();
	return (0);
}
