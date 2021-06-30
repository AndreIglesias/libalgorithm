/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k24.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:08:18 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/30 17:09:51 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	k =  24
**	char		**tab = (char **)calloc(16777213, sizeof(char *));
**	tab[hash(line)] = "str"
*/

unsigned int	k24(const char *key)
{
	unsigned int	hash;

	hash = 5031;
	while (*key)
		hash = (hash * 101) + *key++;
	return (hash % 16777213);
}
