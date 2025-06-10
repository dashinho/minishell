/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:43:27 by mohel-kh          #+#    #+#             */
/*   Updated: 2025/06/10 12:50:40 by mohben-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && !(s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
	{
		if (is_quote(s[i]))
			i = skip_quote(s, i);
		else
			i++;
	}
	return (i);
}

static int	count_words(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
			i++;
		if (!s[i])
			break ;
		count++;
		i += get_word_len(&s[i]);
	}
	return (count);
}

static char	*copy_word(const char *s, int len)
{
	char	*word;
	char	quote;

	int (i), (j);
	word = (char *)ft_malloc(len + 1,'A');
	i = 0;
	j = 0;
	if (!word)
		return (NULL);
	while (i < len)
	{
		if (is_quote(s[i]))
		{
			quote = s[i++];
			word[j++] = quote;
			while (s[i] && s[i] != quote)
				word[j++] = s[i++];
			if (s[i] == quote)
				word[j++] = s[i++];
		}
		else
			word[j++] = s[i++];
	}
	word[j] = '\0';
	return (word);
}

static void	*free_all(char **arr, int count)
{
	while (--count >= 0)
		free(arr[count]);
	free(arr);
	return (NULL);
}

char	**ft_split_space(const char *s)
{
	char	**res;

	int (i), (j), (len);
	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	res = ft_malloc(sizeof(char *) * (count_words(s) + 1),'A');
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
			i++;
		if (!s[i])
			break ;
		len = get_word_len(&s[i]);
		res[j] = copy_word(&s[i], len);
		if (!res[j])
			return (free_all(res, j));
		i += len;
		j++;
	}
	res[j] = NULL;
	return (res);
}
