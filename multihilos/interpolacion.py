    def ordenar(lista):
        n = len(lista)
        for i in range(n - 1):
            for j in range(n - 1 - i):
                if lista[j] > lista[j + 1]:
                    lista[j], lista[j + 1] = lista[j + 1], lista[j]
        return lista
    
    
    def interpolacion(lista, objetivo):
        inicio = 0
        fin = len(lista) - 1
    
        while inicio <= fin and lista[inicio] <= objetivo <= lista[fin]:
            if lista[fin] == lista[inicio]:
                if lista[inicio] == objetivo:
                    return inicio
                return -1
    
            medio = inicio + ((objetivo - lista[inicio]) * (fin - inicio)) // (lista[fin] - lista[inicio])
            medio = int(medio)
    
            if lista[medio] == objetivo:
                return medio
            elif lista[medio] < objetivo:
                inicio = medio + 1
            else:
                fin = medio - 1
    
        return -1
    
    
    ventas = [175.67, 196.53, 25.50, 18.30, 13, 16.35, 250]
    ventas = ordenar(ventas)
    print("Ventas ordenadas:", ventas)
    
    n = len(ventas)
    venta_media = ventas[n // 2]
    print("Venta media (mediana):", venta_media)
    
    posicion = interpolacion(ventas, venta_media)
    
    if posicion != -1:
        print("La venta media se encuentra en la posicion", posicion)
    else:
        print("La venta media no se encuentra en la lista")