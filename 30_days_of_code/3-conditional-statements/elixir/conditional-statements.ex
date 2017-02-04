defmodule Solution do
  use Bitwise
  case Integer.parse(IO.gets("")) do
    {val, _} ->
      cond do
        band(val, 1) == 1 ->
          IO.puts "Weird"
        val in (2..5) ->
          IO.puts "Not Weird"
        val in (6..20) ->
          IO.puts "Weird"
        val > 20 ->
          IO.puts "Not Weird"
      end
  end
end
