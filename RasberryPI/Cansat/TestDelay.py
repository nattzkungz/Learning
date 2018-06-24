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

        scheduler.start()
        try:
        	# This is here to simulate application activity (which keeps the main thread alive).
        	while True:
            		time.sleep(2)
    	except (KeyboardInterrupt, SystemExit):
        	# Not strictly necessary if daemonic mode is enabled but should be done if possible
        	scheduler.shutdown
