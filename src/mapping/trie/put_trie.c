/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_trie.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:15:26 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/30 18:49:37 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libalgorithm.h"

static void	rput_trie(t_trie *root, char *str, int lvl)
{
	int		i;

	if (root->end)
	{
		str[lvl] = 0;
		ft_putstr(str);
		ft_putstr("=");
		ft_putstr(root->value);
		ft_putchar('\n');
		return ;
	}
	i = 0;
	while (i < 127)
	{
		if (root->children && root->map[i])
		{
			str[lvl] = (char)i;
			str[lvl + 1] = 0;
			rput_trie(root->map[i], str, lvl + 1);
		}
		i++;
	}
}

void	put_trie(t_trie *root)
{
	char	str[KEY_SIZE];

	rput_trie(root, str, 0);
}
