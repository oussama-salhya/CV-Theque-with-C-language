#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define BIG_MAX 100
#define MAX 25
#include "TPAYS.h"
#include "TPERMIS.h"
#include "TETATCIVILE.h"
#include "TVILLES.h"
#include "TLANGUE.h"
#include "TCANDIDATS.h"
#include "TEXPERIENCES.h"
#include "TTYPECONTRAT.h"
#include "TCV.h"
#include "TLANGUE.h"


struct TLANGUE
{
  int Idlng;
  char NomLng[50];
  char Nvlecture[50];
  char Nvecrit[50];
  char Nvoral[50];
  int Idcvl;

};struct TLANGUE L;

void AjouterLng()
{

	FILE *Fl;
	Fl=fopen("TLANGUE.txt","a");
	test_file_opening(Fl);
  printf("\tSaisir le Nom de la langue ");
  scanf("%s",&L.NomLng);
  	getchar();
  	if(RechercheLngParNom(L.NomLng)==1)
    {
        printf("Cette langue existe deja \n");
        return;
    }
 	printf("\tSaisir le niveau de lecture de cette langue ");
	scanf("%s",&L.Nvlecture);
    printf("\tSaisir le niveau d'ecriture de cette langue ");
	scanf("%s",&L.Nvecrit);
	printf("\tSaisir le niveau oral de cette langue ");
	scanf("%s",&L.Nvoral);
    printf("\tSaisir l'indice du Cv ou se trouve cette langue ");
  	L.Idcvl=SaisirCV();
	L.Idlng=getIDLng("TLANGUE.txt")+1;
	fflush(stdin);
	fprintf(Fl,"%d ;%s ;%s ;%s ;%s ;%d \n",L.Idlng,L.NomLng,L.Nvecrit,L.Nvlecture,L.Nvoral,L.Idcvl);
	printf("\n\nla langue %u %s est ajoute au fichier TLANGUE.txt avec success \n",L.Idlng,L.NomLng);
	fclose(Fl);
}

void RechercheLng()
{
	int NumR,j=0;
	printf("\n\tEntrez l'indice de la langue a rechercher :");
	scanf("%d",&NumR);
	FILE *Fl;
	Fl=fopen("TLANGUE.txt","r");
	do
	{
	fscanf(Fl,"%d ;%s ;%s ;%s ;%s ;%d \n",&L.Idlng,&L.NomLng,&L.Nvecrit,&L.Nvlecture,&L.Nvoral,&L.Idcvl);
	if(NumR==L.Idlng)
	{
	        printf("\n\t===============INFORMATION SUR LA LANGUE : %d  ================\n\t ",L.Idlng);
	        printf("\n\tLe Nom de la langue : %s",L.NomLng);
	        printf("\n\tLe niveau de lecture de cette langue : %s",L.Nvlecture);
	        printf("\n\tLe niveau d'ecriture de cette langue : %s",L.Nvecrit);
	        printf("\n\tLe niveau oral de cette langue : %s",L.Nvoral);
	        AfficherCVComp(L.Idcvl);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fl));
	fclose(Fl);
	if(j==0){
	    printf("\n\tDesole! cette langue n'existe pas\n");
	}
}

void SupprimerLng()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez L'indice de la langue a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechLng(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Flt,*Fl;
	        Fl=fopen("TLANGUE.txt","r");
	        test_file_opening(Fl);
	        Flt=fopen("LANGUE.txt","a");
	        test_file_opening(Flt);
	        do
	        {
	         fscanf(Fl,"%d ;%s ;%s ;%s ;%s ;%d \n",&L.Idlng,&L.NomLng,&L.Nvecrit,&L.Nvlecture,&L.Nvoral,&L.Idcvl);
	         if(NumRech!=L.Idlng)
	         {
			          fprintf(Flt,"%d ;%s ;%s ;%s ;%s ;%d \n",L.Idlng,L.NomLng,L.Nvecrit,L.Nvlecture,L.Nvoral,L.Idcvl);
	         }
	        }while(!feof(Fl));
	        fclose(Flt);
	        fclose(Fl);
	        remove("TLANGUE.txt");
	        rename("LANGUE.txt","TLANGUE.txt");
	        printf("\n\tLa suppression Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tl'indice de la langue n'existe pas");
	}
}

void ModifierLng(){

	FILE *Fl,*Flt;
	int num,i;
	char rep='n';
	printf("\n\tEntrez L'indice de la langue a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechLng(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fl=fopen("TLANGUE.txt","r");
	    test_file_opening(Fl);
	    Flt=fopen("LANGUE.txt","a");
	    test_file_opening(Flt);

	 do
	{
    fscanf(Fl,"%d ;%s ;%s ;%s ;%s ;%d \n",&L.Idlng,&L.NomLng,&L.Nvecrit,&L.Nvlecture,&L.Nvoral,&L.Idcvl);
	if(num==L.Idlng)
	{
		L.Idlng=num;
		printf("\tSaisir le nouveau Nom de la langue ");
  	scanf("%s",&L.NomLng);
    if(RechercheLngParNom(L.NomLng)==1)
    {
        printf("\tCette langue existe deja \n");
        return;
    }
	  printf("\tSaisir le nouveau niveau de lecture  ");
		scanf("%s",&L.Nvlecture);
	  printf("\tSaisir le nouveau niveau d'ecriture  ");
		scanf("%s",&L.Nvecrit);
		printf("\tSaisir le nouveau niveau oral  ");
		scanf("%s",&L.Nvoral);
	  printf("\tSaisir le nouveau indice du Cv de cette langue Parmis cette liste ");
	  L.Idcvl=SaisirCV();
	}
  fprintf(Flt,"%d ;%s ;%s ;%s ;%s ;%d \n",L.Idlng,L.NomLng,L.Nvecrit,L.Nvlecture,L.Nvoral,L.Idcvl);
	}while(!feof(Fl));
    fclose(Flt);
    fclose(Fl);
	remove("TLANGUE.txt");
	rename("LANGUE.txt","TLANGUE.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annule\n");
	}
	}
	else
	{
	printf("\n\tL'indice de la langue N'existe pas\n");
	}
}

int RechercheLngParNom(char * NomLng)
{
    int 	id;
    char  Nomlangue_courant[MAX];
    char  Nvlecture_courant[MAX];
    char  Nvecrit_courant[MAX];
    char  Nvoral_courant[MAX];
    int   idcv;
    char  line[BIG_MAX];
    FILE * F=fopen("TLANGUE.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
        fscanf(F,"%d ;%s ;%s ;%s ;%s ;%d \n",&id,&Nomlangue_courant,&Nvecrit_courant,&Nvlecture_courant,&Nvoral_courant,&idcv);
        if(!strcmp(NomLng,Nomlangue_courant))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechLng(int Numrech)
{
	FILE *Fl;
	Fl=fopen("TLANGUE.txt","r");
	test_file_opening(Fl);
	do
		{
		fscanf(Fl,"%d ;%s ;%s ;%s ;%s ;%d \n",&L.Idlng,&L.NomLng,&L.Nvecrit,&L.Nvlecture,&L.Nvoral,&L.Idcvl);
		fflush(stdin);
		if(L.Idlng==Numrech)
			{
			fclose(Fl);
			return 1;
			}
		}while(!feof(Fl));
	fclose(Fl);
	return -1;
}

void AfficherLng()
{
	FILE *Fl;
	Fl=fopen("TLANGUE.txt","r");
	do
	{
    fscanf(Fl,"%d ;%s ;%s ;%s ;%s ;%d \n",&L.Idlng,&L.NomLng,&L.Nvecrit,&L.Nvlecture,&L.Nvoral,&L.Idcvl);
	        printf("\n\t===============INFORMATION SUR LA LANGUE : %d  ================\n\t ",L.Idlng);
            printf("\n\tLe Nom de la langue : %s",L.NomLng);
	        printf("\n\tLe niveau de lecture de cette langue : %s",L.Nvlecture);
	        printf("\n\tLe niveau d'ecriture de cette langue : %s",L.Nvecrit);
	        printf("\n\tLe niveau oral de cette langue : %s",L.Nvoral);
	        AfficherCVComp(L.Idcvl);
	        printf("\n\t-----------------------------------------------------------------");
	}while(!feof(Fl));
	fclose(Fl);
}

int getIDLng(char *File)
{
	int j=(-1);
    int 	id;
    char  Nomlangue_courant[MAX];
    char  Nvlecture_courant[MAX];
    char  Nvecrit_courant[MAX];
    char  Nvoral_courant[MAX];
    int   idcv;
	char N[100];
    FILE *F;
    F=fopen("TLANGUE.txt","r");
    test_file_opening(F);
    while(!feof(F))
	{
    fgets(N,100,F);
    j++;
	}
    if(j==0)
    {
    	fclose(F);
		return 0;
	}
	else
	{
		fclose(F);
		F=fopen(File,"r");
		test_file_opening(F);
		while(!feof(F))
		{
      fscanf(F,"%d ;%s ;%s ;%s ;%s ;%d \n",&id,&Nomlangue_courant,&Nvecrit_courant,&Nvlecture_courant,&Nvoral_courant,&idcv);
		}
	fclose(F);
	return id;
	}
}



void MenuLng()
{
int Choix;char rep;
do
	{
	    system("cls");
	    printf("\n\t               ***********************                ");
	    printf("\n\t****************   MENU DES LANGUES   ********************");
	    printf("\n\t               ***********************                ");
	    printf("\n\t                                               \n");
	    printf("\t*  (1) Ajouter une langue                       *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (2) Rechercher une langue                    *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (3) Supprimer une langue                     *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (4) Modifier une langue                      *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (5) Afficher toutes Les langues              *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (6) Quiter                                   *\n");
	    printf("\t*-----------------------------------------------*\n");

	    do
		    {
		     printf("\n\t>>> Etrez votre choix...");
		     scanf("%d",&Choix);
		     fflush(stdin);
		    }while(Choix<1||Choix>6);
	    switch(Choix)
			{
		    case 1:AjouterLng();
		        break;
		    case 2:RechercheLng();
		        break;
		    case 3:SupprimerLng();
		        break;
		    case 4:ModifierLng();
		        break;
		    case 5:AfficherLng();
		        break;
		    case 6:break;
		    }
	    printf("\n\t>>> Voulez-vous continuez O/N?...");
	    scanf("%s",&rep);
	    fflush(stdin);
	}while(rep=='o'||rep=='O');
}



