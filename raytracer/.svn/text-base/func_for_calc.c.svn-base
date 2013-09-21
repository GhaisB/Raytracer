/*
** func_for_calc.c for rt in /home/dell-a_f/rt/raytracer
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Fri Jun  1 12:53:42 2012 florian dell'aiera
** Last update Sun Jun  3 12:58:52 2012 guillaume boell
*/

#include "../rt.h"

static unsigned char	*calc(t_tmp *tmp, t_obj *obc, t_cod *cor, t_sph *obj_a)
{
  t_sph			*tm;

  tm = obj_a;
  obc->nt = NULL;
  obc->color = 0;
  calcul_X1(cor->x / 4, cor->y, cor->l_x);
  rotate_x(cor->l_o[3], cor->l_o[4], cor->l_o[5], cor->l_x);
  while (obj_a != NULL)
    {
      if (obj_a->type >= 0 && obj_a->type < 20 && obc->inter[obj_a->type]
	  && obc->inter[obj_a->type](cor, tmp, obc, obj_a) == 1
	  && obj_a->negative != -1)
	obc->nt = obj_a;
      else if (obj_a->type >= 0 && obj_a->type < 20 && obc->inter[obj_a->type]
	  && obc->inter[obj_a->type](cor, tmp, obc, obj_a) == 1
	  && obj_a->negative == - 1)
	obc->nt = NULL;
      obj_a = obj_a->nt;
    }
  calc_p_n_color(cor, obc, obc->nt, tmp);
  return (color_func(obc, tm, tmp));
}

void			*calcul_all(void *init2)
{
  t_mlx			*init;
  t_cod			*cor;
  t_sph			*obj_a;
  t_obj			*obc;
  t_tmp			*tmp;

  init = (t_mlx *) init2;
  malloc_calc(&cor, &obc, &tmp);
  my_putstr(init->filename);
  if ((obj_a = parse(init->filename, cor, init, NULL)) == NULL)
    exit(EXIT_FAILURE);
  while (cor->y != HAUTEUR / 4)
    {
      while (cor->x != (LARGEUR * 4))
	{
	  my_pixel_put_to_image(cor->x, cor->y, init,
				calc(tmp, obc, cor, obj_a));
	  cor->x = cor->x + 4;
	  obc->coeff_k = 100000;
	}
      func_download(cor->y, HAUTEUR, init);
      cor->x = 0;
      cor->y = cor->y + 1;
    }
  return (NULL);
}

void			*calcul_all2(void *init2)
{
  t_mlx			*init;
  t_cod			*cor;
  t_sph			*obj_a;
  t_obj			*obc;
  t_tmp			*tmp;

  init = (t_mlx *) init2;
  malloc_calc(&cor, &obc, &tmp);
  if ((obj_a = parse(init->filename, cor, init, NULL)) == NULL)
    exit(EXIT_FAILURE);
  cor->y = HAUTEUR / 4;
  while (cor->y != (2 * (HAUTEUR / 4)))
    {
      while (cor->x != (LARGEUR * 4))
	{
	  my_pixel_put_to_image(cor->x, cor->y, init,
				calc(tmp, obc, cor, obj_a));
          cor->x = cor->x + 4;
	  obc->coeff_k = 100000;
	}
      func_download(cor->y, HAUTEUR, init);
      cor->x = 0;
      cor->y = cor->y + 1;
    }
  return (NULL);
}

void			*calcul_all3(void *init2)
{
  t_mlx			*init;
  t_cod			*cor;
  t_sph			*obj_a;
  t_obj			*obc;
  t_tmp			*tmp;

  init = (t_mlx *) init2;
  malloc_calc(&cor, &obc, &tmp);
  if ((obj_a = parse(init->filename, cor, init, NULL)) == NULL)
    exit(EXIT_FAILURE);
  cor->y = 2 * (HAUTEUR / 4);
  while (cor->y != (3 * (HAUTEUR / 4)))
    {
      while (cor->x != (LARGEUR * 4))
	{
	  my_pixel_put_to_image(cor->x, cor->y, init,
				calc(tmp, obc, cor, obj_a));
          cor->x = cor->x + 4;
	  obc->coeff_k = 100000;
	}
      func_download(cor->y, HAUTEUR, init);
      cor->x = 0;
      cor->y = cor->y + 1;
    }
  return (NULL);
}

void			*calcul_all4(void *init2)
{
  t_mlx			*init;
  t_cod			*cor;
  t_sph			*obj_a;
  t_obj			*obc;
  t_tmp			*tmp;

  init = (t_mlx *) init2;
  malloc_calc(&cor, &obc, &tmp);
  if ((obj_a = parse(init->filename, cor, init, NULL)) == NULL)
    exit(EXIT_FAILURE);
  cor->y = 3 * (HAUTEUR / 4);
  while (cor->y != (4 * (HAUTEUR / 4)))
    {
      while (cor->x != (LARGEUR * 4))
	{
	  my_pixel_put_to_image(cor->x, cor->y, init,
				calc(tmp, obc, cor, obj_a));
          cor->x = cor->x + 4;
	  obc->coeff_k = 100000;
	}
      func_download(cor->y, HAUTEUR, init);
      cor->x = 0;
      cor->y = cor->y + 1;
    }
  return (NULL);
}
