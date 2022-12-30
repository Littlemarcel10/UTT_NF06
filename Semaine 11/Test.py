import ctypes

class Element(ctypes.Structure):
    fields = [("poids", ctypes.c_int), ("valeur", ctypes.c_int), ("quantite", ctypes.c_int)]

lib = ctypes.cdll.LoadLibrary("C:\\Users\\Utilisateur\\Documents\\GitHub\\INF8775\\Semaine 11\\Test.dll")
sac_a_dos = lib.sac_a_dos
sac_a_dos.argtypes = [ctypes.POINTER(Element), ctypes.c_int, ctypes.c_int]