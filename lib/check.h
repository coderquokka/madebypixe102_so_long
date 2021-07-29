/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 18:52:18 by aperez-b          #+#    #+#             */
/*   Updated: 2021/07/29 10:43:56 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H

# define CHECK_H

# include "errors.h"
# include <fcntl.h>
# include "../libft/lib/libft.h"
# include "map.h"

char	**check_params(int argc, char **argv, t_lay *lay);
char	**check_map(int fd, t_lay *lay);

#endif