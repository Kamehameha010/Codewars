""" 
Your job is to write a function which increments a string, to create a new string.

    If the string already ends with a number, the number should be incremented by 1.
    If the string does not end with a number. the number 1 should be appended to the new string.

"""




def increment_string(strng:str):
    import re
    find = re.search(r'(\d{1,}$)',strng)
    if find is None:
        return f"{strng}1"
    strng = strng[:find.start()]
    value = find.group()
    val = str(int(value)+1)
    return f"{strng}{value[:-len(val)]}{val}"
    
