/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:21:52 by groman-l          #+#    #+#             */
/*   Updated: 2023/08/09 14:28:32 by groman-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push_stack(t_stack **stk, int cont, int index)
{
	t_node	*new;

	new = ft_calloc(sizeof(t_node), 1);
	if (!new)
		return (ERROR);
	new->cont = cont;
	new->index = index;
	new->next = (*stk)->first;
	(*stk)->first = new;
	(*stk)->size++;
	return (SUCCESS);
}

int	pop_stack(t_stack **stk)
{
	t_node	*rm;
	t_node	*next;

	if (!*stk || (*stk)->size == 0)
		return (ERROR);
	rm = (*stk)->first;
	next = (*stk)->first->next;
	free(rm);
	(*stk)->first = next;
	(*stk)->size--;
	return (SUCCESS);
}

int	push(t_stack **src, t_stack **dst, int stk)
{
	if (!src || (*src)->size == 0)
		return (ERROR);
	push_stack(dst, (*src)->first->cont, (*src)->first->index);
	pop_stack(src);
	if (stk == STKA)
		ft_printf("pa\n");
	else if (stk == STKB)
		ft_printf("pb\n");
	return (SUCCESS);
}
