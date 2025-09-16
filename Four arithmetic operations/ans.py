N = int(input())    # 要計算的算式數量
for _ in range(N):  # 讀取 N 行算式
    s = input()     # 由標準輸入讀取算式
    func = []       # 儲存算式用的串列
    tmp = ""        # 暫存數字的字串
    for c in s:     # 依序由 s 讀取字元 c
        if c == '(' or c == '+' or c == '-' or c == '*' or c == '/':   # 如果 c 是 (+-*/
            if tmp: # 如果 tmp 有內容，將 tmp 加到 func 最後面，再清空 tmp
                func.append(tmp); tmp = ""
            func.append(c)   # 將 c  加到 func 最後面
        elif c == ')':   # 如果 c 是 )
            n = 0   # 暫存數值用的變數 n
            if tmp: # 如果 tmp 有內容，將 tmp 加到 func 最後面，再清空 tmp
                func.append(tmp); tmp = ""
            while func:  # 如果 func 有內容，繼續執行直到遇到 (
                f = func.pop()   # 取出 func 最後一項並存入 f
                if func[-1] == '(':   # 如果 func 目前最後一項是 (
                    func.pop(); func.append(f); break   # 移除 (，將 f 加到 func 最後面，跳出第17行的 while 迴圈
                elif f == '+':   # 如果 f 是 +，取出 func 最後一項並轉成整數 t，計算 t + n 再轉成字串加到 func 最後面
                    t = int(func.pop()); func.append(str(t + n))
                elif f == '-':   # 如果 f 是 -，取出 func 最後一項並轉成整數 t，計算 t - n 再轉成字串加到 func 最後面
                    t = int(func.pop()); func.append(str(t - n))
                elif f == '*':   # 如果 f 是 *，取出 func 最後一項並轉成整數 t，計算 t * n 再轉成字串加到 func 最後面
                    t = int(func.pop()); func.append(str(t * n))
                elif f == '/':   # 如果 f 是 /，取出 func 最後一項並轉成整數 t，計算 t // n 再轉成字串加到 func 最後面
                    t = int(func.pop()); func.append(str(t // n))
                else:   # 如果 f 不是 (+-*/，則 f 是數字，轉成整數並存入 n
                    n = int(f)
        else:   # 如果 c 不是 (+-*/)，則 c 是數字，加到 tmp 最後面
            tmp += c
    print(func[0])   # 最後 func 只剩下一個元素，就是計算結果

