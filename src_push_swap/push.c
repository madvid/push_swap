/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:05:07 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/15 23:35:39 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** FUNCTION: ft_push
** ARGUMENTS:	t_pp *d_orig
** 				t_pp *d_dest
** DESCRIPTION:
** 	Push the 1st elem of d_orig.stack to the beginning of the d_dest.stack
** 	The function modified the start, len of d_orig/dest consequently.
** RETURN: None.
*/

int		ft_push(int ***s_orig, int ***s_dest, t_info *info, char a_or_b)
{
	size_t		i_orig;
	size_t		i_dest;
	size_t		len;

	i_orig = (a_or_b == 'a') ? info->start2 : info->start1;
	i_dest = (a_or_b == 'a') ? info->start1 : info->start2;
	len = (a_or_b == 'a') ? info->len2 : info->len1;
	if (len == 0)
		return (0);
	else
	{
		(*s_dest)[i_dest - 1] = (*s_orig)[i_orig];
		(*s_orig)[i_orig] = NULL;
		(a_or_b == 'a') ? info->len1++ : info->len2++;
		(a_or_b == 'a') ? info->len2-- : info->len1--;
		(a_or_b == 'a') ? info->start2++ : info->start1++;
		(a_or_b == 'a') ? info->start1-- : info->start2--;
		return (1);
	}
}

/*
** FUNCTION: ft_p_a
** ARGUMENTS:	t_pp *data1
** 				t_pp *data2
** DESCRIPTION:
** 	Push the 1st element of data2.stack to the top of data1.stack (via ft_push).
** 	Then it print 'pa'.
** Return:
**	1: to specify the action was done (it is done in any case)
*/

int		ft_p_a(t_pp *data, t_info *info)
{
	ft_push(&(data->stack2), &(data->stack1), info, 'a') == 1 ?
		ft_add_actions(data, "pa\n") : 0;
	data->nb_actions += 1;
	return (1);
}

/*
** FUNCTION: ft_p_a
** ARGUMENTS:	t_pp *data1
** 				t_pp *data2
** DESCRIPTION:
** 	Push the 1st element of data1.stack to the top of data2.stack (via ft_push).
** 	Then it print 'pb'.
** Return:
**	1: to specify the action was done (it is done in any case)
*/

int		ft_p_b(t_pp *data, t_info *info)
{
	ft_push(&(data->stack1), &(data->stack2), info, 'b') == 1 ?
		ft_add_actions(data, "pb\n") : 0;
	data->nb_actions += 1;
	return (1);
}
