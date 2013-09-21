/*
** pobj_window.c for pobj_window in /home/knocka_a/src
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Tue May 22 12:47:33 2012 antoine knockaert
** Last update Sun Jun  3 19:33:17 2012 antoine knockaert
*/

#include	"../edit.h"

static void	fill_entry_pobj(t_pobj *pobj)
{
  base_options(pobj);
  others_options(pobj);
  pobj->entry[35] = create_gtk_entry(3, "py");
  pobj->entry[36] = create_gtk_entry(3, "pz");
}

static void	fill_widgets_pobj(t_pobj *pobj, t_glob *glob)
{
  int		i;
  int		size[2];

  size[0] = WIDTH_OBJ_WINDOW;
  size[1] = HEIGHT_OBJ_WINDOW;
  pobj->pwindow = create_window(TITLE_OBJ_WINDOW, GTK_WINDOW_TOPLEVEL,
				GTK_WIN_POS_CENTER, size);
  i = 0;
  while (i < NB_PARAM + START_PARAMS)
    {
      pobj->lbl[i] = create_label(glob->pobj_labels[i], GTK_JUSTIFY_LEFT, NULL);
      i++;
    }
  pobj->frame[0] = gtk_frame_new(TXT_NEW_ESSENTIALS);
  pobj->frame[1] = gtk_frame_new(TXT_NEW_OPTIONS);
  pobj->button[0] = create_button(2, TXT_BUTTON_CANCEL);
  pobj->button[1] = create_button(2, TXT_BUTTON_SAVE);
  pobj->vbox[0] = gtk_vbox_new(FALSE, 0);
  pobj->vbox[1] = gtk_vbox_new(FALSE, 0);
  pobj->vbox[2] = gtk_vbox_new(FALSE, 0);
  i = 0;
  while (i < 10)
    pobj->hbox[i++] = gtk_hbox_new(FALSE, 0);
  fill_entry_pobj(pobj);
}

void		connect_signal_pobj(t_glob *glob)
{
  g_signal_connect(G_OBJECT(glob->pobj->button[1]), "clicked",
		   G_CALLBACK(valide_obj), glob);
  g_signal_connect(G_OBJECT(glob->pobj->button[0]), "clicked",
		   G_CALLBACK(destroy_window), NULL);
}

void		pobj_window(GtkWidget *widget, gpointer data)
{
  t_glob	*glob;

  widget = widget;
  glob = (t_glob *) data;
  glob->pobj = xmalloc(sizeof(t_pobj));
  fill_widgets_pobj(glob->pobj, glob);
  link_pobj_widget(glob->pobj);
  connect_signal_pobj(glob);
  gtk_widget_show_all(glob->pobj->pwindow);
}
