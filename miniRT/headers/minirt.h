#ifndef MINIRT_H
# define MINIRT_H

# include "structures.h"

typedef enum e_obj
{
	SPHERE,
	PLANE,
	CYLINDER,
	CAMERA,
	LIGHT,
}	t_object_type;

typedef enum e_info_type
{
	AMB = 0x0001,
	CAM = 0x0002,
	LIT = 0x0004,
}	t_info_type;



#endif