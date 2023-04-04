# Arithmetic Operators +, -, *, /
a, b = 5, 10
c, d = 4, 2
e, f = 9, 2
x, y = 50, 25

print(a + b)
print(c - d)
print(e * f)
print(x / y)

# Membership Operators
ls = [1, 2, 3, 4, 5]
x = 4
y = 6

if x in ls:
  print(x, " is present in the list.")
else:
  print(x, " is not present in the list.")

if y not in ls:
  print(y, " is not present in the list.")
else:
  print(y, " is present in the list.")

# Identity Operators
x = 5
y = 5

if x is y:
  print("x equals y")
else:
  print("x doesn't equal y")

a = 2
b = 3
if a is not b:
  print("a is not b")
else:
  print("a is b")

# Bitwise Operators
a = 10 # 1010
b = 4 # 0100

print(a | b)
print(a & b)
print(~b)

c = 8 #1000
d = 7 #0111

print(c ^ d)

e = 4
print(e << 1)
print(e >> 1)