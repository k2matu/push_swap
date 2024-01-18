/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:50:16 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/18 13:44:03 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lst_to_arr(t_stack **a, int count)
{
	t_stack	*temp;
	int		*arr;
	int		i;

	i = 0;
	temp = *a;
	arr = (int *)malloc(sizeof(int) * count);
	if (!arr)
	{
		free_stack(a);
		exit (-1);
	}
	while (i < count)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
	return (arr);
}

void	fill_stack_pos(t_stack **a, int *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		while (arr[j] != (*a)->data)
			j++;
		if (arr[j] == (*a)->data)
			(*a)->pos = j;
		*a = (*a)->next;
		j = 0;
		i++;
	}
}

void	push_to_stack_b(int *lis, t_stack **a, t_stack **b, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < count)
	{
		if (lis[j] == (*a)->data)
		{
			rotate(&(*a), &(*b), 'a');
			j++;
		}
		else
			push(&(*a), &(*b), 'b');
	}
}

void	sort_big(t_stack **a, int count)
{
	t_stack	*b;
	int		*lis;
	int		*arr;
	int		min_pos;

	b = NULL;
	arr = lst_to_arr(a, count);
	lis = get_lis(arr, count);
	quick_sort(arr, count);
	fill_stack_pos(&(*a), arr, count);
	free(arr);
	push_to_stack_b(lis, &(*a), &b, count);
	free(lis);
	while (b)
	{
		min_pos = cheapest_number(&(*a), &b);
		push_back(&(*a), &b, min_pos);
	}
	rotate_a_back(&*a, count_nodes(*a));
}
