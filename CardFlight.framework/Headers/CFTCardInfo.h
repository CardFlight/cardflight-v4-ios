//
//  CFTCardInfo.h
//  cardflight-sdk
//
//  Created by Adam Duflo on 11/3/16.
//  Copyright © 2016 CardFlight. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CFTEnum.h"

@interface CFTCardInfo : NSObject

@property (nonatomic, readonly, assign) CFTCardBrand cardBrand;
@property (nonatomic, readonly, copy, nullable) NSString *firstSix;
@property (nonatomic, readonly, copy, nullable) NSString *lastFour;
@property (nonatomic, readonly, copy, nullable) NSString *cardholderName;
@property (nonatomic, readonly, assign) CFTCardInputMethod cardInputMethod;

@end
