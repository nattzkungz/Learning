import time

if __name__ == "__main__":
    print (time.time())
    for x in range(10):
        x = x+1
        print(x)
        time.sleep(2)
