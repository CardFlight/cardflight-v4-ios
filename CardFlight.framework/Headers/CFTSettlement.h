//
//  CFTSettlement.h
//  CardFlight
//
//  Created by Rosy Sunuwar on 9/13/19.
//  Copyright © 2019 CardFlight Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CFTEnum.h"

@interface CFTSettlement : NSObject

/*!
 * @property scheme
 * @brief Settlement scheme used by the merchant account.
 * Added in 4.8.9
 */
@property (nonatomic, readonly, assign) CFTMerchantAccountSettlementScheme scheme;

@end
