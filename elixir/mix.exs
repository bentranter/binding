defmodule Hello.Mixfile do
  use Mix.Project

  def project do
    [app: :hello,
     version: "0.0.1",
     elixir: "~> 1.0",
     compilers: [:make, :elixir, :app]]
  end
end

defmodule Mix.Tasks.Compile.Make do
  @shortdoc "Compiles C code into a shared object file"

  def run(_) do
    {result, _error_code} = System.cmd("make", [], stderr_to_stdout: true)
    Mix.shell.info result

    :ok
  end
end
