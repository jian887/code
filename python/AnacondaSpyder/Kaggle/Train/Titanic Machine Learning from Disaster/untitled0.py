# -*- coding: utf-8 -*-
"""
Created on Mon Oct  8 14:16:38 2018

@author: traiyi
"""
import urllib.request

url = "http://www.baidu.com"
page_info = urllib.request.urlopen(url).read()
page_info = page_info.decode('utf-8')
print(page_info)
