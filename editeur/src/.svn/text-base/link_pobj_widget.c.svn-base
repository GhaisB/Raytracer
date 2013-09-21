/*
** link_main_widgets.c for link in /home/knocka_a/repositories/rt/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat Apr 28 18:08:50 2012 antoine knockaert
** Last update Sun Jun  3 12:11:11 2012 antoine knockaert
*/

#include	"../edit.h"

static void	link_pobj_base_first(t_pobj *pobj)
{
  gtk_container_add(GTK_CONTAINER(pobj->pwindow), pobj->vbox[0]);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[0]), pobj->hbox[0], TRUE, FALSE, 10);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[0]), pobj->frame[0], TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[0]), pobj->frame[1], TRUE, TRUE, 10);
  gtk_container_add(GTK_CONTAINER(pobj->frame[0]), pobj->vbox[1]);
  gtk_container_add(GTK_CONTAINER(pobj->frame[1]), pobj->vbox[2]);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[1]), pobj->lbl[0], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[1]), pobj->entry[0], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[1]), pobj->lbl[1], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[1]), pobj->entry[1], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[1]), pobj->lbl[2], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[1]), pobj->entry[2], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[1]), pobj->lbl[3], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[1]), pobj->hbox[2], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[2]), pobj->entry[3], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[2]), pobj->entry[4], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[2]), pobj->entry[5], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[1]), pobj->lbl[20], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[1]), pobj->entry[6], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[1]), pobj->lbl[4], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[1]), pobj->hbox[3], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[3]), pobj->entry[7], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[3]), pobj->entry[8], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[3]), pobj->entry[9], TRUE, FALSE, 2);
}

static void	link_pobj_base_second(t_pobj *pobj)
{
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[5], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->entry[10], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[6], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->entry[11], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[7], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->entry[12], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[8], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->entry[13], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[9], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->hbox[4], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[4]), pobj->entry[14], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[4]), pobj->entry[15], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[4]), pobj->entry[16], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[10], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->hbox[5], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[5]), pobj->entry[17], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[5]), pobj->entry[18], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[5]), pobj->entry[19], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[11], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->hbox[6], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[6]), pobj->entry[20], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[6]), pobj->entry[21], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[6]), pobj->entry[22], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[12], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->entry[23], TRUE, FALSE, 2);
}

static void	link_pobj_opt_first(t_pobj *pobj)
{
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[13], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->entry[24], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[14], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->entry[25], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[15], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->entry[26], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[16], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->entry[27], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[17], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->hbox[7], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[7]), pobj->entry[28], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[7]), pobj->entry[29], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[7]), pobj->entry[30], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[18], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->hbox[8], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[8]), pobj->entry[31], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[8]), pobj->entry[32], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[8]), pobj->entry[33], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->lbl[19], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[2]), pobj->hbox[9], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[9]), pobj->entry[34], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[9]), pobj->entry[35], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[9]), pobj->entry[36], TRUE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(pobj->vbox[0]), pobj->hbox[1], TRUE, FALSE, 10);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[1]), pobj->button[0], TRUE, FALSE, 10);
}

void		link_pobj_widget(t_pobj *pobj)
{
  link_pobj_base_first(pobj);
  link_pobj_base_second(pobj);
  link_pobj_opt_first(pobj);
  gtk_box_pack_start(GTK_BOX(pobj->hbox[1]), pobj->button[1], TRUE, FALSE, 10);
}
