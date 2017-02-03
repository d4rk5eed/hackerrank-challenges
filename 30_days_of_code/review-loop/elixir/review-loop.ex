defmodule Solution do
  import Enum
  require Integer
  {n, _} = Integer.parse(IO.gets(""))
  each(0..n, fn(_) ->
    str = String.rstrip(IO.gets(""))
    evens = filter_map(with_index(String.codepoints(str)), fn(x) ->
      Integer.is_even(elem(x, 1))
    end, fn(x) ->
      elem(x, 0)
    end)

    odds = filter_map(with_index(String.codepoints(str)), fn(x) ->
      Integer.is_odd(elem(x, 1))
    end, fn(x) ->
      elem(x, 0)
    end)

    IO.puts "#{evens} #{odds}"
  end)
end
