#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Fonction.h"



/********* taille du fichier ************/
int taille(FILE *f)
{  fseek(f,SEEK_SET,SEEK_SET);
     int j=-1;
     int car;
   do {
        j++;
        car=fgetc(f);              //a chaque fois q'un caractere est lu on incremente la taille
         if(car==10) j++;

   }while(car!=EOF);

    return j ;
}
/******************************************/

/**************** fonction de cryptage *********************/

    void cryptage(FILE *f, FILE *g,int cle)
    {
    int car;

    int b,i=0;

        b=taille(f);// recuperer la taille du fichier f
        fseek(f,SEEK_SET,SEEK_SET);

         while(i<=b)// tant que ne pas arriver au debut du fichier f
        {

           fseek(f,-i,SEEK_END); // decaler de 1 caractere de la fin vers le debut
           i++;

          car= fgetc(f);

          if(car!=EOF){

            car+=cle; // on prend un caractere de la fin du fichier 1 on rajoute la cle et on met dans le fichier crypté
            fputc(car,g);


         }

       }

}
/**************************************************/

/**************** fonction de decryptage *******************/
void decryptage( FILE *f,FILE *g,FILE *h,int cle)
{

    int b,i=0;
    int car;


        b=taille(f);

        fseek(g,SEEK_SET,SEEK_SET);

         while(i<=b)
        {

         fseek(g,-i,SEEK_END);
         i++;
         car=fgetc(g);

       if(car!=EOF)
        {
         car-=cle;

         fputc(car,h);

         }

        }

        fclose(h);



    }
/*****************************************/

/********************   Fonction de Comparaison  **********************************/
 int comparaison (FILE *f, FILE *h)
{
       fseek(f,SEEK_SET,SEEK_SET);
        fseek(h,SEEK_SET,SEEK_SET);

        int same=0,carf,carh;

        while((!feof(f))||(!feof(h))&&(same==0)) // tant que same est different de faux on reboucle
        {
            carf=fgetc(f);
            carh=fgetc(h);

            if(carf==carh)// si les caracteres de h et f sont egaux alors same est vrai
                {

                same=0;
           }
            else{
                if((carf==EOF)||(carh==EOF))
                {
                    same=0;
                }else {
                     if((carf==10)||(carh==10)) {same=0;}


                  else{  same=1; }// si le caractere de f different de caractere de h alors same est a faux
                }
            }
        }return same;
}
/******************** MENU******************************************/

int menu(){
    int c=0;
while (c<1||c>5){
           /* affichage menu */
      printf( "\t\t\t------------------------------------------------\n"
             " \t\t\t********* VOICI LE MENU DU PROGRAMME **********\n"
             "\t\t\t--------------------------------------------------\n"
              "\t\t\t\t 1.Le fonctionnement\n \n"
              "\t\t\t\t 2.Le cryptage \n\n"
              "\t\t\t\t 3.Le decryptage \n\n"
              "\t\t\t\t 4.La comparaison\n\n"
              "\t\t\t\t 5.Quitter\n\n");
              scanf("%d",&c);
    }

    return c ;
}
/************** Couleur**********************/

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
