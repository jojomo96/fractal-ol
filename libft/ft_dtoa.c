/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:11:58 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/07 13:27:37 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

static void	reverse_string(char *str, int length)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

static void	convert_num_to_str(int num, char *str, int *str_index)
{
	int	rem;

	while (num != 0)
	{
		rem = num % 10;
		if (rem > 9)
			str[(*str_index)++] = (rem - 10) + 'a';
		else
			str[(*str_index)++] = rem + '0';
		num = num / 10;
	}
}

static void	ft_int_to_str(int num, char *str, int *str_index)
{
	int	i;
	int	is_negative;

	i = 0;
	is_negative = 0;
	if (num == 0)
	{
		str[(*str_index)++] = '0';
		return ;
	}
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	convert_num_to_str(num, str, str_index);
	if (is_negative)
		str[(*str_index)++] = '-';
	reverse_string(str, *str_index);
}

// Main function to convert double to string
void	ft_dtoa(double n, char *res, int afterpoint)
{
	int	ipart;
	int	fpart;
	int	i;

	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	ipart = (int)n;
	fpart = n - (double)ipart;
	i = 0;
	if (res[0] == '-')
		i = 1;
	ft_int_to_str(ipart, res + i, &i);
	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * pow(10.0, afterpoint);
		ft_int_to_str((int)fpart, res + i + 1, &i);
	}
}
