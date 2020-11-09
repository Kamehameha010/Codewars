def narcissistic(value):
    # Code away
    lst = list(str(value))
    c = [pow(int(f), len(lst)) for f in lst]

    if sum(c) == value:
        return True
    else:
        return False


def add_binary(a, b):
    return bin(a+b)[2::]


def row_sum_odd_numbers(n):
    # return n**3
    # range en vez de for  sum([x for x in range(min, (min+dif+1),2)])
    dif = n*2-2
    min = int(n*dif/2+1)
    return sum([x for x in range(min, (min+dif+1), 2)])


def to_weird_case(string):
    div = string.split(" ")
    lst = []
    for c in range(len(div)):
        for i, j in enumerate(div[c]):
            if i % 2 == 0:
                lst.append(j.upper())
            else:
                lst.append(j)
        lst.append(" ")

    return "".join(lst).strip()


def validPhoneNumber(phoneNumber):
    import re
    return re.compile(r"^\(\d{3}\)\s\d{3}\-\d{4}$").match(phoneNumber) != None


def move_zeros(array):
    lst = []
    count = 0
    for indx, val in enumerate(array):
        if val == 0 and not type(val) is bool :
            count += 1
        else:
            lst.append(val)
    lst += [0]*count
    return lst

