#
# Ecosystem emulator in ruby
# George 'papanikge' Papanikolaou
# This is mainly to experiment with the dynamic OOP languages
#

require './organisms.rb'

#
# Our imaginary marine world (with metadata et all)
#
class World
  include Enumerable

  attr_reader :dim_x
  attr_reader :dim_y
  attr_reader :org_count
  # this is the actual array that keeps the organisms
  # TODO: should we make the 'World' class a subclass of Array?
  attr_accessor :map

  def initialize
    @org_count = 0
    # possible ranges are hard coded because I'm bored
    @dim_x = rand(15..30)
    @dim_y = rand(15..30)
    init_world(@dim_x,@dim_y)
  end

  #
  # Runs a block of code against our world (needs a block)
  #
  def traverse_map
    @map.each_with_index do |xs, i|
      xs.each_with_index do |ys, j|
        @map[i][j] = yield(ys)
      end
    end
  end

  #
  # Create or reinitialize a 'world' array for the game
  #
  def init_world(x, y)
    @map = Array.new(x) { |c| c = Array.new(y) }
    @map.each_with_index do |xs, i|
      xs.each_with_index do |ys, j|
        @map[i][j] = gen_random_org(i, y)
        @org_count += 1
      end
    end
  end

  #
  # One unit of time (for the world)
  #
  def step
    traverse_map do |el|
      fail "cell does not contain organism" unless el.class.ancestors.include? Organism
      el.tick
    end
  end

  #
  # Add an organism to a specific cell. This also updates metadata
  #
  def add(org, x, y)
    puts "You requested a #{org.class} in #{x},#{y}."
    if @map[x][y]
      # This may be an example of bad programming. We cannot use #eat_or_interact
      # here because it only handles organisms inside our world.
      if @map[x][y] > org.size
        @map[x][y].orgs_eaten += org.size
        org = nil
      else
        org.orgs_eaten += @map[x][y].size
        org.x = x
        org.y = y
        @map[x][y] = org
      end
    else
      # there was nothing there
      @map[x][y] = org
    end
    puts "Added"
    @org_count+=1
  end

  #
  # Adds an infection to a cell of the map that kills all the neighbor cells.
  # Needs a level of infection to determine how many neighbors to kill.
  # Works recursively.
  #
  def infect(level, x, y)
    return unless level > 0
    (1..9).each do |n|
      coords = @map[x][y].get_coords(n)
      infect(level - 1, coords[0],coords[1])  # Recursive step
      @map[coords[0]][coords[1]] = nil        # Die...
    end
  end

  #
  # Prints info (of course)
  #
  def info
    # TODO: add Graphics (see OpenGL or Shoes)
    puts "The map is: #{@dim_x}x#{@dim_y}, and contains #{@org_count} organisms."
  end

  #
  # Functions responsible for getting user input, and acting accordingly
  #

  def get_user_coords
    x ||= rand(0..@dim_x)   # fail-safes. Also we probably need these
    y ||= rand(0..@dim_y)   # because ruby scopes...
    puts "Reminder that the map is: #{@dim_x}x#{@dim_y}"
    loop do
      print "x? "
      x = STDIN.gets.chomp.to_i
      break if (0..@dim_x).include? x
    end
    loop do
      print "y? "
      y = STDIN.gets.chomp.to_i
      break if (0..@dim_y).include? y
    end
    return [x,y]
  end

  #
  # Wrapper aroung World#add
  #
  def user_add
    choice ||= gen_random_org
    puts "Available organisms to add:"
    $orgs.each { |org| puts org }
    input = STDIN.gets.chomp
    input.capitalize!
    $orgs.each do |org|
      if org.include? input
        choice = eval "#{org}.new"
        break
      end
    end
    c = get_user_coords
    choice.x = c[0]
    choice.y = c[1]
    add(choice, c[0], c[1])
  end

  def user_infect
    level ||= rand(1..4)
    puts "Level of infection? "
    loop do
      level = STDIN.gets.chomp.to_i
      break if level < 30
      puts "Too big. You're mean. "
    end
    c = get_user_coords
    infect(level, c[0], c[1])
  end
end

#
# Main thread of execution
#

puts "Welcome to this (hardly) funny little game. :)"
puts "Generating the map..."
$world = World.new
puts "Done. The ecosystem map will have #{$world.dim_x}x#{$world.dim_y} dimensions."
print "Options:\tS: step\n\tA: add\n\tV: infect\n\tI: info\n\tR: restart\n\tQ: quit\n"
loop do
  puts ">>> Main menu <<<"
  input = STDIN.gets.chomp
  input.downcase!
  case input
  when 's' then $world.step
  when 'a' then $world.user_add
  when 'v' then $world.user_infect
  when 'i' then $world.info
  when 'r' then $world.init_world
  when 'q' then break
  else puts "Wrong option."
  end
end
