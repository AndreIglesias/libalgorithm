/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libalgorithm.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:06:36 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/01 18:32:21 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBALGORITHM_H
# define LIBALGORITHM_H

# include "libstd.h"
# include "libtypes.h"

# define KEY_SIZE 200

typedef struct s_map
{
	t_trie				*root;
	void				(*set)(struct s_map *, char *, char *);
	char				*(*get)(struct s_map *, char *);
	void				(*destructor)(struct s_map *);
}	t_map;

/*
**	hash
*/

unsigned long	djb2(unsigned char *key);

/*
**	mapping
*/

t_map			new_map(void);

/*
**	trie
*/

t_trie			*new_trie(void);
void			insert_trie(t_trie **root, char *cmd, int eq);
void			insert_trie_pair(t_trie **root, char *key, char *value);
char			*get_value(t_trie *root, char *cmd);
void			put_trie(t_trie *root);
t_trie			**delete_value(t_trie **root, char *key);
void			delete_node(t_trie **node);
void			free_trie(t_trie **root);

#endif
