/*
** setenv.c for minishell1 in /home/boell_g/Documents/projets/minishell1
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Fri Dec 16 15:40:17 2011 guillaume boell
** Last update Tue Apr 24 22:48:34 2012 antoine knockaert
*/
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include "../rt.h"

int	is_same(char *str, char *to_comp)
{
  int	i;

  i = 0;
  while (str[i] && to_comp[i] && str[i] == to_comp[i])
    i++;
  if (to_comp[i] == 0)
    return (i);
  else
    return (0);
}

int	get_word_lenght(char *s)
{
  int	i;

  i = 0;
  while (s[i] && s[i] != '\n')
    i++;
  return (i);
}

char	*get_term_name(char **envp)
{
  int	i;
  int	y;
  char	*word;

  i = y = 0;
  while (*envp && !(i = is_same(*envp, "TERM=")))
    {
      is_same(*envp, "TERM=");
      envp++;
    }
  if (*envp)
    word = xmalloc(get_word_lenght(*envp + i) + 1);
  else
    {
      my_putstr("TERM NOT SET\n");
      exit(0);
    }
  while (*envp && (*envp)[i] && (*envp)[i] != '\n')
    {
      word[y] = (*envp)[i];
      y++;
      i++;
    }
  word[y] = 0;
  return (word);
}
