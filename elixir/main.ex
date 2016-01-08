defmodule Hello do
  @on_load :init

  def init() do
    :erlang.load_nif("./binding", 0)
  end

  def hello(_str, _num) do
    raise "NIF binding/2 not implemented!"
  end

  def test() do
    raise "NIF binding/0 not implemented!"
  end
end
