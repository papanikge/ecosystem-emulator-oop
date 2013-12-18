#
# Ecosystem emulator in ruby
# George 'papanikge' Papanikolaou
# This is mainly to experiment with the dynamic OOP languages
#

require './organisms.rb'

#
# Create or reinitialize a 'world' array for the game
#
class World
  include Enumerable

  attr_reader :dim_x
  attr_reader :dim_y
  # this is the actual array that keeps the organisms
  # TODO: should we make the 'World' class a subclass of Array?
  attr_accessor :map

  def initialize
    # possible ranges are hard coded because I'm bored
    @dim_x = rand(15..30)
    @dim_y = rand(15..30)
    init_world(@dim_x,@dim_y)
  end

  #
  # Runs a block of code against our world
  #
  def traverse_map
    @map.each_with_index do |xs, i|
      xs.each_with_index do |ys, j|
        @map[i][j] = yield(ys)
      end
    end
  end

  def init_world(x, y)
    @map = Array.new(x) { |c| c = Array.new(y) }
    traverse_map do |el|
      el = gen_random_org
    end
  end

  #
  # One unit of time
  #
  def step
    traverse_map do |el|
      fail "cell does not contain organism" unless el.class.ancestors.include? Organism
      el.move
    end
  end

  #
  # Add an organism to a specific cell
  #
  def add(org, x, y)
    @map[x][y] = org
    # TODO (interact)
  end

  #
  # Adds an infection to a cell of the map that kills all the neighbor cells
  #
  def infect(x, y)
    # TODO
  end

  #
  # Prints info (of course)
  #
  def info
    # TODO
  end
end

#
# Main thread of execution
#

puts "Welcome to this (hardly) funny little game. :)"
puts "Generating the map..."
world = World.new
puts "Done. The ecosystem map will have #{world.dim_x}x#{world.dim_y} dimensions."
print ">>> Main menu <<<\n\tS: step\n\tA: add\n\tV: infect\n\tI: info\n\tR: restart\n\tQ: quit\n"
loop do
  input = STDIN.gets.chomp
  input.downcase!
  case input
  when 's' then world.step
  when 'a' then world.add
  when 'v' then world.infect
  when 'i' then world.info
  when 'r' then world.init_world
  when 'q' then break
  else puts "Wrong option."
  end
end
