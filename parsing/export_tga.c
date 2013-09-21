/*
** export_tga.c for export_tga in /home/knocka_a/repositories/rt
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri May 11 16:40:06 2012 antoine knockaert
** Last update Thu May 31 18:58:47 2012 antoine knockaert
*/

#include	"../rt.h"

void		my_putc(int i, int fd)
{
  char		c;

  c = (char) i;
  if (write(fd, &c, 1) == -1)
    {
      puts("invalid write\n");
      exit(EXIT_FAILURE);
    }
}

void		create_header(int fd)
{
  int		i;

  i = 0;
  my_putc(0, fd);
  my_putc(0, fd);
  my_putc(2, fd);
  while (i < 9)
    {
      my_putc(0, fd);
      i++;
    }
  my_putc((LARGEUR & 0x00FF), fd);
  my_putc((LARGEUR & 0xFF00) / 256, fd);
  my_putc((HAUTEUR & 0x00FF), fd);
  my_putc((HAUTEUR & 0xFF00) / 256, fd);
  my_putc(24, fd);
  my_putc(0, fd);
}

void		export_tga(t_mlx *init, char *str)
{
  int		fd;
  int		i;
  int		j;
  int		right;

  right = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
  fd = open(str, O_CREAT | O_RDWR, right);
  create_header(fd);
  i = HAUTEUR - 1;
  j = (HAUTEUR * LARGEUR * 4) - 1;
  while (i >= 0)
    {
      j = i * LARGEUR * 4;
      while (j < ((i + 1) * LARGEUR * 4))
	{
	  my_putc((int) (init->data[j]), fd);
	  my_putc((int) (init->data[j + 1]), fd);
	  my_putc((int) (init->data[j + 2]), fd);
	  j += 4;
	}
      i--;
    }
  close(fd);
}
