/*
** export.h for export.h in /home/bouffl_g/Depot/rt/export
** 
** Made by guillaume boufflers
** Login   <bouffl_g@epitech.net>
** 
** Started on  Wed May 23 11:05:48 2012 guillaume boufflers
** Last update Thu May 24 11:02:11 2012 guillaume boufflers
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>

#define RED	0x000000FF
#define BLUE	0x00FF0000
#define GREEN	0x0000FF00
#define ALPHA	0xFF000000

typedef struct s_bmp
{
  uint32_t	filesz;
  uint16_t	creator1;
  uint16_t	creator2;
  uint32_t	bmp_offset;
}		t_bmp;

typedef struct	s_dib
{
  uint32_t	header_sz;
  int32_t	width;
  int32_t	height;
  uint16_t	nplanes;
  uint16_t	bitspp;
  uint32_t	compress_type;
  uint32_t	bmp_bytesz;
  int32_t	hres;
  int32_t	vres;
  uint32_t	ncolors;
  uint32_t	nimpcolors;
  int	        blue;
  int		green;
  int		red;
  int		alpha;
}		t_dib;
