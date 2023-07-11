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

struct TBENEVOLAT
{
  int  Idbenevolat;
  char TitreBenevolat[50];
  char organisation[50];
  char poste[50];
  char activite[50];
  int Idcv;

};struct TBENEVOLAT B ;
void Ajouterben()
{

	FILE *Fb;
	Fb=fopen("TBENEVOLAT.txt","a");
	test_file_opening(Fb);
  printf("\tSaisir le titre du benevolat ");
  scanf("%s",&B.TitreBenevolat);
  	getchar();
 	printf("\tSaisir l'organisation de ce benevolat ");
	scanf("%s",&B.organisation);
    printf("\tSaisir Le poste occupe  ");
	scanf("%s",&B.poste);
	printf("\tSaisir L'activite de ce benevolat  ");
	scanf("%s",&B.activite);
    printf("\tSaisir l'indice du Cv ou se trouve ce benevolat ");
  	B.Idcv=SaisirCV();
	B.Idbenevolat=getIDben("TBENEVOLAT.txt")+1;
	fflush(stdin);
	fprintf(Fb,"%d ;%s ;%s ;%s ;%s ;%d \n",B.Idbenevolat,B.TitreBenevolat,B.organisation,B.poste,B.activite,B.Idcv);
	printf("\n\nke benevolat %u %s est ajoute au fichier TBENEVOLAT.txt avec success \n",B.Idbenevolat,B.TitreBenevolat);
	fclose(Fb);
}

void Rechercheben()
{
	int NumR,j=0;
	printf("\n\tEntrez l'indice du benevolat a rechercher :");
	scanf("%d",&NumR);
	FILE *Fb;
	Fb=fopen("TBENEVOLAT.txt","r");
	do
	{
	fscanf(Fb,"%d ;%s ;%s ;%s ;%s ;%d \n",&B.Idbenevolat,&B.TitreBenevolat,&B.organisation,&B.poste,&B.activite,&B.Idcv);
	if(NumR==B.Idbenevolat)
	{
	        printf("\n\t===============INFORMATION SUR Le benevolat : %d  ================\n\t ",B.Idbenevolat);
	        printf("\n\tLe titre : %s",B.TitreBenevolat);
	        printf("\n\tL'organisation : %s",B.organisation);
	        printf("\n\tLe poste : %s",B.poste);
	        printf("\n\tL'activite : %s",B.activite);
	        AfficherCVComp(B.Idcv);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fb));
	fclose(Fb);
	if(j==0){
	    printf("\n\tDesole! cette benevolat n'existe pas\n");
	}
}

void Supprimerben()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez L'indice du benevolat a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechben(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Fbt,*Fb;
	        Fb=fopen("TBENEVOLAT.txt","r");
	        test_file_opening(Fb);
	        Fbt=fopen("BENEVOLAT.txt","a");
	        test_file_opening(Fbt);
	        do
	        {
	         fscanf(Fb,"%d ;%s ;%s ;%s ;%s ;%d \n",&B.Idbenevolat,&B.TitreBenevolat,&B.organisation,&B.poste,&B.activite,&B.Idcv);
	         if(NumRech!=B.Idbenevolat)
	         {
			          fprintf(Fbt,"%d ;%s ;%s ;%s ;%s ;%d \n",B.Idbenevolat,B.TitreBenevolat,B.organisation,B.poste,B.activite,B.Idcv);
	         }
	        }while(!feof(Fb));
	        fclose(Fbt);
	        fclose(Fb);
	        remove("TBENEVOLAT.txt");
	        rename("BENEVOLAT.txt","TBENEVOLAT.txt");
	        printf("\n\tLa suppression Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tl'indice du benevolat n'existe pas");
	}
}

void Modifierben(){

	FILE *Fb,*Fbt;
	int num,i;
	char rep='n';
	printf("\n\tEntrez L'indice du benevolat a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechben(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fb=fopen("TBENEVOLAT.txt","r");
	    test_file_opening(Fb);
	    Fbt=fopen("BENEVOLAT.txt","a");
	    test_file_opening(Fbt);

	 do
	{
    fscanf(Fb,"%d ;%s ;%s ;%s ;%s ;%d \n",&B.Idbenevolat,&B.TitreBenevolat,&B.organisation,&B.poste,&B.activite,&B.Idcv);
	if(num==B.Idbenevolat)
	{
		B.Idbenevolat=num;
		printf("\tSaisir le nouveau titre du benevolat ");
        scanf("%s",&B.TitreBenevolat);
	    printf("\tSaisir la nouvelle organisation ");
		scanf("%s",&B.organisation);
	    printf("\tSaisir le nouveau poste de ce benevolat ");
		scanf("%s",&B.poste);
		printf("\tSaisir la nouvelle activite de ce benevolat ");
		scanf("%s",&B.activite);
	    printf("\tSaisir le nouveau indice du Cv du benevolat Parmis cette liste ");
	    B.Idcv=SaisirCV();
	}
  fprintf(Fbt,"%d ;%s ;%s ;%s ;%s ;%d \n",B.Idbenevolat,B.TitreBenevolat,B.organisation,B.poste,B.activite,B.Idcv);
	}while(!feof(Fb));
    fclose(Fbt);
    fclose(Fb);
	remove("TBENEVOLAT.txt");
	rename("BENEVOLAT.txt","TBENEVOLAT.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annule\n");
	}
	}
	else
	{
	printf("\n\tL'indice du benevolat N'existe pas\n");
	}
}

int RechercheBenPartitre(char * titreben)
{
    int 	id;
    char  titreben_courant[MAX];
    char  organisation_courant[MAX];
    char  poste_courant[MAX];
    char  activite_courant[MAX];
    int   idcv;
    char  line[BIG_MAX];
    FILE * F=fopen("TBENEVOLAT.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
        fscanf(F,"%d ;%s ;%s ;%s ;%s ;%d \n",&id,&titreben_courant,&organisation_courant,&poste_courant,&activite_courant,&idcv);
        if(!strcmp(titreben,titreben_courant))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechben(int Numrech)
{
	FILE *Fb;
	Fb=fopen("TBENEVOLAT.txt","r");
	test_file_opening(Fb);
	do
		{
		fscanf(Fb,"%d ;%s ;%s ;%s ;%s ;%d \n",&B.Idbenevolat,&B.TitreBenevolat,&B.organisation,&B.poste,&B.activite,&B.Idcv);
		fflush(stdin);
		if(B.Idbenevolat==Numrech)
			{
			fclose(Fb);
			return 1;
			}
		}while(!feof(Fb));
	fclose(Fb);
	return -1;
}

void Afficherben()
{
	FILE *Fb;
	Fb=fopen("TBENEVOLAT.txt","r");
	do
	{
    fscanf(Fb,"%d ;%s ;%s ;%s ;%s ;%d \n",&B.Idbenevolat,&B.TitreBenevolat,&B.organisation,&B.poste,&B.activite,&B.Idcv);
	        printf("\n\t===============INFORMATION SUR Le benevolat : %d  ================\n\t ",B.Idbenevolat);
	        printf("\n\tLe titre : %s",B.TitreBenevolat);
	        printf("\n\tL'organisation : %s",B.organisation);
	        printf("\n\tLe poste : %s",B.poste);
	        printf("\n\tL'activite : %s",B.activite);
	        AfficherCVComp(B.Idcv);
	        printf("\n\t-----------------------------------------------------------------");
	}while(!feof(Fb));
	fclose(Fb);
}

int getIDben(char *File)
{
	int j=(-1);
    int 	id;
    char  titreben_courant[MAX];
    char  organisation_courant[MAX];
    char  poste_courant[MAX];
    char  activite_courant[MAX];
    int   idcv;
	char N[100];
    FILE *F;
    F=fopen("TBENEVOLAT.txt","r");
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
      fscanf(F,"%d ;%s ;%s ;%s ;%s ;%d \n",&id,&titreben_courant,&organisation_courant,&poste_courant,&activite_courant,&idcv);;
		}
	fclose(F);
	return id;
	}
}



void Menubenevolat()
{
int Choix;char rep;
do
	{
	    system("cls");
	    printf("\n\t              ***********************                ");
	    printf("\n\t*************** MENU DES BENEVOLATS ********************");
	    printf("\n\t*             ***********************                ");
	    printf("\n\t*                                             *\n ");
	    printf("\t*  (1) Ajouter un benevolat                   *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (2) Rechercher un benevolat                *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (3) Supprimer un benevolat                 *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (4) Modifier un benevolat                  *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (5) Afficher toutes Les benevolats          *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (6) Quiter                                   *\n");
	    printf("\t*-----------------------------------------------*\n");

	    do
		    {
		     printf("\n\t>>> Etrez votre choix...");
		     scanf("%d",&Choix);
		    }while(Choix<1||Choix>6);
	    switch(Choix)
			{
		    case 1:Ajouterben();
		        break;
		    case 2:Rechercheben();
		        break;
		    case 3:Supprimerben();
		        break;
		    case 4:Modifierben();
		        break;
		    case 5:Afficherben();
		        break;
		    case 6:break;
		    }
	    printf("\n\t>>> Voulez-vous continuez O/N?...");
	    scanf("%s",&rep);
	    fflush(stdin);
	}while(rep=='o'||rep=='O');
}


