/*
** xappels.c for fdf in /home/boell_g/Documents/projets/fdf/graphtest
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Mon Dec  5 10:51:06 2011 guillaume boell
** Last update Sat Apr 28 20:02:00 2012 antoine knockaert
*/
#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	"../edit.h"

int		xread(int fd, void *buf, size_t count)
{
  int		ret;

  if ((ret = read(fd, buf, count)) == -1)
    {
      my_putstr("Gtk: Error on read\n");
      exit(0);
    }
  return (ret);
}

int		xopen(const char *pathname, int flags)
{
  int		ret;

  if ((ret = open(pathname, flags)) == -1)
    {
      my_putstr("Gtk: Error on open\n");
      exit(0);
    }
  return (ret);
}

int		xclose(int fd)
{
  if (close(fd) == -1)
    {
      my_putstr("Gtk: Error on clone\n");
      exit(0);
    }
  return (0);
}
