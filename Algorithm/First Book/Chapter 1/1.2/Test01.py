# -*- coding: utf-8 -*-
"""
Created on Thu Oct 11 20:05:57 2018

@author: traiyi
"""
import math

pi = math.pi
# 生成pi的值

r ,h = map(int, input().split()) # 输入

s1 = pi*pi*r
s2 = 2.0*pi*r*h
s = 2.0*s1 + s2
print('Area =%.3f'%s)                    # 输出
# print (math.pi)