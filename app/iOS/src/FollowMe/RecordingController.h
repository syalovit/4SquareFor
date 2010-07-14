//
//  RecordingController.h
//
//  Created by yalo on 7/12/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>

@interface RecordingController : UIViewController {
	NSMutableDictionary *recordSetting;
	NSString * recorderFilePath;
	AVAudioRecorder * recorder;
}

- (void) startRecording;
- (void) stopRecording;

- (IBAction)listenUp:(UIView *)sender;
- (IBAction)listenDown:(UIView *)sender;

@end
