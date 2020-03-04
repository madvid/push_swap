/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:02:59 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/03 21:40:16 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"
# include <stdlib.h>

typedef enum	e_stat
{
	STAT_ERR,
	STAT_OK
}				t_stat;

int		ft_check_args(int nb_arg, char **av);

#endif