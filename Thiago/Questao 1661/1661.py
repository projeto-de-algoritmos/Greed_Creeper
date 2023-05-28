def main():
    numHabitantes = int(input())
    while(numHabitantes != 0):
        
        compraVendeGarrafas = list(map(int,input().split()))
        aux = 0
        unidadeTrab = 0
        for i in compraVendeGarrafas:
            aux += i
            unidadeTrab += abs(aux)


        print(unidadeTrab)

        numHabitantes = int(input())


main()