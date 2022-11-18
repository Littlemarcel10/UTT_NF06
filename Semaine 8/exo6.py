def est_negatif(x):
    if x < 0:
        return True
    else:
        return False

def est_impair(x):
    if x % 2 == 1:
        return True
    else:
        return False

def est_premier(x):
    if x == 2:
        return True
    elif x < 2:
        return False
    else:
        for i in range(2, x):
            if x % i == 0:
                return False
        return True


x=int(input("Veuiilez entrer un nombre entier"))
impair= est_impair(x)
print(impair)
neg =est_negatif(x)
print(neg)
premier = est_premier(x)
print(premier)  
# On souhaite déterminer le nombre de fois où il y a un nombre impaire dans une liste
a = 0
b= 0
liste = []
print("Entrez une liste de nombres entiers")
for i in range(5):
    liste.append(int(input("Entrez un nombre entier")))
    impaire = est_impair(liste[i])
    premiere = est_premier(liste[i])
    if impaire == True:
        a = a + 1
    if premiere == True:
        b = b + 1
    
        
print("Il y a", a, "nombre impaire dans la liste")
print("Il y a", b, "nombre premier dans la liste")