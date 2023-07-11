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
#include "TCOMPETENCES.h"


struct TPROJETS
{
  int  IdProject;
  char TitreProjet[50];
  char Secteur[50];
  char DateRealisation[50];
  char Description[150];
  char TypeProjet[50];
  int Idcv;

};struct TPROJETS Pr ;

void AjouterProj()
{

	FILE *Fb;
	Fb=fopen("TPROJETS.txt","a");
	test_file_opening(Fb);
  printf("\tSaisir le titre du projet ");
  scanf("%s",&Pr.TitreProjet);
  	getchar();
 	printf("\tSaisir le secteur de ce projet ");
	scanf("%s",&Pr.Secteur);
    printf("\tSaisir La date de realisation ");
	scanf("%s",&Pr.DateRealisation);
	printf("\tSaisir Description sur ce projet ");
	scanf("%s",&Pr.Description);
	printf("\tSaisir le type de ce projet  ");
	scanf("%s",&Pr.TypeProjet);
    printf("\tSaisir l'indice du Cv ou se trouve ce projet ");
  	Pr.Idcv=SaisirCV();
	Pr.IdProject=getIDProj("TPROJETS.txt")+1;
	fflush(stdin);
	fprintf(Fb,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n",Pr.IdProject,Pr.TitreProjet,Pr.TypeProjet,Pr.Secteur,Pr.DateRealisation,Pr.Description,Pr.Idcv);
	printf("\n\nle projet %u %s est ajoute au fichier TPROJETS.txt avec success \n",Pr.IdProject,Pr.TitreProjet);
	fclose(Fb);
}

void RechercheProj()
{
	int NumR,j=0;
	printf("\n\tEntrez l'indice du Projet a rechercher :");
	scanf("%d",&NumR);
	FILE *Fb;
	Fb=fopen("TPROJETS.txt","r");
	do
	{
	fscanf(Fb,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n",&Pr.IdProject,&Pr.TitreProjet,&Pr.TypeProjet,&Pr.Secteur,&Pr.DateRealisation,&Pr.Description,&Pr.Idcv);
	if(NumR==Pr.IdProject)
	{
	        printf("\n\t===============INFORMATION SUR Le projet : %d  ================\n\t ",Pr.IdProject);
	        printf("\n\tLe titre : %s",Pr.TitreProjet);
	        printf("\n\tLe Type : %s",Pr.TypeProjet);
	        printf("\n\tLe secteur : %s",Pr.Secteur);
	        printf("\n\t description : %s",Pr.Description);
	        printf("\n\t Date Realisation : %s",Pr.DateRealisation);
	        AfficherCVComp(Pr.Idcv);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fb));
	fclose(Fb);
	if(j==0){
	    printf("\n\tDesole! ce projet n'existe pas\n");
	}
}

void SupprimerProj()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez L'indice du projet a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechProj(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Fbt,*Fb;
	        Fb=fopen("TPROJETS.txt","r");
	        test_file_opening(Fb);
	        Fbt=fopen("PROJETS.txt","a");
	        test_file_opening(Fbt);
	        do
	        {
                fscanf(Fb,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n",&Pr.IdProject,&Pr.TitreProjet,&Pr.TypeProjet,&Pr.Secteur,&Pr.DateRealisation,&Pr.Description,&Pr.Idcv);
                if(NumRech!=Pr.IdProject)
                {
                    fprintf(Fbt,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n",Pr.IdProject,Pr.TitreProjet,Pr.TypeProjet,Pr.Secteur,Pr.DateRealisation,Pr.Description,Pr.Idcv);
                }
	        }while(!feof(Fb));
	        fclose(Fbt);
	        fclose(Fb);
	        remove("TPROJETS.txt");
	        rename("PROJETS.txt","TPROJETS.txt");
	        printf("\n\tLa suppression Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tl'indice du projet n'existe pas");
	}
}

void ModifierProj(){

	FILE *Fb,*Fbt;
	int num,i;
	char rep='n';
	printf("\n\tEntrez L'indice du projet a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechProj(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fb=fopen("TPROJETS.txt","r");
	    test_file_opening(Fb);
	    Fbt=fopen("PROJECTS.txt","a");
	    test_file_opening(Fbt);

	 do
	{
    fscanf(Fb,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n",&Pr.IdProject,&Pr.TitreProjet,&Pr.TypeProjet,&Pr.Secteur,&Pr.DateRealisation,&Pr.Description,&Pr.Idcv);
	if(num==Pr.IdProject)
	{
	    printf("\tSaisir le nouveau titre de ce projet ");
        scanf("%s",&Pr.TitreProjet);
		Pr.IdProject=num;
		printf("\tSaisir le nouveau secteur de ce projet ");
        scanf("%s",&Pr.Secteur);
        printf("\tSaisir La nouvelle date de realisation ");
        scanf("%s",&Pr.DateRealisation);
        printf("\tSaisir la nouvelle Description sur ce projet");
        scanf("%s",&Pr.Description);
        printf("\tSaisir le nouvelle type de ce projet");
        scanf("%s",&Pr.TypeProjet);
        printf("D\tSaisir le nouveau indice du Cv ou se trouve ce projet");
	    Pr.Idcv=SaisirCV();
	}
    fprintf(Fbt,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n",Pr.IdProject,Pr.TitreProjet,Pr.TypeProjet,Pr.Secteur,Pr.DateRealisation,Pr.Description,Pr.Idcv);
    }while(!feof(Fb));
    fclose(Fbt);
    fclose(Fb);
	remove("TPROJETS.txt");
	rename("PROJETS.txt","TPROJETS.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annule\n");
	}
	}
	else
	{
	printf("\n\tL'indice du PROJET N'existe pas\n");
	}
}

int RechercheProjPartitre(char * titreproj)
{
    int  id;
    char TitreProjet_courant[MAX];
    char Secteur_courant[MAX];
    char DateRealisation_courant[MAX];
    char Description_courant[MAX];
    char TypeProjet_courant[MAX];
    int Idcv;
    FILE * F=fopen("TPROJETS.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
    fscanf(F,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n",&id,&TitreProjet_courant,&TypeProjet_courant,&Secteur_courant,&DateRealisation_courant,&Description_courant,&Idcv);
        if(!strcmp(titreproj,TitreProjet_courant))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechProj(int Numrech)
{
	FILE *Fb;
	Fb=fopen("TPROJETS.txt","r");
	test_file_opening(Fb);
	do
		{
        fscanf(Fb,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n",&Pr.IdProject,&Pr.TitreProjet,&Pr.TypeProjet,&Pr.Secteur,&Pr.DateRealisation,&Pr.Description,&Pr.Idcv);
		fflush(stdin);
		if(Pr.IdProject==Numrech)
			{
			fclose(Fb);
			return 1;
			}
		}while(!feof(Fb));
	fclose(Fb);
	return -1;
}

void AfficherProj()
{
	FILE *Fb;
	Fb=fopen("TPROJETS.txt","r");
	do
	{
    fscanf(Fb,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n",&Pr.IdProject,&Pr.TitreProjet,&Pr.TypeProjet,&Pr.Secteur,&Pr.DateRealisation,&Pr.Description,&Pr.Idcv);
            printf("\n\t===============INFORMATION SUR Le projet : %d  ================\n\t ",Pr.IdProject);
	        printf("\n\tLe titre : %s",Pr.TitreProjet);
	        printf("\n\tLe Type : %s",Pr.TypeProjet);
	        printf("\n\tLe secteur : %s",Pr.Secteur);
	        printf("\n\t description : %s",Pr.Description);
	        printf("\n\t Date Realisation : %s",Pr.DateRealisation);
	        AfficherCVComp(Pr.Idcv);
	        printf("\n\t-----------------------------------------------------------------");
	}while(!feof(Fb));
	fclose(Fb);
}

int getIDProj(char *File)
{
	int j=(-1);
    int  id;
    char TitreProjet_courant[MAX];
    char Secteur_courant[MAX];
    char DateRealisation_courant[MAX];
    char Description_courant[MAX];
    char TypeProjet_courant[MAX];
    int Idcv;
	char N[100];
    FILE *F;
    F=fopen("TPROJETS.txt","r");
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
            fscanf(F,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n",&id,&TitreProjet_courant,&TypeProjet_courant,&Secteur_courant,&DateRealisation_courant,&Description_courant,&Idcv);
		}
	fclose(F);
	return id;
	}
}

void Menuprojet()
{
int Choix;char rep;
do
	{
	    system("cls");
	    printf("\n\t              ***********************                ");
	    printf("\n\t***************   MENU DES PROJET   ********************");
	    printf("\n\t              ***********************                ");
	    printf("\n\t                                               \n");
	    printf("\t*  (1) Ajouter un projet                        *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (2) Rechercher un projet                     *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (3) Supprimer un projet                      *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (4) Modifier un projet                       *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (5) Afficher toutes Les projets              *\n");
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
		    case 1:AjouterProj();
		        break;
		    case 2:RechercheProj();
		        break;
		    case 3:SupprimerProj();
		        break;
		    case 4:ModifierProj();
		        break;
		    case 5:AfficherProj();
		        break;
		    case 6:break;
		    }
	    printf("\n\t>>> Voulez-vous continuez O/N?...");
	    scanf("%s",&rep);
	    fflush(stdin);
	}while(rep=='o'||rep=='O');
}



