/*
** widget_for_obj.c for wdj in /home/knocka_a/repositories/rt/editeur/src
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sun Jun  3 09:51:33 2012 antoine knockaert
** Last update Sun Jun  3 10:05:51 2012 antoine knockaert
*/

#include	"../edit.h"

void		others_options(t_pobj *pobj)
{
  pobj->entry[10] = create_gtk_entry(3, "");
  pobj->entry[11] = create_gtk_entry(3, "");
  pobj->entry[12] = create_gtk_entry(3, "");
  pobj->entry[13] = create_gtk_entry(3, "");
  pobj->entry[14] = create_gtk_entry(3, "ax");
  pobj->entry[15] = create_gtk_entry(3, "ay");
  pobj->entry[16] = create_gtk_entry(3, "az");
  pobj->entry[17] = create_gtk_entry(3, "bx");
  pobj->entry[18] = create_gtk_entry(3, "by");
  pobj->entry[19] = create_gtk_entry(3, "bz");
  pobj->entry[20] = create_gtk_entry(3, "cx");
  pobj->entry[21] = create_gtk_entry(3, "cy");
  pobj->entry[22] = create_gtk_entry(3, "cz");
  pobj->entry[23] = create_gtk_entry(3, "");
  pobj->entry[24] = create_gtk_entry(3, "");
  pobj->entry[25] = create_gtk_entry(3, "");
  pobj->entry[26] = gtk_check_button_new_with_mnemonic("_Activer le damier");
  pobj->entry[27] = create_gtk_entry(3, "");
  pobj->entry[28] = create_gtk_entry(3, "lx");
  pobj->entry[29] = create_gtk_entry(3, "ly");
  pobj->entry[30] = create_gtk_entry(3, "lz");
  pobj->entry[31] = create_gtk_entry(3, "lx");
  pobj->entry[32] = create_gtk_entry(3, "ly");
  pobj->entry[33] = create_gtk_entry(3, "lz");
  pobj->entry[34] = create_gtk_entry(3, "px");
}

void		base_options(t_pobj *pobj)
{
  pobj->entry[0] = create_gtk_entry(20, "");
  pobj->entry[1] = gtk_combo_box_text_new();
  gtk_combo_append(GTK_COMBO_BOX_TEXT(pobj->entry[1]), "SPHERE");
  gtk_combo_append(GTK_COMBO_BOX_TEXT(pobj->entry[1]), "PLAN");
  gtk_combo_append(GTK_COMBO_BOX_TEXT(pobj->entry[1]), "CYLINDRE");
  gtk_combo_append(GTK_COMBO_BOX_TEXT(pobj->entry[1]), "CONE");
  gtk_combo_append(GTK_COMBO_BOX_TEXT(pobj->entry[1]), "PARABOLOIDE");
  gtk_combo_append(GTK_COMBO_BOX_TEXT(pobj->entry[1]), "DISQUE");
  gtk_combo_append(GTK_COMBO_BOX_TEXT(pobj->entry[1]), "SELLE");
  gtk_combo_append(GTK_COMBO_BOX_TEXT(pobj->entry[1]), "PARALELLOGRAMME");
  gtk_combo_append(GTK_COMBO_BOX_TEXT(pobj->entry[1]), "TRIANGLE");
  gtk_combo_append(GTK_COMBO_BOX_TEXT(pobj->entry[1]), "TORE");
  gtk_combo_append(GTK_COMBO_BOX_TEXT(pobj->entry[1]), "CUBETROUE");
  gtk_combo_append(GTK_COMBO_BOX_TEXT(pobj->entry[1]), "LAMPE");
  pobj->entry[2] = gtk_color_button_new();
  gtk_color_button_set_title(GTK_COLOR_BUTTON(pobj->entry[2]),
			     "Choisissez une couleur :");
  pobj->entry[3] = create_gtk_entry(3, "x");
  pobj->entry[4] = create_gtk_entry(3, "y");
  pobj->entry[5] = create_gtk_entry(3, "z");
  pobj->entry[6] = create_gtk_entry(3, "r");
  pobj->entry[7] = create_gtk_entry(3, "rx");
  pobj->entry[8] = create_gtk_entry(3, "ry");
  pobj->entry[9] = create_gtk_entry(3, "rz");
}
