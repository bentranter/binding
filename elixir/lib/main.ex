Hello do
  @on_load :init
  def init() do
    :erlang.load_nif("../src/binding", 0)
  end
end
