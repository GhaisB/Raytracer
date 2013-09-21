/*
** light_calc.c for pt in /home/knocka_a/repositories/rt/pathtracer
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Jun  1 15:57:49 2012 antoine knockaert
** Last update Sat Jun  2 10:56:43 2012 guillaume duez
*/

#include "../rt.h"

#define RA(x) ((x * M_PI) / 180)
#define AR(x) ((x / M_PI) * 180)

void			do_lum(t_obj *obc, t_cod *cor, t_sph *obj_hit, double omeg)
{
  obc->bounce -= 80;
  if (obc->bri)
    {
      normalize(cor->n);
      normalize(cor->l_x);
      brdf(cor, obj_hit, obc, omeg);
    }
}

void			get_light(t_tmp *tmp, t_obj obc, t_cod cor, t_sph *obj_a)
{
  t_sph			*tm;
  t_sph			*obj_hit;
  double		old_lx[3];
  double		old_n[3];
  double		r;
  double		d;

  tm = obj_a;
  obj_hit = obc.nt;
  init_light(&cor, old_lx, old_n);
  while (obj_a)
    {
      if (obj_a->bri > 0)
	{
	  set_r_d(&r, &d, &obc, obj_a);
	  set_ray(&cor, obj_a, &obc);
	  rand_vec(&(cor.l_x), (double)AR(atan(r / d)));
	  calc_pt(tmp, &obc, &cor, tm);
	  obc.bounce -= 80;
	  do_lum(&obc, &cor, obj_hit, (2 * M_PI *
				       (1 - (d / (sqrt(pow(d, 2) + pow(r, 2)))))));
	}
      obj_a = obj_a->nt;
    }
  de_init_light(&cor, old_lx, old_n);
}

void			post_work(t_mlx *init, t_cod *cor, int *pass)
{
  *pass = *pass + 1;
  my_putstr("Pass ");
  my_put_nbr(*pass);
  my_putstr(" finished\n");
  gere_expose(init);
  cor->x = 0;
  cor->y = 0;
}

void			line_ended(t_mlx *init, t_cod *cor)
{
  if (FRAME_PER_PIX > 2 || cor->y % 120 == 0)
    gere_expose(init);
  cor->x = 0;
  cor->y = cor->y + 1;
}
