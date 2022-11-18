import random
a = int(random.randint(1, 100))
stop = 0
print("Entrez un nombre entre 1 et 100\n")
while stop == 0:
    devine= int(input(""))
    c = devine
    if devine == a:
        print("Vous avez gagné\n")
        stop = 1
    elif devine < a:
        print("Le nombre est plus grand\n")
        print("Entrez un nombre entre", c, "et 100\n")
        
    else:
        print("Le nombre est plus petit\n")
        print("Entrez un nombre entre 1 et", c)      
        
    
