/*
** add_to_list_obj.c for calc in /home/knocka_a/repositories/rt/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Tue May 29 18:43:33 2012 antoine knockaert
** Last update Tue May 29 18:45:26 2012 antoine knockaert
*/

#include	"../edit.h"

void		add_to_list_obj_edit(t_glob *glob, t_sph *maillon)
{
  t_sph		*tmp;

  tmp = glob->obj_a;
  if (tmp == NULL)
    {
      glob->obj_a = maillon;
    }
  else
    {
      while (tmp->nt)
	tmp = tmp->nt;
      tmp->nt = maillon;
    }
}
