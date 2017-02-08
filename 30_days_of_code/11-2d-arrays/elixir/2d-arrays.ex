defmodule Solution do
  @hg_matrix [
    {0, 0}, {1, 0}, {2, 0},
    {nil, nil}, {1, 1}, {nil, nil},
    {0, 2}, {1, 2}, {2, 2}
  ]

  def fetch(list, {x, y}) do
    Enum.at(Enum.at(list, y), x)
  end

  def tuple_sum(_, {_x, _y}, {nil, nil}) do
    0
  end

  def tuple_sum(list, {x, y}, {n, m}) do
    fetch(list, {x + n, y + m})
  end


  def hourclass(list, {x, y}) do
    Enum.reduce(@hg_matrix, 0, fn({n, m}, acc) ->
      acc + tuple_sum(list, {x, y}, {n, m})
    end)
  end

  def run(list) do
    max = -1_000_000
    maxes = for y <- 0..3, x <- 0..3 do
      sum = hourclass(list, {x, y})
      if sum > max, do: max = sum
      max
    end
    Enum.max(maxes)
  end
end

input = Enum.reduce((0..5), [], fn(_, acc) ->
  acc ++ [Enum.map(String.split(IO.gets("")), fn(x) -> String.to_integer(x) end)]
end)

IO.puts "#{Solution.run(input)}"
