/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_trie.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:02:29 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/30 18:03:36 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libalgorithm.h"

char	*get_value(t_trie *root, char *cmd)
{
	t_trie	*temp;
	int		i;
	char	x;

	if (root == NULL)
		return (NULL);
	i = 0;
	temp = root;
	while (cmd[i])
	{
		x = cmd[i];
		temp = temp->map[(int)x];
		if (temp == NULL)
			return (NULL);
		i++;
	}
	if (temp->end)
		return (temp->value);
	return (NULL);
}
