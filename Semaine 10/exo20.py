#  Palindromes

def text_split(string):
    list_string = [x for x in string]
    print(list_string)

def palindrome(string):
    string = string.lower()
    print(list_string)
    list_string = [x for x in string]
    list_string.reverse()
    if list_string == [x for x in string]:
        print("C'est un palindrome")
    else:
        print("Ce n'est pas un palindrome")

palindrome("Kayak")