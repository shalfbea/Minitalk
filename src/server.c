/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:00:41 by shalfbea          #+#    #+#             */
/*   Updated: 2022/02/08 17:59:49 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	ft_putstr_fd("received smth", 1);
	ft_putnbr_fd(sig, 1);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_sigacton sigs;

	(void) argc;
	(void) argv;
	memset(&sigs, 0, sizeof(sigs));
	sigs.sa_handler = signal_handler;
	sigset_t   set;
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sigs.sa_mask = set;
	sigaction(SIGUSR1, &sigs, 0);
	sigaction(SIGUSR2, &sigs, 0);
	ft_putnbr_fd(getpid(), 1);

	while (1)
		usleep(1);
	return (0);
}
