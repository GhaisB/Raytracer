/*
** my_strcmp.c for str in /home/knocka_a/rendu/c/korewar/virtual_m
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat Feb 11 11:57:07 2012 antoine knockaert
** Last update Sat May  5 15:06:35 2012 antoine knockaert
*/

#include	"../rt.h"

int		my_match(char *str1, char *str2)
{
  int		i;

  i = 0;
  while (str1 && str2 && str1[i] && str2[i])
    {
      if (str1[i] != str2[i])
	return (0);
      i++;
    }
  if (str1 && str2 && str1[i] == 0 && str2[i] == 0)
    return (1);
  else
    return (0);
}
