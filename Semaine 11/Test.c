typedef struct
{
    int poids;
    int valeur;
    int quantite;
} element_t;

void sac_a_dos(int n, element_t *elements, int poids_max, int *valeur_max)
{
    // Tableau pour stocker les valeurs maximales possibles pour chaque poids
    int valeurs[poids_max + 1];
    for (int i = 0; i <= poids_max; i++)
    {
        valeurs[i] = 0;
    }

    // Remplissage du sac à dos en utilisant l'algorithme du théorème du sac à dos
    for (int i = 0; i < n; i++)
    {
        // Boucle qui parcourt les quantités disponibles pour chaque produit
        for (int k = 0; k < elements[i].quantite; k++)
        {
            for (int j = poids_max; j >= elements[i].poids; j--)
            {
                int valeur = valeurs[j - elements[i].poids] + elements[i].valeur;
                if (valeur > valeurs[j])
                {
                    valeurs[j] = valeur;
                }
            }
        }
    }

    // Stockage de la valeur maximale dans le pointeur de sortie
    *valeur_max = valeurs[poids_max];
    // Affichage des produits sélectionnés
    int poids_restant = poids_max;
    for (int i = n - 1; i >= 0; i--)
    {
        if (valeurs[poids_restant] != valeurs[poids_restant - elements[i].poids])
        {
            printf("Produit sélectionné: poids = %d, valeur = %d, quantite = %d\n", elements[i].poids, elements[i].valeur, elements[i].quantite);
            poids_restant -= elements[i].poids;
        }
    }
}

int main(int argc, char *argv[])
{
    // Exemple d'utilisation de la fonction avec des données en entrée
    element_t elements[] = {{2, 3, 2}, {3, 4, 6}, {4, 5, 1}, {5, 8, 2}, {9, 10, 1}};
    int poids_max = 20;
    int valeur_max;
    sac_a_dos(5, elements, poids_max, &valeur_max);
    printf("Valeur maximale = %d\n", valeur_max);

    return 0;
}
