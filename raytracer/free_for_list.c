/*
** free_for_list.c for zéd in /home/duez_a//rtv1/tp
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Fri Feb 24 13:58:37 2012 guillaume duez
** Last update Tue Apr 24 22:54:27 2012 antoine knockaert
*/

#include "../rt.h"

t_sph	*delete(t_sph *sph)
{
  t_sph	*element;

  element = sph;
  if (element != NULL)
    {
      element = element->nt;
      free(sph);
      return (element);
    }
  else
    return (NULL);
}
