import numpy as np
import matplotlib.pyplot as plt
import time


def loop(strs:str,i: int):
    time.sleep(1)
    print(i," ",strs)



def showIm(arr: np.ndarray):
    print("showIm")
    plt.imshow(arr)
    plt.show()

def hello_world(i :int ,strs: str):
    print("收到了{}".format(i))
    for t in range(i):
        print(strs)
    arr=np.asarray([[1,2,3],[4,5,6]])
    return arr

if __name__=="__main__":
    print(hello_world(2,"aaa"))
    arr=np.random.random((500,500))
    # showIm(arr)
    loop("11111")
