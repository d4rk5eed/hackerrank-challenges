defmodule Solution do
  case Integer.parse(IO.gets("")) do
    {n, _} ->
      1..10
      |> Enum.each(fn(x) -> IO.puts "#{n} x #{x} = #{n*x}" end)
  end
end
