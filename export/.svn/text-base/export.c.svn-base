/*
** export.c for export in /home/knocka_a/repositories/rt/parsing
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Thu May 31 17:00:54 2012 antoine knockaert
** Last update Sat Jun  2 14:38:38 2012 antoine knockaert
*/

#include "./export.h"
#include "../rt.h"

int	nb_line(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    i++;
  return (i + 1);
}

void	write_the_file(t_bmp *bmp, t_dib *dib, int fd, unsigned char *data)
{
  char	**map;

  dib = dib;
  my_putchar_file('B', fd);
  my_putchar_file('M', fd);
  if (write(fd, bmp, sizeof(t_bmp)) == -1)
    exit(0);
  if (write(fd, dib, sizeof(t_dib)) == -1)
    exit(0);
  data = make_decalage(data);
  map = get_map(data);
  put_pix_bmp(map, fd);
}

void	init_bmp(t_bmp **bmp)
{
  (*bmp)->filesz = sizeof(t_bmp) + sizeof(t_dib) + 2 + LARGEUR * HAUTEUR * 4;
  (*bmp)->creator1 = 0;
  (*bmp)->creator2 = 0;
  (*bmp)->bmp_offset = sizeof(t_bmp) + sizeof(t_dib) + 2;
}

void	init_dib(t_dib **dib)
{
  (*dib)->header_sz = sizeof(t_dib);
  (*dib)->width = LARGEUR;
  (*dib)->height = HAUTEUR;
  (*dib)->nplanes = 1;
  (*dib)->bitspp = 32;
  (*dib)->compress_type = 3;
  (*dib)->bmp_bytesz = 32;
  (*dib)->hres = 2835;
  (*dib)->vres = 2835;
  (*dib)->ncolors = 0;
  (*dib)->nimpcolors = 0;
  (*dib)->green = GREEN;
  (*dib)->blue = BLUE;
  (*dib)->red = RED;
  (*dib)->alpha = ALPHA;
}

void	export_bmp(unsigned char *data, char *filename)
{
  t_dib	*dib;
  t_bmp	*bmp;
  int	fd;
  int	right;

  dib = xmalloc(sizeof(t_dib));
  bmp = xmalloc(sizeof(t_bmp));
  right = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
  fd = open(filename, O_CREAT | O_RDWR, right);
  init_bmp(&bmp);
  init_dib(&dib);
  write_the_file(bmp, dib, fd, data);
}
