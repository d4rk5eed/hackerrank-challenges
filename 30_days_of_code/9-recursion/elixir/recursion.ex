defmodule Solution do
  def factorial(1), do: 1

  def factorial(0), do: 1

  def factorial(n), do: n * factorial(n-1)
end

{n, _} = Integer.parse(IO.gets(""))
IO.puts Solution.factorial(n)
