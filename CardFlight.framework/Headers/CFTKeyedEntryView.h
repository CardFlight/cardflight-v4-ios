/*
 *****************************************************************
 * CFTKeyedEntryView.h
 *
 * Copyright (c) 2015 CardFlight Inc. All rights reserved.
 *****************************************************************
 */

#import <UIKit/UIKit.h>

@interface CFTKeyedEntryView : UIView

+ (nonnull instancetype)new NS_UNAVAILABLE;
- (nonnull instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

/*!
 * @brief Resign first responder from all fields
 * @discussion Sends the custom manual entry textfields the resignFirstResponder
 * message.
 * Added in 1.5.1
 */
- (void)resignAll;

/*!
 * @brief Clear all input from all fields
 * @discussion Clears all the input from the textfields and returns it to its
 * initial state.
 * Added in 1.5.1
 */
- (void)clearInput;

/*!
 * @brief Set keyboard appearance of custom manual entry textfields
 * @param keyboardAppearance UIKeyboardAppearance enumeration of keyboard type
 * @discussion Assigns a UIKeyboardAppearance to the custom manual entry textfields.
 * UIKeyboardAppearanceDefault is used by default.
 * Added in 1.5.1
 */
- (void)useKeyboardAppearance:(UIKeyboardAppearance)keyboardAppearance;

/*!
 * @brief Set font for custom manual entry textfields
 * @param newFont UIFont of font to use
 * @discussion Assigns a font to use for the custom manual entry textfields.
 * Uses bold system font size 17 by default. Passing nil reenables the default font.
 * Added in 1.5.1
 */
- (void)useFont:(nonnull UIFont *)newFont;

/*!
 * @brief Set font color for custom manual entry textfields
 * @param newColor UIColor of color to use
 * @discussion Assigns a color to use for the font for the custom manual
 * entry textfields. Black is used by default. Passing nil reenables the default font color.
 * Added in 1.5.1
 */
- (void)useFontColor:(nonnull UIColor *)newColor;

/*!
 * @brief Set the font alert color for custom manual entry textfields
 * @param newColor UIColor of color to use
 * @discussion Assigns a color to use for the font when the validation fails.
 * A red color (253, 0, 17) is used by default. Passing nil reenables the default alert font color.
 * Added in 1.5.1
 */
- (void)useFontAlertColor:(nonnull UIColor *)newColor;

/*!
 * @brief Set the border color for custom manual entry
 * @param newColor UIColor of color to use
 * @discussion Assigns a new color to the textfield border.
 * Black is used by default. Passing nil reenables the default border color.
 * Added in 1.5.1
 */
- (void)useBorderColor:(nonnull UIColor *)newColor;

@end
