# fonctions sur les triangles
import TrianglesLibrary as tl

triangle = []
for i in range(3):
    triangle.append(int(input("Entrez la longueur d'un côté du triangle\n")))
tl.type_triangle(triangle)
tl.perimetre_triangle(triangle)
tl.aire_triangle(triangle)