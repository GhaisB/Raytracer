/*
** init_ptr_func.c for init_ptr in /home/knocka_a/repositories/rt
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon May  7 10:49:04 2012 antoine knockaert
** Last update Sat Jun  2 10:23:57 2012 guillaume duez
*/

#include	"../rt.h"

void		init_ptr_func_inter(t_obj *obc)
{
  obc->inter[0] = &(inter_hyperbo);
  obc->inter[1] = &(inter_sphere);
  obc->inter[2] = &(inter_plan);
  obc->inter[3] = &(inter_cyl);
  obc->inter[4] = &(inter_con);
  obc->inter[5] = &(inter_parabo);
  obc->inter[6] = &(inter_disq);
  obc->inter[7] = &(inter_selle);
  obc->inter[8] = &(inter_para);
  obc->inter[9] = &(inter_triangle);
  obc->inter[10] = NULL;
  obc->inter[11] = &(inter_tore);
  obc->inter[12] = &(cube_hole);
}

void		init_ptr_func_normal(t_obj *obc)
{
  obc->normale[0] = &(calc_n_for_hyperbo);
  obc->normale[1] = &(calc_n_for_sphere);
  obc->normale[2] = &(calc_n_for_plan);
  obc->normale[3] = &(calc_n_for_cyl);
  obc->normale[4] = &(calc_n_for_con);
  obc->normale[5] = &(calc_n_for_parabo);
  obc->normale[6] = &(calc_n_for_disque);
  obc->normale[7] = NULL;
  obc->normale[8] = &(calc_n_for_para);
  obc->normale[9] = &(calc_n_for_triangle);
  obc->normale[10] = NULL;
  obc->normale[11] = &(calc_n_for_tore);
  obc->normale[12] = &(calc_n_for_cube);
}

void		init_ptr_func_shadow(t_obj *obc)
{
  obc->shadow[0] = &(inter_hyperbo_sha);
  obc->shadow[1] = &(inter_sphere_sha);
  obc->shadow[2] = &(inter_plan_sha);
  obc->shadow[3] = &(inter_cyl_sha);
  obc->shadow[4] = &(inter_con_sha);
  obc->shadow[5] = &(inter_para_sha);
  obc->shadow[6] = &(inter_disq_sha);
  obc->shadow[7] = NULL;
  obc->shadow[8] = &(inter_parale_sha);
  obc->shadow[9] = &(inter_triangle_sha);
  obc->shadow[10] = NULL;
  obc->shadow[11] = &(inter_tore_shadow);
  obc->shadow[12] = &(cube_hole_shadow);
}
