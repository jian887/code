# -*- coding: utf-8 -*-
"""
Created on Thu Sep 27 12:25:20 2018

@author: traiyi
"""
# 变量和参数传递
a = [1, 2, 3]

b = a

a.append(4) #添加元素

print(b)

## 参数传递
def append_element(some_list, element):
    some_list.append(element)
    
data = [1, 2, 3]

append_element(data, 4)  # 添加元素的函数

print(data)


# 动态引用、强类型(赋值来定义类型)

## 动态引用
a = 5
c = type(a)
print(c)

a = 'foo'
c = type(a)
print(c)

## 强类型
a = 4.5
b = 2
print(a/b)

## 判断类型
a = 5
print(isinstance(a,int))

### 使用类型元祖判断对象类型
a = 4; b = 4.5
print(isinstance(a,(int,float)))
print(isinstance(b,(int,float)))
print(isinstance(a,(str,float)))

# 属性和方法
"""
访问对象的名字通常称作“反射”。
本书不会大量使用getattr函数和相关的hasattr和setattr函数，
使用这些函数可以高效编写原生的、可重复使用的代码。
"""
## 因为这是在做数据分析嘛
a = 'foo'
print(a.center)
print(getattr(a,'center'))

# 鸭子类型


# 引入
import some_module
result = some_module.f(5)
pi = some_module.PI
print(result , pi)
print(pi)

## or
from some_module import  g , PI
result = g(5, PI)
print(result)

## or
from some_module import *
result = g(5, PI)
print(result)

## or
import some_module as sm 
from some_module import PI as pi, g as g1
r1 = sm.f
r2 = g1(5,pi)

#二元运算符
a = [1,2]
b = a
c = list(a)  # list 总是创建一个新的python 列表

print(a , b , c)
print (a is b)   # 判断对象是否相同  
print (a is not c)
print (a == c)  # 判断值是否相同

a = 100
b = 50

print(a&b)
print(a|b)
print(a^b)

# 三元运算符


# 可变与不可变对象

## 可变 ：列表、字典、NumPy数组
a_list = ['foo', 2 ,[4,5]]

a_list[1] = '34'

a_list[2] = (2,4)

print(a_list)

## 不可变 字符串、元组

a_tuple = (3,4,(4,5))

### false a_tuple[2] = (2,3)

# 数据类型

fval = 7.43
fval2 = 6.78e-5
fval3 = 3//2

print(fval,fval2,fval3)

# 字符串
a = 'one way'
b = "two way"
c = """
three
way
"""
c2 = """three
way
"""
c_count = c.count('\n')  # 计算字符串后面的换行符
c2_count = c2.count('\n')

print(a)
print(b)
print(c)
print(c2)
print(c_count)
print(c2_count)

a = 335.56567
s1 = str(a)
print(s1    )

s = 'python'
list(s)
print(s[:3])

s2 = '232\\43'
s3 = 'dsfhksfj\\fs\\\sfs\\dfdsf'
s4 = r'dsfhksfj\\fs\\\sfs\\dfdsf'
print(s2)
print(s3)
print(s4)

print(s2+s4)

## 字符格式化

template = '{0:.3f} {1:s} are worth US${2:d} and {3:.2f}'

# print(template.format(4.5464,'you',34.3,45)) false
print(template.format(4.5464,'you',34,45.23)) # ture

# 数据类型

## 布尔值

print(True and True)
print(True or False)

## 空值

a = None

print(a is None)
print(a == None)

# 日期和时间

from datetime import datetime ,date , time

dt = datetime(2018,10,6,16,40,34)
print(dt , dt.day , dt.minute)

print(dt.strftime('%m/%d/%y %h:%m'))
print(dt.strftime('%m/%d/%Y %H:%m'))



print(datetime.strptime('20091031', '%Y%m%d'))














