from ctypes import *

# Загружаем библиотеку
dice = CDLL('./dice.so')


print(dice.d6())
