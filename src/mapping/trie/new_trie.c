/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_trie.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:18:25 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/30 19:26:19 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libalgorithm.h"
#include "libstring.h"

t_trie	*new_trie(void)
{
	t_trie	*new;

	new = (t_trie *)malloc(sizeof(t_trie));
	if (!new)
		return (NULL);
	new->map = (t_trie **)malloc(sizeof(t_trie *) * 127);
	if (!new->map)
		return (NULL);
	ft_memset(new->map, 0, sizeof(t_trie *) * 127);
	new->end = 0;
	new->children = 0;
	new->value = NULL;
	return (new);
}
