/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:44:10 by groman-l          #+#    #+#             */
/*   Updated: 2023/08/09 14:28:36 by groman-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	swap(t_stack *src, int stk)
{
	int	cont;
	int	index;

	if (!src || src->size <= 1)
		return (ERROR);
	cont = src->first->cont;
	index = src->first->index;
	src->first->cont = src->first->next->cont;
	src->first->index = src->first->next->index;
	src->first->next->cont = cont;
	src->first->next->index = index;
	if (stk == STKA)
		ft_printf("sa\n");
	else if (stk == STKB)
		ft_printf("sb\n");
	return (SUCCESS);
}

int	swap_swap(t_stack *stka, t_stack *stkb)
{
	if (stka || stkb || stka->size <= 1 || stkb->size <= 1)
		return (ERROR);
	swap(stka, 0);
	swap(stkb, 0);
	ft_printf("ss\n");
	return (SUCCESS);
}
