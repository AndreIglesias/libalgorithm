/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:00:09 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/01 17:38:27 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libalgorithm.h"

static void	set_map(struct s_map *map, char *key, char *value)
{
	insert_trie_pair(&map->root, key, value);
}

static char	*get_map(struct s_map *map, char *key)
{
	return (get_value(map->root, key));
}

static void	destruct_map(struct s_map *map)
{
	free_trie(&map->root);
}

t_map	new_map(void)
{
	t_map	map;

	map.root = new_trie();
	map.set = &set_map;
	map.get = &get_map;
	map.destructor = &destruct_map;
	return (map);
}
