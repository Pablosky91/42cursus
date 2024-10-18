/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:45:17 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:17 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**free_all(char **words, size_t count);
static char		**copy_words(char **words, char const *s, char c);
static size_t	count_words(char const *s, char c);

/*
Allocates (with malloc(3)) and returns an array of strings obtained
	by splitting ’s’ using the character ’c’ as a delimiter.
The array must end with a NULL pointer.
*/
char	**ft_split(char const *s, char c)
{
	char	**words;

	words = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!words)
		return (0);
	words = copy_words(words, s, c);
	return (words);
}

static char	**free_all(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}

static char	**copy_words(char **words, char const *s, char c)
{
	size_t	start_word;
	size_t	word_len;
	size_t	i;
	size_t	num_word;

	start_word = 0;
	word_len = 0;
	i = 0;
	num_word = 0;
	while (i <= ft_strlen(s))
	{
		if ((s[i] == c || !s[i]) && word_len)
		{
			words[num_word] = ft_substr(s, start_word, word_len);
			if (!words[num_word])
				return (free_all(words, num_word));
			word_len = 0;
			num_word++;
		}
		else if (s[i] != c)
			if (!word_len++)
				start_word = i;
		i++;
	}
	return (words);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		is_start_word;
	size_t	i;

	count = 0;
	is_start_word = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && !is_start_word)
			is_start_word = 1;
		else if (s[i] != c && is_start_word)
		{
			is_start_word = 0;
			count++;
		}
		i++;
	}
	return (count);
}
