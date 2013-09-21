/*
** main.c for my_select in /home/boell_g/projets/my_select
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Fri Jan  6 14:21:53 2012 guillaume boell
** Last update Thu May  3 10:49:46 2012 guillaume boell
*/
#include <unistd.h>
#include <termios.h>
#include <term.h>
#include "../rt.h"

int	put_int(int c)
{
  if (write(1, &c, 1) == -1)
    exit(0);
  return (0);
}

void	activ_cap(char *name)
{
  char	*str;

  if ((str = tgetstr(name, NULL)) != NULL)
    tputs(str, 1, put_int);
}

void	param_term(struct termios *t, int is_end)
{
  if (!is_end)
    {
      t->c_lflag &= ~ICANON;
      t->c_cc[VMIN]= 1;
      t->c_cc[VTIME] = 0;
    }
  else
    {
      t->c_lflag |= ICANON;
      t->c_cc[VMIN]= 0;
      t->c_cc[VTIME] = 0;
    }
  xtcsetattr(0, 0, t);
}
