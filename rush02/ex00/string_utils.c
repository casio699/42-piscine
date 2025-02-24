/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhoder <ahkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 04:05:23 by ahkhoder          #+#    #+#             */
/*   Updated: 2025/02/24 04:05:26 by ahkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

char	*ft_strdup(char *str)
{
	int		len;
	char	*copy;
	int		i;

	len = ft_strlen(str);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*new_str;

	new_str = malloc(n + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < n && str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
