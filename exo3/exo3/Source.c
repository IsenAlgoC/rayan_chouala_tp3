#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NBMAXNOTES 30

int main() {
	float note[NBMAXNOTES], moyenne = 0, temp = 0, ecartType = 0, somme = 0, valide = 0;

	int i = 0, j = 0, absent = 0, max = 0, min = 20;
	char rep;
	for (i = 0; i < NBMAXNOTES; i++) { note[i] = -2; }
	i = 0;
	while (i != NBMAXNOTES)
	{
		printf("Entrer la note no %d : ", i + 1);
		scanf_s("%5F", &note[i]);
		if (note[i] > 20 || note[i] < 0)
		{
			printf("Eleve absent ? ou voulez-vous arreter la saisie des notes? A/O/N : ");
			rep = _getch();
			switch (rep)
			{
			case 'A':
				absent++;
				note[i] = -1;
				i++;
				break;
			case 'O':
				note[i] = -2;
				i = NBMAXNOTES;
				break;
			case 'N':
				note[i] = -2;
				break;
			default:
				printf("Error");
				break;
			}
			printf("\n");
		}
		else
		{
			printf("\n");
			if (note[i] > max) { max = note[i]; }
			if (note[i] < min) { min = note[i]; }
			i++;
			valide++;
		}
	}
	for (j = 0; j < NBMAXNOTES; j++)
	{
		if (note[j] == -2) { break; }
		if (note[j] != -1) { somme = somme + note[j]; }
	}
	moyenne = somme / valide;

	somme = 0;
	for (size_t i = 0; i < NBMAXNOTES; i++)
	{
		if (note[i] == -2) { break; }
		if (note[i] != -1) {
			temp = pow((note[i] - moyenne), 2);

			somme += temp;
		}
	}

	ecartType = somme / (valide - 1);
	ecartType = sqrt(ecartType);

	printf("\n");
	printf("La moyenne des %0.2f eleves est de %0.2f \n", valide, moyenne);
	printf("La note maximale est %d\n", max);
	printf("La note minimale est %d\n", min);
	printf("Il y'a eu %d absent(s)\n", absent);
	printf("L'ecart-type vaut %0.2f\n", ecartType);
	i = 0;
	printf("\n");
	printf("Liste des notes : \n");
	printf("\n");
	printf("| No note | Valeur note |\n");
	printf("|---------|-------------|\n");

	while (note[i] != -2 && i < NBMAXNOTES)
	{
		printf("| %-7d | %-11.2f |\n", i + 1, note[i]);
		i += 1;
	}


	float copieNote[NBMAXNOTES];
	for (size_t i = 0; i < NBMAXNOTES; i++) { copieNote[i] = note[i]; }
	int indexNote[NBMAXNOTES];
	for (size_t i = 0; i < NBMAXNOTES; i++) { indexNote[i] = i; }



	i = 0;
	int tour = 0;
	do
	{
		tour = 0;
		for (size_t i = 0; i < NBMAXNOTES; i++)
		{
			if (copieNote[i + 1] > copieNote[i])
			{
				temp = copieNote[i];
				copieNote[i] = copieNote[i + 1];
				copieNote[i + 1] = temp;

				temp = indexNote[i];
				indexNote[i] = indexNote[i + 1];
				indexNote[i + 1] = temp;
				tour++;
			}
		}

	} while (tour != 0);

	i = 0;
	printf("\n");
	printf("\n");
	printf("Liste des notes dans l'ordre croissant :\n");
	printf("\n");
	printf("| Rang  | No note | Valeur note |\n");
	printf("|-------|---------|-------------|\n");
	while (note[i] != -2 && i < NBMAXNOTES)
	{
		printf("| %-5d | %-7d | %-11.2f |\n", i + 1, indexNote[i] + 1, copieNote[i]);
		i += 1;
	}

	printf("\nBye !\n");

	system("pause");
}
