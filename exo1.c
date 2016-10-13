#include <stdio.h>
#define N 8
#define VRAI 1
#define FAUX 0


void init_matrice(char mat[N][N])
{
/* Cette fonction initialise la matrice de type char en paramètre avec des '.'*/
	int i, j;
	
	for (i=0 ; i < N  ; i++)
	{
		for (j=0 ; j < N ; j ++)
		{
			mat[i][j] = '.';
		}
	}
}

void afficher_matrice (char mat[N][N])
{
/* Cette fonction affiche le contenu de la matrice de type char en paramètre*/
	int i, j;
	
	for (i=0 ; i < N  ; i++)
	{
		for (j=0 ; j < N ; j ++)
		{
			printf("%c ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int coord_valid (int x, int y)
{
/* Cette fonction booléenne vérifie si les coordonnées entrées sont comprises dans la matrice NxN */
	if ( (0 <= x) && (x < N) && (0 <= y) && (y < N) )
		return VRAI;
	else
		return FAUX;

}

void saisie_coord(int * x, int * y)
{
	printf("Saisir des coordonnées entre 1 et 8 (x,y):\n");
	scanf("%i%i", x, y);
		
	/* Vérification de la validité des coordonnées saisies */
	while (coord_valid(*x,*y) == FAUX)	
	{
		printf("Erreur, coordonnées hors de la matice !\nSaisir des coordonnées entre 1 et 8 (x,y):\n");
		scanf("%i%i", x, y);
	}
}

void tour (char mat[N][N], int x, int y)
{
	int i;
	
	for (i=0 ; i < N ; i++)
	{
		mat[x-1][i] = '*';
	}
	for (i=0 ; i < N ; i++)
	{
		mat[i][y-1] = '*';
	}
	mat[x-1][y-1] = 't';
}

void fou (char mat[N][N], int x, int y)
{
	int i, j;
	for (i = x-1, j = y-1; i >= 0 && j >= 0 ; i--, j--)
	{
		mat[i][j] = '*';
	}
	for (i = x-1, j = y-1; i < N && j >= 0 ; i++, j--)
	{
		mat[i][j] = '*';
	}
	for (i = x-1, j = y-1; i >= 0 && j < N ; i--, j++)
	{
		mat[i][j] = '*';
	}
	for (i = x-1, j = y-1; i < N && j < N ; i++, j++)
	{
		mat[i][j] = '*';
	}
	mat[x-1][y-1] = 'f';
}

void dame (char mat[N][N], int x, int y)
{
	int i, j;
	
	/* Lignes / colonnes */
	for (i=0 ; i < N ; i++)
	{
		mat[x-1][i] = '*';
	}
	for (i=0 ; i < N ; i++)
	{
		mat[i][y-1] = '*';
	}
	
	/*Diagonales */
	for (i = x-1, j = y-1; i >= 0 && j >= 0 ; i--, j--)
	{
		mat[i][j] = '*';
	}
	for (i = x-1, j = y-1; i < N && j >= 0 ; i++, j--)
	{
		mat[i][j] = '*';
	}
	for (i = x-1, j = y-1; i >= 0 && j < N ; i--, j++)
	{
		mat[i][j] = '*';
	}
	for (i = x-1, j = y-1; i < N && j < N ; i++, j++)
	{
		mat[i][j] = '*';
	}

	mat[x-1][y-1] = 'd';
}

int main()
{
	char echiquier[N][N];
	int x, y;		// Coordonnées saisies par l'utilisateur
	int choix;
		
	do
	{	/* Affichage du menu */
		printf("\n\nMenu :\n");
		printf(" 1 - Tour\n");
		printf(" 2 - Fou\n");
		printf(" 3 - Dame\n");
		printf(" 4 - Quitter\n");
		printf("Choix de la pièce : ");
		scanf("%i",&choix);
		
		
		switch(choix)
		{	case 1 : saisie_coord(&x,&y); init_matrice(echiquier); tour(echiquier,x,y); afficher_matrice(echiquier); break;
			case 2:  saisie_coord(&x,&y); init_matrice(echiquier); fou(echiquier,x,y); afficher_matrice(echiquier); break;
			case 3:  saisie_coord(&x,&y); init_matrice(echiquier); dame(echiquier,x,y); afficher_matrice(echiquier); break;
			case 4: break;
		
			default: printf("Erreur: votre choix doit etre compris entre 1 et 4\n");
		}
			
	}
	while(choix!=4);
	
}