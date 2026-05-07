import random
import math

def solve(jar_count):
    print("\n==========================")
    print("술단지 개수:", jar_count)
    print("==========================")

    # 1. 최소 신하 수 구하기
    servant = math.ceil(math.log2(jar_count))
    print("필요한 신하 수:", servant)

    # 2. 술단지 -> 이진수
    jar_bin = {}

    for i in range(jar_count):
        b = format(i, 'b').zfill(servant)
        jar_bin[i] = b

    print("\n[술단지 이진수]")
    for k in jar_bin:
        print(k, ":", jar_bin[k])

    # 3. 신하가 마실 술단지
    servants = {}

    for i in range(servant):
        servants["신하" + str(i+1)] = []

    for jar in jar_bin:
        b = jar_bin[jar][::-1]   # 뒤집어서 보기 쉽게

        for i in range(servant):
            if b[i] == '1':
                servants["신하" + str(i+1)].append(jar)

    print("\n[신하가 마시는 술]")
    for s in servants:
        print(s, ":", servants[s])

    # 4. 랜덤 독단지
    poison = random.randint(0, jar_count-1)
    print("\n실제 독단지:", poison)

    # 5. 누가 죽는지 확인
    dead = []
    b = jar_bin[poison][::-1]

    for i in range(servant):
        if b[i] == '1':
            dead.append("신하" + str(i+1))

    print("죽은 신하:", dead)

    # 6. 다시 독단지 찾기
    result = ['0'] * servant

    for d in dead:
        idx = int(d.replace("신하", "")) - 1
        result[idx] = '1'

    result_bin = ''.join(result[::-1])
    found = int(result_bin, 2)

    print("\n찾아낸 이진수:", result_bin)
    print("찾아낸 단지:", found)

    # 7. 비교
    print("\n[결과]")
    print("실제:", poison)
    print("찾은:", found)

    if poison == found:
        print("정답")
    else:
        print("오답")

# 실행
solve(4)
solve(6)
solve(10)