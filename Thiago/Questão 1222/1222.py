while True:
    try:
        entrada = input().split()
        qnt_palavras = int(entrada[0])
        linhasPorPag = int(entrada[1])
        charsPorLinha = int(entrada[2])

        texto = input().split()

        letras = len(texto[0])
        paginas = 1
        linhas = 1

        for i in range(1, qnt_palavras):
            tamanho = len(texto[i])

            if letras + tamanho + 1 <= charsPorLinha:
                    letras += tamanho + 1
            else:
                    linhas += 1
                    if linhas > linhasPorPag:
                        paginas += 1
                        linhas = 1

                    letras = tamanho

        print(paginas)

    except EOFError:
        break