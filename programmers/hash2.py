#https://programmers.co.kr/learn/courses/30/lessons/42577?language=python3
def solution(phone_book):
    answer = True
    d_map = {}

    for phone in phone_book:
        for key in d_map:
            if d_map[key].find(phone) == 0 or phone.find(key) == 0:
                return False

        d_map[phone] = phone

    return answer
