#On refait l'exo 14 en mettant un set dans le tuple
Users = [('Bob', {'Foot', 'Dormir', 'chomage'}), ('Eva', {'gueuler', 'Dormir'})]
def ajouter():
    
    nombre_nouveau = int(input("Entrez le nombre de nouveaux utilisateurs\n"))
    for i in range(nombre_nouveau):
        my_set = set()
        my_tuple = ()
        nouveaux = []
        nouveau_nom = input("Entrez le nom du nouveau utilisateur\n")
        nouveaux.append(nouveau_nom)
        nouveau_hobby = int(input("Entrez le nombre d'hobbies du nouveau utilisateur\n"))
        for j in range(nouveau_hobby):
            hobby = input("Entrez un hobby\n")
            my_set.add(hobby)
        my_tuple = (nouveau_nom,my_set)
        Users.append(my_tuple)
    print(Users)

def ajouter_activité():
    utilisateur = input("Entrez le nom d'un utilisateur\n")
    for i in range(len(Users)):
        if utilisateur in Users[i][0]:
            remplacement = list(Users[i])
            nouvelle_activité = input("Entrez une nouvelle activité\n")
            remplacement[1].add(nouvelle_activité)
            Users[i] = tuple(remplacement)
    print(Users)

def activité_commun2():
    stop = 0
    compte = 0
    lettres = input("Entrez quelques lettres afin de déterminer l'activité\n")
    
    for i in range(len(Users)):
        utilisateur = list(Users[i])
        hobby = list(utilisateur[1])
        for j in range(len(hobby)):
            if lettres in hobby[j] and stop == 0:
                commune = hobby[j]
                print("Activité:\n",hobby[j])
                stop = 1
    for i in range(len(Users)):
        utilisateur = list(Users[i])
        hobby = list(utilisateur[1])
        for j in range(len(hobby)):
            if hobby[j] == commune:
                print(utilisateur[0])
                compte = compte+1
    print("Nombre de personnes pratiquant cette activité: ",compte)
 
def comparaison():
    commun = 0
    l = 0
    utilisateur1 = input("Entrez le nom d'un utilisateur\n")
    utilisateur2 = input("Entrez le nom d'un autre utilisateur\n")
    activite_en_commun = 0
    activite = []
    for i in range(len(Users)):
        if utilisateur1 in Users[i][0]:
            for j in range(len(Users)):
                if utilisateur2 in Users[j][0]:
                    utilisateur3 = list(Users[i])
                    utilisateur4 = list(Users[j])
                    hobby1 = list(utilisateur3[1])
                    hobby2 = list(utilisateur4[1])
                    for k in range(len(hobby1)):
                        for l in range(len(hobby2)):
                            if hobby1[k] == hobby2[l]:
                                activite.append(hobby1[k])
                                commun = commun+1
    print("Nombre d'activités en commun: ",commun)
    print("Activités en commun: ",activite)

def supprimer():
    utilisateur = input("Entrez le nom d'un utilisateur\n")
    for i in range(len(Users)):
        if utilisateur in Users[i][0]:
            del Users[i]
            print("Utilisateur supprimé")
    print(Users)            

def supprimer_activité():
    utilisateur = input("Entrez le nom d'un utilisateur\n")
    activité = input("Entrez une activité\n")
    # on enlève l'activité de l'utilisateur
    for i in range(len(Users)):
        if utilisateur in Users[i][0]:
            remplacement = list(Users[i])
            remplacement[1].remove(activité)
            Users[i] = tuple(remplacement)
    print(Users)

def remplacer_activité():
    utilisateur = input("Entrez le nom d'un utilisateur\n")
    activité = input("Entrez une activité\n")
    for i in range(len(Users)):
        if utilisateur in Users[i][0]:
            remplacement = list(Users[i])
            remplacement[1].remove(activité)
            nouvelle_activité = input("Entrez une nouvelle activité\n")
            remplacement[1].add(nouvelle_activité)
            Users[i] = tuple(remplacement)






i = 0
continu = 0


while continu == 0:
    print("Bienvenue dans la base de données des hobbies")
    print("1. Ajouter un utilisateur")
    print("2. Détermine le nombre de personnes qui ont un hobby en commun")
    print("3. Activités communes entre deux utilisateurs")
    print("4. Supprimer une activité d'un utilisateur")
    print("5. Supprimer un utilisateur")
    print("6. Remplacer une activité d'un utilisateur")
    print("7. Ajouter une activité à un utilisateur")
    print("8. Quitter")
    choix= int(input("Votre choix\n"))
    if choix == 1:
        ajouter()
        print(Users)
    elif choix == 2:
        activité_commun2()
        print(Users)
    elif choix == 3:
        comparaison()
        print(Users)
    elif choix == 4:
        supprimer_activité()
        print(Users)
    elif choix == 5:
        supprimer()
        print(Users)
    elif choix == 6:
        remplacer_activité()
        print(Users)
    elif choix == 7:
        ajouter_activité()
        print(Users)
    elif choix == 8:
        continu = 1