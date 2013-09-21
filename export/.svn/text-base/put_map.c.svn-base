/*
** display_endroit.c for  in /home/bouffl_g//rt
** 
** Made by guillaume boufflers
** Login   <bouffl_g@epitech.net>
** 
** Started on  Wed May 23 22:47:19 2012 guillaume boufflers
** Last update Thu May 31 17:02:29 2012 antoine knockaert
*/

#include "../rt.h"
#include "./export.h"

void	put_pix_bmp(char **map, int fd)
{
  int	size;
  int	j;

  size = nb_line(map) - 2;
  while (size >= 0)
    {
      j = 0;
      while (j < (LARGEUR * 4))
	{
	  my_putchar_file(map[size][j], fd);
	  j++;
	}
      size--;
    }
}
