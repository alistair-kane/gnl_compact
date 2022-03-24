/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 04:12:10 by alistair          #+#    #+#             */
/*   Updated: 2022/02/23 04:30:49 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	char	flags[255];
	int		i;
	int		j;
	
	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			flags[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while(argv[i][j])
			{
				if (!flags[(unsigned char)argv[i][j]])
				{
					flags[(unsigned char)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);	
}