#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#define BIG_MAX 100
#define MAX 25
#include "TPAYS.h"
#include "TPERMIS.h"
#include "TETATCIVILE.h"
#include "TVILLES.h"
#include "TCANDIDATS.h"
#include "TEXPERIENCES.h"
#include "TTYPECONTRAT.h"
#include "TCV.h"
#include "TCOMPETENCES.h"


struct TTYPECONTRAT
{
    int IdTypecontrat;
	char Typecontrat[50];
};struct TTYPECONTRAT T ;


void AjoutertTC()
{

	FILE *Fp;
	Fp=fopen("TTYPECONTRAT.txt","a");
	test_file_opening(Fp);
	printf("\tSaisir le Type de contrat ");
	scanf("%s",&T.Typecontrat);
	getchar();
	if(RechercheTCParNom(T.Typecontrat)==1)
    {
        printf("\tCette Type deja existe\n");
        return;
    }

	T.IdTypecontrat=getIDTypecontrat("TTYPECONTRAT.txt")+1;
	fflush(stdin);

	fprintf(Fp,"%d ; %s  \n",T.IdTypecontrat,T.Typecontrat);
	printf("\n\nle Type %u %s est ajoute au fichier TTYPECONTRAT.txt avec success \n",T.IdTypecontrat,T.Typecontrat);
	fclose(Fp);
}

void RechercheTC()
{
	int NumR,j=0;
	printf("\n\tEntrez le numero du type de contrat a rechercher :");
	scanf("%d",&NumR);
	FILE *Fp;
	Fp=fopen("TTYPECONTRAT.txt","r");
	do
	{
	fscanf(Fp,"%d ;%s \n",&T.IdTypecontrat,&T.Typecontrat);
	if(NumR==T.IdTypecontrat)
	{
	        printf("\n\t===============INFORMATION SUR LE TYPE  %d  ================\n\t ",T.IdTypecontrat);
	        printf("\n\tLe Type \t\t\t:%s",T.Typecontrat);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fp));
	fclose(Fp);
	if(j==0){
	    printf("\n\tDesole! Ce TYPE de contrat n'existe pas\n");
	}
}

void AfficherTCE(int NumR)
{
	FILE *Fp;
	Fp=fopen("TTYPECONTRAT.txt","r");
	do
	{
  fscanf(Fp,"%d ;%s \n",&T.IdTypecontrat,&T.Typecontrat);
  if(NumR==T.IdTypecontrat)
	{
      printf("\n\tLe Type \t\t\t:%s",T.Typecontrat);
	}
	}while(!feof(Fp));
	fclose(Fp);
}


void SupprimerTC()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez Le numero du TYPE a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechTC(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Fpt,*Fp;
	        Fp=fopen("TTYPECONTRAT.txt","r");
	        test_file_opening(Fp);
	        Fpt=fopen("TYPECONTRAT.txt","a");
	        test_file_opening(Fpt);
	        do
	        {
	         fscanf(Fp,"%d ;%s \n",&T.IdTypecontrat,&T.Typecontrat);
	         if(NumRech!=T.IdTypecontrat)
	         {
	         fprintf(Fpt,"%d ;%s \n",T.IdTypecontrat,T.Typecontrat);
	         }
	        }while(!feof(Fp));
	        fclose(Fpt);
	        fclose(Fp);
	        remove("TTYPECONTRAT.txt");
	        rename("TYPECONTRAT.txt","TTYPECONTRAT.txt");
	        printf("\n\tLa suppression Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tCe numero du TYPE de contrat n'existe pas");
	}
}

void ModifierTC(){

	FILE *Fp,*Fpt;
	int num,i;
	char rep='n';
	printf("\n\tEntrez Le numero du type de contrat a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechTC(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fp=fopen("TTYPECONTRAT.txt","r");
	    test_file_opening(Fp);
	    Fpt=fopen("TYPECONTRAT.txt","a");
	    test_file_opening(Fpt);

	 do
	 {
	fscanf(Fp,"%d ;%s \n",&T.IdTypecontrat,&T.Typecontrat);
	if(num==T.IdTypecontrat)
	{
	T.IdTypecontrat=num;

	printf("\n\tEntrez Le Nouveau Type de contrat :");
	gets(T.Typecontrat);
	if(RechercheTCParNom(T.Typecontrat)==1)
    {
        printf("\tCette Type deja existe\n");
        return;
    }
	}
	fprintf(Fpt,"%d ;%s \n",T.IdTypecontrat,T.Typecontrat);
	}while(!feof(Fp));
    fclose(Fpt);
    fclose(Fp);
    remove("TTYPECONTRAT.txt");
    rename("TYPECONTRAT.txt","TTYPECONTRAT.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annule\n");
	}
	}
	else
	{
	printf("\n\tCe Numero du Type de contrat N'existe pas\n");
	}
}

int RechercheTCParNom(char * Typecontrat)
{
	unsigned int 	id;
    char  Typecontrat_courant[MAX];
    char  line[BIG_MAX];
    FILE * F=fopen("TTYPECONTRAT.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
        fscanf(F,"%d ;%s \n",&id,Typecontrat_courant);
        if(!strcmp(Typecontrat,Typecontrat_courant))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechTC(int Numrech)
{
	FILE *Fp;
	Fp=fopen("TTYPECONTRAT.txt","r");
	test_file_opening(Fp);
	do
		{
		fscanf(Fp,"%d ;%s \n",&T.IdTypecontrat,&T.Typecontrat);
		fflush(stdin);
		if(T.IdTypecontrat==Numrech)
			{
			fclose(Fp);
			return 1;
			}
		}while(!feof(Fp));
	fclose(Fp);
	return -1;
}

void AfficherTC()
{
FILE *Fp;
Fp=fopen("TTYPECONTRAT.txt","r");
printf("\n\tLa liste des types de contrat :\n");
printf("\n\tNumero\tLe Pays\n");
printf("\n\t--------------------------------------\n");
do
{
fscanf(Fp,"%d ;%s \n",&T.IdTypecontrat,&T.Typecontrat);
fflush(stdin);
printf("\n\t%d ;%s \n",T.IdTypecontrat,T.Typecontrat);
}while(!feof(Fp));
fclose(Fp);
}

int getIDTypecontrat(char *File)
{
	unsigned int id;
	int j=(-1);
	char Typecontrat_courant[MAX];
	char N[100];
    FILE *F;
    F=fopen("TTYPECONTRAT.txt","r");
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
			fscanf(F,"%d ;%s \n",&id,Typecontrat_courant);
		}
	fclose(F);
	return id;
	}
}

void MenuTypeContrat()
{
int Choix;char rep;
do
	{
	    system("cls");
	    printf("\n\t                **********************                  ");
	    printf("\n\t***************  MENU DE TYPE CONTRAT  ********************");
	    printf("\n\t                **********************                ");
	    printf("\n\t                                              \n");
	    printf("\t*  (1) Ajouter un type                          *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (2) Rechercher Une type                      *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (3) Supprimer Un type                        *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (4) Modifier Une type                        *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (5) Afficher tous Les types                  *\n");
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
		    case 1:AjoutertTC();
		        break;
		    case 2:RechercheTC();
		        break;
		    case 3:SupprimerTC();
		        break;
		    case 4:ModifierTC();
		        break;
		    case 5:AfficherTC();
		        break;
		    case 6:break;
		    }
	    printf("\n\t>>> Voulez-vous continuez O/N?...");
	    scanf("%s",&rep);
	    fflush(stdin);
	}while(rep=='o'||rep=='O');
}
