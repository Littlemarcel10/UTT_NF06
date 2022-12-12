import random as rd
#Jeu de devinette
Banque = [{'mot':'poire', 'description':'Fruit venant d un arbre'},{'mot':'chaussure','description':'On peut marcher avec'},{'mot':'ordinateur','description':'On peut jouer avec'},{'mot':'table','description':'On peut manger dessus'},{'mot':'chaise','description':'On peut s assoir dessus'},{'mot':'pomme','description':'Fruit rouge et croquant'},{'mot':'voiture','description':'On peut rouler avec'}]

def choix_mot():
    n = rd.randint(0,len(Banque)-1)
    mot = Banque[n]["mot"]
    description = Banque[n]["description"]
    jeu(mot,description)

def jeu(mot,description):
    mot_cache = "_ " * len(mot)
    compteur = 0
    print(mot)
    print("Vous avez 3 vies, devinez une lettre dans le mot")
    print("Le mot est",description)
    vie = 3
    while vie > 0:
        print("Il vous reste",vie,"vies")
        print("Le mot est",mot_cache)
        print("Quelle lettre voulez-vous tester?")
        lettre = input()
        if lettre in mot:
            print("La lettre est dans le mot")
            for i in range(len(mot)):
                if lettre == mot[i]:
                    mot_cache = mot_cache[:i*2] + lettre + mot_cache[i*2+1:]
                    compteur = compteur + 1
                    print(compteur)
                    vie = vie + 1
        else:            
            vie = vie - 1
        if compteur == len(mot):
            print("Vous avez gagné!")
            print("Le mot était",mot)
            break           
    if vie == 0:
        print("Vous avez perdu")
        print("⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠟⠛⠻⠿⣿⣿⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿")
        print("⣿⣿⣿⣿⣿⣿⠟⠉⠄⠄⠄⠄⠄⠄⠄⠉⢟⠉⠄⠄⠄⠄⠄⠈⢻⣿⣿⣿⣿⣿")   
        print("⣿⣿⣿⣿⡿⠃⠄⠄⠤⠐⠉⠉⠉⠉⠉⠒⠬⡣⠤⠤⠄⠄⠄⠤⠤⠿⣿⣿⣿⣿")
        print("⣿⣿⣿⣿⠁⠄⠄⠄⠄⠄⠄⠠⢀⡒⠤⠭⠅⠚⣓⡆⡆⣔⡙⠓⠚⠛⠄⣹⠿⣿")
        print("⣿⠟⠁⡌⠄⠄⠄⢀⠤⠬⠐⣈⠠⡤⠤⠤⣤⠤⢄⡉⢁⣀⣠⣤⣤⣀⣐⡖⢦⣽")
        print("⠏⠄⠄⠄⠄⠄⠄⠄⠐⠄⡿⠛⠯⠍⠭⣉⣉⠉⠍⢀⢀⡀⠉⠉⠉⠒⠒⠂⠄⣻")
        print("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠩⠵⠒⠒⠲⢒⡢⡉⠁⢐⡀⠬⠍⠁⢉⣉⣴⣿⣿")
        print("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠉⢉⣒⡉⠁⠁⠄⠄⠉⠂⠙⣉⣁⣀⣙⡿⣿⣿")
        print("⠄⠄⠄⠄⠄⠄⠄⠄⢠⠄⡖⢉⠥⢤⠐⢲⠒⢲⠒⢲⠒⠲⡒⠒⡖⢲⠂⠄⢀⣿")
        print("⠄⠄⠄⠄⠄⠄⠄⠄⠈⢆⡑⢄⠳⢾⠒⢺⠒⢺⠒⠚⡖⠄⡏⠉⣞⠞⠁⣠⣾⣿")
        print("⠄⠄⠄⠄⠄⠄⢆⠄⠄⠄⠈⠢⠉⠢⠍⣘⣒⣚⣒⣚⣒⣒⣉⠡⠤⣔⣾⣿⣿⣿")
        print("⠷⣤⠄⣀⠄⠄⠄⠈⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣤⣾⣿⣿⣿⣿⣿")
        print("⠄⠄⠉⠐⠢⠭⠄⢀⣒⣒⡒⠄⠄⠄⠄⠄⠄⣀⡠⠶⢶⣿⣿⣿⣿⣿⣿⣿⣿⣿")
        print("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠁⠈⠄⠄⠄⠄⠄⠄⠈⠻⣿⣿⣿⣿⣿⣿⣿")
        print("Le mot était",mot)
choix_mot()