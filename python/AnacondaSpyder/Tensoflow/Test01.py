# -*- coding: utf-8 -*-
"""
Created on Tue Oct 16 08:22:15 2018

@author: traiyi
"""

import tensorflow as tf

# 3
hello = tf.constant('Hello, TensorFlow!')
se = tf.Session()
print(se.run(hello))
# 'Hello, TensorFlow!'