def fun(input_list,index):
    try:
        output_list = [0]*len(input_list)
        output_list[index] = input_list[index]/int(input_list[index+1])
    except ValueError:
        print("Invalid Value")
    except ZeroDivisionError:
        print("Division by Zero")
    finally:
        print("End of function")
try:
    list1 = [2,4,'6',2,8]
    list2 = fun(list1,4)
except TypeError:
    print("Invalid type")
except IndexError:
    print("Invalid index")
finally:
    print("End of program")