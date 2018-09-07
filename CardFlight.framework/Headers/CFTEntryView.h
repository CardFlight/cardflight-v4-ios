/*
 *****************************************************************
 * CFTEntryView.h
 *
 * Copyright (c) 2018 CardFlight Inc. All rights reserved.
 *****************************************************************
 */

#import <UIKit/UIKit.h>

@protocol CFTEntryView

/*!
 * @brief Resign first responder from all fields
 * @discussion Sends the custom manual entry textfields the resignFirstResponder
 * message.
 * Added in 4.6.0
 */
- (void)resignAll;

/*!
 * @brief Clear all input from all fields
 * @discussion Clears all the input from the textfields and returns it to its
 * initial state.
 * Added in 4.6.0
 */
- (void)clearInput;

/*!
 * @brief Set keyboard appearance of custom manual entry textfields
 * @param keyboardAppearance UIKeyboardAppearance enumeration of keyboard type
 * @discussion Assigns a UIKeyboardAppearance to the custom manual entry textfields.
 * UIKeyboardAppearanceDefault is used by default.
 * Added in 4.6.0
 */
- (void)useKeyboardAppearance:(UIKeyboardAppearance)keyboardAppearance;

@end
