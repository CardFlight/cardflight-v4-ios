/*!
 * @header CFTTransaction.h
 *
 * @brief The Transaction object is used to process any charges you want to make. 
 * It is the main point of interaction with the CardFlight SDK.
 *
 * @copyright 2018 CardFlight Inc. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import "CFTEnum.h"
#import "CFTConstants.h"

@class CFTCardInfo;
@class CFTCardReaderInfo;
@class CFTCardAID;
@class CFTTransactionParameters;
@class CFTTokenizationParameters;
@class CFTAmount;
@class CFTKeyedEntryView;
@class CFTMessage;
@class CFTKeyedEntryContainer;
@class CFTTransactionRecord;

@protocol CFTTransactionDelegate;

@interface CFTTransaction : NSObject

/*!
 * @property delegate
 * @brief Delegate to receive callbacks during a transaction
 * Added in 4.0.0
 */
@property (nonatomic, readwrite, weak, nullable) id <CFTTransactionDelegate> delegate;

/*!
 * @property transactionParameters
 * @brief Transaction Parameters used by the Transaction
 * Added in 4.0.0
 */
@property (nonatomic, readonly, strong, nullable) CFTTransactionParameters *transactionParameters;

/*!
 * @property tokenizationParameters
 * @brief Tokenization Parameters used by the Transaction
 * Added in 4.3.0
 */
@property (nonatomic, readonly, strong, nullable) CFTTokenizationParameters *tokenizationParameters;


/*!
 * @property reachability
 * @brief Current reachability of the transaction
 * Added in 4.1.0
 */
@property (nonatomic, readonly) CFTReachability reachability;

/**
  Network type used for the transaction.
 */
@property (nonatomic, readonly) CFTNetworkType networkType;


- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

/*!
 * @brief Initialize with a delegate
 * @param delegate id<CFTTransactionDelegate> - Delegate to be assigned
 * @return CFTTransaction - Initialized with the passed delegate, or nil if the SDK is in a state where a transaction cannot be started
 * @discussion Convenience class initializer that accepts a delegate so that 
 * callbacks can be received immediately.
 * Added in 4.0.0
 */
+ (nullable instancetype)transactionWithDelegate:(nonnull id<CFTTransactionDelegate>)delegate;

/*!
 * @brief Initialize with a delegate
 * @param delegate id<CFTTransactionDelegate> - Delegate to be assigned
 * @return CFTTransaction - Initialized with the passed delegate, or nil if the SDK is in a state where a transaction cannot be started
 * @discussion Initializer that accepts a delegate so that callbacks
 * can be received immediately.
 * Added in 4.0.0
 */
- (nullable instancetype)initWithDelegate:(nonnull id<CFTTransactionDelegate>)delegate
NS_SWIFT_NAME(init(delegate:));

/*!
 * @brief Update the reachability of the transaction
 * @param reachability CFTReachability
 * @discussion Updates the reachability for the transaction. New
 * transactions default to CFTReachabilityFull
 * Added in 4.1.0
 */
- (void)updateReachability:(CFTReachability)reachability
NS_SWIFT_NAME(update(reachability:));

/*!
 * @brief Scan for compatible Bluetooth card readers
 * @discussion Initiates a scan for compatible Bluetooth card readers
 * Added in 4.0.0
 */
- (void)scanBluetoothCardReaders
NS_SWIFT_NAME(scanBluetoothCardReaders());

/*!
 * @brief Select a CFTCardReader
 * @param cardReaderInfo CFTCardReaderInfo
 * @param cardReaderModel CFTCardReaderModel
 * @discussion Will connect with the supplied reader.
 * Added in 4.0.0
 */
- (void)selectCardReaderInfo:(nullable CFTCardReaderInfo *)cardReaderInfo
             cardReaderModel:(CFTCardReaderModel)cardReaderModel
NS_SWIFT_NAME(select(cardReaderInfo:cardReaderModel:));

/*!
 * @brief Use a keyed entry view
 * @param zipEnabled BOOL
 * @return CFTKeyedEntryView - Returned with passed zipEnabled
 * @discussion Will return a keyed entry view if state is CFTTransactionStatePendingTransactionParameters or CFTTransactionStatePendingCardInput
 * Added in 4.0.0
 */
- (nullable CFTKeyedEntryView *)keyedEntryViewWithZipEnabled:(BOOL)zipEnabled
NS_SWIFT_NAME(keyedEntryView(zipEnabled:))
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.6.0. Use `keyedEntryContainer` instead");

/*!
 * @brief Use a card or address entry view
 * @return CFTKeyedEntryContainer - Returned entry view container
 * @discussion Will return an entry container if state is CFTTransactionStatePendingTransactionParameters or CFTTransactionStatePendingCardInput
 * Container will have its avsEntryView property populated if AVS is supported
 * Added in 4.6.0
 */
- (nullable CFTKeyedEntryContainer*)keyedEntryContainer
NS_SWIFT_NAME(keyedEntryContainer());


/*!
 * @brief Use card and avs info generated from keyed entry views
 * @discussion Will use information input into keyed entry views for card and avs info
 * Added in 4.0.0
 */
- (void)useKeyedCardInfo
NS_SWIFT_NAME(useKeyedCardInfo());

/*!
 * @brief Attempt to begin a sale for an amount
 * @param transactionParameters CFTTransactionParameters - TransactionParameters used for sale
 * @discussion Will attempt to begin a sale. If the state is not CFTTransactionStatePendingTransactionParameters,
 * the transactionDidUpdateState:error callback will respond with an error.
 * Added in 4.0.0
 */
- (void)beginSaleWithTransactionParameters:(nonnull CFTTransactionParameters *)transactionParameters
NS_SWIFT_NAME(beginSale(transactionParameters:));

/*!
 * @brief Attempt to authorize an amount
 * @param transactionParameters CFTTransactionParameters - TransactionParameters used for authorization
 * @discussion Will attempt to begin an authorization. If the state is not CFTTransactionStatePendingTransactionParameters,
 * the transactionDidUpdateState:error callback will respond with an error.
 * Added in 4.0.0
 */
- (void)beginAuthorizationWithTransactionParameters:(nonnull CFTTransactionParameters *)transactionParameters
NS_SWIFT_NAME(beginAuthorization(transactionParameters:));

/*!
 * @brief Attempt to tokenize a card
 * @param tokenizationParameters CFTTokenizationParameters - TokenizationParameters used for tokenize
 * @discussion Will attempt to begin the process of tokenizing. If the state is not CFTTransactionStatePendingTransactionParameters,
 * the transactionDidUpdateState:error callback will respond with an error.
 * Updated in 4.3.0
 */
- (void)beginTokenizingWithParameters:(nonnull CFTTokenizationParameters *)tokenizationParameters
NS_SWIFT_NAME(beginTokenizing(tokenizationParameters:));

/*!
 * @brief Select a CFTCardAID to use for the transaction
 * @param cardAid CFTCardAID
 * @discussion Will use the card application identifier.
 * Added in 4.0.0
 */
- (void)selectCardAid:(nonnull CFTCardAID *)cardAid
NS_SWIFT_NAME(select(cardAid:));

/*!
 * @brief Specify how to process the transaction
 * @param processOption CFTProcessOption
 * @discussion Will attempt to use the process option for transaction continuation. If the state is not
 * CFTTransactionStatePendingProcessOption, the transactionDidUpdateState:error callback will respond with an error.
 * Added in 4.0.0
 */
- (void)selectProcessOption:(CFTProcessOption)processOption
NS_SWIFT_NAME(select(processOption:));

/*!
 * @brief Attach signature CVM to transaction
 * @param signatureImage png of signature to be attached
 * @discussion Will attempt to attach signature. If the state is not
 * CFTTransactionStateCompleted, the transactionDidUpdateState:error callback will respond with an error.
 * Added in 4.1.0
 */
- (void)attachSignature:(nullable UIImage *)signatureImage
NS_SWIFT_NAME(attach(signature:));

/*!
 * @brief Private method
 * @param parameter1 id - First parameter of the method
 * @param parameter2 id - Second parameter of the method
 * @discussion This is only to be used by clients who have made arrangements with CardFlight
 * Added in 4.1.0
 */
- (void)privateFunctionOne:(nullable id)parameter1 withParameter2:(nullable id)parameter2
NS_SWIFT_NAME(privateFunctionOne(_:with:));

@end

@protocol CFTTransactionDelegate <NSObject>

@required

/*!
 * @brief The current state of the transaction
 * @param transaction CFTTransaction
 * @param state CFTTransactionState
 * @param error NSError
 * @discussion Required callback telling the transaction changed state. If an illegal state
 * change was attempted, an error will be returned.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didUpdateState:(CFTTransactionState)state error:(nullable NSError *)error
NS_SWIFT_NAME(transaction(_:didUpdate:error:));

/*!
 * @brief A message to display to users
 * @param transaction CFTTransaction
 * @param message NSString
 * @discussion Required callback containing a message to be displayed to users.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didRequestDisplayMessages:(nonnull CFTMessage *)message
NS_SWIFT_NAME(transaction(_:didRequestDisplay:));

/*!
 * @brief The card info to use for the transaction
 * @param transaction CFTTransaction
 * @param cardInfo CFTCardInfo
 * @discussion Required callback containing a representation of the card used for the transaction.
 * Pass the desired CFTProcessOption into selectProcessOption.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didRequestProcessOptionWithCardInfo:(nonnull CFTCardInfo *)cardInfo
NS_SWIFT_NAME(transaction(_:didRequestProcessOption:));

/*!
 * @brief The deferred transaction data
 * @param transaction CFTTransaction
 * @param transactionData NSData
 * @discussion Required callback containing a data representation of a transaction
 * if CFTProcessOptionDefer was used for selectProcessOption.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didDeferWithData:(nonnull NSData *)transactionData
NS_SWIFT_NAME(transaction(_:didDefer:));

/*!
 * @brief The cardholder verification method requested
 * @param transaction CFTTransaction
 * @param cvm CFTCVM
 * @discussion Required callback containing he cardholder verification method requested
 * for the transaction. If CFTCVMSignature is requested, pass
 * a base64 encoded image as NSData into attachCvmData.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didRequestCvm:(CFTCVM)cvm
NS_SWIFT_NAME(transaction(_:didRequest:));

/*!
 * @brief A transaction record from a completed transaction
 * @param transaction CFTTransaction
 * @param transactionRecord CFTTransactionRecord
 * @discussion Required callback containing the resulting transaction record
 * from a transaction in the CFTTransactionStateCompleted state.
 * Added in 4.7.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didCompleteWithTransactionRecord:(nonnull CFTTransactionRecord *)transactionRecord
NS_SWIFT_NAME(transaction(_:didComplete:));

@optional

/*!
 * @brief A historical transaction from a completed transaction
 * @param transaction CFTTransaction
 * @param historicalTransaction CFTHistoricalTransaction
 * @discussion Optional callback containing the resulting historical transaction
 * from a transaction in the CFTTransactionStateCompleted state.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didCompleteWithHistoricalTransaction:(nonnull CFTHistoricalTransaction *)historicalTransaction
NS_SWIFT_NAME(transaction(_:didComplete:))
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.7.0. Use `didCompleteWithTransactionRecord` instead");

/*!
 * @brief A card reader event was received
 * @param transaction CFTTransaction
 * @param cardReaderEvent CFTCardReaderEvent
 * @param cardReaderInfo CFTCardReaderInfo
 * @discussion Optional callback triggered when a card reader encounters an event.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didReceiveCardReaderEvent:(CFTCardReaderEvent)cardReaderEvent
     cardReaderInfo:(nullable CFTCardReaderInfo *)cardReaderInfo
NS_SWIFT_NAME(transaction(_:didReceive:cardReaderInfo:));

/*!
 * @brief A keyed entry event was received
 * @param transaction CFTTransaction
 * @param keyedEntryEvent CFTKeyedEntryEvent
 * @discussion Optional callback triggered when a keyed entry view encounters an event.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didReceiveKeyedEntryEvent:(CFTKeyedEntryEvent)keyedEntryEvent
NS_SWIFT_NAME(transaction(_:didReceive:))
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.6.0. Use `didReceiveKeyedEntryContainerEvent` instead");

/*!
 * @brief An entry event was received
 * @param transaction CFTTransaction
 * @param keyedEntryContainerEvent CFTKeyedEntryContainerEvent
 * @discussion Optional callback triggered when the keyed entry container encounters an event.
 * Added in 4.6.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didReceiveKeyedEntryContainerEvent:(CFTKeyedEntryContainerEvent)keyedEntryContainerEvent
NS_SWIFT_NAME(transaction(_:didReceive:));

/*!
 * @brief The card readers available for use
 * @param transaction CFTTransaction
 * @param cardReaderArray NSArray<CFTCardReaderInfo *>
 * @discussion Optional callback with the available card readers that can
 * be used to obtain card data. Pass the desired card reader into selectCardReaderInfo.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didUpdateCardReaderArray:(nonnull NSArray<CFTCardReaderInfo *> *)cardReaderArray
NS_SWIFT_NAME(transaction(_:didUpdate:));

/*!
 * @brief The card input methods available for use
 * @param transaction CFTTransaction
 * @param cardInputMethodArray NSArray<NSNumber *>
 * @discussion Optional callback with the available card input methods for the connected reader
 * that can be used to process a transaction. The integerValue of a respective card input method
 * matches directly with a CFTCardInputMethod enum value.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didUpdateCardInputMethodArray:(nonnull NSArray<NSNumber *> *)cardInputMethodArray
NS_SWIFT_NAME(transaction(_:didUpdate:));

/*!
 * @brief The card application identifiers available for use
 * @param transaction CFTTransaction
 * @param cardAidArray NSArray<CFTCardAID *>
 * @discussion Optional callback with the available card application identifiers to use for the transaction.
 * Pass the desired card application identifier into selectCardAid.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didRequestCardAidSelection:(nonnull NSArray<CFTCardAID *> *)cardAidArray
NS_SWIFT_NAME(transaction(_:didRequestCardAidSelection:));

@end
