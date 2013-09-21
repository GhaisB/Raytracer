/*
** add_params_first.c for add in /home/knocka_a/parsing
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Tue May  8 17:54:20 2012 antoine knockaert
** Last update Fri Jun  1 12:17:11 2012 antoine knockaert
*/

#include	"../rt.h"

static void	add_params_base(t_sph *obj, double *values)
{
  obj->color = values[0];
  obj->x = values[1];
  obj->y = values[2];
  obj->z = values[3];
  if (values[4] > 0)
    obj->r = values[4];
  else
    obj->r = 1;
  obj->xro = values[5];
  obj->yro = values[6];
  obj->zro = values[7];
  obj->bri = values[8];
  obj->trans = values[9];
  obj->ref = values[10];
  obj->ck = values[11];
  obj->a[0] = values[12];
  obj->a[1] = values[13];
  obj->a[2] = values[14];
  obj->b[0] = values[15];
  obj->b[1] = values[16];
  obj->b[2] = values[17];
  obj->c[0] = values[18];
  obj->c[1] = values[19];
  obj->c[2] = values[20];
}

void		add_params_comp(t_sph *obj, double *values)
{
  obj->cons = values[21];
  obj->cons2 = values[22];
  obj->mat_type = values[23];
  obj->damier = values[24];
  obj->ref_flou = values[25];
  obj->limit_min[0] = values[26];
  obj->limit_min[1] = values[27];
  obj->limit_min[2] = values[28];
  obj->limit_max[0] = values[29];
  obj->limit_max[1] = values[30];
  obj->limit_max[2] = values[31];
  obj->perturb[0] = values[32];
  obj->perturb[1] = values[33];
  obj->perturb[2] = values[34];
  obj->damier_color[0] = values[35];
  obj->damier_color[1] = values[36];
  obj->negative = values[37];
}

void		add_params_first(t_sph *obj, double *values)
{
  add_params_base(obj, values);
  add_params_comp(obj, values);
}
