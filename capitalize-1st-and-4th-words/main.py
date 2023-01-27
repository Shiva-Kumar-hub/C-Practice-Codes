'''
OLD MACDONALD: Write a function that capitalizes the first and fourth letters of a name

old_macdonald('macdonald') --> MacDonald

Note: 'macdonald'.capitalize() returns 'Macdonald'
'''

def capitalize(string):
    result = ''
    for i in range(len(string)):
        if (i == 0 or i == 3):
            result += string[i].upper()
        else:
            result += string[i]
    return result
    
import numpy as np 
myString = input("Enter the Input String : ")
result = capitalize(myString)

print(result)