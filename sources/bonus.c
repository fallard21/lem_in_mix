/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:43:44 by fallard           #+#    #+#             */
/*   Updated: 2020/10/15 19:59:32 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "lem_in.h"

void	put_usage(char *av)
{
	if (av)
	{
		write(2, "lem-in: invalid key: '", 23);
		write(2, av, ft_strlen(av));
		write(2, "'\n", 3);
	}
	write(2, "Usage:\n", 8);
	write(2, "\t./lem-in < map\n\t./lem-in -p < map\n", 36);
	write(2, "\t-p\tprint path's\n", 18);
	exit(EXIT_FAILURE);
}

void	ft_parse_flags(int *key_p, int ac, char *av)
{
	if (ac > 2)
		put_usage(NULL);
	else if (ft_strcmp(av, "-p") == 0)
		*key_p = 1;
	else
		put_usage(av);
}

void	ft_print_path(t_frame *frame, t_path *p)
{
	t_link	*tmp;
	int		i;

	i = 0;
	while (p)
	{
		ft_printf("%d) Path size: %d | %s\n\t", i + 1, p->len,
			(p->ants_togo) ? "USED" : "UNUSED");
		tmp = p->start;
		while (tmp)
		{
			if (!tmp->next)
				ft_printf("%s", tmp->room->name);
			else
				ft_printf("%s -> ", tmp->room->name);
			tmp = tmp->next;
		}
		p = p->next;
		i++;
		ft_printf("\n");
	}
	ft_printf("Number of steps: %d\n\n", frame->current_steps);
}
