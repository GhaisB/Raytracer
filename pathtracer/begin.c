/*
** begin.c for rt in /home/boell_g/Documents/projets/rt
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Fri Jun  1 18:50:26 2012 guillaume boell
** Last update Sat Jun  2 15:19:33 2012 antoine knockaert
*/

#include <pthread.h>
#include "../rt.h"

static void	thread_launch(t_mlx *init)
{
  pthread_t	threadp[4];

  pthread_create(&threadp[0], NULL, calcul_all_pt, (void *) init);
  pthread_create(&threadp[1], NULL, calcul_all_pt, (void *) init);
  pthread_create(&threadp[2], NULL, calcul_all_pt, (void *) init);
  pthread_create(&threadp[3], NULL, calcul_all_pt, (void *) init);
  pthread_join(threadp[0], NULL);
  pthread_join(threadp[1], NULL);
  pthread_join(threadp[2], NULL);
  pthread_join(threadp[3], NULL);
  save_original_data(init);
}

static int	echap(int keycode, void *init)
{
  t_mlx		*init2;

  init2 = (t_mlx *) init;
  if (keycode == 65307)
    my_exit(init2);
  else if (keycode == 110)
    black_white(init2);
  else if (keycode == 98)
    {
      backup_original_data(init2);
      gere_expose(init2);
    }
  else if (keycode == 114)
    reverse_mode(init2);
  else if (keycode == 115)
    export_tga(init2, "raytracer.tga");
  else if (keycode == 100)
    export_bmp(init2->data, "raytracer.bmp");
  else if (keycode == 97)
    aliasing(init2);
  else if (keycode == 65451)
    lumens_mode(init2, 15);
  else if (keycode == 65453)
    lumens_mode(init2, -15);
  return (0);
}

static void	go(char *filename)
{
  t_mlx		*init;
  int		bpp;
  int		sizeline;
  int		endian;

  init = xmalloc(sizeof(t_mlx));
  init->mlx_ptr = mlx_init();
  init->filename = filename;
  if (init->mlx_ptr == NULL)
    exit(0);
  init->win_ptr = mlx_new_window(init->mlx_ptr, LARGEUR, HAUTEUR, "Raytracer");
  if (init->win_ptr == NULL)
    exit(0);
  init->img = mlx_new_image(init->mlx_ptr, LARGEUR, HAUTEUR);
  init->data = (unsigned char *)mlx_get_data_addr(init->img,
						  &bpp, &sizeline, &endian);
  init->pass = 0;
  thread_launch(init);
  mlx_expose_hook(init->win_ptr, gere_expose, init);
  mlx_key_hook(init->win_ptr, echap, init);
  mlx_loop(init->mlx_ptr);
}

int		go_patht(char *str)
{
  if (!XInitThreads())
    {
      my_putstr("Rt-error : Unable to init libX threads\n");
      exit(EXIT_FAILURE);
    }
  go(str);
  return (0);
}
