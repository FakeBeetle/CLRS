def insertion_sort(x:list,metric:list):
    for i in range(1,len(x)):
        j = i
        while j>0 and metric[j]<metric[j-1]:
            x[j],x[j-1] = x[j-1],x[j]
            j -= 1

def partition(x:list,pivot:int):
    upper = []
    lower = []
    for i in x:
        if i>pivot:
            upper.append(i)
        elif i < pivot:
            lower.append(i)
    return (lower,upper)

def select(x:list,order:int):#该算法尚未考虑有相同元素的情况
    #分组
    if len(x)<5:
        insertion_sort(x,x)
        return x[order-1]
    else:
        y = []
        for i in range(0,len(x),5):
            if (i+5>=len(x)):
                y.append(x[i:].copy())
            else:
                y.append(x[i:i+5].copy())

        for interval in y:
            insertion_sort(interval,interval)#内部排序

        medians = []

        for interval in y:
            medians.append(interval[int(len(interval)/2)])

        md_of_medians = select(medians,int(len(y)/2)+1)
        lower,upper = partition(x,md_of_medians)
        if  order == len(lower)+1:
            return md_of_medians
        elif order<len(lower)+1:

            return select(lower,order)
        elif order>len(lower)+1:
            return select(upper,order-len(lower)-1)

x = [3,9,2,4,12,1,35,23,5,6,11,87,44,63,18]
for i in range(1,16):
    print(select(x,i),end =" ")
insertion_sort(x,x)
print(x)








