#Suite de Fibonacci
n= int(input("Entrez un nombre entier"))
u0=0
u1=1
for i in range(n):
    if i >1:
        u2=u0+u1
        u0=u1
        u1=u2
print(u2)