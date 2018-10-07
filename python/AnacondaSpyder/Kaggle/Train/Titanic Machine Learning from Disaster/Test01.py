# -*- coding: utf-8 -*-
"""
Created on Sat Sep 22 10:42:17 2018

@author: traiyi
"""
import re
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import warnings

from pandas import Series,DataFrame


train_data = pd.read_csv("train.csv")

test_data = pd.read_csv("test.csv")

sns.set_style('whitegrid')
print(train_data.head())

print(train_data.info())

print("-"*40)

print(test_data.info())

train_data['Survived'].value_counts().plot.pie(autopct = '%0.2f%%')

"""
些机器学习算法能够处理缺失值，比如神经网络，一些则不能。对于缺失值，一般有以下几种处理方法：

（1）如果数据集很多，但有很少的缺失值，可以删掉带缺失值的行；

（2）如果该属性相对学习来说不是很重要，可以对缺失值赋均值或者众数。比如在哪儿上船Embarked这一属性（共有三个上船地点），缺失俩值，可以用众数赋值

---------------------

本文来自 Koala_Tree 的CSDN 博客 ，全文地址请点击：https://blog.csdn.net/Koala_Tree/article/details/78725881?utm_source=copy 

"""
