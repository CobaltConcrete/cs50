## request input from user for amount of change, then return least number of coins (quarters/dimes/nickels/pennies) required to meet the amount

def main():
    c = change_owed()

    quarters = int(c / 25)

    c -= quarters*25

    dimes = int(c / 10)

    c -= dimes*10

    nickels = int(c / 5)

    c -= nickels*5

    pennies = int(c / 1)

    print(quarters + dimes + nickels + pennies)


def change_owed():
    while True:
        try:
            c = float(input("Change owed: "))
        except ValueError:
            continue
        else:
            if c > 0:
                break
    return int(c*100)

main()
