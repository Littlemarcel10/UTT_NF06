def saisir_vecteur():
    vecteur = []
    nb_element = int(input("Entrez le nombre d'éléments: "))
    for i in range(nb_element):
        element = int(input("Entrez un élément: "))
        vecteur.append(element)
    return vecteur
    

def saisir_matrice():
    matrice = []
    
    nb_vecteur = int(input("Entrez le nombre de vecteurs: "))
    nb_element = int(input("Entrez le nombre d'éléments: "))
    for i in range(nb_vecteur):
            vecteur = []
            for i in range(nb_element):
                element = int(input("Entrez un élément: "))
                vecteur.append(element)
            matrice.append(vecteur)
        
    print(matrice)