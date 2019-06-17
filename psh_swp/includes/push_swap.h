/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:21:05 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/17 17:33:12 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "../../libft/libft.h"
# include <stdio.h>

typedef struct	s_stack
{
	int			*array;
	int			size;
}				t_stack;

t_stack			*init_stack_a(t_stack *stack, int argc, char **argv);
long			modified_atoi(const char *str);
int				duplic(t_stack *stack, int index);
void			print_tab(t_stack *stack);
void 			selection_sort(t_stack *stack_a, t_stack *stack_b);
t_stack			*sort_three_last_numbers_on_a(t_stack *stack);
t_stack			*sort_three_last_numbers_on_a2(t_stack *stack_a);
void			quicksort(t_stack *stack_a, t_stack *stack_b);
int				find_median(t_stack *stack);
void			reverse_rotate(t_stack *stack);
void			push(t_stack *from, t_stack *dest);
void			rotate(t_stack *stack);
void			swap(t_stack *stack);
void			free_tab(char **tab);
void			which_sort(t_stack *stack_a, t_stack *stack_b);
int				check_sorted_params(t_stack *stack);

#endif
