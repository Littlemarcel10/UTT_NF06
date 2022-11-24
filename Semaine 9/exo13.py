#Listes
continu = 0
while continu ==0:
    print("Veuillez indiquer votre choix")
    print("1. Insérer un tableau d'entiers")
    print("2. Faire la somme, la moyenne et le produit des éléments du tableau")
    print("3. Vérification")
    print("4. Retourner une tranche du tableau")
    
    choix = int(input("Votre choix\n"))
    if choix == 1:
        liste = []
        n= int(input("Indiquez le nombre d'éléments du tableau\n"))
        
        print("Entrez une liste de nombres entiers")
        for i in range(n):
            liste.append(int(input("Entrez un nombre entier\n")))
        print(liste)
        
    if choix == 2:
        somme = 0
        produit = 1
        for i in range(len(liste)):
            somme = somme + liste[i]
            produit = produit * liste[i]
        moyenne = somme / len(liste)
        print("La somme est", somme)
        print("La moyenne est", moyenne)
        print("Le produit est", produit)
        
    if choix == 3:
        print("1. Vérifier si un nombre est présent dans le tableau")
        print("2. Insérer un nombre dans le tableau")
        print("3. Supprimer un nombre du tableau")
        choix2= int(input("Votre choix\n"))
        if choix2 == 1:
            nombre = int(input("Entrez un nombre\n"))
            if nombre in liste:
                print("Le nombre est présent dans le tableau")
            else:
                print("Le nombre n'est pas présent dans le tableau")
        if choix2 == 2:
            nombre = int(input("Entrez un nombre\n"))
            liste.append(nombre)
            print(liste)
        if choix2 == 3:
            nombre = int(input("Entrez un nombre\n"))
            if nombre in liste:
                liste.remove(nombre)
                print(liste)
            else:
                print("Le nombre n'est pas présent dans le tableau")
        else:
            print("Veuillez entrer un choix valide")
    if choix == 4:
        indice1 = int(input("Entrez l'indice de début\n"))
        indice1 = indice1 - 1
        indice2 = int(input("Entrez l'indice de fin\n"))
        print(liste[indice1:indice2])
        liste2 = liste[indice1:indice2]
        liste2.reverse()
        liste[indice1:indice2] = liste2
        print(liste)
        
              
        