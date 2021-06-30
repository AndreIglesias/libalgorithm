/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_trie.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:00:36 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/30 19:01:32 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libalgorithm.h"

void	free_trie(t_trie **root)
{
	int		i;

	if (!(*root)->children)
	{
		delete_node(root);
		return ;
	}
	i = 0;
	while (i < 127)
	{
		if ((*root)->children && (*root)->map[i])
		{
			free_trie(&(*root)->map[i]);
			(*root)->children--;
		}
		i++;
	}
	delete_node(root);
	return ;
}
