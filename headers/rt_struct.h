/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 22:43:33 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/02 21:47:52 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCT_H
# define RT_STRUCT_H
# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <float.h>
# include <pthread.h>

typedef struct	s_3loop
{
	int			i;
	int			j;
	int			k;
}				t_3loop;

typedef struct	s_com
{
	double		im;
	double		re;
}				t_com;

typedef	struct	s_ipoint
{
	int			x;
	int			y;
}				t_ipoint;

typedef	struct	s_dpoint
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_vector
{
	double		v1;
	double		v2;
	double		v3;
}				t_vector;

# define VEC(a, b, c) (t_vector){a, b, c}

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

# define COL(a, b, c) (t_color){a, b, c}

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	dir;
}				t_ray;

typedef struct	s_cubic
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		sq_a;
	double		p;
	double		q;
	double		cb_p;
}				t_cubic;

typedef struct	s_quartic
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		z;
	double		u;
	double		v;
	double		sub;
	double		sq_a;
	double		p;
	double		q;
	double		r;
}				t_quartic;

typedef struct	s_moebius
{
	double		a;
	double		ax;
	double		ay;
	double		az;
	double		bx;
	double		by;
	double		bz;
}				t_moebius;

typedef struct	s_cell
{
	float		mindisttocell;
	t_vector	base;
	t_vector	toclosest;
	t_vector	closest;
}				t_cell;

typedef struct	s_cell2
{
	t_vector	cell;
	t_vector	cellposition;
	t_vector	tocell;
	t_vector	diff;
	t_vector	tocenter;
	t_vector	celldifference;
	float		edgedistance;
}				t_cell2;

typedef struct	s_voronoi
{
	float		valuechange;
	float		isborder;
	t_vector	cellcolor;
	t_vector	value;
	t_vector	noise;
}				t_voronoi;

typedef struct	s_perlin
{
	t_vector	*ranvec;
	int			*perm_x;
	int			*perm_y;
	int			*perm_z;
}				t_perlin;

typedef	struct	s_texture
{
	int			is_txt;
	SDL_Surface	*surface;
	Uint32		*data;
	double		scale;
}				t_texture;

typedef struct	s_noise
{
	int			is_noise;
	int			type;
	double		scale1;
	double		scale2;
	t_color		col1;
	t_color		col2;
	t_perlin	p;
}				t_noise;

typedef struct	s_o
{
	t_texture	txt;
	t_noise		noi;
	t_vector	pos;
	t_vector	rot;
	t_vector	i;
	t_vector	j;
	t_vector	k;
	t_vector	ex_rot;
	t_color		col;
	double		size;
	double		height;
	double		weight;
	double		ka;
	double		kd;
	double		ks;
	double		ke;
	double		kr;
	char		*name;
	char		rotaxis;
	int			spec;
	int			(*hit)();
	struct s_o	*cont;
	struct s_o	*next;
}				t_object;

typedef	struct	s_interval
{
	double		t_min;
	double		t_max;
}				t_interval;

# define I(a, b) (t_interval){a, b}

typedef struct	s_phong
{
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
}				t_phong;

typedef	struct	s_l
{
	t_vector	pos;
	t_vector	dir;
	t_ipoint	soft;
	t_color		col;
	double		intensity;
	double		flashlight;
	double		angle;
	int			type;
	struct s_l	*next;
}				t_light;

typedef struct	s_hit
{
	t_object	*curr_obj;
	t_object	cap;
	t_vector	p;
	t_vector	n;
	t_vector	oc;
	t_vector	temp;
	t_vector	d;
	t_vector	i;
	t_vector	j;
	t_color		col;
	t_ray		ray;
	double		u;
	double		v;
	double		t;
	double		m0;
	double		m1;
	double		a;
	double		b;
	double		c;
	double		t0;
	double		t1;
	double		delta;
	int			surface;
	int			(*hit)();
}				t_hit;

typedef struct	s_camera
{
	t_vector	origin;
	t_vector	lower_left_corner;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	lookat;
	t_vector	w;
	t_vector	u;
	t_vector	v;
	double		fov;
	double		half_h;
	double		half_w;
}				t_camera;

typedef struct	s_scene
{
	t_camera	cam;
	t_light		*light;
	t_object	*object;
	t_object	*curr_object;
	t_hit		record;
	double		theta;
	double		anti_a;
	double		amb;
	double		speed;
	int			col;
	int			row;
}				t_scene;

typedef struct	s_ptr
{
	void		*win;
	void		*mlx;
	void		*img;
	int			*data;
	int			bpp;
	int			size;
	int			endian;
	char		*save_img;
	int			cam_slct;
	int			light_slct;
	int			inc_dec;
	int			filter;
	t_light		*curr_light;
	t_scene		*scene;
	void		*bgimg;
	int			*bgdata;
	int			do_mb;
}				t_ptr;

typedef struct	s_load
{
	void	*img;
	int		*data;
	int		tmp;
	int		tmp2;
	int		inc;
	int		count;
	int		row;
	int		col;
	t_ptr	*p;
}				t_load;

typedef struct	s_thread
{
	int			i;
	int			*inc;
	int			*count;
	t_ptr		*e;
	t_scene		*scene;
}				t_thread;

typedef struct	s_var
{
	double		m;
	double		n;
	double		o;
	double		p;
	int			a;
	int			i;
	int			k;
	t_interval	t;
	t_ray		*ray;
}				t_var;

#endif
