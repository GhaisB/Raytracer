/*
** calc.c for pt in /home/knocka_a/repositories/rt/pathtracer
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Jun  1 15:57:05 2012 antoine knockaert
** Last update Sun Jun  3 19:35:07 2012 antoine knockaert
*/

#include "../rt.h"

#define RA(x) ((x * M_PI) / 180)
#define AR(x) ((x / M_PI) * 180)

static inline void	replace_l_o(double *base, double *save, t_cod *cor,
				    int st)
{
  if (st == 0)
    {
      base[0] = save[0];
      base[1] = save[1];
      base[2] = save[2];
      base[3] = save[3];
      base[4] = save[4];
      base[5] = save[5];
    }
  else
    {
      save[0] = cor->l_o[0];
      save[1] = cor->l_o[1];
      save[2] = cor->l_o[2];
      save[3] = cor->l_o[3];
      save[4] = cor->l_o[4];
      save[5] = cor->l_o[5];
    }
}

static inline void	init_launch(t_cod *cor, t_obj *obc)
{
  cor->frames_left = 0;
  obc->color = 0;
  cor->ray_col[0] = 0;
  cor->ray_col[1] = 0;
  cor->ray_col[2] = 0;
  cor->col_final[0] = 0;
  cor->col_final[1] = 0;
  cor->col_final[2] = 0;
}

static void		do_image(t_mlx *init, t_cod *cor, t_sph *obj_a,
				 t_obj *obc)
{
  t_tmp			*tmp;

  tmp = xmalloc(sizeof(t_tmp));
  malloc_tmp(tmp);
  while (cor->y != HAUTEUR)
    {
      while (cor->x != (LARGEUR * 4))
	{
	  init_launch(cor, obc);
	  while (cor->frames_left++ < FRAME_PER_PIX)
	    {
	      replace_l_o(cor->l_o, cor->l_o_save,  NULL, 0);
	      obc->bounce = 0;
	      calcul_X1(cor->x / 4, cor->y, cor->l_x);
	      put_pix(cor, init, calc_pt(tmp, obc, cor, obj_a), init->pass);
	      obc->coeff_k = 100000;
	    }
	  cor->x = cor->x + 4;
	}
      line_ended(init, cor);
    }
  post_work(init, cor, &(init->pass));
  my_putstr("Finised\n");
}

static void		do_blur(t_mlx *init, t_cod *cor, t_sph *obj_a,
				t_obj *obc)
{
  t_tmp			*tmp;
  int			x;
  int			y;

  tmp = xmalloc(sizeof(t_tmp));
  malloc_tmp(tmp);
  y = 0;
  while (cor->y != HAUTEUR)
    {
      x = 0;
      while (cor->x != (LARGEUR * 4))
	{
	  init_launch(cor, obc);
	  replace_l_o(cor->l_o, cor->l_o_save, NULL, 0);
	  obc->bounce = 0;
	  calcul_X1(cor->x / 4, cor->y, cor->l_x);
	  obc->coeff_k = 100000;
	  tent_filter_pt(x, y, init, calc_k(tmp, obc, cor, obj_a));
	  cor->x = cor->x + 4;
	  x++;
	}
      y++;
      line_ended(init, cor);
    }
  my_putstr("Post processing finished\n");
}

void			*calcul_all_pt(void *init2)
{
  t_mlx			*init;
  t_cod			*cor;
  t_sph			*obj_a;
  t_obj			*obc;

  init = (t_mlx *) init2;
  obc = xmalloc(sizeof(t_obj));
  init_obc(obc);
  srand48(1);
  obj_a = NULL;
  cor = xmalloc(sizeof(t_cod));
  func_for_coordonne(cor);
  cor->ray_col = xmalloc(3 * sizeof(double));
  cor->l_o = xmalloc(6 * sizeof(double));
  obj_a = parse(init->filename, cor, init, NULL);
  if (obj_a == NULL)
    exit(0);
  replace_l_o(cor->l_o, cor->l_o_save, cor, 1);
  do_image(init, cor, obj_a, obc);
  if (init->pass == 4)
    do_blur(init, cor, obj_a, obc);
  return (NULL);
}
