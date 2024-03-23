def factorial_recursivo(n):
    if n == 0:
        return 1
    else:
        return n*factorial_recursivo(n-1)

prueba = factorial_recursivo(5)
print(f"El factorial de 5 es",prueba)