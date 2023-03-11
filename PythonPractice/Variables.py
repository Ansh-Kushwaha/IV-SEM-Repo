x = 1 #int
y = "ABC" #String
z = 'DEF' #String

print(x, y, z)

# Multiple assignment
a, b, c = 25, 30, 35

print(a, b, c)

# Unpacking list
fruits = ["Apple", "Banana", "Cherry"]
d, e, f = fruits

print(d, e, f)

# Variable scope
s = "awesome"

def myF():
    s = "fantastic"
    print("Python is " + s)

myF()
print("Python is " + s)

# global keyword

def myF2():
    global g
    g = 12
    print(g)
myF2()
print(g)