/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:37:50 by gusousa           #+#    #+#             */
/*   Updated: 2022/10/21 11:43:15 by gusousa          ###   ########.fr       */
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

/**
 * Eu devo pegar a lista que já tenho
 * Olhar cada numero
 * Comparar o quantos numeros são menores que ele (definir indice)
 * Colocar atrás em uma outra lista
 * Devolver a lista não organizada, em que os numeros viraram indice
 */
t_list	*categorize_index(t_list **list_a)
{
	t_list	*list_a_move;
	t_list	*new_list_a;
	int	n_index;
	int	actual_num;

	new_list_a = NULL;
	list_a_move = *list_a;
	while (list_a_move)
	{
		actual_num = ft_atoi((*list_a)->content);
		n_index = find_index(*list_a, actual_num);
		ft_lstadd_back(&new_list_a, ft_lstnew(ft_itoa(n_index)));
		list_a_move = list_a_move->next;
	}
	return (new_list_a);
}

/**
 * Conta os índices do argumento
 * *
 */
void	receive_value(char **argv, t_list **list_a)
{
	int		i;
	
	i = 1;
	//conto qtd args.
	while (argv[i])
		i++;
	// Adiciono na frente porque começo por trás.
	while (--i)
		ft_lstadd_front(list_a, ft_lstnew(argv[i]));
	*list_a = categorize_index(list_a);
}

// Checar se é valido
// Receber os valores de argv
// organizar 3
// organizar 5
// organizar all
int	main(int argc, char **argv)
{
	t_list	*list_a;
//	t_list	*list_b;

//	list_b = NULL;
	if (argc > 1 && argv)
	{
		if (check_arg(argv))
		{
			receive_value(argv, &list_a);
			/*'if (argc == 4)
				sort_3(&list_a);
			else if (argc <= 6)
				sort_5(&list_a, &list_b);
			else
				sort_big(&list_a, list_b);
*/
			ft_printf("Done\n");
		}
	}
	return (0);
}
