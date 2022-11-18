#analyse de texte
texte = input("Entrez un texte\n")
voyelles = 0
# On va compter le nombre de mots
mots = len(texte.split())
print("Il y a", mots, "mots dans le texte")

# on va compter le nombre de voyelles
texte = texte.lower()
for i in range(len(texte)):
    if texte[i] in "aeiouy":
        voyelles = voyelles + 1
print("Il y a", voyelles, "voyelles dans le texte")
#On va afficher les mots avec 2 voyelles
split = texte.split()
for i in range(len(split)):
    for j in range(len(split[i])):
        if split[i][j] in "aeiouy":
            voyelles = voyelles + 1
    if voyelles == 2:
        print(split[i])
    voyelles = 0

