# cardflight-v4-ios
CardFlight SDK Version 4 for iOS

# How to Install

## CocoaPods

[CocoaPods](http://www.cocoapods.org/) is the recommended method of installing CardFlight.

##### Podfile

```ruby
platform :ios, '8.0'
pod "CardFlight-v4"
```

## Github

1. Clone this repo into your project.
```
git clone https://github.com/CardFlight/cardflight-v4-ios
```

2. Add the framework to your Xcode project
```
CardFlight.framework
```

3. Update the plist for the target that will use the library
```
key - Privacy - Microphone Usage Description
value - Microphone access is required for the app to communicate with audio jack based card readers
key - Privacy - Bluetooth Peripheral Usage Description
value - Bluetooth access is required for the app to communicate with bluetooth based card readers
```
4. (For Bold series reader only) Add Bold accessory protocol string to plist
```
key - Supported external accessory protocols
value - com.miura.shuttle
value - com.cardflight.bold
```


# Documentation

Full documentation can be found [here](http://docs.cardflight.com/sdk_documentation/).
