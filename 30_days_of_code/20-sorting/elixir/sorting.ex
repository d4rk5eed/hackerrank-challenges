defmodule Solution do
  import Enum
  import List

  def bubble([h1 | [h2 | tail]], state) do
    if h1 > h2 do
      {arr, state} = bubble([h1 | tail], state + 1)
      {[h2 | arr], state}
    else
      {arr, state} = bubble([h2 | tail], state)
      {[h1 | arr], state}
    end
  end

  def bubble([h | []], state) do
    {[h], state}
  end

  def loop(list, state) do
    {list_copy, state} = bubble(list, state)
    if list_copy != list do
      {list_copy, state} = loop(list_copy, state)
    end
    {list_copy, state}
  end

  def input() do
    IO.gets("")
    list = map(String.split(IO.gets("")), fn(x) ->
      {n, _} = Integer.parse(x)
      n
    end)

    {sorted, state} = loop(list, 0)
    IO.puts "Array is sorted in #{state} swaps."
    IO.puts "First Element: #{first(sorted)}"
    IO.puts "Last Element: #{last(sorted)}"
  end
end

Solution.input
