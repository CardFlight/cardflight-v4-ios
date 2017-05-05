//
//  CFTCardReaderInfo.h
//  cardflight-sdk
//
//  Created by Adam Duflo on 11/3/16.
//  Copyright © 2016 CardFlight. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CFTEnum.h"

@interface CFTCardReaderInfo : NSObject

@property (nonatomic, readonly, copy, nonnull) NSString *name;
@property (nonatomic, readonly, assign) CFTCardReaderType cardReaderType;
@property (nonatomic, readonly, assign) CFTCardReaderModel cardReaderModel;
@property (nonatomic, readonly, assign) CFTBatteryStatus batteryStatus;

@end
