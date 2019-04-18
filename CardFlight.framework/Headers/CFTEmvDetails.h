/*!
 * @header CFTEmvDetails.h
 *
 * @brief The CFTEmvDetails object contains all the emv data that a payment processor returns.
 * The CFTEmvDetails object has no writable parameters and only contains [out of PCI-scope] information.
 *
 * @copyright 2019 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

@interface CFTEmvDetails : NSObject

/*!
 * @property applicationPreferredName
 * @brief Application preferred name.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *applicationPreferredName;

/*!
 * @property applicationId
 * @brief Application Id.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *applicationId;

/*!
 * @property applicationLabel
 * @brief Application Label.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *applicationLabel;

/*!
 * @property transactionStatusIndicator
 * @brief Transaction status indicator.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *transactionStatusIndicator;

/*!
 * @property applicationResponseCode
 * @brief Application response code.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *applicationResponseCode;

/*!
 * @property applicationCryptogram
 * @brief Application crypto gram.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *applicationCryptogram;

/*!
 * @property applicationTransactionCounter
 * @brief Application transaction counter.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *applicationTransactionCounter;

/*!
 * @property panSequenceNumber
 * @brief Pan sequence number.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *panSequenceNumber;

/*!
 * @property issuerActionCodeOnline
 * @brief Issuer action code online.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *issuerActionCodeOnline;

/*!
 * @property issuerActionCodeDenial
 * @brief Issuer code denial.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *issuerActionCodeDenial;

/*!
 * @property issuerActionCodeDefault
 * @brief Issuer action code default.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *issuerActionCodeDefault;

/*!
 * @property cardholderVerificationMethod
 * @brief Card holder verification method.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *cardholderVerificationMethod;

/*!
 * @property entryMode
 * @brief Entry mode.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *entryMode;


/*!
* @brief Returns `CFTEmvDetails` object as a dictionary.
* @return `NSDictionary` - NSDictionary representation of `CFTEmvDetails`.
* @discussion The returning dictionary will have `key`s in printable format.
*/
- (NSDictionary<NSString*, NSString*> *)asDictionary;

@end
