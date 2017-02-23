defmodule Solution do
  def fine({e_day, e_month, e_year}, {a_day, a_month, a_year}) when a_day > e_day and e_year == a_year and e_month == a_month do
    (a_day - e_day) * 15
  end

  def fine({e_day, e_month, e_year}, {a_day, a_month, a_year}) when a_month > e_month and e_year == a_year do
    (a_month - e_month) * 500
  end

  def fine({e_day, e_month, e_year}, {a_day, a_month, a_year}) when a_year > e_year do
    10000
  end

  def fine({e_day, e_month, e_year}, {a_day, a_month, a_year}), do: 0
end

a_date = List.to_tuple(Enum.map(String.split(IO.gets("")), fn(i) ->
      String.to_integer(i)
    end))

e_date = List.to_tuple(Enum.map(String.split(IO.gets("")), fn(i) ->
      String.to_integer(i)
    end))
IO.puts Solution.fine(e_date, a_date)
