/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:03:19 by mohel-kh          #+#    #+#             */
/*   Updated: 2025/06/10 12:51:16 by mohben-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		c;
	char	*dup;

	c = 0;
	while (s1[c] != '\0')
		c++;
	dup = (char *)ft_malloc(c * sizeof(char) + 1,'A');
	if (!dup)
		return (0);
	c = 0;
	while (s1[c] != '\0')
	{
		dup[c] = s1[c];
		c++;
	}
	dup[c] = '\0';
	return (dup);
}
