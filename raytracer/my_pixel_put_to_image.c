/*
** my_pixel_put_to_image.c for rt in /home/dell-a_f/rt/raytracer
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Fri Jun  1 11:31:24 2012 florian dell'aiera
** Last update Sun Jun  3 13:07:02 2012 guillaume boell
*/

#include "../rt.h"

#define X2(x) (x * x)

static unsigned char	*dot_color(unsigned char *c, int poid,
				   unsigned char *old_color)
{
  unsigned char		*col;

  col = xmalloc(5);
  if (poid >= 1)
    {
      col[0] = (old_color[0] * poid + c[0]) / (poid + 1);
      col[1] = (old_color[1] * poid + c[1]) / (poid + 1);
      col[2] = (old_color[2] * poid + c[2]) / (poid + 1);
      col[3] = 0;
      free(old_color);
    }
  else
    {
      col[0] = c[0];
      col[1] = c[1];
      col[2] = c[2];
      col[3] = 0;
    }
  return (col);
}

static double		*init_for_color(t_obj *obc, int *tmp_co, int *poid)
{
  double		*n2;

  n2 = xmalloc(3 * sizeof(double));
  n2[0] = obc->n[0];
  n2[1] = obc->n[1];
  n2[2] = obc->n[2];
  *tmp_co = obc->color;
  *poid = 0;
  return (n2);
}

unsigned char		*color_func(t_obj *obc, t_sph *obj_a, t_tmp *tmp)
{
  t_sph			*light;
  int			pd;
  unsigned char		*color;
  int			tmp_co;
  double		*n2;

  n2 = init_for_color(obc, &tmp_co, &pd);
  light = obj_a;
  color = (unsigned char*) &obc->color;
  while (obc->color != 0 && light != NULL)
    {
      if (light != NULL && light->type == 10)
	{
	  recup_l(light, obc, tmp);
	  calc_cos_x(obc, tmp);
	  stock_l(obc, tmp);
	  obc->color = tmp_co;
	  color = dot_color(func_for_light_color(obc, obj_a, light, tmp)
			    , pd, color);
	  return_temp(obc, n2, &pd);
	}
      light = light->nt;
    }
  free(n2);
  return (color);
}

void			my_pixel_put_to_image(int x, int y, t_mlx *init,
					      unsigned char *color)
{
  int			a;

  a = x + (y * LARGEUR * 4);
  init->data[a] = color[0];
  init->data[a + 1] = color[1];
  init->data[a + 2] = color[2];
  init->data[a + 3] = 0;
}

