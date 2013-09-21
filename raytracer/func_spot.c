/*
** func_spot.c for he in /home/duez_a//rtv1/tp
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Thu Feb 23 10:22:13 2012 guillaume duez
** Last update Sun Jun  3 13:01:58 2012 guillaume boell
*/

#include "../rt.h"

#define X2(x) (x * x)
#define RA(x) ((x * M_PI) / 180)

static int	calc_omber(t_sph *obj_a, t_obj *obc, t_tmp *tmp)
{
  obc->coeff_k = 1000;
  while (obj_a != NULL)
    {
      if (obj_a->type >= 0 && obj_a->type < 20 && obc->shadow[obj_a->type]
          && obc->nt != obj_a)
	obc->shadow[obj_a->type](tmp, obc, obj_a);
      obj_a = obj_a->nt;
    }
  if (obc->coeff_k > 0 && obc->coeff_k < 1)
    return (1);
  return (0);
}

unsigned char	*func_for_light_color(t_obj *obc, t_sph *obj_a,
				       t_sph *light, t_tmp *tmp)
{
  unsigned char	*color;
  unsigned char	*light_c;

  light_c = (unsigned char *) &light->color;
  if ((obc->cos_x < 0.1 && obc->cos_x > 0) || obc->cos_x < 0)
    obc->cos_x = 0.1;
  color = (unsigned char*) &obc->color;
  color[0] = (unsigned char) ((double) color[0]
			      * (1 - obc->bri) + (light_c[0] * obc->bri));
  color[1] = (unsigned char) ((double) color[1]
			      * (1 - obc->bri) + (light_c[1] * obc->bri));
  color[2] = (unsigned char) ((double) color[2]
			      * (1 - obc->bri) + (light_c[2] * obc->bri));
  color[0] = (unsigned char) ((double)color[0] * obc->cos_x);
  color[1] = (unsigned char) ((double)color[1] * obc->cos_x);
  color[2] = (unsigned char) ((double)color[2] * obc->cos_x);
  if (calc_omber(obj_a, obc, tmp) == 1)
    {
      color[0] = (unsigned char) ((double) color[0] * 0.3);
      color[1] = (unsigned char) ((double) color[1] * 0.3);
      color[2] = (unsigned char) ((double) color[2] * 0.3);
    }
  return (color);
}
