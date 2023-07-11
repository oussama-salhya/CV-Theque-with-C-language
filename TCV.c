#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define BIG_MAX 100
#define MAX 25


struct TCV
{
  int idCV;
  int idCandidat;
  char TitreCV[20];
  char DateCreation[20];
  char TypeCV[20];


};struct TCV CV ;

void AjouterCV()
{

	FILE *Fcv;
	Fcv=fopen("TCV.txt","a");
	test_file_opening(Fcv);
  	printf("\tSaisir le titre du cv ");
  	scanf("%s",&CV.TitreCV);
  	getchar();
  	printf("\tSaisir la Date de creation du cv ");
	scanf("%s",&CV.DateCreation);
  	printf("\tSaisir le type du cv ");
  	scanf("%s",&CV.TypeCV);
  	printf("\tSaisir l'identifiant du candidat dans cette liste ");
  	AfficherCandidats();
  	printf("\n\t entrer l'id : ");
  	scanf("%d",&CV.idCandidat);
    CV.idCV=getIDCV("TCV.txt")+1;
    fflush(stdin);
  	if(rechCandidat(CV.idCandidat)==1)
    {
        fprintf(Fcv,"%d ;%d ;%s ;%s ;%s   \n",CV.idCV,CV.idCandidat,CV.TitreCV,CV.DateCreation,CV.TypeCV);
        printf("\n\nle CV %d %s est ajoute au fichier TCANDIDATS.txt avec success \n",CV.idCV,CV.TitreCV);
        fclose(Fcv);
        return;
    }
    printf("l'identifiant du Candidat n'existe pas");
    fclose(Fcv);
}

void RechercheCV()
{
	int NumR,j=0;
	printf("\n\tEntrez l'identifiant du cv a rechercher :");
	scanf("%d",&NumR);
	FILE *Fcv;
	Fcv=fopen("TCV.txt","r");
	do
	{
	fscanf(Fcv,"%d ;%d ;%s ;%s ;%s   \n",&CV.idCV,&CV.idCandidat,&CV.TitreCV,&CV.DateCreation,&CV.TypeCV);
	if(NumR==CV.idCV)
	{
	        printf("\n\t===============INFORMATION SUR LE CV : %d  ================\n\t ",CV.idCV);
	        printf("\n\tLe titre du cv : %s",CV.TitreCV);
	        printf("\n\tL'identifiant du candidat : %d",CV.idCandidat);
	        printf("\n\tLa date de creation  \t\t\t : %s",CV.DateCreation);
	        printf("\n\tLe type du cv \t\t\t:%s",CV.TypeCV);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fcv));
	fclose(Fcv);
	if(j==0){
	    printf("\n\tDesole! Le cv n'existe pas\n");
	}
}

void AfficherCVComp(int NumR)
{
	FILE *Fcv;
	Fcv=fopen("TCV.txt","r");
	do
	{
	fscanf(Fcv,"%d ;%d ;%s ;%s ;%s   \n",&CV.idCV,&CV.idCandidat,&CV.TitreCV,&CV.DateCreation,&CV.TypeCV);
	if(NumR==CV.idCV)
	   {
        printf("\n\tLe titre du cv : %s",CV.TitreCV);
        printf("\n\tL'identifiant du candidat : %d",CV.idCandidat);
        printf("\n\tLa date de creation  \t\t\t : %s",CV.DateCreation);
        printf("\n\tLe type du cv \t\t\t:%s",CV.TypeCV);
	   }
  }while(!feof(Fcv));
	fclose(Fcv);
}

void SupprimerCV()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez l'identifiant du cv a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechCV(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Fcvt,*Fcv;
	        Fcv=fopen("TCV.txt","r");
	        test_file_opening(Fcv);
	        Fcvt=fopen("CV.txt","a");
	        test_file_opening(Fcvt);
	        do
	        {
	        fscanf(Fcv,"%d ;%d ;%s ;%s ;%s   \n",&CV.idCV,&CV.idCandidat,&CV.TitreCV,&CV.DateCreation,&CV.TypeCV);
	         if(NumRech!=CV.idCV)
	         {
			fprintf(Fcvt,"%d ;%d ;%s ;%s ;%s   \n",CV.idCV,CV.idCandidat,CV.TitreCV,CV.DateCreation,CV.TypeCV);
	         }
	        }while(!feof(Fcv));
	        fclose(Fcvt);
	        fclose(Fcv);
	        remove("TCV.txt");
	        rename("CV.txt","TCV.txt");
	        printf("\n\tLa suppression Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tl'identifiant du cv n'existe pas");
	}
}

void ModifierCV(){

	FILE *Fcv,*Fcvt;
	int num,i;
	char rep='n';
	printf("\n\tEntrez l'identifiant du cv a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechCV(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fcv=fopen("TCV.txt","r");
	    test_file_opening(Fcv);
	    Fcvt=fopen("CV.txt","a");
	    test_file_opening(Fcvt);

	 do
	{
	fscanf(Fcv,"%d ;%d ;%s ;%s ;%s   \n",&CV.idCV,&CV.idCandidat,&CV.TitreCV,&CV.DateCreation,&CV.TypeCV);
	if(num==CV.idCV)
	{
		CV.idCV=num;
		printf("\tSaisir le nouveau titre du CV ");
  		scanf("%s",&CV.TitreCV);
	    printf("\tSaisir le nouveau identifiant du candidat ");
	    AfficherCandidats();
  		printf("\n\tid : ");
		scanf("%d",&CV.idCandidat);
	  	printf("\tSaisir la nouvelle date de creation du cv  ");
		scanf("%s",&CV.DateCreation);
		printf("\tSaisir le type du nouveau cv ");
		scanf("%s",&CV.TypeCV);



	}
	fprintf(Fcvt,"%d ;%d ;%s ;%s ;%s   \n",CV.idCV,CV.idCandidat,CV.TitreCV,CV.DateCreation,CV.TypeCV);
	}while(!feof(Fcv));
    fclose(Fcvt);
    fclose(Fcv);
	remove("TCV.txt");
	rename("CV.txt","TCV.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annule\n");
	}
	}
	else
	{
	printf("\n\tL'indice du cv N'existe pas\n");
	}
}

int RechercheCVPartitre(char * titreCV)
{
	unsigned int id;
    char  TitreCV[MAX];
    char  idCandidat[MAX];
    char TypeCV[15];
    char DateCreation[50];
    char  line[BIG_MAX];
    FILE * F=fopen("TCV.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
        fscanf(F,"%d ;%d ;%s ;%s ;%s   \n",&id,&idCandidat,&TitreCV,&DateCreation,&TypeCV);
        if(!strcmp(TitreCV,titreCV))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechCV(int Numrech)
{
	FILE *Fcv;
	Fcv=fopen("TCV.txt","r");
	test_file_opening(Fcv);
	do
		{
		fscanf(Fcv,"%d ;%d ;%s ;%s ;%s   \n",&CV.idCV,&CV.idCandidat,&CV.TitreCV,&CV.DateCreation,&CV.TypeCV);
		fflush(stdin);
		if(CV.idCV==Numrech)
			{
			fclose(Fcv);
			return 1;
			}
		}while(!feof(Fcv));
	fclose(Fcv);
	return -1;
}

void AfficherCV()
{
	FILE *Fcv;
	Fcv=fopen("TCV.txt","r");
	do
	{
	fscanf(Fcv,"%d ;%d ;%s ;%s ;%s   \n",&CV.idCV,&CV.idCandidat,&CV.TitreCV,&CV.DateCreation,&CV.TypeCV);
	        printf("\n\t===============INFORMATION SUR LE CV : %d  ================\n\t ",CV.idCV);
	        printf("\n\tLe titre du cv : %s",CV.TitreCV);
	        printf("\n\tL'identifiant du candidat : %d",CV.idCandidat);
	        printf("\n\tLa date de creation : %s",CV.DateCreation);
	        printf("\n\tLe type du cv : %s",CV.TypeCV);
	        printf("\n\t-----------------------------------------------------------------");
	}while(!feof(Fcv));
	fclose(Fcv);
}

int getIDCV(char *File)
{
    int j=(-1);
	unsigned int id;
    char  TitreCV[MAX];
    char  idCandidat[MAX];
    char TypeCV[15];
    char DateCreation[50];
	char N[100];
    FILE *F;
    F=fopen("TCV.txt","r");
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
			fscanf(F,"%d ;%d ;%s ;%s ;%s   \n",&id,&idCandidat,&TitreCV,&DateCreation,&TypeCV);
		}
	fclose(F);
	return id;
	}
}

void MenuCV()
{
int Choix;char rep;
do
	{
	    system("cls");
	    printf("\n\t              **********************                  ");
	    printf("\n\t***************     MENU DU CV     ****************");
	    printf("\n\t              **********************                ");
	    printf("\n\t                                               \n");
	    printf("\t*  (1) Ajouter un Cv                            *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (2) Rechercher Un Cv                         *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (3) Supprimer Un Cv                          *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (4) Modifier Un Cv                           *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (5) Afficher tous Les Cvs                    *\n");
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
		    case 1:AjouterCV();
		        break;
		    case 2:RechercheCV();
		        break;
		    case 3:SupprimerCV();
		        break;
		    case 4:ModifierCV();
		        break;
		    case 5:AfficherCV();
		        break;
		    case 6:break;
		    }
	    printf("\n\t>>> Voulez-vous continuez O/N?...");
	    scanf("%s",&rep);
	    fflush(stdin);
	}while(rep=='o'||rep=='O');
}
