/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 19:27:36 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/04 21:53:27 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DEFINE_H
# define RT_DEFINE_H

# define PS p->scene
# define PSC p->scene->curr_object
# define PSRC p->scene->record.curr_obj
# define P_ID p->inc_dec
# define THA p->scene->theta
# define MSP mlx_string_put

# define IMG_NBR 36

# define ROT_X 1
# define ROT_Y 2
# define ROT_Z 3

# define FRAME 10
# define MENU_BAR 150
# define IMG_WIDTH ((int)WIDTH)
# define IMG_HEIGHT (IMG_WIDTH / 2)
# define WIN_WIDTH (IMG_WIDTH + (2 * FRAME))
# define WIN_HEIGHT (IMG_HEIGHT + FRAME + MENU_BAR)

# define COND_SLCT1(x) (x > FRAME && x < IMG_WIDTH + FRAME)
# define COND_SLCT2(y) (y > MENU_BAR && y < IMG_HEIGHT + MENU_BAR)
# define COND_SELECT(x, y) (COND_SLCT1(x) && COND_SLCT2(y))

# define VORONOI_0          0
# define VORONOI_1          1
# define VORONOI_2          2
# define VORONOI_3          3
# define VORONOI_4          4
# define VORONOI_5          5
# define VORONOI_6          6
# define PERLIN_0           7
# define PERLIN_1           8
# define PERLIN_2           9
# define PERLIN_3           10
# define CHECKER_BOARD      11
# define FRACTAL_0          12
# define FRACTAL_1          13
# define FRACTAL_2          14
# define FRACTAL_3          15
# define FRACTAL_4          16
# define FRACTAL_5          17
# define FRACTAL_6          18
# define FRACTAL_7          19
# define MAMAMIYA           20
# define CERCLES            21

# define BG_COL_1 0xAAAAAA
# define BG_COL_2 0xB8B8B8
# define BG_COL_3 0x3E3E3d
# define BG_COL_4 0x797978

# define NONE_FILTER 0
# define MOTION_BLUR_FILTER 1
# define MOTION_BLUR2_FILTER 2
# define CARTOON_FILTER 3
# define SEPIA_FILTER 4
# define RED_FILTER 5
# define GREEN_FILTER 6
# define BLUE_FILTER 7
# define NEGATIVE_FILTER 8
# define GRAY1_FILTER 9
# define GRAY2_FILTER 10
# define GRAY3_FILTER 11
# define GRAY4_FILTER 12
# define GRAY5_FILTER 13

# define FILTER_MB_W 9
# define FILTER_MB_H 9

# define FILTER_MB1_W 5
# define FILTER_MB1_H 5

# define C1_1(x, y) (x == 0 && y == 0)
# define C1_2(x, y) (x == 0 && y == 1)
# define C1_3(x, y) (x == 1 && y == 0)

# define FILTER_C1(x, y) C1_1(x, y) || C1_2(x, y) || C1_3(x, y)

# define C2_1(x, y) (x == 3 && y == 0)
# define C2_2(x, y) (x == 4 && y == 0)
# define C2_3(x, y) (x == 4 && y == 1)

# define FILTER_C2(x, y) C2_1(x, y) || C2_2(x, y) || C2_3(x, y)

# define C3_1(x, y) (x == 0 && y == 3)
# define C3_2(x, y) (x == 0 && y == 4)
# define C3_3(x, y) (x == 1 && y == 4)

# define FILTER_C3(x, y) C3_1(x, y) || C3_2(x, y) || C3_3(x, y)

# define C4_1(x, y) (x == 4 && y == 3)
# define C4_2(x, y) (x == 4 && y == 4)
# define C4_3(x, y) (x == 3 && y == 4)

# define FILTER_C4(x, y) C4_1(x, y) || C4_2(x, y) || C4_3(x, y)

# define FILTER_TWO_1(x, y) (FILTER_C1(x, y) || FILTER_C2(x, y))
# define FILTER_TWO_2(x, y) (FILTER_C3(x, y) || FILTER_C4(x, y))

# define FILTER_COND(x, y) FILTER_TWO_1(x, y) || FILTER_TWO_2(x, y)

# define FILTER_C_W 5
# define FILTER_C_H 5
# define FILTERSIZE (FILTER_C_H * FILTER_C_W)
# define FACTOR 1.0 / 9.0
# define BIAS 0.0

# define COL1 0x333333
# define COL2 0x000000

# define COND_BG1(row) (row > FRAME && row < MENU_BAR - FRAME)
# define COND_BG2(col) (col > FRAME && col < WIN_WIDTH - FRAME)
# define BG_COND(row, col) (COND_BG1(row) && COND_BG2(col))
# define RWH(row) (row < WIN_HEIGHT - FRAME)
# define CWW(col) (col < WIN_WIDTH - FRAME)
# define BG_COND1(row, col) (col == FRAME && row > MENU_BAR && RWH(row))
# define BG_COND2(row, col) (row == MENU_BAR && col > FRAME && CWW(col))

# define NBTHREAD 4

# define DEFAULT -2147483648.0

# define FR(x, y) ({free(x); y;})
# define C_S "\t\"Object\": \"Sphere\""
# define C_P "\t\"Object\": \"Plane\""
# define C_CO "\t\"Object\": \"Cone\""
# define C_CY "\t\"Object\": \"Cylinder\""
# define C_D "\t\"Object\": \"Disk\""
# define C_T "\t\"Object\": \"Torus\""
# define C_PA "\t\"Object\": \"Paraboloid\""
# define C_H "\t\"Object\": \"Hyperboloid\""
# define C_PC "\t\"Object\": \"PCube\""
# define C_TR "\t\"Object\": \"Triangle\""
# define C_CU "\t\"Object\": \"Cube\""
# define C_M "\t\"Object\": \"Moebius\""

# define HIT_S ft_hit_sphere
# define HIT_P ft_hit_plane
# define HIT_CY ft_hit_cylinder
# define HIT_CO ft_hit_cone
# define HIT_D ft_hit_disk
# define HIT_T ft_hit_torus
# define HIT_PA ft_hit_paraboloid
# define HIT_H ft_hit_hyperboloid
# define HIT_PC ft_hit_perforated_cube
# define HIT_TR ft_hit_triangle
# define HIT_CU ft_hit_cube
# define HIT_M ft_hit_moebius

# define COL_TYPE(x) (x < 0.0 || x > 1.0)

# define END(x) (x[0][ft_strlen(*x) - 1])

# define MLX_KEY_LEFT 123
# define MLX_KEY_RIGHT 124
# define MLX_KEY_UP 126
# define MLX_KEY_DOWN 125
# define MLX_KEY_ESC 53
# define MLX_KEY_ENTER 36
# define MLX_KEY_D 2
# define MLX_KEY_S 1
# define KEY_SPACEBAR 49
# define MLX_KEY_X 7
# define MLX_KEY_Y 16
# define MLX_KEY_Z 6
# define MLX_KEY_A 0
# define MLX_KEY_O 31
# define MLX_KEY_C 8
# define MLX_KEY_L 37
# define MLX_KEY_V 9
# define MLX_KEY_I 34
# define MLX_KEY_MINUS 27
# define MLX_KEY_PLUS 24

# define RE_DRAW_C1(x) (x == 123 || x == 124 || x == 126 || x == 125)
# define RE_DRAW_C2(x) (x == 16 || x == 7 || x == 27 || x == 24 || x == 6)
# define RE_DRAW_C4(x) (x == 49 || x == 0)
# define RE_DRAW_C5(x) (RE_DRAW_C1(x) || RE_DRAW_C2(x))
# define RE_DRAW_C6(x) ((PSC || p->cam_slct || p->light_slct))
# define RE_DRAW(x) ((RE_DRAW_C6(x) && (RE_DRAW_C5(x)))|| RE_DRAW_C4(x))

# define RE_MAIN_C1(x) (x == 36 || x == 51 || x == 2 || x == 11)
# define RE_MAIN_C2(x) (x == 1 || x == 7 || x == 16 || x == 6 || x == 0)
# define RE_MAIN_C3(x) (x == 31 || x == 8 || x == 37 || x == 49)

# define RE_MAIN(x) (RE_MAIN_C1(x) || RE_MAIN_C2(x) || RE_MAIN_C3(x))

# define GOT_TXT(x) (x == HIT_S || x == HIT_P || x == HIT_CY || x == HIT_CO)

# define THE_ABS(x) { x = x > 0 ? x : -x; }
# define IFLR(x) (int)floor(x)
# define RGB(x) (int)(255.99 * x)
# define RGBTOI(x, y, z) (x * 256 * 256 + y * 256 + z)
# define I_TO_R(col) (col / (256 * 256))
# define I_TO_G(col) ((col / 256) % 256)
# define I_TO_B(col) (col % 256)
# define DEG_TO_RAD(x) ((x) * (M_PI / 180.0))
# define RAD_TO_DEG(x) ((x) * (180.0 / M_PI))

# define EQN_EPS     1e-9
# define IS_ZERO(x)	((x) > -EQN_EPS && (x) < EQN_EPS)

# define POW1(x) pow((double)(x), 1.0/3.0)
# define POW2(x) pow((double)-(x), 1.0/3.0)

# define CBRT(x) ((x) > 0.0 ? POW1(x) : ((x) < 0.0 ? -POW2(x) : 0.0))

# define C_C(c1, c2) (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b)

# define CMP1(x) ft_strncmp(x, "\t\t\"color\": \"", 12)
# define CMP2(x) ft_strncmp(x, "\t\t\"texture\": \"", 14)
# define CMP3(x) ft_strncmp(x, "\t\t\"noise\": \"", 12)

# define IS_FORTH(x) (CMP1(x) && CMP2(x) && CMP3(x))

# define IS_THIRD(x) ft_strncmp(x, "\t\t\"translation\": \"", 18)

# define LOAD_WIDTH IMG_WIDTH
# define LOAD_HEIGHT 5

# define D_LIGHT 0
# define P_LIGHT 1

# define IS_PERLIN(x) (x == 7 || x == 8 || x == 9 || x == 10)

# define PHONG 0
# define BLINN_PHONG 1

# define FC o->cont->cont->cont->cont->cont->cont

# define IS_PLANE 1
# define NOT_PLANE 0

#endif
