"""
Merge Sort
"""

def mergesort(seq):
    mid = len(seq) // 2
    left, right = seq[:mid], seq[mid:]
    if len(left) > 1:
        left = mergesort(left)
    if len(right) > 1:
        right = mergesort(right)
    result = []
    while left and right:
        if left[-1] >= right[-1]:
            result.append(left.pop())
            print result
        else:
            result.append(right.pop())
            print result
    result.reverse()
    return (left or right) + result


def unit_test():
    seq = [3, 4, 9, 6, 1, 8, 2, 7, 5]
    print mergesort(seq)

if __name__ == "__main__":
    unit_test()
