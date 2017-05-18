/*!
 * @header CFTLogger.h
 *
 * @brief Handles routing of logging debug messages
 *
 * @copyright 2017 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

@protocol CFTLoggerDelegate <NSObject>

@optional

/*!
 * @brief Capture logging messages
 * @param output NSString - The log message
 * @discussion Optional callback to reroute logging messages to a
 * file instead of to the console.
 * Added in 4.0
 */
- (void)loggerOutput:(nonnull NSString *)output;

@end

@interface CFTLogger : NSObject

@property (nonatomic, readwrite, weak, nullable) id <CFTLoggerDelegate> delegate;

/*!
 * @brief Accessor for the logger singleton
 * @discussion Access the logger singleton
 * Added in 4.0
 */
+ (nonnull CFTLogger *)sharedLogger;

/*!
 * @brief Set logging mode of the SDK
 * @param logging BOOL to turn on or off logging mode
 * @discussion Pass YES to enable developer logging mode to the console.
 * Added in 4.0
 */
- (void)setLogging:(BOOL)logging;

@end
