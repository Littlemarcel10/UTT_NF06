#Hobbies database
users = [("Bob", "Movies", "Football", "Reading"), ("Alice", "Swimming", "Football", "Handball", "gaming"), ("Eva", "Movies", "Coding", "Gaming")] 

def ajouter():
   nombre_nouveau = int(input("Entrez le nombre de nouveaux utilisateurs\n"))
   for i in range(nombre_nouveau):
       nouveaux = []
       nouveau_nom = input("Entrez le nom du nouveau utilisateur\n")
       nouveaux.append(nouveau_nom)
       nouveau_hobby = int(input("Entrez le nombre d'hobbies du nouveau utilisateur\n"))
       for j in range(nouveau_hobby):
           nouveaux_hobbies = input("Entrez un hobby\n")
           nouveaux.append(nouveaux_hobbies)
       users.append(tuple(nouveaux))

def ajouter_activité():
    utilisateur = input("Entrez le nom d'un utilisateur\n")
    for i in range(len(users)):
        if utilisateur in users[i][0]:
            remplacement = list(users[i])
            nouvelle_activité = input("Entrez une nouvelle activité\n")
            remplacement.append(nouvelle_activité)
            users[i] = tuple(remplacement)
    print(users)

def activité_commun():
    stop = 0
    activité = input("Entrez une activité\n")
    for i in range(len(users)):
        for j in range(len(users[i])):
            if users[i][j] == activité and stop == 0:
                print(users[i][0])
                stop = 1


# On refait la même fonction mais l'activité doit être reconnu avec peu de lettres
def activité_commun2():
    stop = 0
    compte = 0
    lettres = input("Entrez quelques lettres afin de déterminer l'activité\n")
    for i in range(len(users)):
        for j in range(len(users[i])):
            if lettres in users[i][j] and stop == 0: # Si les lettres sont dans l'activité le if stop et on passe à la suite
                print("Activité:\n",users[i][j])
                activité= users[i][j]
                stop = 1
    for i in range(len(users)):
        for j in range(len(users[i])):
            if users[i][j] == activité:
                print(users[i][0])
                compte = compte+1
    print("Nombre de personnes pratiquant cette activité: ",compte)

def comparaison():
    commun = 0
    l = 0
    activité = []
    utilisateur1 = input("Entrez le nom d'un utilisateur\n")
    utilisateur2 = input("Entrez le nom d'un autre utilisateur\n")
    activite_en_commun = 0
    for i in range(len(users)):
        if utilisateur1 in users[i][0]:
            for j in range(len(users[i])):
                for k in range(len(users)):
                    if utilisateur2 in users[k][0]:
                        for l in range(len(users[k])):
                            if users[i][j] == users[k][l]:
                                commun = commun+1
                                activité.append(users[i][j])
                                
    print("Nombre d'activités en commun: ",commun)
    print("Activités en commun: ",activité)


def supprimer():
    utilisateur = input("Entrez le nom d'un utilisateur\n")
    for i in range(len(users)-1):
        if utilisateur in users[i][0]:
            users.remove(users[i])
            print("Utilisateur supprimé")
    print(users)

def supprimer_activité():
    utilisateur = input("Entrez le nom d'un utilisateur\n")
    activité = input("Entrez une activité\n")
    # On enlève l'activité de l'utilisateur
    for i in range(len(users)):
        if utilisateur in users[i][0]:
            remplacement = list(users[i])
            remplacement.remove(activité)
            users[i] = tuple(remplacement)
    print(users)

def remplacer_activité():
    utilisateur = input("Entrez le nom d'un utilisateur\n")
    activité = input("Entrez une activité\n")
    for i in range(len(users)):
        if utilisateur in users[i][0]:
            remplacement = list(users[i])
            remplacement.remove(activité)
            nouvelle_activité = input("Entrez une nouvelle activité\n")
            remplacement.append(nouvelle_activité)
            users[i] = tuple(remplacement)
    print(users)

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
        print(users)
    elif choix == 2:
        activité_commun2()
    elif choix == 3:
        comparaison()
    elif choix == 4:
        supprimer_activité()
    elif choix == 5:
        supprimer()
    elif choix == 6:
        remplacer_activité()
    elif choix == 7:
        ajouter_activité()
    elif choix == 8:
        continu = 1