#include "ftxui/component/app.hpp" // for App
#include "ftxui/component/component.hpp" // for Radiobox, Renderer, Tab, Toggle, Vertical
#include "ftxui/component/component_base.hpp" // for ComponentBase
#include "ftxui/dom/elements.hpp" // for Element, separator, operator|, vbox, border
#include <iostream>
#include <string> // for string, basic_string
#include <vector> // for vector

using namespace ftxui;

int main() {
  std::vector<std::string> tab_values{
      "problem",
      "solver options",
      "solve",
  };

  int tab_selected = 0;

  Component tab_toggle = Toggle(&tab_values, &tab_selected);

  // Problem Statement Tab
  std::string filepath;

  auto input = Input(&filepath, "Enter absolute file path");

  auto problem_container =
      Renderer(Container::Vertical({input}), 
      [&] { return vbox({input->Render()}); }
    );

    // solver options tab

    bool enable_gpu_accelaration = false;

    auto gpu_accelerator = Checkbox("Enable Gpu Accelaration", &enable_gpu_accelaration);

    auto solver_options_container = Renderer(
      Container::Vertical({gpu_accelerator}),
      [&] { return vbox({gpu_accelerator->Render()}); }
    );

    // solve tab

    auto solve_button =Button("Start Solving!", [] { std::cout << "clicked button"; });

    auto solve_container = Renderer(
      Container::Vertical({solve_button}),
      [&] { return vbox({solve_button->Render()}); }
    );

    auto tab_container = Container::Tab(
        {
            problem_container,
            solver_options_container,
            solve_container,
        },
        &tab_selected);

  auto root_container = Container::Vertical({
      tab_toggle,
      tab_container,
  });

  auto renderer = Renderer(root_container, [&] {
    return vbox({
              text("Polysolve"),
               tab_toggle->Render(),
               separator(),
               tab_container->Render(),
           }) |
           border;
  });

  auto screen = App::TerminalOutput();
  screen.Loop(renderer);
}