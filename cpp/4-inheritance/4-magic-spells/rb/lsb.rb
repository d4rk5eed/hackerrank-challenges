class AssertionError < RuntimeError
  def initialize(l, r)
    @l = l
    @r = r

    super("\nLeft: " + @l.inspect + "\n" + "Right: " + @r.inspect + "\n")
  end
end

def assert(left, right)
  raise AssertionError.new(left, right) unless left == right
end

class LSB
  def initialize(a, b)
    @a = a
    @b = b
    @p = Array.new(@a.size + 1) {Array.new(@b.size + 1, nil)}
  end

  def init_lengths_list
    @c = Array.new(@a.size + 1) {Array.new(@b.size + 1, nil)}
    @c[0] = Array.new(@a.size + 1, 0)
    @c.map! { |x| x[0] = 0; x  }
  end

  def length(x, y)
    return @c[x][y] unless @c[x][y].nil?

    if @a[x-1] == @b[y-1]
      @c[x][y] = length(x-1, y-1) + 1
      @p[x][y] = [x-1, y-1]
    elsif @c[x-1][y] >= @c[x][y-1]
      @c[x][y] = length(x-1, y)
      @p[x][y] = [x-1, y]
    else
      @c[x][y] = length(x, y-1)
      @p[x][y] = [x, y-1]
    end
    @c[x][y]
  end

  def max_length
    @c[@a.size][@b.size]
  end

  def sequence(x, y)
    return '' if @p[x][y].nil?

    k, m = @p[x][y]
    if @a[x-1] == @b[y-1]
      sequence(k, m) + @a[x-1]
    else
      sequence(k, m)
    end
  end

  def i
    @c.inspect
  end
end

lsb = LSB.new('abc', 'bcd')
assert lsb.init_lengths_list, [[0, 0, 0, 0], [0, nil, nil, nil],[0, nil, nil, nil],[0, nil, nil, nil]]

1.upto(3) do |x|
  1.upto(3) do |y|
    lsb.length(x, y)
  end
end

assert lsb.length(0,0), 0
assert lsb.length(2,1), 1
assert lsb.length(3,3), 2

assert lsb.sequence(3,3), 'bc'
