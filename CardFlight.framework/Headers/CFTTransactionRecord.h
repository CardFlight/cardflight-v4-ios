/*!
 * @header CFTTransactionRecord.h
 *
 * @brief The Transaction Record object is created (usually by a Transaction object)
 * to represent the record of a past transaction.
 *
 * @copyright 2019 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "CFTEnum.h"
#import "CFTConstants.h"

@class CFTTransactionParameters;
@class CFTCardReaderInfo;
@class CFTCardInfo;
@class CFTAvsResponse;
@class CFTAmount;
@class CFTMerchantAccount;

@interface CFTTransactionRecord : NSObject

/*!
 * @property amount
 * @brief Amount processed
 * Added in 4.8.2
 */
@property (nonatomic, readonly, strong, nonnull) CFTAmount *amount;

/*!
 * @property transactionState
 * @brief Current state of the transaction
 * Added in 4.7.0
 */
@property (nonatomic, readonly, assign) CFTApiTransactionState apiTransactionState;

/*!
 * @property authCodes
 * @brief AuthCodes of a transaction.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, strong, nullable) NSArray<NSString *> *authCodes;

/*!
 * @property avsResponse
 * @brief Avs result of the transaction
 * Added in 4.5.0
 */
@property (nonatomic, readonly, strong, nullable) CFTAvsResponse *avsResponse;

/*!
 * @property callbackUrl
 * @brief Callback URL transaction information was reported to.
 * Added in 4.8.2
 */
@property (nonatomic, readonly, strong, nullable) NSURL *callbackUrl;

/*!
 * @property cardInfo
 * @brief Card Info used by the Transaction
 * Added in 4.7.0
 */
@property (nonatomic, readonly, strong, nullable) CFTCardInfo *cardInfo;

/*!
 * @property cardReaderInfo
 * @brief Card Reader Info used by the Transaction
 * Added in 4.7.0
 */
@property (nonatomic, readonly, strong, nullable) CFTCardReaderInfo *cardReaderInfo;

/*!
 * @property cardToken
 * @brief Card Token generated by the Transaction
 * Added in 4.1.0
 */
@property (nonatomic, readonly, strong, nullable) NSString *cardToken;

/*!
 * @property createdAt
 * @brief Date when the Transaction was created
 * Added in 4.7.0
 */
@property (nonatomic, readonly, strong, nonnull) NSDate *createdAt;

/*!
 * @property merchant account
 * @brief MerchantAccount to use for processing
 * Added in 4.7.0
 */
@property (nonatomic, readonly, strong, nonnull) CFTMerchantAccount *merchantAccount;

/*!
 * @property message
 * @brief Message explaining the [result] of the transaction. Can be null.
 * Added in 4.8.2
 */
@property (nonatomic, readonly, copy, nullable) NSString *message;

/*!
 * @property metadata
 * @brief The metadata hash is used to store any additional information with a Transaction on the CardFlight Gateway.
 * Added in 4.8.0
 */
@property (nonatomic, readonly, strong, nullable) NSDictionary *metadata;

/*!
 * @property referenceId
 * @brief Reference number of the transaction
 * Updated in 4.1.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *referenceId;

/*!
 * @property result
 * @brief Result of the Transaction
 * Added in 4.7.0
 */
@property (nonatomic, readonly, assign) CFTTransactionResult result;

/*!
 * @property sdkData
 * @brief SDK generated data from the original transaction.
 * Added in 4.8.2
 */
@property (nonatomic, readonly, strong, nullable) NSDictionary *sdkData;

/*!
 * @property signatureUrl
 * @brief URL of the signature data
 * Added in 4.7.0
 */
@property (nonatomic, readonly, strong, nullable) NSURL *signatureUrl;

/*!
 * @property transactedAt
 * @brief Date when the Transaction was processed
 * Updated in 4.5.0
 */
@property (nonatomic, readonly, strong, nullable) NSDate *transactedAt;

/*!
 * @property transactionId
 * @brief Unique identifier of the transaction
 * Added in 4.8.2
 */
@property (nonatomic, readonly, copy, nullable) NSString *transactionId;

/*!
 * @property transactionType
 * @brief Type of Transaction
 * Added in 4.7.0
 */
@property (nonatomic, readonly, assign) CFTTransactionType transactionType;

/*!
 * @property chargeId
 * @brief CardFlight charge ID from a transaction
 * Added in 4.1.0
 */
@property (nonatomic, readwrite, copy, nullable) NSString *chargeId
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.8.2 Use `transactionId` for error in string representation instead");

/*!
 * @property declineMessage
 * @brief Decline message (Only populated if the result was declined)
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *declineMessage
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.8.2 Use `message` instead");

/*!
 * @property error
 * @brief Error that occurred (Only populated if the result was errored)
 * Added in 4.7.0
 */
@property (nonatomic, readonly, strong, nullable) NSError *error
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.8.2 Use `message` for error in string representation instead");


/*!
 * @property transactionParameters
 * @brief Transaction Parameters used by the Transaction
 * Added in 4.7.0
 */
@property (nonatomic, readonly, strong, nullable) CFTTransactionParameters *transactionParameters
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.8.2 Use use the respective properties(amount, merchantAccount...) instead.");

/*!
 * @property uuid
 * @brief UUID of the Transaction
 * Added in 4.7.0
 */
@property (nonatomic, readonly, strong, nullable) NSUUID *uuid
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.8.2 Use `sdkData` to get `uuid` instead");

@end
