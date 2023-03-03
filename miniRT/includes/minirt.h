/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:13:55 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 17:33:51 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../mlx/mlx.h"

# include "libft.h"
# include "structures.h"
# include "vector.h"
# include "parse.h"
# include "ray.h"
# include "hit.h"
# include "setting.h"
# include "key_map.h"

# define FALSE 0
# define TRUE 1
# define WIDTH	1200
# define HEIGHT	800
# define EPSILON 1e-6

# define LUMEN 3
# define SHININESS 64.0
# define SPEC_STREN 0.5

# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"

void	draw(t_info *info);

#endif
