import requests
import json

response = requests.get("https://randomuser.me/api/?results=10")

users = json.loads(response.text)

print(users)

for i in range(len(users["results"])):
    nom = users["results"][i]["name"]["last"]
    Prenom = users["results"][i]["name"]["first"]
    titre = users["results"][i]["name"]["title"]
    sexe = users["results"][i]["gender"]
    birthday = users["results"][i]["dob"]["date"]
    
    print("Utilisateur",i+1," : ",titre,nom,Prenom,"né le",birthday,"est de sexe",sexe)


