lista = [35, 12, 48, 5, 19, 2]
 
# Burbuja ascendente
def burbuja_asc(arr):
    arr = arr.copy()
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr
 
# Burbuja descendente
def burbuja_desc(arr):
    arr = arr.copy()
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] < arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr
 
# Insercion
def insercion(arr):
    arr = arr.copy()
    for i in range(1, len(arr)):
        clave = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > clave:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = clave
    return arr
 
# Seleccion
def seleccion(arr):
    arr = arr.copy()
    n = len(arr)
    for i in range(n - 1):
        menor = i
        for j in range(i + 1, n):
            if arr[j] < arr[menor]:
                menor = j
        arr[i], arr[menor] = arr[menor], arr[i]
    return arr
 
 
print("Lista original:", lista)
print("Burbuja ascendente:", burbuja_asc(lista))
print("Burbuja descendente:", burbuja_desc(lista))
print("Insercion:", insercion(lista))
print("Seleccion:", seleccion(lista))