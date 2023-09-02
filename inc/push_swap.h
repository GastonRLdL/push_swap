/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:31:27 by groman-l          #+#    #+#             */
/*   Updated: 2023/08/09 18:56:37 by groman-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> 
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

# define ERROR		-1
# define SUCCESS	0
# define TRUE		1
# define FALSE		0
# define STKA		1
# define STKB		2

typedef struct s_node
{
	int				cont;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*first;
	t_node	*last;
}	t_stack;

/*******check.c********/
int		parse(int ac, char **av);
/*******init.c*********/
int		double_init(t_stack **stk1, t_stack **stk2);
/********utils.c*******/
int		free_willy(t_stack *stk);
void	willy_willy(t_stack *stka, t_stack *stkb);
int		print_node(t_stack *stk);
/*******push.c*********/
int		push(t_stack **src, t_stack **dst, int stk);
int		push_stack(t_stack **stk, int cont, int index);
/*******swap.c*********/
int		swap(t_stack *src, int stk);
int		swap_swap(t_stack *stka, t_stack *stkb);
/*******rotate.c*******/
int		get_bot(t_stack *src, t_node **bot, int limit);
int		rotate(t_stack *src, int stk);
int		rotate_rotate(t_stack *stka, t_stack *stkb);
/*******rev_rotate.c***/
int		rev_rotate(t_stack *src, int stk);
int		rev_rot_rot(t_stack *stka, t_stack *stkb);
/*******sorting.c******/
int		is_sorted(t_stack *stack);
void	sort_digits(t_stack *stka, t_stack *stkb, int bit);
void	sort_big(t_stack *stka, t_stack *stkb);
/*******push_swap******/
void	indexer(t_stack *stk);
int		find_pos(t_stack *src, int trgt);
/*******tiny_sort******/
int		sort_small(t_stack *stka, t_stack *stkb);
#endif