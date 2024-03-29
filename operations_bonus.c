/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:50:46 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/20 22:01:50 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_second_bonus(t_stack **lst)
{
	t_stack	*first;
	t_stack	*second;

	if ((*lst)->next->next == *lst)
	{
		*lst = (*lst)->next;
		return ;
	}
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next->prev = first;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	second->prev->next = second;
	*lst = second;
}

void	swap_bonus(t_stack **a_lst, t_stack **b_lst, char c)
{
	if (c == 'a' || c == 's')
	{
		if (!(*a_lst) || (*a_lst)->next == *a_lst)
			return ;
		swap_second_bonus(a_lst);
	}
	if (c == 'b' || c == 's')
	{
		if (!(*b_lst) || (*b_lst)->next == *b_lst)
			return ;
		swap_second_bonus(b_lst);
	}
	(void)c;
}

void	push_bonus(t_stack **src, t_stack **dest, char c)
{
	t_stack	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	if (*src == (*src)->next)
		*src = NULL;
	else
	{
		*src = temp->next;
		temp->prev->next = *src;
		(*src)->prev = temp->prev;
		temp->next = temp;
		temp->prev = temp;
	}
	add_front(&(*dest), temp);
	(void)c;
}

void	rotate_bonus(t_stack **a_lst, t_stack **b_lst, char c)
{
	if (c == 'a' || c == 'r')
	{
		if (!(*a_lst) || (*a_lst)->next == *a_lst)
			return ;
		*a_lst = (*a_lst)->next;
	}
	if (c == 'b' || c == 'r')
	{
		if (!(*b_lst) || (*b_lst)->next == *b_lst)
			return ;
		*b_lst = (*b_lst)->next;
	}
	(void)c;
}

void	reverse_rotate_bonus(t_stack **a_lst, t_stack **b_lst, char c)
{
	if (c == 'a' || c == 'r')
	{
		if (!(*a_lst) || (*a_lst)->next == *a_lst)
			return ;
		*a_lst = (*a_lst)->prev;
	}
	if (c == 'b' || c == 'r')
	{
		if (!(*b_lst) || (*b_lst)->next == *b_lst)
			return ;
		*b_lst = (*b_lst)->prev;
	}
	(void)c;
}
