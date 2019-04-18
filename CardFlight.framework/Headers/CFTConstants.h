/*!
 * @header CFTConstants.h
 *
 * @brief Constants used by the SDK
 *
 * @copyright 2018 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class CFTHistoricalTransaction;
@class CFTTransactionRecord;

@interface CFTConstants : NSObject

// Completion Blocks
typedef void (^CFTBasicBlock)(NSError * _Nullable error);
typedef void (^CFTStandardBlock)(BOOL success, NSError * _Nullable error);
typedef void (^CFTLegacyTransactionBlock)(CFTHistoricalTransaction * _Nullable historicalTransaction, NSError * _Nullable error);
typedef void (^CFTTransactionBlock)(CFTTransactionRecord * _Nullable transactionRecord, NSError * _Nullable error);

@end
