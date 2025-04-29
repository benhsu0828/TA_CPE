import re

def uncompress_text():
    word_list = []

    while True:
        line = input()
        if line.strip() == "0":
            break

        result = []
        tokens = re.findall(r'[A-Za-z]+|\d+|[^A-Za-z\d]', line)

        for token in tokens:
            if token.isalpha():
                result.append(token)
                if token in word_list:
                    pos = word_list.index(token)
                    result[-1] = str(pos + 1)
                    word_list.pop(pos)
                word_list.insert(0, token)
            elif token.isdigit():
                word = word_list[int(token) - 1]
                result.append(word)
                word_list.pop(int(token) - 1)
                word_list.insert(0, word)
            else:
             
                result.append(token)

        print("".join(result))

uncompress_text()