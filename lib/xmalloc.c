/*
** xmalloc.c for xmalloc in /home/knocka_a/repositories/42sh/lib
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Apr  9 14:02:34 2012 antoine knockaert
** Last update Sat May 26 15:31:58 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"../rt.h"

void		*xmalloc(int size)
{
  void		*tmp;

  tmp = NULL;
  tmp = malloc(size);
  if (tmp == NULL)
    {
      my_putstr("Error on malloc\n");
      exit(EXIT_FAILURE);
    }
  return (tmp);
}
