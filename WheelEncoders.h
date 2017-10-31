#ifndef WHEEL_ENCODER_H
#define WHEEL_ENCODER_H

/**
 * @brief Handles interrupts from left and right wheel encoders. Assumes there
 * are 2 encoders; some assumption has to be made because the interrupt methods
 * need to be static. The ticks accumulate non-directionally until reset.
 * Direction will have to be handled
 */
class WheelEncoders {
  public:
    // enforce static class (no objects of this class)
    WheelEncoders() = delete;

    /**
     * @brief Set up interrupts on the given pins.
     * @param leftInterruptPin A platform specific interrupt pin. It should not
     * be used for another interrupt.
     */
    static void setUp(const int leftInterruptPin, const int rightInterruptPin);

    /**
     * @brief Get accumulated left ticks since last clear. The ticks are cleared
     * at
     * initialization time.
     */
    static int getLeftTicks();
    static int getRightTicks();

    /**
     * @brief Reset the accumulated ticks.
     */
    static void clear();

  private:
    static void leftInterrupt();
    static void rightInterrupt();

    static volatile int _ticksLeft, _ticksRight;
};

#endif // WHEEL_ENCODER_H
