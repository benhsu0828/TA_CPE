while True:
    n = int(input())
    if n == 0: break
    elif n == 1:
        print("Discarded cards: ")
        print("Remaining card: 1")
    else:
        cards = [i for i in range(1, n+1)]
        discards = []
        while len(cards) > 1:
            discards.append(cards.pop(0))
            c = cards.pop(0)
            cards.append(c)
        print("Discarded cards: ", end="")
        for i in range(len(discards)):
            print("{:d}".format(discards[i]), end="\n" if i == len(discards)-1 else ", ")
        print("Remaining card: {:d}".format(cards[0]))