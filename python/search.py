def linearSearch(element, *args):
    for i in range(len(args)):
        if args[i] == element:
            return f"Element found at position {i + 1}"
    else:
        return "Element not found"


def binarySearch(element, *args):
    sortedList = list(args)
    sortedList.sort()

    left = 0
    right = len(args) - 1
    mid = (left + right) // 2

    while(left <= right):
        if element < sortedList[mid]:
            right = mid - 1
        elif element > sortedList[mid]:
            left = mid + 1
        
        else:
            return f"Element found at position {mid + 1}"
    
        mid = (left + right) // 2

    else:
        return "Element Not Found"



print(binarySearch(9,3,5,6,2,7))