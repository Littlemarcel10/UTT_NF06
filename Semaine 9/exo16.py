Liste_films= [{'nom': 'Attack on Titan', 'année': '2021', 'note IMDB': '9', 'copie': '99', 'prix': '2', 'durée': '2'}, {'nom': 'Bonky boi', 'année': '2012', 'note IMDB': '8', 'copie': '0', 'prix': '12', 'durée': '35'},{'nom': 'Ratatouille', 'année': '2007', 'note IMDB': '8.5', 'copie': '5', 'prix': '10', 'durée': '30'},{'nom': 'The Godfather', 'année': '1972', 'note IMDB': '9.2', 'copie': '0', 'prix': '15', 'durée': '60'},{'nom': 'The Shawshank Redemption', 'année': '1994', 'note IMDB': '9.3', 'copie': '2', 'prix': '20', 'durée': '60'},{'nom': 'The Dark Knight', 'année': '2008', 'note IMDB': '9', 'copie': '1', 'prix': '25', 'durée': '60'},{'nom': 'The Lord of the Rings: The Return of the King', 'année': '2003', 'note IMDB': '8.9', 'copie': '1', 'prix': '30', 'durée': '60'},{'nom': 'The Lord of the Rings: The Fellowship of the Ring', 'année': '2001', 'note IMDB': '8.8', 'copie': '1', 'prix': '35', 'durée': '60'},{'nom': 'The Lord of the Rings: The Two Towers', 'année': '2002', 'note IMDB': '8.7', 'copie': '1', 'prix': '40', 'durée': '60'},{'nom': 'The Matrix', 'année': '1999', 'note IMDB': '8.7', 'copie': '1', 'prix': '45', 'durée': '60'}]

def ajouter_film():
    nom = input("Entrez le nom d'un film\n")
    année = input("Entrez l'année de sortie du film\n")
    note = input("Entrez la note IMDB du film\n")
    copie = input("Entrez le nombre de copies du film\n")
    prix = input("Entrez le prix du film\n")
    durée = input("Entrez la durée du film\n")
    Liste_films.append({"nom":nom,"année":année,"note IMDB":note,"copie":copie,"prix":prix,"durée":durée})
    print(Liste_films)

def disponible(Liste_films):
    return Liste_films.get("copie") != "0"
    
    
def trier_film():
    only_available = False
    print("Tout les films sont:")
    print(Liste_films)
    only_available = True
    if only_available == True:
        print("Les films disponibles sont:")
        print(list(filter(disponible, Liste_films)))
continu = 0

def trie_note():
    print("Les films triés par note sont:")
    print(sorted(Liste_films, key=lambda x: x["note IMDB"], reverse=True))

def location():
    print("Les films disponibles sont:")
    print(list(filter(disponible, Liste_films)))
    choix = input("Entrez le nom du film que vous voulez louer\n")
    for film in Liste_films:
        if choix in film["nom"]:
            film["copie"] = str(int(film["copie"]) - 1)
            print("Le film a été loué")
            print(Liste_films)
            break
while continu ==0:       
    print("Bienvenue dans notre vidéothèque")
    print("1. Ajouter un film")
    print("2. Afficher les films disponibles")
    print("3. Afficher les films triés par note")
    print("4. Louer un film")
    print("5. Quitter")

    choix = input("Entrez votre choix\n")
    if choix == "1":
        ajouter_film()
    elif choix == "2":
        trier_film()
    elif choix == "3":
        trie_note()
    elif choix == "4":
        location()
    elif choix == "5":
        print("Au revoir")
        continu = 1
    