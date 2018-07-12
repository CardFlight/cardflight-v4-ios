/*!
 * @header CFTEnum.h
 *
 * @brief Enumerations used with the SDK
 *
 * @copyright 2018 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

/*!
 * @typedef CFTTransactionState
 * @brief Current state of the transaction
 * @constant CFTTransactionStateUnknown Transaction is in an unknown state, should not occur in normal operation
 * @constant CFTTransactionStatePendingTransactionParameters Transaction has no transaction parameters and is not ready to begin
 * @constant CFTTransactionStatePendingCardInput Transaction has been set up and is waiting for card input
 * @constant CFTTransactionStatePendingProcessOption Transaction has payment attached and is waiting for process option selection
 * @constant CFTTransactionStateProcessing Transaction is currently processing the payment
 * @constant CFTTransactionStateCompleted Transaction has finished processing
 * @constant CFTTransactionStateDeferred Transaction has been deferred and must be resumed using deferred transaction data
 * @discussion Current public state of the transaction
 * Most transactions will proceed through all 5 states in linear order.
 * The current state can be used to determine the flow of control in the host application.
 * Added in 4.0.0
 */
typedef NS_ENUM(NSInteger, CFTTransactionState) {
    CFTTransactionStateUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTTransactionStatePendingTransactionParameters NS_SWIFT_NAME(pendingTransactionParameters) = 1,
    CFTTransactionStatePendingCardInput NS_SWIFT_NAME(pendingCardInput) = 2,
    CFTTransactionStatePendingProcessOption NS_SWIFT_NAME(pendingProcessOption) = 3,
    CFTTransactionStateProcessing NS_SWIFT_NAME(processing) = 4,
    CFTTransactionStateCompleted NS_SWIFT_NAME(completed) = 5,
    CFTTransactionStateDeferred NS_SWIFT_NAME(deferred) = 6
};

/*!
 * @typedef CFTCardReaderEvent
 * @brief Events triggered by the card reader
 * @constant CFTCardReaderEventUnknown Unknown event, should not occur in normal operation
 * @constant CFTCardReaderEventDisconnected A reader was disconnected
 * @constant CFTCardReaderEventConnected A reader was connected
 * @constant CFTCardReaderEventConnectionErrored A reader connection attempt failed
 * @constant CFTCardReaderEventSwiped A swipe was received by the reader
 * @constant CFTCardReaderEventSwipeErrored A bad swipe was received by the reader
 * @constant CFTCardReaderEventInserted A card was inserted into the reader
 * @constant CFTCardReaderEventInsertErrored A card was inserted into the reader but could not be read
 * @constant CFTCardReaderEventCardRemoved The inserted card was removed from the reader
 * @constant CFTCardReaderEventTapped A card tap was received by the reader
 * @constant CFTCardReaderEventTapErrored A card tap was received by the reader but could not be read
 * @constant CFTCardReaderEventUpdateStarted The reader started updating
 * @constant CFTCardReaderEventUpdateCompleted The reader completed updating
 * @constant CFTCardReaderEventAudioRecordingPermissionNotGranted Audio recording permissions were not granted
 * @constant CFTCardReaderEventFatalError Reader encountered a fatal error
 * @discussion Specifies the events pertaining to the card reader
 * Added in 4.0.0
 */
typedef NS_ENUM(NSInteger, CFTCardReaderEvent) {
    CFTCardReaderEventUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTCardReaderEventDisconnected NS_SWIFT_NAME(disconnected) = 1,
    CFTCardReaderEventConnected NS_SWIFT_NAME(connected) = 2,
    CFTCardReaderEventConnectionErrored NS_SWIFT_NAME(connectionErrored) = 3,
    CFTCardReaderEventCardSwiped NS_SWIFT_NAME(cardSwiped) = 4,
    CFTCardReaderEventCardSwipeErrored NS_SWIFT_NAME(cardSwipeErrored) = 5,
    CFTCardReaderEventCardInserted NS_SWIFT_NAME(cardInserted) = 6,
    CFTCardReaderEventCardInsertErrored NS_SWIFT_NAME(cardInsertErrored) = 7,
    CFTCardReaderEventCardRemoved NS_SWIFT_NAME(cardRemoved) = 8,
    CFTCardReaderEventCardTapped NS_SWIFT_NAME(cardTapped) = 9,
    CFTCardReaderEventCardTapErrored NS_SWIFT_NAME(cardTapErrored) = 10,
    CFTCardReaderEventUpdateStarted NS_SWIFT_NAME(updateStarted) = 11,
    CFTCardReaderEventUpdateCompleted NS_SWIFT_NAME(updateCompleted) = 12,
    CFTCardReaderEventAudioRecordingPermissionNotGranted NS_SWIFT_NAME(audioRecordingPermissionNotGranted) = 13,
    CFTCardReaderEventFatalError NS_SWIFT_NAME(fatalError) = 14,
    CFTCardReaderEventConnecting NS_SWIFT_NAME(connecting) = 15,
    CFTCardReaderEventBatteryStatusUpdated NS_SWIFT_NAME(batteryStatusUpdated) = 16
};

/*!
 * @typedef CFTKeyedEntryEvent
 * @brief Events triggered by key entered card information
 * @constant CFTKeyedEntryEventUnknown
 * @constant CFTKeyedEntryEventCardIncomplete The card information provided is not yet complete
 * @constant CFTKeyedEntryEventCardComplete The card information provided has completed card number, expiration date, and CVV value
 * @discussion Specifies whether or not complete key entered card information was provided
 * Added in 4.0.0
 */
typedef NS_ENUM(NSInteger, CFTKeyedEntryEvent) {
    CFTKeyedEntryEventUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTKeyedEntryEventCardIncomplete NS_SWIFT_NAME(cardIncomplete) = 1,
    CFTKeyedEntryEventCardComplete NS_SWIFT_NAME(cardComplete) = 2
};

/*!
 * @typedef CFTCardInputMethod
 * @brief Method by which card info was captured
 * @constant CFTCardInputMethodUnknown Unknown method, should not occur in normal operation
 * @constant CFTCardInputMethodKey Card info generated from key entry
 * @constant CFTCardInputMethodSwipe Card info generated from swipe data
 * @constant CFTCardInputMethodDip Card info generated from dipped data
 * @constant CFTCardInputMethodTap Card info generated from NFC tapped data
 * @constant CFTCardInputMethodSwipeFallback Card info generated from a swipe following failed dip attempts
 * @constant CFTCardInputMethodQuickChip Card info generated from quick chip data
 * @discussion Specifies the method by which card info was generated
 * Added in 4.0.0
 */
typedef NS_ENUM(NSInteger, CFTCardInputMethod) {
    CFTCardInputMethodUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTCardInputMethodKey NS_SWIFT_NAME(key) = 1,
    CFTCardInputMethodSwipe NS_SWIFT_NAME(swipe) = 2,
    CFTCardInputMethodDip NS_SWIFT_NAME(dip) = 3,
    CFTCardInputMethodTap NS_SWIFT_NAME(tap) = 4,
    CFTCardInputMethodSwipeFallback NS_SWIFT_NAME(swipeFallback) = 5,
    CFTCardInputMethodQuickChip NS_SWIFT_NAME(quickChip) = 6
};

/*!
 * @typedef CFTProcessOption
 * @brief Options for processing a transaction
 * @constant CFTProcessOptionUnknown Unknown option, should not occur in normal operation
 * @constant CFTProcessOptionProcess Process the transaction online normally
 * @constant CFTProcessOptionDefer Save the transaction to process at a later date
 * @constant CFTProcessOptionAbort Cancel the transaction without processing
 * @discussion Transactions can either be processed online, saved for later processing, or canceled without processing.
 * Added in 4.0.0
 */
typedef NS_ENUM(NSInteger, CFTProcessOption) {
    CFTProcessOptionUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTProcessOptionProcess NS_SWIFT_NAME(process) = 1,
    CFTProcessOptionDefer NS_SWIFT_NAME(defer) = 2,
    CFTProcessOptionAbort NS_SWIFT_NAME(abort) = 3
};

/*!
 * @typedef CFTCVM
 * @brief Supported cardholder verification methods
 * @constant CFTCVMUnknown Unknown CVM, should not occur in normal operation
 * @constant CFTCVMNone No CVM requested
 * @constant CFTCVMSignature Signature CVM requested
 * @discussion All currently supported cardholder verification methods
 * Added in 4.0.0
 */
typedef NS_ENUM(NSInteger, CFTCVM) {
    CFTCVMUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTCVMNone NS_SWIFT_NAME(none) = 1,
    CFTCVMSignature NS_SWIFT_NAME(signature) = 2
};

/*!
 * @typedef CFTTransactionResult
 * @brief Outcome of a transaction
 * @constant CFTTransactionResultUnknown Unknown result, should not occur in normal operation
 * @constant CFTTransactionResultApproved Transaction was approved online
 * @constant CFTTransactionResultDeclined Transaction was declined online
 * @constant CFTTransactionResultErrored Transaction encountered an error
 * @constant CFTTransactionResultAborted Transaction was cancelled before processing
 * @constant CFTTransactionResultVoided Transaction was voided before it batched out
 * @discussion The final outcome of a transaction
 * Updated in 4.1.0
 */
typedef NS_ENUM(NSInteger, CFTTransactionResult) {
    CFTTransactionResultUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTTransactionResultApproved NS_SWIFT_NAME(approved) = 1,
    CFTTransactionResultDeclined NS_SWIFT_NAME(declined) = 2,
    CFTTransactionResultErrored NS_SWIFT_NAME(errored) = 3,
    CFTTransactionResultAborted NS_SWIFT_NAME(aborted) = 4,
    CFTTransactionResultVoided NS_SWIFT_NAME(voided) = 5
};

typedef NS_ENUM(NSInteger, CFTAvsResult) {
    CFTAvsResultUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTAvsResultMatched NS_SWIFT_NAME(matched) = 1,
    CFTAvsResultNotMatched NS_SWIFT_NAME(notMatched) = 2,
    CFTAvsResultNotRequested NS_SWIFT_NAME(notRequested) = 3,
    CFTAvsResultServiceUnavailable NS_SWIFT_NAME(serviceUnavailable) = 4
};

/*!
 * @typedef CFTTransactionType
 * @bried The type of transaction being performed
 * @constant CFTTransactionTypeUnknown Unknown type, should not occur in normal operation
 * @constant CFTTransactionTypeSale Standard sale
 * @constant CFTTransactionTypeRefund A refunded sale
 * @constant CFTTransactionTypeAuthorization An authorized but not yet captured transaction
 * @discussion Valid types of transactions that can be performed
 * Updated in 4.1.0
 */
typedef NS_ENUM(NSInteger, CFTTransactionType) {
    CFTTransactionTypeUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTTransactionTypeSale NS_SWIFT_NAME(sale) = 1,
    CFTTransactionTypeRefund NS_SWIFT_NAME(refund) = 2,
    CFTTransactionTypeAuthorization NS_SWIFT_NAME(authorization) = 3,
    CFTTransactionTypeTokenization NS_SWIFT_NAME(tokenization) = 4
};

/*!
 * @typedef CFTApiTransactionStatus
 * @bried The current status of the historical transaction
 * @constant CFTTransactionTypeUnknown Unknown state. An error has occurred.
 * @constant CFTHistoricalTransactionStatusPendingPreApproved Authorization requested, awaiting result.
 * @constant CFTHistoricalTransactionStatusPreApproved Authorization approved, cardholder statement shows funds as `PENDING`.
 * @constant CFTHistoricalTransactionStatusPendingApproved Sale, Capture, or Refund requested, awaiting result.
 * @constant CFTHistoricalTransactionStatusApproved Sale, Capture, or Refund approved, funds to be moved between merchant and cardholder.
 * @constant CFTHistoricalTransactionStatusPendingVoid Void requested, awaiting result.
 * @constant CFTHistoricalTransactionStatusVoided Transaction voided, funds are released to cardholder and no money is moved.
 * @constant CFTHistoricalTransactionStatusDeclined Authorization, Sale, or Refund request declined.
 * @constant CFTHistoricalTransactionStatusSettled Capture, Sale, or Refund settled.
 * @discussion This status mirrors the transaction status available from the Cardflight API
 * Added in 4.1.0
 */
typedef NS_ENUM(NSInteger, CFTApiTransactionStatus) {
    CFTHistoricalTransactionStatusUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTHistoricalTransactionStatusPendingPreApproved NS_SWIFT_NAME(pendingPreApproved) = 1,
    CFTHistoricalTransactionStatusPreApproved NS_SWIFT_NAME(preApproved) = 2,
    CFTHistoricalTransactionStatusPendingApproved NS_SWIFT_NAME(pendingApproved) = 3,
    CFTHistoricalTransactionStatusApproved NS_SWIFT_NAME(approved) = 4,
    CFTHistoricalTransactionStatusPendingVoid NS_SWIFT_NAME(pendingVoid) = 5,
    CFTHistoricalTransactionStatusVoided NS_SWIFT_NAME(voided) = 6,
    CFTHistoricalTransactionStatusDeclined NS_SWIFT_NAME(declined) = 7,
    CFTHistoricalTransactionStatusSettled NS_SWIFT_NAME(settled) = 8
    
};

/*!
 * @typedef CFTCardBrand
 * @brief All recognized card brands
 * @constant CFTCardBrandUnknown Card doesn't match any known configuration
 * @constant CFTCardBrandAmericanExpress Supported, Range: 34, 37
 * @constant CFTCardBrandChinaUnionPay Not supported, Range: 56
 * @constant CFTCardBrandDinersClubCarteBlanche Not supported, Range: 300-305
 * @constant CFTCardBrandDinersClubInternational Not supported, Range: 309, 36, 38-39
 * @constant CFTCardBrandDiscoverCard Supported, Range: 6011, 622126-622925, 644-649, 65
 * @constant CFTCardBrandInterpayment Not supported, Range: 636
 * @constant CFTCardBrandInstapayment Not supported, Range: 637-639
 * @constant CFTCardBrandJCB Not supported, Range: 3528-3589
 * @constant CFTCardBrandMaestro Not supported, Range: 50, 56-69
 * @constant CFTCardBrandDankort Not supported, Range: 5019
 * @constant CFTCardBrandMastercard Supported, Range: 2221-2720, 51-55
 * @constant CFTCardBrandVisa Supported, Range: 4
 * @constant CFTCardBrandUATP Not supported, Range: 1
 * @constant CFTCardBrandVerve Not supported, Range: 16, 19
 * @constant CFTCardBrandCardGuard Not supported, Range: 5392
 * @discussion All card brands recognized by the SDK. Not all recognized cards
 * are supported for running transactions. Credit card numbers starting within the
 * specified range are considered part of that card brand
 * Added in 4.0.0
 */
typedef NS_ENUM(NSInteger, CFTCardBrand) {
    CFTCardBrandUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTCardBrandAmericanExpress NS_SWIFT_NAME(americanExpress) = 1,
    CFTCardBrandChinaUnionPay NS_SWIFT_NAME(chinaUnionPay) = 2,
    CFTCardBrandDinersClubCarteBlanche NS_SWIFT_NAME(dinersClubCarteBlanche) = 3,
    CFTCardBrandDinersClubInternational NS_SWIFT_NAME(dinersClubInternational) = 4,
    CFTCardBrandDiscoverCard NS_SWIFT_NAME(discoverCard) = 5,
    CFTCardBrandInterpayment NS_SWIFT_NAME(interpayment) = 6,
    CFTCardBrandInstapayment NS_SWIFT_NAME(instapayment) = 7,
    CFTCardBrandJCB NS_SWIFT_NAME(JCB) = 8,
    CFTCardBrandMaestro NS_SWIFT_NAME(maestro) = 9,
    CFTCardBrandDankort NS_SWIFT_NAME(dankort) = 10,
    CFTCardBrandMastercard NS_SWIFT_NAME(mastercard) = 11,
    CFTCardBrandVisa NS_SWIFT_NAME(visa) = 12,
    CFTCardBrandUATP NS_SWIFT_NAME(UATP) = 13,
    CFTCardBrandVerve NS_SWIFT_NAME(verve) = 14,
    CFTCardBrandCardGuard NS_SWIFT_NAME(cardguard) = 15
};

/*
 * @typedef CFTReachability
 * @brief Set network reachability for the current transaction
 * @constant CFTReachabilityUnknown Current reachability is unknown
 * @constant CFTReachabilityFull Full network access
 * @constant CFTReachabilityRestricted Limited network access
 * @discussion Reachability is set per-transaction and if it is set to resticted
 * EMV transactions will not be permitted in order to ensure the transaction
 * will be able to be deferred
 * Added in 4.1.0
 */
typedef NS_ENUM(NSInteger, CFTReachability) {
    CFTReachabilityUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTReachabilityFull NS_SWIFT_NAME(full) = 1,
    CFTReachabilityRestricted NS_SWIFT_NAME(restricted) = 2
};

/*!
 * @typedef CFTCardReaderModel
 * @brief Compatible card readers
 * @constant CFTCardReaderModelUnknown Reader type is unknown or no reader is present
 * @constant CFTCardReaderModelShuttle Audio jack, swipe only
 * @constant CFTCardReaderModelBTMag Bluetooth, swipe only
 * @constant CFTCardReaderModelA100 Audio jack, swipe only
 * @constant CFTCardReaderModelA200 Audio jack, swipe and dip
 * @constant CFTCardReaderModelB550 Bluetooth, swipe, dip, and tap
 * @constant CFTCardReaderModelB500 Bluetooth, swipe and dip
 * @constant CFTCardReaderModelA250 Audio jack, swipe, dip, and tap
 * @constant CFTCardReaderModelB200 Bluetooth, swipe and dip
 * @constant CFTCardReaderModelB250 Bluetooth, swipe, dip, and tap
 * @discussion All compatible card readers, with their interface and supported input methods
 * Added in 4.0.0
 */
typedef NS_ENUM(NSInteger, CFTCardReaderModel) {
    CFTCardReaderModelUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTCardReaderModelShuttle NS_SWIFT_NAME(shuttle) = 1,
    CFTCardReaderModelBTMag NS_SWIFT_NAME(btMag) = 2,
    CFTCardReaderModelA100 NS_SWIFT_NAME(A100) = 3,
    CFTCardReaderModelA200 NS_SWIFT_NAME(A200) = 4,
    CFTCardReaderModelB550 NS_SWIFT_NAME(B550) = 5,
    CFTCardReaderModelB500 NS_SWIFT_NAME(B500) = 6,
    CFTCardReaderModelA250 NS_SWIFT_NAME(A250) = 7,
    CFTCardReaderModelB200 NS_SWIFT_NAME(B200) = 8,
    CFTCardReaderModelB250 NS_SWIFT_NAME(B250) = 9
};

/*!
 * @typedef CFTBatteryStatus
 * @brief Card reader battery status
 * @constant CFTBatteryStatusUnknown Unknown battery status
 * @constant CFTBatteryStatusLow Low battery, charge immediately
 * @constant CFTBatteryStatusNominal Sufficent battery to run transactions
 * @constant CFTBatteryStatusPluggedIn Card reader running off AC power
 * @discussion Status of battery in card readers that contain a rechargable battery
 * Added in 4.0.0
 */
typedef NS_ENUM(NSInteger, CFTBatteryStatus) {
    CFTBatteryStatusUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTBatteryStatusLow NS_SWIFT_NAME(low) = 1,
    CFTBatteryStatusNominal NS_SWIFT_NAME(nominal) = 2,
    CFTBatteryStatusPluggedIn NS_SWIFT_NAME(pluggedIn) = 3
};

/*!
 * @typedef CFTCardReaderType
 * @brief Card reader type
 * @constant CFTCardReaderTypeUnknown Unknown reader
 * @constant CFTCardReaderTypeAudioJack Audio jack reader type
 * @constant CFTCardReaderTypeBluetooth Bluetooth reader type
 * @discussion Added in 4.0.0
 */
typedef NS_ENUM(NSInteger, CFTCardReaderType) {
    CFTCardReaderTypeUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTCardReaderTypeAudioJack NS_SWIFT_NAME(audioJack) = 1,
    CFTCardReaderTypeBluetooth NS_SWIFT_NAME(bluetooth) = 2
};

/*!
 * @typedef CFTCardReaderStatus
 * @brief Card reader status
 * @constant CFTCardReaderStatusAvailable Available reader
 * @constant CFTCardReaderStatusConnected Currently connected reader
 * @discussion Added in 4.1.0
 */
typedef NS_ENUM(NSInteger, CFTCardReaderStatus) {
    CFTCardReaderStatusAvailable NS_SWIFT_NAME(available) = 0,
    CFTCardReaderStatusConnected NS_SWIFT_NAME(connected) = 1
};

/*!
 * @typedef CFTReaderUtilitiesSessionStatus
 * @brief Utilities session status
 * @constant CFTUtilitiesSessionStatusOpen The utilities session is open
 * @constant CFTUtilitiesSessionStatusClosed The utilities session is closed
 * @discussion Added in 4.1.0
 */
typedef NS_ENUM(NSInteger, CFTReaderUtilitiesSessionStatus) {
    CFTReaderUtilitiesSessionStatusOpen NS_SWIFT_NAME(open) = 0,
    CFTReaderUtilitiesSessionStatusClosed NS_SWIFT_NAME(closed) = 1
};

