/*
** malloc_calc.c for malloc_calc in /home/knocka_a/repositories/rt
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri May  4 11:49:10 2012 antoine knockaert
** Last update Sun Jun  3 13:04:21 2012 guillaume boell
*/

#include "../rt.h"

void		malloc_calc(t_cod **cor, t_obj **obc, t_tmp **tmp)
{
  *tmp = xmalloc(sizeof(t_tmp));
  malloc_tmp(*tmp);
  *obc = xmalloc(sizeof(t_obj));
  init_obc(*obc);
  *cor = xmalloc(sizeof(t_cod));
  func_for_coordonne(*cor);
  (*cor)->l_o = xmalloc(6 * sizeof(double));
}
