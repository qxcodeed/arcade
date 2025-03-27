from typing import List

# ++
def processa(vet: List[int]) -> None:
    if len(vet) == 0:
        return
    aux: List[int] = []
    for i in range(len(vet) - 1):
        aux.append(vet[i] + vet[i + 1])
    processa(aux)
    out = [str(x) for x in vet]
    print("[ {} ]".format(" ".join(out)))
    # $$
    # pass
    # ==
    # 1. defina o ponto de parada
    # 2. monte o vetor auxiliar com os resultados das somas
    # 3. chame recursivamente a função processa para o vetor auxiliar
    # 4. imprima o vetor original
