def ordenar(lista):
    n = len(lista)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if lista[j] < lista[j + 1]:
                lista[j], lista[j + 1] = lista[j + 1], lista[j]
    return lista
 
 
def busqueda_binaria(lista, objetivo):
    inicio = 0
    fin = len(lista) - 1
 
    while inicio <= fin:
        medio = (inicio + fin) // 2
 
        if lista[medio] == objetivo:
            return medio
        elif lista[medio] > objetivo:
            inicio = medio + 1
        else:
            fin = medio - 1
 
    return -1
 
 
edades = [75, 35, 12, 15, 5, 14, 21]
edades = ordenar(edades)
buscar = 15
 
resultado = busqueda_binaria(edades, buscar)
 
if resultado != -1:
    print("Elemento 15 encontrado en la posicion", resultado)
else:
    print("Elemento no encontrado")