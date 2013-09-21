/*
** begin.c for rt in /home/boell_g/Documents/projets/rt
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Wed May 30 17:42:03 2012 guillaume boell
** Last update Thu May 31 16:22:36 2012 guillaume boell
*/

#include "../rt.h"

void		my_exit(t_mlx *init)
{
  xfree(init->saved_data);
  exit(0);
}
