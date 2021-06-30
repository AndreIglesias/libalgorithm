/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djb2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:10:31 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/30 15:17:10 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	k = 33 ;((hash << 5) + hash)
*/

unsigned long	djb2(unsigned char *key)
{
	unsigned long	hash;

	hash = 5381;
	while (*key)
		hash = ((hash << 5) + hash) + *key++;
	return (hash);
}
