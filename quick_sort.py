def quick_sort(list, start, end):
    i , j = start, end
    tmp = list[i]

    while j > i:
        while list[j] >= tmp and j > i:
            j = j - 1
        if j > i and list[j] < tmp:
            list[i] = list[j]
            i = i + 1
            while list[i] < tmp and i < j:
                i = i + 1
            if list[i] > tmp and j > i:
                list[j] = list[i]
    list[i] = tmp
    
    if start < i - 1:
        quick_sort(list, start, i-1)
    if end > j + 1:
        quick_sort(list, j + 1, end)


if __name__ == '__main__':
    old_list = [5,8,2,6,7,4,3,9,1]
    quick_sort(old_list, 0, 8)
    print old_list

