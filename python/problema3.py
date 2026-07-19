import random
 
arreglo = [random.randint(1, 100) for _ in range(10)]
 
# Burbuja
def burbuja(arr):
    arr = arr.copy()
    n = len(arr)
    comparaciones = 0
    intercambios = 0
    for i in range(n - 1):
        for j in range(n - 1 - i):
            comparaciones += 1
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                intercambios += 1
    return arr, comparaciones, intercambios
 
# Insercion
def insercion(arr):
    arr = arr.copy()
    n = len(arr)
    comparaciones = 0
    intercambios = 0
    for i in range(1, n):
        clave = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > clave:
            comparaciones += 1
            arr[j + 1] = arr[j]
            intercambios += 1
            j -= 1
        if j >= 0:
            comparaciones += 1
        arr[j + 1] = clave
    return arr, comparaciones, intercambios
 
# Seleccion
def seleccion(arr):
    arr = arr.copy()
    n = len(arr)
    comparaciones = 0
    intercambios = 0
    for i in range(n - 1):
        menor = i
        for j in range(i + 1, n):
            comparaciones += 1
            if arr[j] < arr[menor]:
                menor = j
        if menor != i:
            arr[i], arr[menor] = arr[menor], arr[i]
            intercambios += 1
    return arr, comparaciones, intercambios
 
 
print("Arreglo original:", arreglo)
 
res, comp, inter = burbuja(arreglo)
print("\nBurbuja:", res)
print("Numero de comparaciones:", comp, ", Numero de intercambios:", inter)
 
res, comp, inter = insercion(arreglo)
print("\nInsercion:", res)
print("Numero de comparaciones:", comp, ", Numero de intercambios:", inter)
 
res, comp, inter = seleccion(arreglo)
print("\nSeleccion:", res)
print("Numero de comparaciones:", comp, ", Numero de intercambios:", inter)
 