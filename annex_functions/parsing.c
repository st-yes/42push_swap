/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:05:28 by styes             #+#    #+#             */
/*   Updated: 2022/07/30 04:19:12 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* check if str has a valid syntax;
* allowed syntax: A, +A, -A (with A being composed of digits [0, 9])
*/
int	valid_arg(char	*str, t_node	**stack_a)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		error(1, stack_a);
	if (i > 1)
		error(1, stack_a);
	while (ft_isdigit(str[i]) && str[i])
		i++;
	if (str[i] == '\0')
		return (1);
	error(1, stack_a);
	return (0);
}

/*
* PARSING PROTOCOL:
* must be numeric
* no duplicate
* more than one paramater
* unsorted
* in INT range
* no ""
* no "+" or "-"
*/
t_node	**parsing(int argc, char **argv)
{
	int			i;
	long		num;
	t_node		*stack_a;
	t_node		**head_a;

	i = 1;
	stack_a = create_node(int_check(ft_atoi(argv[i]), &stack_a));
	if (valid_arg(argv[i], &stack_a))
	{
		head_a = &stack_a;
		if (argc >= 3)
			num = ft_atoi(argv[++i]);
	}
	while (argc >= 3 && i < argc && valid_arg(argv[i], &stack_a))
	{
		if (!is_int(ft_atoi(argv[i])) || identical_found(&stack_a, num))
			error(1, &stack_a);
		add_node_end(&stack_a, create_node(num));
		if (++i == argc)
			break ;
		num = ft_atoi(argv[i]);
	}
	if (i != argc && argc != 2)
		error(1, &stack_a);
	return (head_a);
}
