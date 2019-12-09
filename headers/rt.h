/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:10:19 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/02 23:34:03 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <SDL.h>
# include <SDL_image.h>
# include <SDL_mixer.h>
# include "rt_define.h"
# include "rt_struct.h"

typedef t_vector	(*t_r)(t_vector, double);

int			ft_solve_cubic(double w[4], double s[3]);
int			ft_solve_quartic(double w[5], double s[4]);
int			ft_solve_quadric(double c[3], double s[2]);

t_color		ft_get_noise(t_object *o, t_hit *rec, t_noise *noise);

void		*ft_loading(t_load *t);
void		ft_starting(t_ptr *p, int longg);

void		ft_perlin_init(t_perlin *plin);
float		ft_noise(t_perlin *p, t_vector v);
float		ft_perlin_noise(t_perlin *p, t_vector v, int depth);
t_color		ft_voronoi_noise(t_vector p, t_color c_border, t_noise *noise);

t_color		ft_lerp(t_color a, t_color b, float f);
double		ft_frac(double value);
float		ft_step(float a, float x);
float		ft_smoothstep(float a, float b, float x);

float		ft_rand1dto1d(float value, float mutator);
t_vector	ft_rand1dto3d(float value);
float		ft_rand3dto1d(t_vector value, t_vector dot_dir);
t_vector	ft_rand3dto3d(t_vector value);

char		*ft_copy_imgdata(int *img, int width, int height);
void		ft_filter_cartoon(int *data);
void		ft_filter_mb(int *data);
void		ft_filter_mb1(t_ptr *p, int *data);
void		ft_set_filter(t_color *c, int filter);

t_color		ft_get_texture(t_texture *t, double *u, double *v);

double		ft_clamping(double value);
int			ft_clamp_int(int value, int min, int max);
t_vector	ft_rand_in_sphere(t_vector center, double radius);
t_vector	ft_reflect(t_vector v, t_vector n);
void		ft_adjustment(t_color *c);
int			ft_shading(t_scene *scene, t_vector light, t_light *l);
t_color		diffuse(t_scene *s, t_light *l);
t_color		specular(t_scene *s, t_light *l);
void		ft_lighting(t_scene *s, t_light *l, t_color *col);

void		ft_add_camera(t_ptr *p, int fd, char **line, int t);
void		ft_get_object(t_ptr *p, t_object *obj, int fd, char **line);
void		ft_add_object(t_ptr *p, int fd, char **line, int t);
void		ft_add_light(t_light *light[2], t_ptr *p, int fd, char **line);
int			ft_get_data(t_ptr *p, int fd, int n1, int n2);

void		ft_do_rot(t_ptr *p, t_vector *ret, char **each);
t_vector	ft_linetorot(t_ptr *p, char **line, int free_it);
t_vector	ft_linetovec(t_ptr *p, char **line, int free_it);
t_color		ft_linetocol(t_ptr *p, char **line, int free_it);
void		ft_linetotxt(t_texture	*txt, t_ptr *p, char **line, int free_it);
void		ft_linetonoise(t_noise	*noi, t_ptr *p, char **line, int free_it);
void		ft_linetosize(t_object *o, t_ptr *p, char **line, int free_it);
double		ft_linetod(t_ptr *p, char **line, int free_it);
t_ipoint	ft_linetosoft(t_ptr *p, char **line, int free_it);
void		ft_linetocoef(t_object *o, t_ptr *p, char **line, int free_it);
void		ft_check_data(t_ptr *p);
int			ft_parser(t_ptr *p, char *chemin);

double		ffmin(double a, double b);
double		ffmax(double a, double b);
t_color		ft_tracer(t_thread *p, t_ray *r, int d);
t_color		ft_ray_tracer(t_thread *p, double col, double row);
void		*ft_calcul(t_thread *p);
void		ft_begin(t_ptr *p);
int			ft_draw(t_ptr *p);

int			ft_delete_object(t_object **list, t_object **to_delete);
void		ft_select_obj(t_ptr *p, int col, int row);
void		ft_selected_event(int key, t_ptr *p);
int			ft_menu_event(int key, t_ptr *p);

void		ft_save_img(t_ptr *p);
void		ft_save_video(t_ptr *p);
void		ft_free_exit(char *display, int err, t_ptr **p);
void		ft_cam_rotation(int key, t_ptr *p);
void		ft_cam_light_event(int key, t_ptr *p);
int			ft_close(t_ptr *p);
int			ft_deal_key(int key, t_ptr *p);
int			ft_mouse_press(int button, int x, int y, t_ptr *p);
void		ft_perror_exit(void);

void		ft_mlx_putpixel(t_ptr *p, int x, int y, int color);
void		ft_create_image(t_ptr *p);
void		ft_init(t_ptr *p);
void		ft_background(t_ptr *p);

int			ft_hit(t_scene *s, t_ray r, t_interval t, t_hit *h);
int			ft_hit_sphere(t_object *o, t_ray *r, t_interval t, t_hit *h);
int			ft_hit_cylinder(t_object *o, t_ray *r, t_interval t, t_hit *h);
int			ft_hit_disk(t_object *o, t_ray *r, t_interval t, t_hit *h);
int			ft_hit_cone(t_object *o, t_ray *r, t_interval t, t_hit *h);
int			ft_hit_plane(t_object *o, t_ray *r, t_interval t, t_hit *h);
int			ft_hit_torus(t_object *o, t_ray *r, t_interval t, t_hit *rrr);
int			ft_hit_paraboloid(t_object *obj, t_ray *ray,
		t_interval t, t_hit *rrr);
int			ft_hit_hyperboloid(t_object *o, t_ray *ray, t_interval t, t_hit *r);
void		ft_init_pcube(t_object *o, t_ray *ray, double c[5]);
int			ft_hit_perforated_cube(t_object *o, t_ray *ray,
		t_interval t, t_hit *r);
int			ft_hit_moebius(t_object *o, t_ray *ray, t_interval t, t_hit *r);

void		ft_plane_mapping(t_hit *rec, t_object *o);

void		ft_free_objects(t_object **object, void *mlx, int end);
void		ft_free_lights(t_light **light);
t_light		*ft_copy_lights(t_light *old);
t_object	*ft_copy_objects(t_object *old);
t_scene		*ft_copy_scene(t_scene *old);
t_ptr		*ft_copy_ptr(t_ptr *old);

t_camera	ft_init_camera(t_vector lookfrom, t_vector lookat, double vfov);
t_scene		*ft_init_scene();
t_vector	ft_vector(double x, double y, double z);
t_vector	ft_add(t_vector a, t_vector b);
t_vector	ft_sub(t_vector a, t_vector b);
t_vector	ft_div(t_vector a, t_vector b);
t_vector	ft_pro(t_vector a, t_vector b);
t_vector	ft_normalize(t_vector a);
t_vector	ft_pro_k(t_vector a, double k);
t_vector	ft_div_k(t_vector a, double k);
t_vector	ft_cross(t_vector a, t_vector b);
t_vector	ft_vfloor(t_vector v);
t_vector	ft_vabs(t_vector v);
t_vector	ft_coltovec(t_color c);
t_color		ft_vectocol(t_vector v);
double		ft_dot(t_vector a, t_vector b);
double		ft_length(t_vector a);
double		ft_lengthsquared(t_vector a);
double		ft_angle_between(t_vector a, t_vector b);

t_color		ft_add_c(t_color a, t_color b);
t_color		ft_div_kc(t_color a, double k);
t_color		ft_pro_c(t_color a, t_color b);
t_color		ft_add_kc(t_color a, double k);
t_color		ft_pro_kc(t_color a, double k);

t_ray		ft_ray(t_vector a, t_vector b);
t_ray		ft_get_ray(t_camera *p, double u, double v);
t_vector	ft_ray_function(t_ray *r, double t);
double		ffmin(double a, double b);
double		ffmax(double a, double b);

t_vector	ft_rot_x(t_vector old, double theta);
t_vector	ft_rot_y(t_vector old, double theta);
t_vector	ft_rot_z(t_vector old, double theta);
t_vector	ft_rotcam_y(t_vector old, double theta);
t_vector	ft_rotcam_x(t_vector old, double theta);

int			ft_bg_col(int bg, int x, int y);
void		ft_object_selected(t_ptr *p);
void		ft_display_properties(t_ptr *p);
void		ft_display_moves(t_ptr *p);
void		ft_background(t_ptr *p);
char		*ft_ctoa(t_color c);
char		*ft_vtoa(t_vector v);
void		ft_menu_bar(t_ptr *p);

void		ft_vects_1(t_object *o);
void		ft_vects_2(t_object *o);
void		ft_fin(t_object *o);
t_vector	ft_rot_vec(t_vector a, t_vector b, double t);
double		ft_xz_angle(t_vector v);
double		ft_yz_angle(t_vector v);
double		ft_xy_angle(t_vector v);
void		ft_move_triangle(t_object *o);
void		ft_vects(t_object *obj);
void		ft_detect(t_object *new, t_object *old, int x);
void		ft_add_conts(t_object *o, t_vector r, int x, t_object *tete);
void		ft_pos(t_object *o);
int			ft_rot_obj(t_ptr *p, t_vector (*ft_rot)(t_vector, double));
int			ft_hit_triangle(t_object *o, t_ray *r, t_interval t, t_hit *rrr);
int			ft_hit_cube(t_object *o, t_ray *r, t_interval t, t_hit *rec);
int			ft_fix_rec(t_hit *o, t_hit *new);
void		ft_free_conts(t_object	**object);
void		*ft_copy_conts(t_object *old, t_object *new);
void		ft_cube_ijk(t_object *obj);
void		ft_plane_ijk(t_object *obj);
void		ft_triangle_ijk(t_object *obj);
void		ft_rot_ijk(t_r ft_r, double t, t_object *o);
t_object	*ft_set_val(t_object *old, t_object *new);
void		ft_init_copy_obj(t_object *new, t_object *old);

t_object	*four_x_case(t_object *new, t_object *old);
t_object	*zero_x_case(t_object *new, t_object *old);
t_object	*three_x_case(t_object *new, t_object *old);
t_object	*two_x_case(t_object *new, t_object *old);
t_object	*one_x_case(t_object *new, t_object *old);

t_color		ft_color(int iter, t_noise *noise);
t_com		ft_specific_julia(int choix);
t_color		ft_julia(double col, double row, t_noise *noise);
t_color		ft_get_fractal(t_object *o, t_hit *rec, t_noise *noise);
t_color		ft_get_checkerboard(t_object *o, t_hit *rec, t_noise *noise);
t_color		ft_get_mamamiya(t_object *o, t_hit *rec, t_noise *noise);
t_color		ft_get_cercles(t_object *o, t_hit *rec, t_noise *noise);

#endif
