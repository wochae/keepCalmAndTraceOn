/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:25:49 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 17:35:35 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"

# include "libft.h"
# include "structures_bonus.h"
# include "vector_bonus.h"
# include "parse_bonus.h"
# include "ray_bonus.h"
# include "hit_bonus.h"
# include "setting_bonus.h"
# include "key_map_bonus.h"

# define FALSE 0
# define TRUE 1
# define WIDTH 1200
# define HEIGHT	800
# define EPSILON 1e-6

# define LUMEN 3
# define SHININESS 64.0
# define SPEC_STREN 0.5

# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"

void	draw(t_info *info);

#endif
