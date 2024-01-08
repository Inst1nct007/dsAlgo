def quickSort(start, end, li):
    if start < end:
        pivot = start
        for i in range(start, end):
            if li[i] < li[(start + end) // 2]:
                pivot += 1
        if pivot != (start + end) // 2:
            li[(start + end) // 2] += li[pivot]
            li[pivot] = li[(start + end) // 2] - li[pivot]
            li[(start + end) // 2] -= li[pivot]
        i = start
        j = end - 1
        while i < j:
            if li[i] >= li[pivot] and li[pivot] > li[j]:
                li[i] += li[j]
                li[j] = li[i] - li[j]
                li[i] -= li[j]
                i += 1
            elif li[i] > li[pivot] and li[pivot] < li[j] or pivot == j:
                j -= 1
            else:
                i += 1
        quickSort(start, pivot, li)
        quickSort(pivot + 1, end, li)



li = [6,5,4,3,2,1]
# li = [7,8,5,6,4,3]
# li = [6,2,1,4,5,7,8]
# li = [7,2,1,6,8,5,3,4]
# li = [1,1,1,1,1,1]
# li = [1,2,3,3,2,1]

quickSort(0, len(li), li)
print(li)
