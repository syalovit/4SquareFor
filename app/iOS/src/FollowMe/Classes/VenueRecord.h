//
//  VenueRecord.h
//  FollowMe
//
//  Created by yalo on 7/10/10.
//  Copyright 2010 Deductive Systems Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface VenueRecord : NSObject
{
	NSDictionary *venueDataDict;
	float geolat, geolong;

}

@property (nonatomic, assign) float geolat, geolong;
@property (nonatomic, assign) NSDictionary *venueDataDict;


@end
