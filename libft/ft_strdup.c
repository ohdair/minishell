/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:35:37 by jaewpark          #+#    #+#             */
/*   Updated: 2022/05/03 19:35:44 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*output;
	int		i;

	if (!s)
		return (NULL);
	output = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!output)
		return (0);
	i = -1;
	while (s[++i])
		output[i] = s[i];
	output[i] = '\0';
	return (output);
}
