defmodule Mix.Tasks.Compile.Binding do
  @shortdoc "Compiles C code into a shared object file"

  def run(_) do
    {result, _error_code} = System.cmd("make", ["binding.so"], stderr_to_stdout: true)
    IO.binwrite result
    :ok
  end
end

defmodule Binding.Mixfile do
  use Mix.Project

  def project do
    [app: :binding,
     version: "0.0.1",
     elixir: ">= 0.14.3 and < 2.0.0",
     compilers: [:binding, :elixir, :app]]
  end
end
