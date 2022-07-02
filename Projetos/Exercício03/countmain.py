from os import system
from functions import callsorting

system("cls||clear")
print("[1] - Escolha o tamanho do vetor:\n")
escolha = 0
while not escolha:
  try:
    print("[1] - O vetor terá tamanho de 10 índices"\
      "\n[2] - O vetor terá tamanho de 100 índices"\
      "\n[3] - O vetor terá tamanho de 1000 índices"\
      "\n[4] - O vetor terá tamanho de 10000 índices")
    escolha = int(input("Qual é a sua escolha? "))
  except ValueError:
    escolha = 0; system("cls||clear")
    print("Entrada inválida! Entre com um inteiro.")
  else:
    if escolha == 1:
      vector, pos = [], 10
      for i in range(10): vector.append(10 - i)
    elif escolha == 2:
      vector, pos = [], 30
      for i in range(100): vector.append(100 - i)
    elif escolha == 3:
      vector, pos = [], 30
      for i in range(1000): vector.append(1000 - i)
    elif escolha == 4:
      vector, pos = [], 30
      for i in range(10000): vector.append(10000 - i)
    else:
      escolha = 0; system("cls||clear")
      print("Digite um valor fornecido!")

system("cls||clear")
print("Exibindo o vetor (máximo de 30 casas):")
for i in range(pos): print(vector[i], end = " ")

print("\n\n[2] - Escolha a ordenação do vetor:\n")
escolha = 0
while not escolha:
  try:
    print("[1] - Embaralhar o vetor randomicamente"\
      "\n[2] - Manter o vetor em ordem decrescente")
    escolha = int(input("Qual é a sua escolha? "))
  except ValueError:
    escolha = 0; system("cls||clear")
    print("Entrada inválida! Entre com um inteiro.")
  else:
    if escolha == 1:
      from random import shuffle
      shuffle(vector)
    elif escolha != 2:
      escolha = 0; system("cls||clear")
      print("Digite um valor fornecido!")

system("cls||clear")
print("Exibindo o vetor (máximo de 30 casas):")
for i in range(pos): print(vector[i], end = " ")

print("\n\n[3] - Escolha o algoritmo de ordenação:\n")
escolha = 0
while not escolha:
  try:
    print("[1] - Escolher o Bubblesort como algoritmo"\
      "\n[2] - Escolher o Mergesort como algoritmo"\
      "\n[3] - Escolher o Countingsort como algoritmo")
    escolha = int(input("Qual é a sua escolha? "))
  except ValueError:
    escolha = 0; system("cls||clear")
    print("Entrada inválida! Entre com um inteiro.")
  else:
    if escolha in [1, 2, 3]: algorithm = escolha
    else:
      escolha = 0; system("cls||clear")
      print("Digite um valor fornecido!")

system("cls||clear")
print("Exibindo o vetor (máximo de 30 casas):")
for i in range(pos): print(vector[i], end = " ")

swaps, comps, diff, arrays = callsorting(vector, algorithm)
print("\n\n[4] - Ordenação do vetor realizada!")

print("Exibindo o vetor (máximo de 30 casas):")
for i in range(pos): print(vector[i], end = " ")
print(f"\n\nQuantidade de trocas feitas: {swaps}")
print(f"Quantidade de comparações feitas: {comps}")
print(f"O tempo de execução do algoritmo foi de {diff}s")
print(f"Nº de vetores percorridos no algoritmo: {arrays}")