def factorial(n):
  if n > 1:
    return n * factorial(n-1);
  else:
    return 1;

n = int(raw_input().strip())

print factorial(n)
