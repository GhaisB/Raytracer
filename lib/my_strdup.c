/*
** my_strdup.c for my_str in /home/knocka_a/rendu/c/allum1_reseau
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sun Feb  5 22:59:58 2012 antoine knockaert
** Last update Wed May  9 01:01:39 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"../rt.h"

char		*my_strdup(char *str)
{
  int		size;
  char		*ret;
  int		i;

  if (str == NULL)
    return (NULL);
  i = 0;
  size = my_strlen(str);
  ret = xmalloc((size + 10) * sizeof(char));
  if (ret)
    {
      while (str[i])
	{
	  ret[i] = str[i];
	  i++;
	}
      ret[i] = '\0';
    }
  return (ret);
}
