defmodule Solution do
  def loop_search(:eof, _) do
  end

  def loop_search(value, book) do
    value = String.rstrip(value)
    if book[value] do
      IO.puts "#{value}=#{book[value]}"
    else
      IO.puts "Not found"
    end
    loop_search(IO.read(:stdio, :line), book)
  end
end

{n, _} = Integer.parse(IO.gets(""))

phone_book = Enum.reduce((1..n), %{}, fn(_, acc) ->
  [name, phone] = String.split(String.strip(IO.gets("")))
  Map.put(acc, name, phone)
end)

Solution.loop_search(IO.read(:stdio, :line), phone_book)
