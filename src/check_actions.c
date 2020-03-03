/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:33:44 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/03 15:34:15 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"
#include "common.h"
#include "libft.h"

int		ft_check_actions(char *buf, const char **actions)
{
	int		i;

	i = -1;
	while (actions[++i])
		if (ft_strcmp(buf, actions[i]) == 0)
			break ;
	return ((i == 11) ? (int)STAT_ERR : (int)STAT_OK);
}

int		ft_read_actions(const char **actions)
{
	char	*buf;
	int		stat_arg;

	stat_arg = (int)STAT_OK;
	if (!(buf = ft_memalloc(4)))
		return ((int)STAT_ERR);
	while (stat_arg == (int)STAT_OK)
	{
		read(0, buf, 4);
		stat_arg = ft_check_actions(buf, actions);
		ft_bzero(buf, 4);
	}
	return (stat_arg);
}
