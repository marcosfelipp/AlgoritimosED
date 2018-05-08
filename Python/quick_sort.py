def particiona(vetor, inicio, fim):
	x = vetor[inicio]
	i = inicio +1
	j = fim

	while i <= j:
		if vetor[i] < x:
			i+=1
		elif x < vetor[j]:
			j-=1
		else:
			aux = vetor[i]
			vetor[i] = vetor[j]
			vetor[j] = aux
			i+=1
			j-=1

	aux = vetor[j]
	vetor[j] = vetor[inicio]
	vetor[inicio] = aux

	return j

def quick_sort(vetor, inicio, fim):
	if inicio < fim:
		p = particiona(vetor, inicio, fim)
		quick_sort(vetor, inicio, p-1)
		quick_sort(vetor, p+1, fim)


if __name__ == "__main__":
	vetor = [9,8,7,6,5,4,3,2,1,0,10,88,53,6,7,8,44,5,33,11,10,14,56]
	quick_sort(vetor,0,len(vetor)-1)
	print(vetor)