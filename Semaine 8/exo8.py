import math 
# solveur équation du second degré
a = float(input("Entrez la valeur de a\n"))
b = float(input("Entrez la valeur de b\n"))
c = float(input("Entrez la valeur de c\n"))

delta = b**2 - 4*a*c
if delta < 0:
    print("Il n'y a pas de solution réelle")
    print("Solution imaginaire")
    print("x1 = ", -b/(2*a), "+", math.sqrt(-delta)/(2*a), "i")
    print("x2 = ", -b/(2*a), "-", math.sqrt(-delta)/(2*a), "i")
if delta == 0:
    x = -b/(2*a)
    print("Il y a une solution double", x)
if delta > 0:    
    e1 = (b-math.sqrt(delta))/(2*a)
    e2 = (b+math.sqrt(delta))/(2*a)
    print("Il y a deux solutions", e1, "et", e2)
    