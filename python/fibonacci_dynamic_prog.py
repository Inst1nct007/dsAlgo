def fibonacci(n):
    for i in range(n):
        if i <= 1:
            li[i] = i
        else:
            li[i] = li[i - 1] + li[i - 2]


n = 10
li = []
for i in range(n):
    li.append(0)
fibonacci(n)
print(li)
