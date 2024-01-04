/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:32:30 by kmatjuhi          #+#    #+#             */
/*   Updated: 2023/12/28 11:41:26 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (temp == NULL)
	{
		printf("empty stack\n");
		return ;
	}
	printf("%ld", stack->data);
	stack = stack->next;
	while (temp != stack)
	{
		printf("%ld", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*next;

	if (argc < 2)
		return (0);
	a = stoi(argc, argv);
	if (!a)
	{
		write(2, "Error\n", 7);
		exit (0);
	}
	algo(&a);
	free_stack(&a);
	return (0);
}