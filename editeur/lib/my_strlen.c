/*
** my_strlen.c for he in /home/duez_a//rtv1/tp
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue Feb 14 16:10:56 2012 guillaume duez
** Last update Tue May 22 11:59:57 2012 antoine knockaert
*/

#include	"../edit.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}
