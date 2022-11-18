nom = input("Quel est votre nom ?")
age = int(input("Quel est votre age ?"))
taille = int(input("Quel est votre taille ?"))


if age >= 18:
    print("Vous êtes majeur")

if len(nom) > 20 :
    print("Votre nom est long")
elif len(nom) > 15 :
    print("Votre nom est semi-long")
elif len(nom) == 8 or len(nom) == 9 or len(nom) == 10 :
    print("Votre nom est semi-court")
elif len(nom) < 8 :
    print("Votre nom est court")

if taille > 172 :
    print("Vous êtes grand")
elif taille < 172 :
    print("Vous êtes petit")
