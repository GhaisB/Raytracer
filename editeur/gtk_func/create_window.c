/*
** new_window.c for new_window in /home/knocka_a/repositories/rt/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Apr 27 17:15:40 2012 antoine knockaert
** Last update Sat Jun  2 19:13:58 2012 antoine knockaert
*/

#include	"../edit.h"

/*
** Positons possibles :
** GTK_WIN_POS_NONE : Random
**            _CENTER
**            _MOUSE
**            _CENTER_ALWAYS
**            _CENTER_ON_PARENT
**
** Types possible :
** GTK_WINDOW_TOPLEVEL / GTK_WINDOW_POPUP
**
*/
GtkWidget	*create_window(char *title, GtkWindowType type,
			       GtkWindowPosition position, int *size)
{
  GtkWidget	*pwindow;

  pwindow = NULL;
  pwindow = gtk_window_new(type);
  if (pwindow)
    {
      gtk_window_set_position(GTK_WINDOW(pwindow), position);
      gtk_window_set_default_size(GTK_WINDOW(pwindow), size[0], size[1]);
      gtk_window_set_title(GTK_WINDOW(pwindow), (const gchar *) title);
      gtk_window_set_resizable(GTK_WINDOW(pwindow), TRUE);
      gtk_window_set_decorated(GTK_WINDOW(pwindow), TRUE);
    }
  else
    my_putstr("Gtk: Error while creating window\n");
  return (pwindow);
}
