/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:53:51 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/18 11:28:47 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int				index_of_smallest(t_stack *stack)
{
	int		i;
	int		min;
	int		index;

	i = 0;
	min = stack->array[0];
	index = 0;
	while (i < stack->size)
	{
		if (stack->array[i] < min)
		{
			min = stack->array[i];
			index = i;
		}
		i++;
	}
	return (index);
}

t_stack			*rotate_small_numbers_to_top(t_stack *stack_a, int i, int min)
{
	if (stack_a->array[0] > min)
	{
		if (i == 1)
		{
			swap(stack_a);
			ft_putstr("sa\n");
		}
		else if (i > stack_a->size / 2)
		{
			reverse_rotate(stack_a);
			ft_putstr("rra\n");
		}
		else if (i <= stack_a->size / 2)
		{
			rotate(stack_a);
			ft_putstr("ra\n");
		}
	}
	return (stack_a);
}

t_stack			*sort_tree_last2(t_stack *s)
{
	if (s->array[0] > s->array[1] && s->array[1] < s->array[2] \
		&& s->array[0] < s->array[2])
	{
		swap(s);
		ft_putstr("sa\n");
	}
	else if (s->array[0] > s->array[1] && s->array[1] > s->array[2] \
		&& s->array[0] > s->array[2])
	{
		swap(s);
		ft_putstr("sa\n");
		reverse_rotate(s);
		ft_putstr("rra\n");
	}
	return (s);
}

t_stack			*sort_three_last_numbers_on_a(t_stack *s)
{
	if (s->array[0] < s->array[1] && s->array[1] > s->array[2] \
		&& s->array[0] > s->array[2])
	{
		reverse_rotate(s);
		ft_putstr("rra\n");
	}
	else if (s->array[0] < s->array[1] && s->array[1] > s->array[2] \
		&& s->array[0] < s->array[2])
	{
		reverse_rotate(s);
		ft_putstr("rra\n");
		swap(s);
		ft_putstr("sa\n");
	}
	else if (s->array[0] > s->array[1] && s->array[1] < s->array[2] \
		&& s->array[0] > s->array[2])
	{
		rotate(s);
		ft_putstr("ra\n");
	}
	else
		s = sort_tree_last2(s);
	return (s);
}

void			selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		min;

	while (stack_a->size > 3 && check_sorted_params(stack_a) != -1)
	{
		i = index_of_smallest(stack_a);
		min = stack_a->array[i];
		stack_a = rotate_small_numbers_to_top(stack_a, i, min);
		if (stack_a->array[0] == min && check_sorted_params(stack_a) != -1)
		{
			push(stack_a, stack_b);
			ft_putstr("pb\n");
		}
	}
	if (stack_a->size == 3)
		sort_three_last_numbers_on_a(stack_a);
	while (stack_b->size > 0)
	{
		push(stack_b, stack_a);
		ft_putstr("pa\n");
	}
}
