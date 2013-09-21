/*
** hex_to_double.c for hex_to_double in /home/knocka_a
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Wed May  9 19:56:52 2012 antoine knockaert
** Last update Thu May 31 20:13:05 2012 antoine knockaert
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static double	my_pow(int nb, int pow)
{
  double	res;
  int		i;

  i = 0;
  res = nb;
  if (pow == 0)
    return (1);
  else if (pow == 1)
    return (nb);
  else
    {
      while (i < (pow - 1))
	{
	  res *= nb;
	  i++;
	}
    }
  return (res);
}

static int	recup_char(char c)
{
  if (c <= '9' && c >= '0')
    return (c - '0');
  else if (c >= 'A' && c <= 'F')
    return (c - 55);
  else
    return (0);
}

double		hex_to_double(char *str)
{
  int		i;
  int		pow;
  double	inter;
  double	result;

  result = 0;
  pow = 0;
  i = strlen(str) - 1;
  while (i >= 0)
    {
      inter = my_pow(16, pow);
      result += recup_char(str[i]) * inter;
      i--;
      pow++;
    }
  return (result);
}
