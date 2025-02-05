#pragma once
/**
 * Scans a keyboard matrix and detects the pressed button.
 * 
 * @param cols The number of columns in the keyboard matrix.
 * @param rows The number of rows in the keyboard matrix.
 * @param allowHold Determines the behavior for keypress holding:
 *                  - If set to `0`: A held key will register as a single keypress.
 *                  - If set to `1`: A held key will register as multiple keypresses (depending on the scan frequency).
 * 
 * @return The index of the pressed key in a flattened array representation of the keyboard matrix.
 *         The array is structured as: [[col0_row0, col1_row0, ...], [col0_row1, col1_row1, ...], ...].
 *         If no key is pressed, it may return a sentinel value (e.g., -1).
 * 
 * @note This function assumes a specific hardware setup where the keyboard matrix is connected to Port F.
 *       Ensure the microcontroller's pin configurations match the expected wiring for proper operation.
 */
int scanKeyboardPortF(int cols, int rows, int allowHold);

/**
 * Initializes the keyboard matrix connected to Port F.
 * 
 * This function configures the necessary pins of Port F as inputs or outputs, 
 * depending on the keyboard matrix wiring. It ensures that the microcontroller 
 * is properly set up to scan the keypad for key presses.
 * 
 * @param rows The number of rows in the keyboard matrix.
 * @param cols The number of columns in the keyboard matrix.
 * 
 * @note This function assumes a specific hardware setup where the keyboard matrix 
 *       is connected to Port F. Ensure the correct wiring and microcontroller configuration 
 *       before calling this function.
 */
void initKeyboardPortF(int rows, int cols);