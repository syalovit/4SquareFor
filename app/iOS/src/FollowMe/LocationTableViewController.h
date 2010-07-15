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
#import "Foursquare.h"
@interface LocationTableViewController : UITableViewController<MyCLControllerDelegate,FoursquareCallback> {
	NSMutableArray *venuesNearMeNow;
	Event *now;
	MyCLController *locationController;

}

-(void) callback:(BOOL) success result:(id) result;
- (void)locationUpdate:(CLLocation *)location; 
- (void)locationError:(NSError *)error;
- (void)appendText:(NSString *)text toFile:(NSString *)filePath;

- (IBAction)listenUp:(UIView *)sender;
- (IBAction)listenDown:(UIView *)sender;


@end