/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:51:02 by groman-l          #+#    #+#             */
/*   Updated: 2023/08/09 14:28:35 by groman-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->first;
	while (node && node->next)
	{
		if (node->index > node->next->index)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

void	sort_digits(t_stack *stka, t_stack *stkb, int bit)
{
	int	num;
	int	i;
	int	size;

	i = 0;
	size = stka->size;
	while (i < size)
	{
		num = stka->first->index;
		if ((num >> bit) & 1)
			rotate(stka, STKA);
		else
			push(&stka, &stkb, STKB);
		i++;
	}
}

void	sort_big(t_stack *stka, t_stack *stkb)
{
	int	size;
	int	i;
	int	max_num;
	int	max_bits;

	size = stka->size;
	max_num = size - 1;
	max_bits = 0;
	while (max_num)
	{
		max_num = max_num >> 1;
		max_bits++;
	}
	i = 0;
	while (i < max_bits)
	{
		sort_digits(stka, stkb, i);
		while (stkb->size)
			push(&stkb, &stka, STKA);
		i++;
	}
}
