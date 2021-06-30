/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libalgorithm.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:06:36 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/30 19:27:14 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBALGORITHM_H
# define LIBALGORITHM_H

# include "libstd.h"

# define KEY_SIZE 200

typedef struct s_trie
{
	t_u_char			children;
	t_u_char			end;
	struct s_trie		**map;
	char				*value;
}	t_trie;

/*
**	hash
*/

unsigned long	djb2(unsigned char *key);

/*
**	mapping
*/

/*
**	trie
*/

t_trie			*new_trie(void);
void			insert_trie(t_trie **root, char *cmd, int eq);
char			*get_value(t_trie *root, char *cmd);
void			put_trie(t_trie *root);
t_trie			**delete_value(t_trie **root, char *key);
void			delete_node(t_trie **node);
void			free_trie(t_trie **root);

#endif
