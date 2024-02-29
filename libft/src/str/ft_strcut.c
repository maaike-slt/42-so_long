/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:22:48 by msloot            #+#    #+#             */
/*   Updated: 2024/02/29 15:45:46 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char	*str)
{
	size_t	i;
	size_t	n;
	char	*ret;

	i = 0;
	n = 0;
	if (ft_strlen(str) < 4)
		return (str);
	while (str[i + 4] != '\0')
		i++;
	if (str[i + 4] == '\0')
	{
		while (str[i] != '\0')
		{
			ret[n] = str[i];
			i++;
		}
		ret[n] = str[i];
	}
	return (ret);
}
