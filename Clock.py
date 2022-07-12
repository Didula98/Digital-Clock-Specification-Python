from datetime import datetime
import numpy as np
import time
import os
import random
import sys

PREF = "\033["
RESET = f"{PREF}0m"
COLOR = f"{PREF}47m"
RANDOM = 0

rows, cols = (5, 56)
clockArea = np.array([[0]*cols]*rows) # clock backgraound
colorGrid = np.array([[0]*cols]*rows) # color code container for random colors


def help():
   print("""
   Run Clock         : python filename.py -c <color>
   Print Random Color: Run Clock: python filename.py -c random
   Help              : python filename.py -h\n""")
   sys.exit()

# compare color args
def selectColors(color):
    colorArray = ["black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"]

    if(color) in colorArray:
        return f"{PREF}4{colorArray.index(color)}m"
    else:
        help()

# random color gradient generator
def randomColorgrid(num):
    colorCode = 6*(num) + 10
    for row in range(0, rows):
        for col in range(0, 56):
            colorGrid[row][col] = colorCode
            if col%10 == 0 and col != 0:
                 colorCode += 1
        colorCode += 31

# add numbers to clock background
def updateClock(num, index):
    clockArea[:, 7*index+1:7*index+7] = numArray[num*5:num*5+5, :]


# number containeer
numArray = np.array([

    #0  
    [1,1,1,1,1,1],
    [1,1,0,0,1,1],
    [1,1,0,0,1,1],
    [1,1,0,0,1,1],
    [1,1,1,1,1,1],

    #1 
    [0,0,0,0,1,1],
    [0,0,0,0,1,1],
    [0,0,0,0,1,1],
    [0,0,0,0,1,1],
    [0,0,0,0,1,1],

    #2 
    [1,1,1,1,1,1],
    [0,0,0,0,1,1],
    [1,1,1,1,1,1],
    [1,1,0,0,0,0],
    [1,1,1,1,1,1],

    #3 
    [1,1,1,1,1,1],
    [0,0,0,0,1,1],
    [1,1,1,1,1,1],
    [0,0,0,0,1,1],
    [1,1,1,1,1,1],

    #4 
    [1,1,0,0,1,1],
    [1,1,0,0,1,1],
    [1,1,1,1,1,1],
    [0,0,0,0,1,1],
    [0,0,0,0,1,1],


    #5 
    [1,1,1,1,1,1],
    [1,1,0,0,0,0],
    [1,1,1,1,1,1],
    [0,0,0,0,1,1],
    [1,1,1,1,1,1],

    #6 
    [1,1,1,1,1,1],
    [1,1,0,0,0,0],
    [1,1,1,1,1,1],
    [1,1,0,0,1,1],
    [1,1,1,1,1,1],


    #7	
    [1,1,1,1,1,1],
    [0,0,0,0,1,1],
    [0,0,0,0,1,1],
    [0,0,0,0,1,1],
    [0,0,0,0,1,1],

    #8 
    [1,1,1,1,1,1],
    [1,1,0,0,1,1],
    [1,1,1,1,1,1],
    [1,1,0,0,1,1],
    [1,1,1,1,1,1],

    #9 
    [1,1,1,1,1,1],
    [1,1,0,0,1,1],
    [1,1,1,1,1,1],
    [0,0,0,0,1,1],
    [1,1,1,1,1,1],

    #colon 50:54
    [0,0,1,1,0,0],
    [0,0,1,1,0,0],
    [0,0,0,0,0,0],
    [0,0,1,1,0,0],
    [0,0,1,1,0,0]
])


if len(sys.argv) == 3 and sys.argv[1] == "-c":
    if sys.argv[2].lower() != "random":
        COLOR = selectColors(sys.argv[2].lower())

    elif sys.argv[2].lower() == "random":
        RANDOM = 1
        randomColorgrid(random.randint(1, 6))

elif len(sys.argv) > 1:
    help()



while True:

    print(f"{PREF}?25l")
    os.system('cls')

    currentTime = datetime.now().strftime("%H:%M:%S") # current time as string

    position = 0

    # update numbers
    for c in currentTime: 
        if(c != ":"):
            updateClock(int(c), position)
            
        else:
            updateClock(10, position)
            
        position += 1

    # print clock
    for i in range(0, rows):
        for j in range(0, 56):
            if(clockArea[i][j] == 1):
                if(RANDOM == 1):
                    print(f"{PREF}48;5;{colorGrid[i][j]}m" + " " + RESET, end='')
                else:
                    print(COLOR + " " + RESET, end='')
            else:
                print(' ', end='')

        print('', end='\n')

    time.sleep(1)
    