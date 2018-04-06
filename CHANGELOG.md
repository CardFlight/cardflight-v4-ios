### 4.4.0
* Added
  * CVV optional on keyed transactions
* Changed
  * Improved handling of declined dip transactions

### 4.3.3
* Changed
  * Improved reader connection error handling

### 4.3.2
* Fixed
  * Incorrect transaction result in some cases
  * Improved TLV parsing

### 4.3.1
* Added
  * Additional logging around reader connections
* Fixed
  * Issues around switching between bluetooth readers

### 4.3.0
* Added
  * Tokenize with existing Braintree customer ID
* Fixed
  * Reference ID on CFTHistoricalTransaction
  * Better handling of transactions with cards that can't be processed

### 4.2.0
* Added
  * Ability to create Historical Transactions from charge IDs
  * Additional field to Historical Transactions
  * NFC support for Bold B550
  * Utility class to allow reader connection outside of Transaction
* Changed
  * Improved log messages
* Fixed
  * Warning for accessing the wrong thread
  * Fallback behavior on Swift readers

### 4.1.0
* Added
  * Tokenization support
  * Reachability support
  * Defer and Resume transaction
  * Card Reader Connecting events
  * Card Reader Battery events
  * Strip architectures script (for App Store uploading)
* Changed
  * Transaction messaging format
* Fixed
  * Unsupported AID handling

### 4.0.3
* Fixed
  * referenceID crash on transactions

### 4.0.2
* Fixed
  * referenceId on approved transactions

### 4.0.1
* Added
  * referenceId to CFTHistoricalTransaction
  * support for A100 card readers
  * CFTInfo class for framework version information
* Changed
  * Removed mandatory card removal in chip transactions
* Fixed
  * Base URL points to correct location

### 4.0
* Initial Release
