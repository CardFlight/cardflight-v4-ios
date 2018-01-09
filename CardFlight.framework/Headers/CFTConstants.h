/*!
 * @header CFTConstants.h
 *
 * @brief Constants used by the SDK
 *
 * @copyright 2018 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class CFTHistoricalTransaction;

@interface CFTConstants : NSObject

// Completion Blocks
typedef void (^CFTBasicBlock)(NSError * _Nullable error);
typedef void (^CFTStandardBlock)(BOOL success, NSError * _Nullable error);
typedef void (^CFTTransactionBlock)(CFTHistoricalTransaction * _Nullable historicalTransaction, NSError * _Nullable error);

@end
