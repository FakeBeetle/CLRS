def insertion_sort(x:list,metric:list,start:int,end:int):
    for i in range(start+1,end+1):
        j = i
        while j>0 and metric[j]<metric[j-1]:
            x[j],x[j-1] = x[j-1],x[j]
            j -= 1
def partition(x:list,pivot:int,start,end) -> int:
    upper = []
    lower = []
    for i in x[start:end+1]:
        if i>pivot:
            upper.append(i)
        elif i < pivot:
            lower.append(i)
    i = len(lower)
    lower.append(pivot)
    lower.extend(upper)
    for j in range(start,end+1):
        x[j] = lower[j]
    return i
def md_of_medians_among_groups(x:list):
    medians = medians_of_groups(x)
    return select(medians,int(len(medians)/2)+1)
def medians_of_groups(x:list):#O(n)
    y = []
    for i in range(0, len(x), 5):
        if (i + 5 >= len(x)):
            y.append(x[i:].copy())
        else:
            y.append(x[i:i + 5].copy())
    for interval in y:
        insertion_sort(interval, interval,0,len(interval)-1)  # 内部排序
    medians = []
    for interval in y:
        medians.append(interval[int(len(interval) / 2)])
    return medians

def select(x:list,order:int):#该算法尚未考虑有相同元素的情况,O(n)
    #分组
    if len(x)<5:
        insertion_sort(x,x,0,len(x)-1)
        return x[order-1]
    else:
        md_of_medians = md_of_medians_among_groups(x)
        i = partition(x,md_of_medians,0,len(x)-1)
        if  order == i+1:
            return md_of_medians
        elif order<i+1:
            return select(x[:i],order)
        elif order>i+1:
            return select(x[i+1:],order-i-1)

x = [3,9,2,4,12,1,35,23,5,6,11,87,44,63,18]
for i in range(1,16):
    print(select(x,i),end =" ")
insertion_sort(x,x,0,len(x)-1)
print(x)








