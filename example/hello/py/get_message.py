N = 1000000
messages = {f"key_{n}": f"hello_{n}" for n in range(N+1)}

def get_message(n):
    return messages[n]
