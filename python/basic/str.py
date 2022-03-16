import sys
from PIL import Image
from numpy import *
from scipy import constants

def test():
    # age = 3
    # args = sys.argv
    # if age >= 18:
    #     print('your age is', age)
    #     print('adult')
    # else:
    #     print('your age is' ,sys.path)
    #     print('teenager')
    im = Image.open('img/50506923.png')
    print(im.format, im.size, im.mode)
    im.thumbnail((200, 100))
    im.save('thumb.jpg', 'JPEG')
if __name__=='__main__':
    test()