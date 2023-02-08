## print ascending and descending stairs with '#' based on input height

def main():

    h = get_height()
    i = int(1)

    while i <= h:
        print(" "*(h-i) + "#"*i + "  " + "#"*i)
        i+=1

def get_height():
    while True:
        h = input("Height: ")
        if h.isdigit() and int(h) > 0 and int(h) < 9:
            break
    return int(h)

main()
