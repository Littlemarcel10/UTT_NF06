etudiants = [{'nom': 'Bob', 'C': {'démo': 10, 'code': 12, 'présentation': 14, 'documentation': 18}, 'Python': {'démo': 4, 'code': 7, 'présentation': 9, 'documentation': 12}}, {'nom': 'Eva', 'C': {'démo': 1, 'code': 2, 'présentation': 3, 'documentation': 4}, 'Python': {'démo': 5, 'code': 6, 'présentation': 7, 'documentation': 8}}]
def ajouter_etudiant():
    nombre_etudiants = int(input("Entrez le nombre d'étudiants: "))
    for i in range(nombre_etudiants):
        nom = input("Entrez le nom de l'étudiant: ")
        c_demo = int(input("Entrez la note de démo en C:"))
        c_code = int(input("Entrez la note de code en C:"))
        c_presentation = int(input("Entrez la note de présentation en C:"))
        c_documentation = int(input("Entrez la note de documentation en C:"))
        python_demo = int(input("Entrez la note de démo en Python:"))
        python_code = int(input("Entrez la note de code en Python:"))
        python_presentation = int(input("Entrez la note de présentation en Python:"))
        python_documentation = int(input("Entrez la note de documentation en Python:"))
        dict_c = {"démo":c_demo,"code":c_code,"présentation":c_presentation,"documentation":c_documentation}
        dict_python = {"démo":python_demo,"code":python_code,"présentation":python_presentation,"documentation":python_documentation}
        dict_etudiant = {"nom":nom,"C":dict_c,"Python":dict_python}
        etudiants.append(dict_etudiant)
# ajouter_etudiant()
# print(etudiants)

def moyenne():
    for i in range(len(etudiants)):
        print("Moyenne de l'étudiant",etudiants[i]["nom"])
        print("C: ",(etudiants[i]["C"]["démo"]+etudiants[i]["C"]["code"]+etudiants[i]["C"]["présentation"]+etudiants[i]["C"]["documentation"])/4)
        print("Python: ",(etudiants[i]["Python"]["démo"]+etudiants[i]["Python"]["code"]+etudiants[i]["Python"]["présentation"]+etudiants[i]["Python"]["documentation"])/4)
# moyenne()

def moyenne_projet_etu():
    moyenne_C = 0
    moyenne_Python = 0
    # On fait la moyenne des étudiants pour chaque projet
    for i in range(len(etudiants)):
        moyenne_C = moyenne_C + (etudiants[i]["C"]["démo"]+etudiants[i]["C"]["code"]+etudiants[i]["C"]["présentation"]+etudiants[i]["C"]["documentation"])/4
    print("Moyenne de C: ",moyenne_C/len(etudiants))
    for i in range(len(etudiants)):
        moyenne_Python = moyenne_Python + (etudiants[i]["Python"]["démo"]+etudiants[i]["Python"]["code"]+etudiants[i]["Python"]["présentation"]+etudiants[i]["Python"]["documentation"])/4
    print("Moyenne de Python: ",moyenne_Python/len(etudiants))
# moyenne_projet_etu()