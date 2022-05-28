import pickle

n = int(input("Введите длину будущего массива: "))
arr = [int(input(f"Введите {i} элемент массива: ")) for i in range(n)]

with open("./new_file.txt", "wb") as f:
    for num in arr:
        pickle.dump(num, f)

new_arr = []

with open("./new_file.txt", "rb") as f:
    for i in range(n):
        new_arr.append(pickle.load(f))

print(new_arr)
