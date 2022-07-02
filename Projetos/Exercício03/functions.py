def callsorting(vector, algorithm):
  from datetime import datetime
  t1 = datetime.now()
  if algorithm == 1:
    swaps, comps, travel = bubblesort(vector)
    t2 = datetime.now()
  elif algorithm == 2:
    swaps, x, comps, travel = mergesort(vector); del x
    t2 = datetime.now()
  else:
    swaps, comps, travel = countingsort(vector)
    t2 = datetime.now()
  diff = (t2 - t1).total_seconds()
  return swaps, comps, travel, diff

def bubblesort(vector):
  flag, swaps, comps = 1, 0, 0
  tam = len(vector)
  while flag:
    flag = 0
    for j in range(tam - 1):
      comps += 1
      if vector[j] > vector[j + 1]:
        swaps += 1; flag = 1
        Aux = vector[j]
        vector[j] = vector[j + 1]
        vector[j + 1] = Aux
    tam -= 1
  travel = len(vector) - tam
  return swaps, comps, travel

def mergesort(vector):
  swaps, flag, comps, travel = 0, 0, 0, 0
  if len(vector) > 1:
    flag = 1; travel += 1
    mid = len(vector) // 2
    left, right = vector[:mid], vector[mid:]
    sums, flag1, comp, res = mergesort(left)
    if flag1: travel += res
    swaps += sums; comps += comp
    sums, flag1, comp, res = mergesort(right)
    if flag1: travel += res
    swaps += sums; comps += comp
    sums, comp = merge(vector, left, right)
    swaps += sums; comps += comp
  return swaps, flag, comps, travel

def merge(vector, left, right):
  comps, swaps = 0, 0
  i, j, k, swaps = 0, 0, 0, 0
  while i < len(left) and j < len(right):
    if left[i] < right[j]:
      vector[k] = left[i]
      i += 1; swaps += 1
    else:
      vector[k] = right[j]
      j += 1; swaps += 1
    k += 1; comps += 1
  while i < len(left):
    vector[k] = left[i]
    i += 1; k += 1
  while j < len(right):
    vector[k] = right[j]
    j += 1; k += 1
  return swaps, comps

def countingsort(vector):
  comps, swaps, travel = 0, 0, 0
  maior, k, aux = vector[0], [], []
  for i in range(1, len(vector)):
    travel += 1; comps += 1
    if vector[i] > maior: maior = vector[i]
  for i in range(maior + 1):
    travel += 1
    k.append(0)
  for i in range(len(vector)):
    travel += 1
    aux.append(0)
    k[vector[i]] += 1
  for i in range(1, len(k)):
    travel += 1
    k[i] = k[i] + k[i-1]
  for i in range(len(vector)-1, 0, -1):
    travel += 1
    k[vector[i]] -= 1
    aux[k[vector[i]]] = vector[i]
  for i in range(len(vector)):
    travel += 1; swaps += 1
    vector[i] = aux[i]
  del aux; return swaps, comps, travel