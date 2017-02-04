defmodule Solution do
  import Enum
  {_, _} = Integer.parse(IO.gets(""))

  arr = String.split(IO.gets(""))

  each(reverse(arr), fn(item) ->
    :ok = IO.write "#{item} "
  end)
  IO.puts ""
end
