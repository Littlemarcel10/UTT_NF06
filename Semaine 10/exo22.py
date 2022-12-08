# Suites géométriques
a = int(input("Entrez le premier terme de la série\n"))
r = int(input("Entrez la raison\n"))
n = int(input("Entrez l'indice à calculer\n"))

print("Le terme d'indice",n,"est",a*r**n)
print("La somme des termes jusqu'à l'indice",n,"est",a*(1-r**(n+1))/(1-r))
liste = [a*r**n for n in range(n+1)]
print("La somme des termes jusqu'à l'indice",n,"est",sum(liste))
