def callsorting(vector, algorithm):
  from datetime import datetime
  t1 = datetime.now()
  if algorithm == 1:
    swaps, comps, arrays = bubblesort(vector)
    t2 = datetime.now()
  elif algorithm == 2:
    swaps, comps, arrays = mergesort(vector)
    t2 = datetime.now()
  else:
    swaps, comps, arrays = countingsort(vector)
    t2 = datetime.now()
  diff = (t2 - t1).total_seconds()
  return swaps, comps, diff, arrays

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
  arrays = len(vector) - tam
  return swaps, comps, arrays

def mergesort(vector):
  swaps, comps, arrays = 0, 0, 0
  if len(vector) > 1:
    arrays = 1
    mid = len(vector) // 2
    left, right = vector[:mid], vector[mid:]
    swap, comp, array1 = mergesort(left)
    swaps += swap; comps += comp
    swap, comp, array2 = mergesort(right)
    swaps += swap; comps += comp
    arrays += array1 + array2
    swap, comp = merge(vector, left, right)
    swaps += swap; comps += comp
  return swaps, comps, arrays

def merge(vector, left, right):
  i, j, k = 0, 0, 0
  swaps, comps = 0, 0
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
  comps, swaps, arrays = 0, 0, 6
  maior, k, aux = vector[0], [], []
  for i in range(1, len(vector)):
    if vector[i] > maior: maior = vector[i]
    comps += 1
  for i in range(maior + 1):
    k.append(0); comps += 1
  for i in range(len(vector)):
    aux.append(0); comps += 1
    k[vector[i]] += 1
  for i in range(1, len(k)):
    k[i] = k[i] + k[i-1]; comps += 1
  for i in range(len(vector)-1, 0, -1):
    k[vector[i]] -= 1; comps += 1
    aux[k[vector[i]]] = vector[i]
  for i in range(len(vector)):
    swaps += 1; comps += 1
    vector[i] = aux[i]
  del aux; return swaps, comps, arrays