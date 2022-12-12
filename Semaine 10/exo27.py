#traitement de fichier

with open('C:\\Users\\Elève\\OneDrive - Université de Technologie de Troyes\\Bureau\\NF06\\UTT_NF06\\Semaine 10\\est.txt') as f:
    arr = f.readlines()
    for i in range(len(arr)):
        arr[i] = arr[i].strip()
    for i in range(len(arr)):
        arr[i] = arr[i].split()
    while i < len(arr):
        for i in range(len(arr[i])):