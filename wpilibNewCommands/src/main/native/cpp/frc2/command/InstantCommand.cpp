// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "frc2/command/InstantCommand.h"
#include "frc2/command/WrapperCommand.h"
#include <utility>

using namespace frc2;

namespace {
class BeforeCommand : public WrapperCommand {
 public:
  BeforeCommand(std::unique_ptr<Command>&& command,
                std::function<void()> init)
      : WrapperCommand(std::move(command)), m_initialize(init) {}

  void Initialize() override {
      m_initialize();
      this->Initialize();
  }

 private:
  std::function<void()> m_initialize;
};
} // namespace

InstantCommand::InstantCommand(std::function<void()> toRun,
                               Requirements requirements)
    : CommandHelper(
          std::move(toRun), [] {}, [](bool interrupted) {}, [] { return true; },
          requirements) {}

// Replace the Init of the new command to also have our current one
InstantCommand::AndThen(CommandPtr&& next) && {
      return std::make_unique<BeforeCommand>(std::move(next), [this] { this->Initialize(); });
}


InstantCommand::InstantCommand() : InstantCommand([] {}) {}
