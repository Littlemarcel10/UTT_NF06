import math

def type_triangle(triangle_list):
    if triangle_list[0] == triangle_list[1] == triangle_list[2]:
        print("C'est un triangle équilatéral")
    elif triangle_list[0] == triangle_list[1] or triangle_list[0] == triangle_list[2] or triangle_list[1] == triangle_list[2]:
        print("C'est un triangle isocèle")
    elif triangle_list[0]**2 + triangle_list[1]**2 == triangle_list[2]**2 or triangle_list[0]**2 + triangle_list[2]**2 == triangle_list[1]**2 or triangle_list[1]**2 + triangle_list[2]**2 == triangle_list[0]**2:
        print("C'est un triangle rectangle")
    else:
        print("C'est un triangle quelconque")

def aire_triangle(triangle_list):
    if triangle_list[0] == triangle_list[1] == triangle_list[2]:
        aire = (math.sqrt(3)/4)*triangle_list[0]**2
        print("L'aire du triangle est de",aire)
    elif triangle_list[0] == triangle_list[1] or triangle_list[0] == triangle_list[2] or triangle_list[1] == triangle_list[2]:
        aire = (triangle_list[0]*math.sqrt(triangle_list[1]**2 - (triangle_list[0]**2)/4))/2
        print("L'aire du triangle est de",aire)
    elif triangle_list[0]**2 + triangle_list[1]**2 == triangle_list[2]**2 or triangle_list[0]**2 + triangle_list[2]**2 == triangle_list[1]**2 or triangle_list[1]**2 + triangle_list[2]**2 == triangle_list[0]**2:
        aire = (triangle_list[0]*triangle_list[1])/2
        print("L'aire du triangle est de",aire)
    else:
        p = (triangle_list[0] + triangle_list[1] + triangle_list[2])/2
        aire = math.sqrt(p*(p-triangle_list[0])*(p-triangle_list[1])*(p-triangle_list[2]))
        print("L'aire du triangle est de",aire)

def perimetre_triangle(triangle_list):
    perimetre = triangle_list[0] + triangle_list[1] + triangle_list[2]
    print("Le périmètre du triangle est de",perimetre)
