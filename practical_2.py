import numpy as np

# Define the matrix
A = np.array([[1, 2, 3],
              [2, 4, 6],
              [3, 6, 9]])

# Perform echelon form reduction
n_rows, n_cols = A.shape
for i in range(min(n_rows, n_cols)):
    # Find the row with the largest absolute value in the current column
    max_row = np.argmax(np.abs(A[i:, i])) + i
    # Swap the current row with the row containing the largest absolute value
    A[[i, max_row]] = A[[max_row, i]]
    # Divide the current row by the first non-zero element
    if A[i, i] != 0:
        A[i] /= A[i, i]
    # Subtract multiples of the current row from the rows below
    for j in range(i + 1, n_rows):
        A[j] -= A[i] * A[j, i]

# Find the rank of the matrix
rank = np.sum(np.abs(np.diag(A)) > 1e-10)
print("Echelon form:\n", A)
print("Rank:", rank)

