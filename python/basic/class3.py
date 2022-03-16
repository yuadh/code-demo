# -*- coding: UTF-8 -*-


import numpy as np
from datetime import datetime
def a_num(rnum):
    x=list(range(rnum))
    y=list(range(rnum))
    z=[]
    for i in range(len(x)):
        y[i]=i**2
        z.append(x[i]+y[i])
    print(x)
    print('-------')
    print(y)
    return z
def b_num(rnum):
    x=np.arange(rnum)
    y=np.arange(rnum)**2
    z=x+y
    print(x)
    print(y)
    return z

s_time = datetime.now()
print(a_num(10000))
e_time = datetime.now()
aTime = e_time-s_time
print(aTime)# a:00.140801
