/*
** begin.c for rt in /home/boell_g/Documents/projets/rt
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Wed May 30 17:42:03 2012 guillaume boell
** Last update Sun Jun  3 19:53:40 2012 florian dell'aiera
*/

#include "../rt.h"

#define X2(x) (x * x)
#define MRAD(x) ((x * M_PI) / 180)

int		gere_expose(t_mlx *init)
{
  mlx_put_image_to_window(init->mlx_ptr, init->win_ptr, init->img, 0, 0);
  return (0);
}

static void	thread_launch(t_mlx *init)
{
  pthread_t	threadp[4];

  if (pthread_create(&threadp[0], NULL, calcul_all, (void *) init))
    my_putstr("Error on launch calc1.\n");
  if (pthread_create(&threadp[1], NULL, calcul_all2, (void *) init))
    my_putstr("Error on launch calc1.\n");
  if (pthread_create(&threadp[2], NULL, calcul_all3, (void *) init))
    my_putstr("Error on launch calc1.\n");
  if (pthread_create(&threadp[3], NULL, calcul_all4, (void *) init))
    my_putstr("Error on launch calc1.\n");
  if (pthread_join(threadp[0], NULL))
    my_putstr("Error on join1.\n");
  if (pthread_join(threadp[1], NULL))
    my_putstr("Error on join2.\n");
  if (pthread_join(threadp[2], NULL))
    my_putstr("Error on join3.\n");
  if (pthread_join(threadp[3], NULL))
    my_putstr("Error on join4.\n");
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

static void	func1(char *filename)
{
  t_mlx		*init;
  int		bpp;
  int		sizeline;
  int		endian;

  init = xmalloc(sizeof(t_mlx));
  init->filename = filename;
  init->mlx_ptr = mlx_init();
  if (init->mlx_ptr == NULL)
    exit(0);
  init->win_ptr = mlx_new_window(init->mlx_ptr, LARGEUR, HAUTEUR, "Raytracer");
  if (init->win_ptr == NULL)
    exit(0);
  init->img = mlx_new_image(init->mlx_ptr, LARGEUR, HAUTEUR);
  init->data = (unsigned char *) mlx_get_data_addr(init->img, &bpp,
						   &sizeline, &endian);
  thread_launch(init);
  mlx_expose_hook(init->win_ptr, gere_expose, init);
  mlx_key_hook(init->win_ptr, echap, init);
  mlx_loop(init->mlx_ptr);
}

int		go_rayt(char *filename)
{
  if (!XInitThreads())
    {
      my_putstr("Rt-error : Unable to init libX threads\n");
      exit(EXIT_FAILURE);
    }
  func1(filename);
  return (0);
}
