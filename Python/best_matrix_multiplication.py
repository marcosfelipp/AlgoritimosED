import numpy as np

def best_multiplication(sizes):
	z = lambda x, y: 0 if x <= y else 100000
	matrix = [[z(i,j) for i in range(len(sizes) +1 )] for j in range(len(sizes) + 1)]
	
	for l in range(2,len(sizes)+1):
		for i in range(1,len(sizes)-l+2):
			j = l + i - 1
			for k in range(i,j):
				q = matrix[i][k] + matrix[k+1][j] + sizes[i-2] * sizes[k-1]* sizes[j-1]
				if q < matrix[i][j]:
					matrix[i][j] = q
	
	return matrix

if __name__ == "__main__":
	mat = (best_multiplication([30,35,15,5,10,20,25]))

	print(np.matrix(mat))