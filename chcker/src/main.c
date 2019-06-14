/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 14:30:09 by lgaultie          #+#    #+#             */
/*   Updated: 2019/06/14 14:32:04 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int					main(int argc, char **argv)
{
	if (argc == 2 && ft_strcmp(argv[1], "-v") == 0)
		return (0);
	if (argc <= 1)
		return (0);
	create_stacks(argc, argv);
	return (0);
}
