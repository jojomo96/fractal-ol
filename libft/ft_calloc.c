/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:10:48 by jmoritz           #+#    #+#             */
/*   Updated: 2024/03/07 00:10:51 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates memory for an array of elements, each with a size of `size`,
 * and initializes all bytes to zero.
 *
 * @param count The number of elements to allocate memory for.
 * @param size The size of each element in bytes.
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (size && count > SIZE_MAX / size)
	{
		return (NULL);
	}
	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr)
		ft_memset(ptr, 0, total_size);
	return (ptr);
}
