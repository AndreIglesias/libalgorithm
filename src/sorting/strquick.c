/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:20:41 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/03 21:09:25 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libalgorithm.h"

static void	swap(char **list, size_t a, size_t b)
{
	char	*tmp;

	tmp = list[a];
	list[a] = list[b];
	list[b] = tmp;
}

static int	partit(char **list, int low, int high, int f(char *, char *))
{
	char	*pivot;
	int		i;
	int		j;

	pivot = list[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (f(list[j], pivot))
		{
			swap(list, i, j);
			i++;
		}
		j++;
	}
	swap(list, i, high);
	return (i);
}

static void	quick(char **list, int low, int high, int f(char *, char *))
{
	int	part;

	if (low < high)
	{
		part = partit(list, low, high, f);
		quick(list, low, part - 1, f);
		quick(list, part + 1, high, f);
	}
}

void	strquick(char **list, size_t size, int f(char *, char *))
{
	quick(list, 0, size - 1, f);
}
