# -*- coding: utf-8 -*-
"""
Created on Mon Oct 15 01:48:34 2018

@author: traiyi
"""


from urllib import request

from bs4 import BeautifulSoup

url = 'https://www.jianshu.com'

headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36'}

# User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36
# User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36
# User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36
page = request.Request(url,headers=headers)
page_info = request.urlopen(page).read()
page_info = page_info.decode('utf')

soup = BeautifulSoup(page_info,'html.parser')  

titles = soup.find_all('a', 'title')
abstracts = soup.find_all('p','abstract')



for title in titles:
     print(title.string+'\n')
     
for abstract in abstracts:
     print(abstract.string+'\n')
       