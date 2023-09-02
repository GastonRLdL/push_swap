/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:42:51 by groman-l          #+#    #+#             */
/*   Updated: 2023/08/09 16:47:00 by groman-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	sort_2(t_stack *src, int stk)
{
	swap(src, stk);
	return (SUCCESS);
}

static int	sort_3(t_stack *src, int stk)
{
	while (!is_sorted(src))
	{
		if (find_pos(src, 0) == 0 && find_pos(src, 2) == 1)
			rev_rotate(src, stk);
		else if (find_pos(src, 1) == 0 && find_pos(src, 0) == 2)
			rev_rotate(src, stk);
		else if (find_pos(src, 1) == 0 && find_pos(src, 0) == 1)
			swap(src, stk);
		else if (find_pos(src, 2) == 1 && find_pos(src, 1) == 0)
			swap(src, stk);
		else if (find_pos(src, 2) == 0 && find_pos(src, 1) == 1)
			swap(src, stk);
		else if (find_pos(src, 2) == 0 && find_pos(src, 0) == 1)
			rotate(src, stk);
	}
	return (SUCCESS);
}

static int	sort_4(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (find_pos(a, 3) == 0)
			push(&a, &b, STKB);
		else if (find_pos(a, 3) == 1)
			swap(a, STKA);
		else if (find_pos(a, 3) == 2)
			rev_rotate(a, STKA);
		else if (find_pos(a, 3) == 3)
			rev_rotate(a, STKA);
	}
	if (a->size == 3)
		sort_3(a, STKA);
	push(&b, &a, STKA);
	rotate(a, STKA);
	return (SUCCESS);
}

static int	sort_5(t_stack *a, t_stack *b)
{
	while (a->size > 4)
	{
		if (find_pos(a, 4) == 0)
			push(&a, &b, STKB);
		else if (find_pos(a, 4) == 1)
			swap(a, STKA);
		else if (find_pos(a, 4) == 2)
			rotate(a, STKA);
		else if (find_pos(a, 4) == 3)
			rev_rotate(a, STKA);
		else if (find_pos(a, 4) == 4)
			rev_rotate(a, STKA);
	}
	if (!is_sorted(a))
		sort_4(a, b);
	push(&b, &a, STKA);
	rotate(a, STKA);
	return (SUCCESS);
}

int	sort_small(t_stack *stka, t_stack *stkb)
{
	if (stka->size == 2)
	{
		sort_2(stka, STKA);
		exit (SUCCESS);
	}
	else if (stka->size == 3)
	{
		sort_3(stka, STKA);
		exit (SUCCESS);
	}
	else if (stka->size == 4)
	{
		sort_4(stka, stkb);
		exit (SUCCESS);
	}
	else if (stka->size == 5)
		sort_5(stka, stkb);
	return (SUCCESS);
}
