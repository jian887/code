print("认识python数据类型")

print("1. Number")

print("2. String")

print("3. List")

print("4. Tuple")

print("5. Dictionary")

var = 1

 # 1. 输入的内容默认为字符串格式，请注意,虽然使用数字区分的，但不要落入陷阱了哦，

while var==1:      # 2. 请注意上面的那个换行符，很可以美化输入哦，不然去掉，你试试/xyx
 i = input("请输入数字来认识我们吧\n");
 if i=='1':
    print("1. Number")
    break
 elif i=='2':
    print("2. String")
    break
 elif i=='3':
    print("3. List")
    break
 elif i=='4':
    print("4. Tuple")
    break
 elif i=='5':
    print("5. Dictionary")
    break
 else:
    print("啊，输入错误，请重新输入吧")
