defmodule Solution do
  def a(0), do: [0]
  def a(1), do: [1]
  def a(x), do: List.flatten([a(div(x,2))] ++  [a(rem(x,2))])
  def a(x), do: List.flatten([a(div(x,2))] ++  [a(rem(x,2))])
  def handle_bit(1, {max, c}), do: {max, c + 1}
  def handle_bit(0, {max, c}), do: { (if (c > max), do: c, else: max ), 0}
end

{n, _} = Integer.parse(IO.gets(""))
{max, _} = Enum.reduce(Solution.a(n) ++ [0], {0, 0}, fn(x, {max, c}) -> Solution.handle_bit(x, {max, c}) end)
IO.puts "#{max}"
