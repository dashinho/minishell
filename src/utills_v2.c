/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:26:56 by mohben-t          #+#    #+#             */
/*   Updated: 2025/06/10 14:02:04 by mohben-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list *test;

static size_t	ft_countword(char const *s, char const *delimiter)
{
	size_t	count;
	size_t	delimiter_len;

	if (!*s)
		return (0);
	count = 0;
	delimiter_len = ft_strlen(delimiter);
	while (*s)
	{
		while (ft_strncmp(s, delimiter, delimiter_len) == 0)
			s += delimiter_len;
		if (*s)
			count++;
		while (*s && ft_strncmp(s, delimiter, delimiter_len) != 0)
			s++;
	}
	return (count);
}

char	**ft_split_a(char const *s, char const *delimiter)
{
	char	**lst;
	size_t	word_len;
	size_t	delimiter_len;
	int		i;

	if (!s || !delimiter)
		return (NULL);
	delimiter_len = ft_strlen(delimiter);
	lst = (char **)ft_malloc((ft_countword(s, delimiter) + 1) * sizeof(char *),'A');
	if (!lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && ft_strncmp(s, delimiter, delimiter_len) == 0)
			s += delimiter_len;
		if (*s)
		{
			char *next_delim = ft_strnstr(s, delimiter, ft_strlen(s));
			if (!next_delim)
				word_len = ft_strlen(s);
			else
				word_len = next_delim - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}
void free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	split = NULL;
}

// void *ft_malloc(size_t size, char flag)
// {
// 	static t_list *head;
// 	static int i = 0;
// 	void *set;

// 	set = NULL;

// 	if (flag == 'A')
// 	{
// 		set = malloc(size);
// 		if (!set)
// 			return (NULL);
// 		printf("%d\n", i);
// 		ft_lstadd_back(&head, ft_lstnew(set));
// 		i++;
// 	}
// 	else
// 	{
// 		int count1 = 0;
// 		int count = 0;
// 		int count3 = 0;
// 		t_list *itt = head;
// 		while(itt)
// 		{
// 			count += 1;
// 			itt = itt->next;
// 		}
// 		printf("count: %d\n", count);
// 		t_list *tmp;
// 		while (head)
// 		{
// 			tmp = head->next;
			
// 			free(head->content);
// 			free(head);
// 			head = NULL;
// 			if(head)
// 			{
// 				printf("freeyini");
// 				count1 += 1;
// 			}
// 			head = tmp;
// 			count3 += 1;
// 		}
// 		printf("count1: %d\n", count1);
// 		printf("count3: %d\n", count3);

// 	}
// 	return set;
// }
void *ft_malloc(size_t size, char flag)
{
    static int i = 0;
    void *set = NULL;
    
    if (flag == 'A')
    {
        set = malloc(size);
        if (!set)
            return (NULL);
        printf("%d\n", i);
        ft_lstadd_back(&test, ft_lstnew(set));
        i++;
    }
    else
    {
        int count = 0;
        int count3 = 0;
        t_list *itt = test;
        
        // Count nodes
        while(itt)
        {
            count += 1;
            itt = itt->next;
        }
        printf("count: %d\n", count);
        
        // Free all nodes
        t_list *tmp;
        while (test)
        {
            tmp = test->next;
            free(test->content);
			if(test->content)
				test->content = NULL;
            free(test);
			if(test)
				test = NULL;
           test = tmp;
            count3 += 1;
        }
		free(test);
        test = NULL;
        printf("count3: %d\n", count3);
        i = 0;  // Reset counter since all memory is freed
    }
    return set;
}
int	is_all_whitespace(const char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0); // Found a non-whitespace character
		i++;
	}
	return (1); // All whitespace or empty
}
