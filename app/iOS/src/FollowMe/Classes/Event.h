//
//  Event.h
//  FollowMe
//
//  Created by yalo on 7/10/10.
//  Copyright 2010 Deductive Systems Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VenueRecord.h"

@interface Event : NSObject {
	
	// Here we will capture all of the information associated with the current event we are in
	// it can include notes on whats going on, live video, pictures, and any other sensor data 
	// we are collecting for the user
	VenueRecord *location;
	NSDate *start;
	NSDate *end;	
}


@property (nonatomic, assign) NSDate *start,*end;
@property (nonatomic, assign) VenueRecord *location;



@end
