/*
** import_bmp.c for bmp in /home/dell-a_f/Documents/projets/rt_copy/raytracer
**
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
**
** Started on  Tue May 29 14:51:25 2012 florian dell'aiera
** Last update Sun Jun  3 19:53:14 2012 florian dell'aiera
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../rt.h"

void			check(struct s_bitmap *pt)
{
  if (pt->height > HAUTEUR || pt->witdh > LARGEUR)
    {
      my_putstr("error taille trop grande\n");
      exit(0);
    }
}

void			do_import(struct s_bitmap *pt, t_mlx *init,
				  unsigned char *buff)
{
  int			i;
  int			j;

  i = pt->height;
  j = 0;
  while (i >= 0)
    {
      while (j < pt->witdh)
	{
	  my_pixel_put_to_image_bmp(j * 4, i, init, buff);
	  j++;
	}
      j = 0;
      i--;
    }
}

void			import_bmp(t_mlx *init)
{
  struct s_bitmap	pt;
  int			fd;
  unsigned char		*buff;
  int			check_r;

  init = init;
  check_r = 0;
  fd = open("scenes/image/image2.bmp", O_RDWR);
  if (fd == -1)
    exit(0);
  else
    check_r = read(fd , &pt, sizeof(struct s_bitmap));
  if (check_r == -1)
    exit(0);
  check_r = 0;
  buff = xmalloc(sizeof(int) * (pt.size_im));
  check_r = read(fd, buff, (pt.size_im));
  if (check_r == -1)
    exit(0);
  check(&pt);
  do_import(&pt, init, buff);
}
