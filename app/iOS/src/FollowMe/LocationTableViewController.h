//
//  LocationTableViewController.h
//
//  Created by yalo on 7/10/10.
//  Copyright 2010 Deductive Systems Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "MyCLController.h"
#import "Event.h"
#import "VenueRecord.h"

@interface LocationTableViewController : UITableViewController<MyCLControllerDelegate> {
	NSMutableArray *venuesNearMeNow;
	Event *now;
	MyCLController *locationController;

}

- (void)locationUpdate:(CLLocation *)location; 
- (void)locationError:(NSError *)error;
- (void)appendText:(NSString *)text toFile:(NSString *)filePath;

- (IBAction)listenUp:(UIView *)sender;
- (IBAction)listenDown:(UIView *)sender;


@end