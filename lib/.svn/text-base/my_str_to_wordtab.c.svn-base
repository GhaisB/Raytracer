/*
** my_str_to_wordtab.c for tab in /home/knocka_a/rendu/c/minishell1_re
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Dec 19 14:30:20 2011 antoine knockaert
** Last update Sat Jun  2 14:31:57 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"../rt.h"

static int	count_oc(char *str, char c)
{
  int		i;
  int		count;

  count = 0;
  i = 0;
  while (str && str[i])
    {
      if (str[i] == c)
	{
	  count++;
	  while (str[i] == c)
	    i++;
	}
      i++;
    }
  return (count);
}

static char	**tab_is_null()
{
  char		**tab;

  tab = xmalloc(1 * sizeof(char *));
  if (tab)
    tab[0] = NULL;
  return (tab);
}

char		**my_str_to_wordtab(char *str, char c)
{
  int		i;
  int		j;
  int		k;
  char		**tab;

  i = 0;
  j = 0;
  tab = xmalloc((count_oc(str, c) + 2) * sizeof(char *));
  if (str == NULL || tab == NULL)
    return (tab_is_null());
  while (tab && str && str[i] && str[i] == c)
    i++;
  while (tab && str[i])
    {
      tab[j] = xmalloc((my_strlen(str) + 2) * sizeof(char));
      k = 0;
      while (tab[j] && str[i] && str[i] != c)
	tab[j][k++] = str[i++];
      if (tab[j])
	tab[j++][k] = '\0';
      while (str && str[i] && str[i] == c)
	i++;
    }
  tab[j] = NULL;
  return (tab);
}
