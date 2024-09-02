/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:46:46 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/08 18:38:27 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "../../inc/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		num[10];
	int			index;
	long int	nb;

	nb = n;
	index = 0;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb == 0)
		write(fd, "0", 1);
	while (nb > 0)
	{
		num[index] = nb % 10 + '0';
		nb /= 10;
		index++;
	}
	while (index > 0)
	{
		index--;
		write(fd, &num[index], 1);
	}
}
