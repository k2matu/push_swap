/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:32:33 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/20 19:53:38 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	long			data ;
	int				pos ;
	struct s_stack	*prev ;
	struct s_stack	*next ;
}	t_stack;

t_stack		*add_new(long data);
t_stack		*stoi(int argc, char **argv);
void		add_front(t_stack **lst, t_stack *new);
void		add_back(t_stack **lst, t_stack *new);
void		fill_stack_pos(t_stack **a, int *arr, int count);
void		free_stack(t_stack **stack);
void		push(t_stack **src, t_stack **dest, char c);
void		push_back(t_stack **a, t_stack **b, int pos);
void		push_to_stack_b(int *lis, t_stack **a, t_stack **b, int count);
void		reverse_rotate(t_stack **a_lst, t_stack **b_lst, char c);
void		rotate(t_stack **a_lst, t_stack **b_lst, char c);
void		swap(t_stack **a_lst, t_stack **b_lst, char c);
void		quicksort(int *arr, int low, int high);
int			*get_lis(int *arr, int len);
int			*lst_to_arr(t_stack **a, int count);
int			cheapest_number(t_stack **a, t_stack **b);
int			check_sorted(t_stack **a);
int			count_a_moves(t_stack **a, int pos);
int			count_b_moves(t_stack **b, int pos);
int			count_moves(t_stack **a, t_stack **b, int pos);
int			count_nodes(t_stack *stack);

#endif