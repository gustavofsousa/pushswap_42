/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:37:50 by gusousa           #+#    #+#             */
/*   Updated: 2022/11/17 14:19:41 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_index(t_list *list_a, int actual_num)
{
	int	index;

	index = 0;
	while (list_a)
	{
		if (actual_num > ft_atoi(list_a->content))
			index++;
		list_a = list_a->next;
	}
	return (index);
}

t_list	*categorize_index(t_list **list_a)
{
	t_list	*list_a_move;
	t_list	*new_list_a;
	int		n_index;
	int		actual_num;

	new_list_a = NULL;
	list_a_move = *list_a;
	while (list_a_move)
	{
		actual_num = ft_atoi(list_a_move->content);
		n_index = find_index(*list_a, actual_num);
		ft_lstadd_back(&new_list_a, ft_lstnew(ft_itoa(n_index)));
		list_a_move = list_a_move->next;
	}
	ft_lstclear(list_a, free);
	return (new_list_a);
}

int	receive_value(char **args, t_list **list_a)
{
	int	i;
	int	total_num;

	i = 1;
	while (args[i])
		i++;
	total_num = i;
	while (i--)
		ft_lstadd_front(list_a, ft_lstnew(args[i]));
	*list_a = categorize_index(list_a);
	return (total_num);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	char	**args;
	int		total_num;

	args = NULL;
	list_b = NULL;
	list_a = NULL;
	if (argc > 1 && argv)
	{
		if (check_arg(argv, argc, &args))
		{
			total_num = receive_value(args, &list_a);
			if (total_num == 3)
				sort_3(&list_a);
			else if (total_num <= 5)
				sort_5(&list_a, &list_b);
			else
				sort_big(&list_a, &list_b);
			quit(&list_a, args, 2);
		}
		else
			quit(&list_a, args, 1);
	}
	return (0);
}
