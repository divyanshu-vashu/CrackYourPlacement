s="vellore college"
my_dict={}
for k in s:
    if k.isalpha():
        if k in my_dict:
            my_dict[k]+=1
        else:
            my_dict[k]=1

print(my_dict)
