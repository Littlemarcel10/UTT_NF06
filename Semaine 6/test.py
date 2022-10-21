#On utilise ctypes pour appeler les fonctions en C

import ctypes as ct
_lib = ct.cdll.LoadLibrary("./test.so")
_lib.hello()
print('\n')
#On appel hello2 depuis le fichier en c
#c = input("Entrez un nombre: ")
#d = input("Entrez un nombre: ")

#_lib.ajoute_entiers.argtypes = [ct.c_int, ct.c_int]
#_lib.ajoute_entiers.restype = ct.c_int

#_lib.ajoute_entiers(2, 3)




