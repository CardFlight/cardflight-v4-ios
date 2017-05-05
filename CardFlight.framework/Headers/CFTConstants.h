//
//  CFTConstants.h
//  cardflight-sdk
//
//  Created by Paul Tower on 10/17/16.
//  Copyright © 2016 CardFlight. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CFTHistoricalTransaction;

@interface CFTConstants : NSObject

// Completion Blocks
typedef void (^CFTBasicBlock)(NSError * _Nullable error);
typedef void (^CFTStandardBlock)(BOOL success, NSError * _Nullable error);
typedef void (^CFTTransactionBlock)(CFTHistoricalTransaction * _Nullable historicalTransaction, NSError * _Nullable error);

@end
