# Application To-Do

tasks = [{'category': 'Devoirs', 'task': 'MT03', 'duration': '45', 'priority': '8'}, {'category': 'Ménage', 'task': 'Aspirateur', 'duration': '10', 'priority': '2'}, {'category': 'liste de courses', 'task': 'Pomme', 'duration': '2', 'priority': '1'}, {'category': 'liste de courses', 'task': 'Pain', 'duration': '1', 'priority': '1'}, {'category': 'liste de courses', 'task': 'Lait', 'duration': '1', 'priority': '1'}, {'category': 'liste de courses', 'task': 'Fromage', 'duration': '1', 'priority': '1'}, {'category': 'liste de courses', 'task': 'Jambon', 'duration': '1', 'priority': '1'}, {'category': 'liste de courses', 'task': 'Oeuf', 'duration': '1', 'priority': '1'}, {'category': 'liste de courses', 'task': 'Chocolat', 'duration': '1', 'priority': '1'}, {'category': 'liste de courses', 'task': 'Café', 'duration': '1', 'priority': '1'}, {'category': 'liste de courses', 'task': 'Sucre', 'duration': '1', 'priority': '1'}, {'category': 'Devoirs', 'tasks': 'MT04', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT05', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT06', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT07', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT08', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT09', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT10', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT11', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT12', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT13', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT14', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT15', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT16', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT17', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT18', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT19', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT20', 'duration': '45', 'priority': '8'}, {'category': 'Devoirs', 'tasks': 'MT21', 'duration': '45', 'priority': '8'}]
liste_filter = []
def add_task():
    """Add a task to the list"""
    number = input("Enter the number of tasks to add: ")
    for i in range(int(number)):
        category = input("Enter a task category: ")
        task = input("Enter a task name: ")
        duree = input("Enter a task duration: ")
        priority = input("Enter a task priority: ")
        tasks.append({"category": category, "task": task, "duration": duree, "priority": priority})
    print(tasks)

def finish_task():
    """Finish a task"""
    task = input("Enter a task name: ")
    for i in range(len(tasks)):
        if task in tasks[i]['task']:
            tasks.remove(tasks[i])
            print(tasks)
            break

def sort_tasks():
    """Sort tasks by priority"""
    print("choose a category first: ")
    choix = input("category: \n")
    list_filter = list(filter(lambda x: x['category'] in choix, tasks))
    list_filter.sort(key=lambda x: x['priority'] ,reverse=True)
    print(list_filter)

def finish_time():
    """Finish time per category and total"""
    print("Temps par catégorie: ")
    liste_category = []
    # on détermine le nombre de catégories
    for i in range(len(tasks)):
        if tasks[i]['category'] not in liste_category:
            liste_category.append(tasks[i]['category'])
            nombre_category = len(liste_category)
    for i in range(nombre_category):
        liste_filter = list(filter(lambda x: x['category'] in liste_category[i], tasks))
        somme = 0
        for j in range(len(liste_filter)):
            somme += int(liste_filter[j]['duration'])
        print(liste_category[i], ":", somme, "minutes")
    print("Temps total: ")
    print(sum(int(i['duration']) for i in tasks), "minutes")

