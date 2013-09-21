/*
** add_to_list_obj.c for add in /home/knocka_a/parsing
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Tue May  8 17:37:31 2012 antoine knockaert
** Last update Tue May  8 17:59:14 2012 antoine knockaert
*/

#include	"../rt.h"

void		add_to_list_obj(t_pars *pars, t_sph *maillon)
{
  t_sph		*tmp;

  tmp = pars->obj_a;
  if (tmp == NULL)
    {
      pars->obj_a = maillon;
    }
  else
    {
      while (tmp->nt)
	tmp = tmp->nt;
      tmp->nt = maillon;
    }
}
