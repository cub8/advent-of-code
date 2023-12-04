# frozen_string_literal: true

# Task one in Advent of Code
class ::TaskOne
  attr_reader :input_data, :numbers, :result

  # @param filename [String]
  def initialize(filename)
    data = ::File.read(filename)
    @input_data = data.split("\n")
    @numbers = []
  end

  # @return [String]
  def call
    find_numbers!
    sum_numbers!

    @result
  end

  private

  # Finds numbers in each line
  #
  # @return [void]
  def find_numbers!
    @input_data.each do |line|
      first_num = '0'
      last_num = '0'
      found_first = false

      line.each_char do |chr|
        chr_matches = chr.match(/\d/)

        if !found_first && chr_matches
          first_num = chr
          found_first = true
        end

        last_num = chr if chr_matches
      end

      merged_num = ::String.new << first_num << last_num
      @numbers << merged_num.to_i
    end

    @numbers.freeze
  end

  # Sums all numbers in @numbers array.
  #
  # @return [void]
  def sum_numbers!
    @result ||= @numbers.sum
  end
end

task = ::TaskOne.new ::ARGV[0]
result = task.call
puts result
