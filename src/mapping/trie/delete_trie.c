/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_trie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:03:10 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/30 19:24:45 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libalgorithm.h"
#include "libstring.h"

void	delete_node(t_trie **node)
{
	if ((*node)->value)
	{
		free((*node)->value);
		(*node)->value = NULL;
	}
	if ((*node)->map)
		free((*node)->map);
	(*node)->map = NULL;
	if (*node)
		free(*node);
	*node = NULL;
}

static t_trie	**rdelete_value(t_trie **root, char *key, int len, int depth)
{
	if (*root == NULL)
		return (NULL);
	if (depth == len)
	{
		if ((*root)->end)
			(*root)->end = 0;
		if ((*root)->value)
		{
			free((*root)->value);
			(*root)->value = NULL;
		}
		if ((*root)->children == 0)
			delete_node(root);
		return (root);
	}
	if ((*root)->map[(int)key[depth]])
	{
		(*root)->map[(int)key[depth]] = *rdelete_value(
				&(*root)->map[(int)key[depth]], key, len, depth + 1);
		if ((*root)->map[(int)key[depth]] == NULL)
			(*root)->children--;
	}
	if ((*root)->children == 0 && (*root)->end == 0)
		delete_node(root);
	return (root);
}

t_trie	**delete_value(t_trie **root, char *key)
{
	return (rdelete_value(root, key, ft_strlen(key), 0));
}
