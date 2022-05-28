with open("./nums.txt", "r") as f:
    nums = []
    
    for line in f:
        nums += [int(x) for x in line.split()]

with open("./new_nums.txt", "w") as f:
    for num in nums:
        if abs(num) % 2 != 0:
            f.write(f"{num} ") 
