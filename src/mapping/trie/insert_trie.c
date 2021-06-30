/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_trie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:51:36 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/30 17:59:48 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libalgorithm.h"
#include "libstring.h"

void	insert_trie(t_trie **root, char *cmd, int eq)
{
	t_trie	*temp;
	int		i;
	char	x;

	if (*root == NULL)
		*root = new_trie();
	i = 0;
	temp = *root;
	while (cmd[i] && i < eq)
	{
		x = cmd[i++];
		if (temp->map[(int)x] == NULL)
		{
			temp->map[(int)x] = new_trie();
			temp->children++;
		}
		temp = temp->map[(int)x];
	}
	if (temp->end)
		return ;
	temp->end = 1;
	if (cmd[eq + 1])
		temp->value = ft_strdup(&cmd[eq + 1]);
	else
		temp->value = ft_strdup("");
}
