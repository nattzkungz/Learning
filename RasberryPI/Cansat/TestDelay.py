import time
import sys
import os
from apscheduler.schedulers.background import BackgroundScheduler

def x():
    for x in range(10):
        x = x+1
        print(x)

def time():
    print (time.time())

if __name__ == '__main__':
    	scheduler = BackgroundScheduler()
        scheduler.add_job(x, 'interval', seconds=3)
        scheduler.add_job(time, 'interval', second=2)
