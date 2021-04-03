try:
    c=[1,5,9,3,6]
    print(c[12])
except TypeError:
    print(5)
except ValueError:
    print(10)
finally:
    print("this is final block")