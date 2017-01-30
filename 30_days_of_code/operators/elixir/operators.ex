case Float.parse(IO.gets("")) do
  {meal_cost, _} ->
    case Integer.parse(IO.gets("")) do
      {tip_percent, _} ->
        case Integer.parse(IO.gets("")) do
          {tax_percent, _} ->
            IO.puts "The total meal cost is "
            <> Integer.to_string(round(meal_cost +
              meal_cost * tip_percent / 100 +
              meal_cost * tax_percent / 100))
            <> " dollars."
        end
    end
end
