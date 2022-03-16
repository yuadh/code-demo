# -*- coding: UTF-8 -*- 
s1 = set('hello') #创建由字符串字母组成集合
s2 = set(('hello',)) #创建一个英文单词集合
print(s1,s2)
s1 = set(['hello','world'])
s2 = set(('hello','Python'))
print(s1,s2)
s1.add('!') #给s1集合添加字符
s1.update(s2) #给s1集合添加s2集合
print(s1,s2)
