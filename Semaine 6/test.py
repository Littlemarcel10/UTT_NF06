#On utilise ctypes pour appeler les fonctions en C

import ctypes as ct
_lib = ct.cdll.LoadLibrary("./test.dll")
_lib.hello()



