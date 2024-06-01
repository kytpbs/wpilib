// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <frc/XboxController.h>

#include "Trigger.h"
#include "frc2/command/CommandScheduler.h"
#include "frc2/command/button/CommandGenericHID.h"

namespace frc2 {
/**
 * A version of {@link frc::XboxController} with {@link Trigger} factories for
 * command-based.
 *
 * @see frc::XboxController
 */
class CommandXboxController : public CommandGenericHID {
 public:
  /**
   * Construct an instance of a controller.
   *
   * @param port The port index on the Driver Station that the controller is
   * plugged into.
   */
  explicit CommandXboxController(int port);

  /**
   * Get the underlying GenericHID object.
   *
   * @return the wrapped GenericHID object
   */
  frc::XboxController& GetHID();

  /**
   * Constructs an event instance around the left bumper's digital signal.
   *
   * @param loop the event loop instance to attach the event to. Defaults to the
   * CommandScheduler's default loop.
   * @return an event instance representing the left bumper's digital signal
   * attached to the given loop.
   */
  Trigger LeftBumper(frc::EventLoop* loop = CommandScheduler::GetInstance()
                                                .GetDefaultButtonLoop()) const;

  /**
   * Constructs an event instance around the right bumper's digital signal.
   *
   * @param loop the event loop instance to attach the event to. Defaults to the
   * CommandScheduler's default loop.
   * @return an event instance representing the right bumper's digital signal
   * attached to the given loop.
   */
  Trigger RightBumper(frc::EventLoop* loop = CommandScheduler::GetInstance()
                                                 .GetDefaultButtonLoop()) const;

  /**
   * Constructs an event instance around the left stick's digital signal.
   *
   * @param loop the event loop instance to attach the event to. Defaults to the
   * CommandScheduler's default loop.
   * @return an event instance representing the left stick's digital signal
   * attached to the given loop.
   */
  Trigger LeftStick(frc::EventLoop* loop = CommandScheduler::GetInstance()
                                               .GetDefaultButtonLoop()) const;

  /**
   * Constructs an event instance around the right stick's digital signal.
   *
   * @param loop the event loop instance to attach the event to. Defaults to the
   * CommandScheduler's default loop.
   * @return an event instance representing the right stick's digital signal
   * attached to the given loop.
   */
  Trigger RightStick(frc::EventLoop* loop = CommandScheduler::GetInstance()
                                                .GetDefaultButtonLoop()) const;

  /**
   * Constructs an event instance around the A button's digital signal.
   *
   * @param loop the event loop instance to attach the event to. Defaults to the
   * CommandScheduler's default loop.
   * @return an event instance representing the A button's digital signal
   * attached to the given loop.
   */
  Trigger A(frc::EventLoop* loop =
                CommandScheduler::GetInstance().GetDefaultButtonLoop()) const;

  /**
   * Constructs an event instance around the B button's digital signal.
   *
   * @param loop the event loop instance to attach the event to. Defaults to the
   * CommandScheduler's default loop.
   * @return an event instance representing the B button's digital signal
   * attached to the given loop.
   */
  Trigger B(frc::EventLoop* loop =
                CommandScheduler::GetInstance().GetDefaultButtonLoop()) const;

  /**
   * Constructs an event instance around the X button's digital signal.
   *
   * @param loop the event loop instance to attach the event to. Defaults to the
   * CommandScheduler's default loop.
   * @return an event instance representing the X button's digital signal
   * attached to the given loop.
   */
  Trigger X(frc::EventLoop* loop =
                CommandScheduler::GetInstance().GetDefaultButtonLoop()) const;

  /**
   * Constructs an event instance around the Y button's digital signal.
   *
   * @param loop the event loop instance to attach the event to. Defaults to the
   * CommandScheduler's default loop.
   * @return an event instance representing the Y button's digital signal
   * attached to the given loop.
   */
  Trigger Y(frc::EventLoop* loop =
                CommandScheduler::GetInstance().GetDefaultButtonLoop()) const;

  /**
   * Constructs an event instance around the back button's digital signal.
   *
   * @param loop the event loop instance to attach the event to. Defaults to the
   * CommandScheduler's default loop.
   * @return an event instance representing the back button's digital signal
   * attached to the given loop.
   */
  Trigger Back(frc::EventLoop* loop = CommandScheduler::GetInstance()
                                          .GetDefaultButtonLoop()) const;

  /**
   * Constructs an event instance around the start button's digital signal.
   *
   * @param loop the event loop instance to attach the event to. Defaults to the
   * CommandScheduler's default loop.
   * @return an event instance representing the start button's digital signal
   * attached to the given loop.
   */
  Trigger Start(frc::EventLoop* loop = CommandScheduler::GetInstance()
                                           .GetDefaultButtonLoop()) const;

  /**
   * Constructs a Trigger instance around the axis value of the left trigger.
   * The returned Trigger will be true when the axis value is greater than
   * {@code threshold}.
   *
   * @param threshold the minimum axis value for the returned Trigger to be
   * true. This value should be in the range [0, 1] where 0 is the unpressed
   * state of the axis. Defaults to 0.5.
   * @param loop the event loop instance to attach the Trigger to. Defaults to
   * the CommandScheduler's default loop.
   * @return a Trigger instance that is true when the left trigger's axis
   * exceeds the provided threshold, attached to the given loop
   */
  Trigger LeftTrigger(double threshold = 0.5,
                      frc::EventLoop* loop = CommandScheduler::GetInstance()
                                                 .GetDefaultButtonLoop()) const;

  /**
   * Constructs a Trigger instance around the axis value of the right trigger.
   * The returned Trigger will be true when the axis value is greater than
   * {@code threshold}.
   *
   * @param threshold the minimum axis value for the returned Trigger to be
   * true. This value should be in the range [0, 1] where 0 is the unpressed
   * state of the axis. Defaults to 0.5.
   * @param loop the event loop instance to attach the Trigger to. Defaults to
   * the CommandScheduler's default loop.
   * @return a Trigger instance that is true when the right trigger's axis
   * exceeds the provided threshold, attached to the given loop
   */
  Trigger RightTrigger(
      double threshold = 0.5,
      frc::EventLoop* loop =
          CommandScheduler::GetInstance().GetDefaultButtonLoop()) const;

  /**
   * Get the right trigger (RT) axis value of the controller. Note that this
   * axis is bound to the range of [0, 1] as opposed to the usual [-1, 1].
   *
   * @return The axis value.
   */
  double GetRightTriggerAxis();

  /**
   * Get the left trigger (LT) axis value of the controller. Note that this axis
   * is bound to the range of [0, 1] as opposed to the usual [-1, 1].
   *
   * @return The axis value.
   */
  double GetLeftTriggerAxis();

  /**
   * Get the Y axis value of right side of the controller.
   *
   * @return The axis value.
   */
  double GetRightY();

  /**
   * Get the Y axis value of left side of the controller.
   *
   * @return The axis value.
   */
  double GetLeftY();

  /**
   * Get the X axis value of right side of the controller.
   *
   * @return The axis value.
   */
  double GetRightX();

  /**
   * Get the X axis value of left side of the controller.
   *
   * @return The axis value.
   */
  double GetLeftX();

 private:
  frc::XboxController m_hid;
};
}  // namespace frc2
