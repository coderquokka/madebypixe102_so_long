/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:58:54 by aperez-b          #+#    #+#             */
/*   Updated: 2021/07/28 11:05:08 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

t_vector	ft_newvector(int x, int y)
{
	t_vector	vect;

	vect.x = x;
	vect.y = y;
	return (vect);
}