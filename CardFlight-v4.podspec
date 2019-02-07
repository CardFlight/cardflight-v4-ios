Pod::Spec.new do |s|
  s.name                      = 'CardFlight-v4'
  s.version                   = '4.6.3'
  s.summary                   = 'CardFlight mobile payments SDK'

  s.description               = <<-DESC
CardFlight mobile payments SDK for accepting credit card payments from with your application. Contact sales@cardflight.com for more information.
                       DESC

  s.homepage                  = 'https://cardflight.com'
  s.license                   = {
                                :type => 'commercial',
                                :text => 'Copyright 2018 Cardflight, Inc. All rights reserved.'
                              }
  s.author                    = { 'CardFlight' => 'support@cardflight.com' }
  s.source                    = { :git => 'https://github.com/CardFlight/cardflight-v4-ios.git', :tag => "v#{s.version}" }
  s.social_media_url          = 'https://twitter.com/cardflight'

  s.ios.deployment_target     = '8.0'
  s.requires_arc              = true

  s.source_files              = 'CardFlight.framework/Headers/*.h'
  s.public_header_files       = 'CardFlight.framework/Headers/*.h'
  s.vendored_frameworks       = 'CardFlight.framework'

  s.frameworks                = 'AVFoundation', 'AudioToolbox', 'CoreAudio', 'CoreBluetooth', 'MediaPlayer', 'ExternalAccessory'

end
