/*
** xappels.c for fdf in /home/boell_g/Documents/projets/fdf/graphtest
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Mon Dec  5 10:51:06 2011 guillaume boell
** Last update Mon May 21 10:04:50 2012 antoine knockaert
*/
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <term.h>
#include <fcntl.h>
#include "../rt.h"

int	xread(int fd, void *buf, size_t count)
{
  int	ret;

  if ((ret = read(fd, buf, count)) == -1)
    {
      my_putstr("read: error\n");
      exit(0);
    }
  return (ret);
}

void	xtcsetattr(int fd, int opts, const struct termios *termios_p)
{
  if (tcsetattr(fd, opts, termios_p) == -1)
    my_putstr("tcsetattr error");
}

int	xtgetent(const char *name)
{
  int	ret;

  if ((ret = tgetent(NULL, name)) != 1)
    exit(0);
  return (ret);
}

int	xopen(const char *pathname, int flags)
{
  int	ret;

  if ((ret = open(pathname, flags)) == -1)
    {
      my_putstr("open: fichier inexistant\n");
      exit(0);
    }
  return (ret);
}

int	xclose(int fd)
{
  if (close(fd) == -1)
    {
      my_putstr("close: error\n");
      exit(0);
    }
  return (0);
}
