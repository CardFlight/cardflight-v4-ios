/*!
 * @header CFTCardInfo.h
 *
 * @brief The Card Info object is a representation of a customer’s payment card information.
 * The Card Info object has no writable parameters and only contains [out of PCI-scope] information.
 *
 * @copyright 2018 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "CFTEnum.h"

@interface CFTCardInfo : NSObject

/*!
 * @property cardId
 * @brief ID of the card that can be used to run additional charges using the API
 * Added in 4.5.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *cardId;

/*!
 * @property cardBrand
 * @brief Card Brand
 * Added in 4.0.0
 */
@property (nonatomic, readonly, assign) CFTCardBrand cardBrand;

/*!
 * @property firstSix
 * @brief First 6 digits of the card number
 * Added in 4.0.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *firstSix;

/*!
 * @property lastFour
 * @brief Last 4 digits of the card number
 * Added in 4.0.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *lastFour;

/*!
 * @property expirationMonth
 * @brief Expiration month
 * Added in 4.2.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *expirationMonth;

/*!
 * @property expirationYear
 * @brief Expiration Year
 * Added in 4.2.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *expirationYear;

/*!
 * @property applicationId
 * @brief Application ID
 * Added in 4.2.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *applicationId;

/*!
 * @property applicationPreferredName
 * @brief Application preferred name
 * Added in 4.2.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *applicationPreferredName;

/*!
 * @property cardholderName
 * @brief Card Brand (The cardholder name is not always available and can be null)
 * Added in 4.0.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *cardholderName;

/*!
 * @property cardInputMethod
 * @brief Card Input Method
 * Added in 4.0.0
 */
@property (nonatomic, readonly, assign) CFTCardInputMethod cardInputMethod;

@end
