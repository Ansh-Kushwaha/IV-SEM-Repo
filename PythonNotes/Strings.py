# strings in python are surrounded by either single, double aur triple quotation marks
a = 'Hello'
b = "World!"
print(a, b)

# Multiline string
c = '''Example of a
        multi line String.'''
print(c)

# *Strings are arrays inn Python same as other poplular programming languages
print(a[0], b[0])

# looping over a String
for s in a :
    print(s)

# len() to get the length of a string
x = len(c)
print("Length of c : ", x)

# membership operators work with strings
if "Example" in c :
    print("Example is present in the string c")