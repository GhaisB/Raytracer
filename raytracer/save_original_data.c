/*
** save_original_data.c for save in /home/knocka_a/repositories/rt/raytracer
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat May 26 15:19:13 2012 antoine knockaert
** Last update Sat Jun  2 10:39:18 2012 guillaume duez
*/

#include	"../rt.h"

void		backup_original_data(t_mlx *init)
{
  int		size;
  int		i;

  i = 0;
  size = HAUTEUR * (LARGEUR * 4);
  while (i < size)
    {
      init->data[i] = init->saved_data[i];
      i++;
    }
}

void		save_original_data(t_mlx *init)
{
  int		size;
  int		i;

  i = 0;
  size = HAUTEUR * (LARGEUR * 4);
  init->saved_data = xmalloc((size + 5) * sizeof(char));
  while (i < size)
    {
      init->saved_data[i] = init->data[i];
      i++;
    }
}
