# Vérifier un mot de passe
mdp = input("Entrez un mot de passe\n")
type(mdp)
Mauvais = 0
chiffre = 0
special = 0
lettres = 0
Lettres = 0
c_liste = list('$#@')
if len(mdp) < 6 or len(mdp) > 16:
    print("La taille du mot de passe est incorrecte")
    Mauvais = 1
if mdp.isalnum() == True:
    print("Le mot de passe ne contient pas des caractères non alphanumériques")
    Mauvais = 1
for c in mdp:
    if c.isdigit() == True:
        chiffre = chiffre + 1
    if c.isalpha() == True:
        if c.islower() == True:
            lettres = lettres + 1
        else:
            Lettres = Lettres + 1    
    if c in c_liste:
        special = special + 1

if chiffre <2:
    print("Le mot de passe doit contenir au moins 2 chiffres")
    Mauvais = 1
if lettres < 2:
    print("Le mot de passe doit contenir au moins 2 lettres minuscules")
    Mauvais = 1
if Lettres < 2:
    print("Le mot de passe doit contenir au moins 2 lettres majuscules")
    Mauvais = 1
if special < 1:
    print("Le mot de passe doit contenir au moins 1 caractères spéciaux")
    Mauvais = 1
if Mauvais == 0:
    print("Le mot de passe est valide")