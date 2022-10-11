/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmas <eelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:11:51 by eelmas            #+#    #+#             */
/*   Updated: 2022/10/10 10:00:55 by eelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//bu fonksiyon kesme işlemi yapılabilir mi diye bakıyor

static int	ft_is_trim_possible(char c, char const *set)
{
	int	count;

	count = -1;
	while (set[++count])
		if (set[count] == c)
			return (1);
	return (0);
}
//bu fonksiyon kesilmiş stringin uzunluğunu alıyor

static int	ft_get_size(char const *s1, char const *set)
{
	int	count;
	int	size;

	size = ft_strlen(s1);
	count = 0;
	while (ft_is_trim_possible(s1[size - count - 1], set))
		count++;
	return (size - count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		count;
	int		size;
	char	*tab;

	count = 0;
	size = 0;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	while (ft_is_trim_possible(s1[count], set))
		count++;
	if (count == (int)ft_strlen(s1))
		return (ft_strdup(""));
	size = ft_get_size(s1 + count, set) + 1;
	tab = (char *)malloc((size) * sizeof(char));
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, s1 + count, size);
	return (tab);
}

//bu fonksiyon malloc() ile hafıza alanı ayırarak başından ve 
//sonundan belirtilen karakterleri kesilmiş stringi döndürür.
