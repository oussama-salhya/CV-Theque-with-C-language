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
#include "TCANDIDATS.h"
#include "TEXPERIENCES.h"
#include "TTYPECONTRAT.h"
#include "TCV.h"
#include "TCOMPETENCES.h"


struct TETATCIVILE
{
    int IdEtatC;
	char NomEtatC[50];
};struct TETATCIVILE E ;

void AjouterEtatC()
{

	FILE *Fe;
	Fe=fopen("TETATCIVILE.txt","a");
	test_file_opening(Fe);
	printf("\tSaisir le Nom du l'Etat Civile ");
	scanf("%s",&E.NomEtatC);
	getchar();
	if(RechercheEtatCParNom(E.NomEtatC)==1)
    {
        printf("Ce EtatC deja existe\n");
        return;
    }

	E.IdEtatC=getIDEtatC("TETATCIVILE.txt")+1;
	fflush(stdin);

	fprintf(Fe,"%d ; %s  \n",E.IdEtatC,E.NomEtatC);
	printf("\n\nle l'Etat Civile %u %s est ajoute au fichier TETATCIVILE.txt avec success \n",E.IdEtatC,E.NomEtatC);
	fclose(Fe);
}

void RechercheEtatC()
{
	int NumR,j=0;
	printf("\n\tEntrez le numero du l'Etat Civile a rechercher :");
	scanf("%d",&NumR);
	FILE *Fe;
	Fe=fopen("TETATCIVILE.txt","r");
	do
	{
	fscanf(Fe,"%d ;%s \n",&E.IdEtatC,&E.NomEtatC);
	if(NumR==E.IdEtatC)
	{
	        printf("\n\t===============INFORMATION SUR l'ETAT CIVILE  %d  ================\n\t ",E.IdEtatC);
	        printf("\n\tLe l'Etat Civile \t\t\t:%s",E.NomEtatC);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fe));
	fclose(Fe);
	if(j==0){
	    printf("\n\tDesole! l'Etat Civile n'existe pas\n");
	}
}

void AfficherEtatCC(int NumR)
{
	FILE *Fe;
	Fe=fopen("TETATCIVILE.txt","r");
	do
	{
	fscanf(Fe,"%d ;%s \n",&E.IdEtatC,&E.NomEtatC);
	if(NumR==E.IdEtatC)
	{
	        printf("\n\tL'Etat Civil \t\t\t:%s",E.NomEtatC);
	}
	}while(!feof(Fe));
	fclose(Fe);
}


void SupprimerEtatC()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez Le numero du l'Etat Civile a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechEtatC(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Fet,*Fe;
	        Fe=fopen("TETATCIVILE.txt","r");
	        test_file_opening(Fe);
	        Fet=fopen("EtatC.txt","a");
	        test_file_opening(Fet);
	        do
	        {
	         fscanf(Fe,"%d ;%s \n",&E.IdEtatC,&E.NomEtatC);
	         if(NumRech!=E.IdEtatC)
	         {
	         fprintf(Fet,"%d ;%s \n",E.IdEtatC,E.NomEtatC);
	         }
	        }while(!feof(Fe));
	        fclose(Fet);
	        fclose(Fe);
	        remove("TETATCIVILE.txt");
	        rename("EtatC.txt","TETATCIVILE.txt");
	        printf("\n\tLa suppression Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tCe numero du l'Etat Civile n'existe pas");
	}
}

void ModifierEtatC(){

	FILE *Fe,*Fet;
	int num,i;
	char rep='n';
	printf("\n\tEntrez Le numero du l'Etat Civile a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechEtatC(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fe=fopen("TETATCIVILE.txt","r");
	    test_file_opening(Fe);
	    Fet=fopen("EtatC.txt","a");
	    test_file_opening(Fet);

	 do
	 {
	fscanf(Fe,"%d ;%s \n",&E.IdEtatC,&E.NomEtatC);
	if(num==E.IdEtatC)
	{
	E.IdEtatC=num;

	printf("\n\tEntrez Le Nouveau Etat :");
	gets(E.NomEtatC);
	if(RechercheEtatCParNom(E.NomEtatC)==1)
    {
        printf("\tCe Etat deja existe\n");
        return;
    }
	}
	fprintf(Fet,"%d ;%s \n",E.IdEtatC,E.NomEtatC);
	}while(!feof(Fe));
    fclose(Fet);
    fclose(Fe);
    remove("TETATCIVILE.txt");
    rename("EtatC.txt","TETATCIVILE.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annule\n");
	}
	}
	else
	{
	printf("\n\tCe Numero du l'Etat Civile N'existe pas\n");
	}
}

int RechercheEtatCParNom(char * NomEtatC)
{
	unsigned int 	id;
    char  NomEtatC_courant[MAX];
    char  line[BIG_MAX];
    FILE * F=fopen("TETATCIVILE.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
        fscanf(F,"%d ;%s \n",&id,NomEtatC_courant);
        if(!strcmp(NomEtatC,NomEtatC_courant))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechEtatC(int Numrech)
{
	FILE *Fe;
	Fe=fopen("TETATCIVILE.txt","r");
	test_file_opening(Fe);
	do
		{
		fscanf(Fe,"%d ;%s \n",&E.IdEtatC,&E.NomEtatC);
		fflush(stdin);
		if(E.IdEtatC==Numrech)
			{
			fclose(Fe);
			return 1;
			}
		}while(!feof(Fe));
	fclose(Fe);
	return -1;
}

void AfficherEtatC()
{
FILE *Fe;
Fe=fopen("TETATCIVILE.txt","r");
printf("\n\tLa liste des Etats Civils :\n");
printf("\n\tNumero\tl'Etat Civile\n");
printf("\n\t--------------------------------------\n");
do
{
fscanf(Fe,"%d ;%s \n",&E.IdEtatC,&E.NomEtatC);
fflush(stdin);
printf("\n\t%d ;%s \n",E.IdEtatC,E.NomEtatC);
}while(!feof(Fe));
fclose(Fe);
}

unsigned int getIDEtatC(char *File)
{
	unsigned int id;
	int j=(-1);
	char NomEtatC_courant[MAX];
	char N[100];
    FILE *F;
    F=fopen("TETATCIVILE.txt","r");
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
			fscanf(F,"%d ;%s \n",&id,NomEtatC_courant);
		}
	fclose(F);
	return id;
	}
}

void MenuEtatC()
{
	setlocale(LC_CTYPE,"");
int Choix;char rep;
do
	{
	    system("cls");
	    printf("\n\t                ************************                  ");
	    printf("\n\t***************  MENU DE L'Etat Civile   ********************");
	    printf("\n\t                *************************               ");
	    printf("\n\t                                               \n ");
	    printf("\t*  (1) Ajouter un Etat Civile                   *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (2) Rechercher Un Etat Civile                *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (3) Supprimer Un Etat Civile                 *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (4) Modifier Un Etat Civile                  *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (5) Afficher tous Les Etats Civils           *\n");
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
		    case 1:AjouterEtatC();
		        break;
		    case 2:RechercheEtatC();
		        break;
		    case 3:SupprimerEtatC();
		        break;
		    case 4:ModifierEtatC();
		        break;
		    case 5:AfficherEtatC();
		        break;
		    case 6:break;
		    }
	    printf("\n\t>>> Voulez-vous continuez O/N?...");
	    scanf("%s",&rep);
	    fflush(stdin);
	}while(rep=='o'||rep=='O');
}
