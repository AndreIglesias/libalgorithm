/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binsert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:33:22 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/08 00:26:11 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libalgorithm.h"

#include "libstring.h"
#include "libstd.h"

void	binsert(char list[][256], char *str, size_t size, int f(char *, char *))
{
	size_t pos;

	pos = 0;
	if (size)
		pos = binsearch(list, (t_sizes){0, size - 1}, str, f);
	strins(list, str, pos, size);
}
