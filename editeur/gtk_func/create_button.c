/*
** create_button.c for create_button in /home/knocka_a/repositories/rt/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Apr 27 22:24:17 2012 antoine knockaert
** Last update Sat Apr 28 12:27:40 2012 antoine knockaert
*/

#include	"../edit.h"

/*
** Types : 1 = Button with label, 2 = Button with label + Mnemonique
** 3 : Button + Label + Image
*/

GtkWidget	*create_button(int type, char *str)
{
  GtkWidget	*button;
  gchar		*str2;

  button = NULL;
  str2 = g_locale_to_utf8(str, -1, NULL, NULL, NULL);
  if (type == 1)
    button = gtk_button_new_with_label((const gchar *) str);
  else if (type == 2)
    button = gtk_button_new_with_mnemonic((const gchar *) str);
  else if (type == 3)\
    button = gtk_button_new_from_stock((const gchar *) str);
  g_free(str2);
  if (!button)
    my_putstr("Gtk: Error while creating button.\n");
  return (button);
}
