//
//  LocationTableViewController.h
//
//  Created by yalo on 7/10/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "HTTPRiot/HTTPRiot.h"
#import "HTTPRiot/HRResponseDelegate.h"

@protocol FoursquareCallback <NSObject>
@required
- (void) callback:(BOOL) status resource:(id) resource;
@end


@interface Foursquare :  NSObject<HRResponseDelegate> {
}



+ (void)listCities:(NSObject *)callback;

+ (void)cityNearestLatitude:(NSString *)geoLat 
				  longitude:(NSString *)geoLong 
				   callback:(NSObject *)callback;

+ (void)switchToCity:(NSNumber *)cityId 
			callback:(NSObject *)callback;

+ (void)recentFriendCheckinsNearLatitude:(NSNumber *)geoLat
							   longitude:(NSNumber *)geoLong
								callback:(NSObject *)callback;

+ (void)checkinAtVenueId:(NSString *)venueId 
			   venueName:(NSString *)venueName 
				   shout:(NSString *)shout 
			 showFriends:(BOOL)showFriends 
			   sendTweet:(BOOL)sendTweet
			tellFacebook:(BOOL)tellFacebook
				latitude:(NSString *)geolat
			   longitude:(NSString *)geolong
				callback:(NSObject *)callback;

+ (void)checkinHistoryWithLimit:(NSNumber *)limit 
					   callback:(NSObject *)callback;

+ (void)detailForUser:(NSNumber *)userId 
		   showBadges:(BOOL)showBadges 
			showMayor:(BOOL)showMayor 
			 callback:(NSObject *)callback;

+ (void)friendsForUser:(NSNumber *)userId  			 
			  callback:(NSObject *)callback;

+ (void)venuesNearLatitude:(double)geoLat 
				 longitude:(double)geoLong
				  matching:(NSString *)keywordSearch  
					 limit:(NSNumber *)limit   
				  callback:(NSObject *)callback;

+ (void)detailForVenue:(NSNumber *)venueId
			  callback:(NSObject *)callback;

+ (void)addVenue:(NSString *)name 
		 address:(NSString *)address 
	 crossStreet:(NSString *)crossStreet 
			city:(NSString *)city
		   state:(NSString *)state
			 zip:(NSString *)zip
		  cityId:(NSNumber *)cityId
		   phone:(NSString *)phone
		callback:(NSObject *)callback;

+ (void)tipsNearLatitude:(NSString *)geoLat
			   longitude:(NSString *)geoLong
				   limit:(NSNumber *)limit 			
				callback:(NSObject *)callback;

+ (void)addTip:(NSString *)tip 
	  forVenue:(NSNumber *)venueId 
	  callback:(NSObject *)callback;

+ (void)addTodo:(NSString *)todo 
	   forVenue:(NSNumber *)venueId 		
	   callback:(NSObject *)callback;

+ (void)friendRequests:(NSObject *)callback;

+ (void)approveFriendRequest:(NSNumber *)userId 
					callback:(NSObject *)callback;

+ (void)denyFriendRequest:(NSNumber *)userId 
				 callback:(NSObject *)callback;

+ (void)sendFriendRequest:(NSNumber *)userId
				 callback:(NSObject *)callback;

+ (void)findFriendsByName:(NSString *)nameQuery
				 callback:(NSObject *)callback;

+ (void)findFriendsByPhone:(NSString *)phoneNumberQuery
				  callback:(NSObject *)callback;

+ (void)findFriendsByTwitter:(NSString *)twitterQuery
					callback:(NSObject *)callback;

+ (void)setPingsOff:(NSObject *)callback;

+ (void)setPingsOffFor:(NSNumber *)userId callback:(NSObject *)callback;

+ (void)setPingsOn:(NSObject *)callback;

+ (void)setPingsOnFor:(NSNumber *)userId callback:(NSObject *)callback;

+ (void)goodnight:(NSObject *)callback;

+ (void)test:(NSObject *)callback;

+ (NSString *)fullAddressForVenue:(NSDictionary *)venueDict;




@end
