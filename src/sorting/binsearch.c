/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binsearch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:41:44 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/08 00:26:17 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libalgorithm.h"

int	binsearch(char array[][256], t_sizes sizes, char *key, int f(char *, char *))
{
	size_t	start;
	size_t	end;
	size_t	mid;

	start = sizes.s1;
	end = sizes.s2;
	if (end < 0 || start < 0)
		return (0);
	mid = 0;
	while (start <= end && 0 <= (long)mid)
	{
		mid = (long)(start + (end - start) / 2);
		if (0 <= (long)mid)
		{
			if (f(key, array[mid]))
				end = mid - 1;
			else
				start = mid + 1;
		}
		else
			break;
	}
	return (start);
}