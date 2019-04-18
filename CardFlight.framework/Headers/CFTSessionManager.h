//
//  CFTSessionManager.h
//  CardFlight
//
//  Created by Prasanna Kumar Challa on 3/28/19.
//  Copyright © 2019 CardFlight Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CFTLogger.h"

/**
 * SessionManager singleton to manage a session.
 *
 */
@interface CFTSessionManager : NSObject

/*!
 * @brief Accessor for the session manager singleton
 * @discussion Access the session manager singleton
 * Added in 4.8.0
 */
+ (nonnull instancetype)shared;

/*!
 * @property Accessor for logging mode of the SDK.
 * @brief Set this to `YES` to enable developer logging mode to the console.
 * Added in 4.8.0
 */
@property (nonatomic, readwrite, assign) BOOL isLogging;

/*!
 * @property loggerDelegate
 * @brief Delegate to receive callabck during Logging.
 * Added in 4.8.0
 */
@property (nonatomic, readwrite, weak, nullable) id <CFTLoggerDelegate> loggerDelegate;

@end
