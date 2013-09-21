/*
** rt.h for rt in /home/knocka_a/repositories/rt
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sat Jun  2 18:56:39 2012 antoine knockaert
** Last update Sat Sep 21 17:29:00 2013 bensafia ghais
*/

#ifndef __RT_H__
#define __RT_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <termios.h>
#include <unistd.h>
#include <pthread.h>
#include <X11/Xlib.h>
#include <stdio.h>
#include "minilibx/mlx.h"

#define	COM		'#'
#define	NB_PARAM	38
#define	HAUTEUR		(600)
#define	LARGEUR		(800)
#define	ECHAP		27
#define	BACKSPACE	127
#define	ENTER		10
#define	SPACE		32
#define	DEL		2117294875
#define	TOP_ARROW	4283163
#define	BOT_ARROW	4348699
#define	PLUS		43
#define	MINUS		45
#define	FRAME_PER_PIX	10

typedef struct		s_cod
{
  int			x;
  int			y;
  double		spx;
  double		spy;
  double		spz;
  double		*color_sp;
  double		bri;
  double		*l_x;
  double		*l_o;
  double		l_o_save[6];
  double		*ray_col;
  double		*n;
  double		frames_left;
  double		col_final[3];
}			t_cod;

typedef struct		s_params
{
  char			method;
}			t_params;

typedef struct		s_sph
{
  char			*name;
  int			color;
  int			type;
  double		x;
  double		y;
  double		z;
  double		r;
  double		xro;
  double		yro;
  double		zro;
  double		bri;
  double		trans;
  double		ref;
  double		ck;
  double		a[3];
  double		b[3];
  double		c[3];
  double		cons;
  double		cons2;
  double		mat_type;
  double		damier;
  double		ref_flou;
  double		limit_min[3];
  double		limit_max[3];
  double		perturb[3];
  int			damier_color[2];
  double		negative;
  struct s_sph		*nt;
}			t_sph;

typedef struct		s_tmp
{
  double		*l_v;
  double		*l_c;
}			t_tmp;

struct			s_bitmap
{
  unsigned short int	data;
  unsigned int		size;
  unsigned short int	reser;
  unsigned short int	reser2;
  int			offset;
  int			size_of_bmp;
  int			witdh;
  int			height;
  unsigned short int	planes;
  unsigned short int	bits;
  unsigned int		compres;
  unsigned int		size_im;
  int			x;
  int			y;
  unsigned int		nb_colors;
  unsigned int		i_nb_colors;
}			__attribute__((__packed__));

typedef struct		coeff_obj
{
  int			color;
  int			ck;
  int			bounce;
  double		cos_x;
  double		coeff_k;
  double		*p;
  double		*n;
  double		bri;
  double		xtmp;
  double		ytmp;
  double		ztmp;
  double		mat_type;
  int			(*inter[20])(t_cod *cor, t_tmp *tmp,
				     struct coeff_obj *obc, t_sph *obj_a);
  void			(*normale[20])(struct coeff_obj *obc,
				       double *p, t_sph *obj_a);
  int			(*shadow[20])(t_tmp *tmp, struct coeff_obj *obc,
				      t_sph *obj_a);
  struct s_sph		*nt;
}			t_obj;

typedef struct		s_mlx
{
  void			*img;
  void			*mlx_ptr;
  void			*win_ptr;
  unsigned char		*data;
  unsigned char		*saved_data;
  char			*filename;
  double		dist_focus;
  double		scale_focus;
  double		blur_power;
  int			pass;
  int			cpt;
}			t_mlx;

typedef struct		s_pars
{
  char			*filename;
  char			**read;
  char			*types[20];
  double		values[NB_PARAM + 2];
  t_sph			*obj_a;
  double		oeil[9];
}			t_pars;

void			objet_limited(t_sph *obj_a, t_obj *obc, t_tmp *tmp,
				      double *delta);
void			recup_l(t_sph *light, t_obj *obc, t_tmp *tmp);
void			calc_cos_x(t_obj *obc, t_tmp *tmp);
void			stock_l(t_obj *obc, t_tmp *tmp);
void			return_temp(t_obj *obc, double *n2, int *poids);
int			inter_con(t_cod *cor, t_tmp *tmp, t_obj *obc,
				  t_sph *obj_a);
int			inter_cyl(t_cod *cor, t_tmp *tmp, t_obj *obc,
				  t_sph *obj_a);
int			inter_sphere(t_cod *cor, t_tmp *tmp, t_obj *obc,
				     t_sph *obj_a);
int			inter_plan(t_cod *cor, t_tmp *tmp, t_obj *obc,
				   t_sph *obj_a);
int			inter_parabo(t_cod *cor, t_tmp *tmp, t_obj *obc,
				     t_sph *obj_a);
int			inter_disq(t_cod *cor, t_tmp *tmp, t_obj *obc,
				   t_sph *obj_a);
int			inter_hyperbo(t_cod *cor, t_tmp *tmp, t_obj *obc,
				      t_sph *obj_a);
int			inter_selle(t_cod *cor, t_tmp *tmp, t_obj *obc,
				    t_sph *obj_a);
int			inter_para(t_cod *cor, t_tmp *tmp, t_obj *obc,
				   t_sph *obj_a);
int			inter_triangle(t_cod *cor, t_tmp *tmp, t_obj *obc,
				       t_sph *obj_a);
int			cube_hole(t_cod *cor, t_tmp *tmp, t_obj *obc,
				  t_sph *obj_a);
int			inter_tore(t_cod *cor, t_tmp *tmp, t_obj *obc,
				   t_sph *obj_a);
void			calc_n_for_con(t_obj *obc, double *p, t_sph *obj_a);
void			calc_n_for_cyl(t_obj *obc, double *p, t_sph *obj_a);
void			calc_n_for_parabo(t_obj *obc, double *p, t_sph *obj_a);
void			calc_n_for_plan(t_obj *obc, double *p, t_sph *obj_a);
void			calc_n_for_sphere(t_obj *obc, double *p, t_sph *obj_a);
void			calc_n_for_disque(t_obj *obc, double *p, t_sph *obj_a);
void			calc_n_for_hyperbo(t_obj *obc, double *p, t_sph *obj_a);
void			calc_n_for_triangle(t_obj *obc, double *p,
					    t_sph *obj_a);
void			calc_n_for_para(t_obj *obc, double *p, t_sph *obj_a);
void			calc_n_for_cube(t_obj *obc, double *p, t_sph *obj_a);
void			calc_n_for_tore(t_obj *obc, double *p, t_sph *obj_a);
int			inter_con_sha(t_tmp *tmp, t_obj *obc, t_sph *obj_a);
int			inter_cyl_sha(t_tmp *tmp, t_obj *obc, t_sph *obj_a);
int			inter_sphere_sha(t_tmp *tmp, t_obj *obc, t_sph *obj_a);
int			inter_plan_sha(t_tmp *tmp, t_obj *obc, t_sph *obj_a);
int			inter_disq_sha(t_tmp *tmp, t_obj *obc, t_sph *obj_a);
int			inter_para_sha(t_tmp *tmp, t_obj *obc, t_sph *obj_a);
int			inter_hyperbo_sha(t_tmp *tmp, t_obj *obc, t_sph *obj_a);
void			stock_k(t_obj *obc, double k1, double k2);
int			inter_parale_sha(t_tmp *tmp, t_obj *obc, t_sph *obj_a);
int			inter_triangle_sha(t_tmp *tmp, t_obj *obc,
					   t_sph *obj_a);
int			inter_tore_shadow(t_tmp *tmp, t_obj *obc, t_sph *obj_a);
int			cube_hole_shadow(t_tmp *tmp, t_obj *obc, t_sph *obj_a);
void			init_p(t_tmp *tmp, double *p0, double *p1, double *p2);
void			init_d(t_tmp *tmp, double *d0, double *d1, double *d2);
void			init_R_r(t_sph *obj_a, double *R, double *r);
int			ferari(t_tmp *tmp, t_obj *obc);
int			gere_expose(t_mlx *init);
int			go_rayt(char *filename);
int			nb_line(char **map);
void			calc_n_for_con(t_obj *obc, double *p, t_sph *obj_a);
void			calc_n_for_cyl(t_obj *obc, double *p, t_sph *obj_a);
void			my_putchar_file(char c, int fd);
void			rotate_x(double xro, double yro, double zro,
				 double *l_OT);
int			count_for_obj(char **str, int i, t_pars *pars);
double			*rot_tran_inverse(t_sph *t_obj_a, double *p);
void			calc_p_n_color(t_cod *cor, t_obj *obc, t_sph *obj_a,
				       t_tmp *tmp);
void			put_pix_bmp(char **map, int fd);
void			modif_lX(t_cod *cor, t_sph *obj_a, t_tmp *tmp);
void			display_enver(unsigned char *data, int fd);
void			export_bmp(unsigned char *data, char *filename);
int			delta_neg(double p, double q, t_obj *obc, double z);
int			find_x(double delta, double p, double q, t_obj *obc,
			       double z);
int			cardran(t_obj *obc, double b, double c, double d);
int			error_func();
t_sph			*delete(t_sph *sph);
void			func_download(int y, int hight, t_mlx *init);
void			*calcul_all(void *init2);
void			*calcul_all2(void *init2);
void			*calcul_all3(void *init2);
void			*calcul_all4(void *init2);
void			func_for_coordonne(t_cod *cor);
double			*list_for_O();
void			malloc_tmp(t_tmp *tmp);
void			init_obc(t_obj *obc);
void			calcul_X1(int x, int y, double *l_x);
double			*rot_ra(double xro, double yro, double zro,
				double rayon);
void			add_to_list_obj(t_pars *pars, t_sph *maillon);
t_sph			*ad_to_beg(t_sph *sph, double *cod, double *rot_ra,
				   int *color_type);
double			*l_cod(double x, double y, double z, double bri);
unsigned char		*make_blue_anaglyph(unsigned char *data);
unsigned char		*make_green_anaglyph(unsigned char *data);
unsigned char		*make_red_anaglyph(unsigned char *data);
unsigned char		*make_decalage(unsigned char *data);
int			*func_color_type(int color, int type);
t_sph			*create_list_for_sph(t_sph *obj_a);
unsigned char		*func_for_light_color(t_obj *obc, t_sph *obj_a,
					      t_sph *light, t_tmp *tmp);
unsigned char		*color_func(t_obj *obc, t_sph *obj_a, t_tmp *tmp);
void			init_ptr_func_inter(t_obj *obc);
void			init_ptr_func_normal(t_obj *obc);
void			init_ptr_func_shadow(t_obj *obc);
void			malloc_calc(t_cod **cor, t_obj **obc, t_tmp **tmp);
void			modif_p_l(t_obj *obc, t_tmp *tmp, t_sph *obj_a);
void			tent_filter_rt(int x, int y, t_mlx *init);
void			my_pixel_put_to_image(int x, int y, t_mlx *init,
					      unsigned char *color);
void			t_objet_limited(t_sph *obj_a, t_obj *obc, t_tmp *tmp,
					double *delta);
void			para(t_sph *obj_a, t_obj *obc, t_tmp *tmp,
			     double *delta);
void			triangle(t_sph *obj_a, t_obj *obc, t_tmp *tmp,
				 double *delta);
void			reverse_mode(t_mlx *init);
void			black_white(t_mlx *init);
void			lumens_mode(t_mlx *init, int type);
void			aliasing(t_mlx *init);
void			save_original_data(t_mlx *init);
void			backup_original_data(t_mlx *init);
int			go_patht(char *filename);
void			normalize(double *v);
void			add_col(double *c, int *s, double factor);
void			add_col_char(double *c,  double col);
void			mult_vect_vect(double *t1, double *t2);
void			mult_vect_cons(double *t1, double cons);
void			rand_vec(double **t, double demi_a);
void			mult_col(unsigned char *c, double *f, double mult,
				 unsigned char *lum_col);
void			get_light(t_tmp *tmp, t_obj obc, t_cod cor,
				  t_sph *obj_a);
void			post_work(t_mlx *init, t_cod *cor, int *pass);
void			line_ended(t_mlx *init, t_cod *cor);
void			my_putstr_file(char *str, int fd);
void			*calcul_all_pt(void *init);
t_sph			*create_list_patht(t_sph *obj_a);
void			tent_filter_pt(int x, int y, t_mlx *init, int poids);
void			put_pix(t_cod *cor, t_mlx *init, double *color,
				int pass);
double			*calc_pt(t_tmp *tmp, t_obj *obc, t_cod *cor,
				 t_sph *obj_a);
int			calc_k(t_tmp *tmp, t_obj *obc, t_cod *cor,
			       t_sph *obj_a);
void			brdf(t_cod *cor, t_sph *obj_hit, t_obj *obc,
			     double omeg);
void			init_light(t_cod *cor, double *old_lx, double *old_n);
void			de_init_light(t_cod *cor, double *old_lx,
				      double *old_n);
void			set_ray(t_cod *cor, t_sph *obj_a, t_obj *obc);
void			set_r_d(double *r, double *d, t_obj *obc, t_sph *obj_a);
double			hex_to_double(char *str);
char			*concat(char *str1, char *str2);
char			*epur_str(char *str, int mfree, char c);
char			**get_map(unsigned char *data);
void			init_str(char *str, int size);
void			display_endroit(char **map, int fd);
int			calcul_first(char *str, int *i);
int			my_getnbr(char *str);
int			my_match(char *str1, char *str2);
void			my_putchar(char c);
int			neg(int nb);
void			my_put_nbr(int nb);
double			calc_k_for_cone(double *k1, double b, double delta,
					double a);
void			my_putstr(char *str);
int			my_strlen(char *str);
char			**my_str_to_wordtab(char *str, char c);
char			**read_all(int fd);
int			xread(int fd, void *buf, size_t count);
void			xtcsetattr(int fd, int opts,
				   const struct termios *termios_p);
int			xtgetent(const char *name);
int			xopen(const char *pathname, int flags);
int			xclose(int fd);
void			xfree(void *tmp);
void			*xmalloc(int size);
char			*my_strdup(char *str);
void			add_params_comp(t_sph *t_obj, double *values);
void			add_params_first(t_sph *t_obj, double *values);
void			add_to_list_t_obj(t_pars *pars, t_sph *maillon);
void			my_putc(int i, int fd);
void			create_header(int fd);
int			init(t_pars *pars, char *filename);
void			export_tga(t_mlx *init, char *str);
void			free_parsing(t_pars *pars);
void			stock_oeil(t_pars *pars, t_cod *cor, t_mlx *init);
void			init_types(t_pars *pars);
void			clean_tabl(char **str);
void			add_to_list(int type, t_pars *pars, char *name);
int			add_oeil_info(char **str, int i, t_pars *pars);
int			parseur(t_pars *pars, char **str);
t_sph			*parse(char *filename, t_cod *cor, t_mlx *init_ptr,
			       char **file);
int			is_type(char *str, t_pars *pars);
int			count_for_t_obj(char **str, int i, t_pars *pars);
void			stock_params(char **str, int i, t_pars *pars,
				     int classic);
int			verif_oeil(t_pars *pars);
void			aff_error(int i, int ret);
void			show_one_opt(char *txt1, char *txt2, char val_select,
				     char val);
void			show_opt_menu(t_params *params);
int			show_main_menu(void);
int			is_same(char *str, char *to_comp);
int			get_word_lenght(char *s);
char			*get_term_name(char **envp);
int			put_int(int c);
void			activ_cap(char *name);
void			param_term(struct termios *t, int is_end);
void			my_exit(t_mlx *init);
void			my_pixel_put_to_image_bmp(int x, int y, t_mlx *init,
						  unsigned char *color);
void			check(struct s_bitmap *pt);
void			do_import(struct s_bitmap *pt, t_mlx *init,
				  unsigned char *buff);
void			import_bmp(t_mlx *init);

#endif
