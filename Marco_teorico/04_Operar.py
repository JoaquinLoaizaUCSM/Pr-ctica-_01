
def suma(a,b):
    return a+b

def resta(a,b):
    return a-b

def multiplicacion(a,b):
    return a*b

def uso(funcion,a,b):
    return funcion(a,b)


prueba_02 = uso(multiplicacion,7,5)
print(f"El producto de 5 * 7 es ",prueba_02)