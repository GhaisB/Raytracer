/*
** my_strdup.c for strdup in /home/knocka_a/repositories/rt/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sun Apr 29 22:47:48 2012 antoine knockaert
** Last update Fri May  4 15:18:58 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"../edit.h"

char		*my_strdup(char *str)
{
  char		*ret;
  int		i;

  i = 0;
  ret = NULL;
  ret = xmalloc((my_strlen(str) + 5) * sizeof(char));
  while (ret && str && str[i])
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}
