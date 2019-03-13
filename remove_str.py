def algo(obj_str):

    length = len(obj_str)
    if length<=1 :
        return obj_str

    rm_list = []

    i = 0
    while i < length:
        flag = False
        index = 0
        for j in reversed(range(i+1, length)):
            if j+j-i<=length:
                if obj_str[i:j] == obj_str[j:(j+j-i)]:
                    rm_list.append([i,j])
                    flag = True
                    index = j
                    break

        if flag:
            i = index
        else:
            i += 1

    res = obj_str
    rm_len = 0

    for item in rm_list:
        res = res[:(item[0]-rm_len)] + res[(item[1]-rm_len):]
        rm_len += (item[1]-item[0])

    return res

if __name__ == '__main__':

    a = 'hahahatodaysokukuoo'

    print(algo(a))