//
//  CFTAdjustment.h
//  CardFlight
//
//  Created by Prasanna Kumar Challa on 8/22/19.
//  Copyright © 2019 CardFlight Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CFTAmount;

/**
 `CFTAdjustment` can be used to provide a `CFTTransaction` with optional tip amount and
 any other additional information that client wants to save along with the transaction.
 */
@interface CFTAdjustment : NSObject

/**
 Amount to tip on top of original transaction amount.
 */
@property (nonatomic, readonly, strong, nullable) CFTAmount *tipAmount;

/**
 Any additional information saved by the client along with the transaction.
 */
@property (nonatomic, readonly, strong, nullable) NSDictionary<NSString*, id> *metadata;


/**
 Initializer
 
 @param amount Tip amount to add to the adjustment.
 @param metadata Metadata to add to the adjustment.
 @return Returns a new instance of `CFTAdjustment`
 */
- (nonnull instancetype)initWithTipAmount:(nullable CFTAmount*)amount
                                 metadata:(nullable NSDictionary<NSString*, id>*)metadata;

@end
