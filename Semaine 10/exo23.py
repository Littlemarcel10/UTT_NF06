#Liste de courses
Articles = [{'article': 'Pomme', 'quantite': '1'}, {'article': 'Poire ', 'quantite': '2'}]

def ajouter_article():
    article = input("Entrez un article\n")
    quantite = input("Entrez la quantité\n")
    if quantite == "":
        ajout_article(article) #Si la quantité n'est pas entrée, on met 1 par défaut
    else:
        ajout_article(article,quantite) #Sinon, on met la quantité entrée
    print(Articles)

def ajout_article(article,quantite=1): # Valeur par défaut de quantité
    n = 0
    print(type(quantite))
    for i in range(len(Articles)):
        if article in Articles[i]["article"]:
            n = Articles[i]["quantite"]
            n = n+quantite
            Articles[i]["quantite"]= n #Si l'article est déjà présent, on ajoute la quantité
            n= 2
    if n == 0:
        Articles.append({"article":article,"quantite":quantite})

def print_liste():
    for i in range(len(Articles)):
        print("Article:", i+1)
        print("Nom:", Articles[i]["article"])
        print("Quantité:", Articles[i]["quantite"])

def supprimer_quantite():
    print("Quel est l'article que vous avez acheter?")
    article = input()
    print("Combien en avez-vous acheter?")
    nombre = input()
    if nombre == "":
        supprimer(article)
    else:
        supprimer(article,nombre)

def supprimer(article,nombre=1):
    quantite = int(nombre)
    for i in range(len(Articles)-1):
        nom = Articles[i]["article"]
        if article in nom:
            n = Articles[i]["quantite"]
            n = n - quantite
            if n <= 0:
                del Articles[i]
            else:
                Articles[i]["quantite"] = n
    print(Articles)

ajouter_article()