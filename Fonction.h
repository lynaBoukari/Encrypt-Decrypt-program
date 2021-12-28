#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
FILE *f,*g,*h;

int taille(FILE *f);

void cryptage(FILE *f, FILE *g,int cle);

void decryptage( FILE *f,FILE *g,FILE *h,int cle);

int comparaison (FILE *f, FILE *h);

int menu();

void Color(int couleurDuTexte,int couleurDeFond);

#endif // FONCTION_H_INCLUDED
