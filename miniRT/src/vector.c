#include "minirt.h"

t_point3	point3(double x, double y, double z)
{
	t_point3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_color3	color3(double x, double y, double z)
{
	t_color3	color;

	color.x = x;
	color.y = y;
	color.z = z;
	return (color);
}

void	vset(t_vec3 *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

double	vlen_d(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vlen(t_vec3 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vec3	plus(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	new;

	new.x = vec1.x + vec2.x;
	new.y = vec1.y + vec2.y;
	new.z = vec1.z + vec2.z;
	return (new);
}

t_vec3	minus(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	new;

	new.x = vec1.x - vec2.x;
	new.y = vec1.y - vec2.y;
	new.z = vec1.z - vec2.z;
	return (new);
}

double	dot(t_vec3 vec1, t_vec3 vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_vec3	cross(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3 normal;

	normal.x = vec1.y * vec2.z - vec1.z * vec2.y;
	normal.y = vec1.z * vec2.x - vec1.x * vec2.z;
	normal.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (normal);
}

t_vec3	unit(t_vec3 vec)
{
	t_vec3	new;
	double	len;

	len = vlen(vec);
	if (len == 0)
	{
		printf("Error: Devider is 0\n");
		exit(1);
	}
	new.x = vec.x / len;
	new.y = vec.y / len;
	new.z = vec.z / len;
	return (new);
}

t_vec3	mult(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	new;

	new.x = vec1.x * vec2.x;
	new.y = vec1.y * vec2.y;
	new.z = vec1.z * vec2.z;
	return (new);
}

// 벡터 스칼라 곱하기(길이 늘리기), 스칼라 나누기 ?
t_vec3	mult_t(t_vec3 vec, double t)
{
	t_vec3	new;

	new.x = vec.x * t;
	new.y = vec.y * t;
	new.z = vec.z * t;
	return (new);
}

t_vec3	devide_t(t_vec3 vec, double t)
{
	t_vec3	new;

	new.x = vec.x / t;
	new.y = vec.y / t;
	new.z = vec.z / t;
	return (new);
}