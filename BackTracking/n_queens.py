def nqueens(n): 

    mat=[[0 for _ in range(n)] for _ in range(n)]
    solutions=[]

    def is_safe(mat, row, col):
        # check same column 
        for i in range(row):
            if mat[i][col] == 1:
                return False

        # check left diagonal 
        i, j = row, col
        while i >= 0 and j >= 0:
            if mat[i][j] == 1:
                return False
            i -= 1
            j -= 1

        # check right diagonal
        i, j = row, col
        while i >= 0 and j < n:
            if mat[i][j] == 1:
                return False
            i -= 1
            j += 1
        return True

    def solve(mat, row):
        if row >=n: 
            solutions.append([row[:] for row in mat])

        for i in range(n) :
            if is_safe(mat, row, i):
                mat[row][i] = 1
                solve(mat, row + 1)
                mat[row][i] = 0

    solve(mat, 0)
    return solutions
 
