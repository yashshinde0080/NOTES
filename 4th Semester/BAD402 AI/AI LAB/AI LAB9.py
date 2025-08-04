# Simple Tic-Tac-Toe Game

def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" *10) 

def check_winner(board, player):
    # Check rows, columns, and diagonals
    for i in range(3):
        if all([cell == player for cell in board[i]]):  # Check rows
            return True
        if all([board[j][i] == player for j in range(3)]):  # Check columns
            return True
    if all([board[i][i] == player for i in range(3)]) or all([board[i][2-i] == player for i in range(3)]):  # Check diagonals
        return True
    return False

def get_move():
    while True:
        move = input("Enter your move (row and column): ").split()
        if len(move) == 2 and move[0].isdigit() and move[1].isdigit():
            return int(move[0]), int(move[1])
        print("Invalid input. Enter row and column as two numbers.")

board = [[" " for _ in range(3)] for _ in range(3)]
current_player = "X"

while True:
    print_board(board)
    row, col = get_move()
    if board[row][col] == " ":
        board[row][col] = current_player
        if check_winner(board, current_player):
            print_board(board)
            print(f"Player {current_player} wins!")
            break
        if all([cell != " " for row in board for cell in row]):
            print_board(board)
            print("It's a draw!")
            break
        current_player = "O" if current_player == "X" else "X"
    else:
        print("Cell is already occupied! Try again.")
