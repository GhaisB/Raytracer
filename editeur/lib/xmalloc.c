/*
** xmalloc.c for xla* in /home/duez_a//ls
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Sun Dec  4 19:55:31 2011 guillaume duez
** Last update Fri Apr 27 23:44:57 2012 antoine knockaert
*/

#include	"../edit.h"

void		*xmalloc(int size)
{
  void		*str;

  str = malloc((size + 1));
  if (str == NULL)
    {
      my_putstr("Gtk: Error on malloc.\n");
      exit(EXIT_FAILURE);
    }
  return (str);
}
