#Liste de courses
articles = [{'nom': 'Pomme', 'quantité': 3}, {'nom': 'Dentifrice', 'quantité': 1}, {'nom': 'Préservatif', 'quantité': 24}, {'nom': 'Brosse à dents', 'quantité': 3}, {'nom': 'Pain', 'quantité': 1}, {'nom': 'Lait', 'quantité': 1}, {'nom': 'Fromage', 'quantité': 1}, {'nom': 'Oeuf', 'quantité': 12}, {'nom': 'Jambon', 'quantité': 1}, {'nom': 'Pâtes', 'quantité': 1}, {'nom': 'Riz', 'quantité': 1}, {'nom': 'Poisson', 'quantité': 1}, {'nom': 'Chocolat', 'quantité': 1}, {'nom': 'Café', 'quantité': 1}, {'nom': 'Thé', 'quantité': 1}, {'nom': 'Laitue', 'quantité': 1}, {'nom': 'Tomate', 'quantité': 1}, {'nom': 'Carotte', 'quantité': 1}, {'nom': 'Pomme de terre', 'quantité': 1}, {'nom': 'Poulet', 'quantité': 1}, {'nom': 'Poisson', 'quantité': 1}, {'nom': 'Pain', 'quantité': 1}, {'nom': 'Lait', 'quantité': 1}, {'nom': 'Fromage', 'quantité': 1}, {'nom': 'Oeuf', 'quantité': 12}, {'nom': 'Jambon', 'quantité': 1}, {'nom': 'Pâtes', 'quantité': 1}, {'nom': 'Riz', 'quantité': 1}, {'nom': 'Poisson', 'quantité': 1}, {'nom': 'Chocolat', 'quantité': 1}, {'nom': 'Café', 'quantité': 1}, {'nom': 'Thé', 'quantité': 1}, {'nom': 'Laitue', 'quantité': 1}, {'nom': 'Tomate', 'quantité': 1}, {'nom': 'Carotte', 'quantité': 1}, {'nom': 'Pomme de terre', 'quantité': 1}, {'nom': 'Poulet', 'quantité': 1}, {'nom': 'Poisson', 'quantité': 1}]

def add_article():
    nombre = int(input("Combien d'articles voulez-vous ajouter?\n"))
    for i in range(nombre):
        nom = input("Entrez le nom de l'article\n")
        quantité = int(input("Entrez la quantité\n"))
        articles.append({'nom':nom,'quantité': quantité})
    print(articles)

