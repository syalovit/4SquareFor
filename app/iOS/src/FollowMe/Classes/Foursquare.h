//
//  LocationTableViewController.h
//
//  Created by yalo on 7/10/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "HTTPRiot/HTTPRiot.h"
#import "HTTPRiot/HRResponseDelegate.h"
typedef void(^FoursquareCallback)(BOOL success, id result);

@interface Foursquare :  NSObject<HRResponseDelegate> {
}



+ (void)listCities:(FoursquareCallback)callback;

+ (void)cityNearestLatitude:(NSString *)geoLat 
				  longitude:(NSString *)geoLong 
				   callback:(FoursquareCallback)callback;

+ (void)switchToCity:(NSNumber *)cityId 
			callback:(FoursquareCallback)callback;

+ (void)recentFriendCheckinsNearLatitude:(NSNumber *)geoLat
							   longitude:(NSNumber *)geoLong
								callback:(FoursquareCallback)callback;

+ (void)checkinAtVenueId:(NSString *)venueId 
			   venueName:(NSString *)venueName 
				   shout:(NSString *)shout 
			 showFriends:(BOOL)showFriends 
			   sendTweet:(BOOL)sendTweet
			tellFacebook:(BOOL)tellFacebook
				latitude:(NSString *)geolat
			   longitude:(NSString *)geolong
				callback:(FoursquareCallback)callback;

+ (void)checkinHistoryWithLimit:(NSNumber *)limit 
					   callback:(FoursquareCallback)callback;

+ (void)detailForUser:(NSNumber *)userId 
		   showBadges:(BOOL)showBadges 
			showMayor:(BOOL)showMayor 
			 callback:(FoursquareCallback)callback;

+ (void)friendsForUser:(NSNumber *)userId  			 
			  callback:(FoursquareCallback)callback;

+ (void)venuesNearLatitude:(double)geoLat 
				 longitude:(double)geoLong
				  matching:(NSString *)keywordSearch  
					 limit:(NSNumber *)limit   
				  callback:(FoursquareCallback)callback;

+ (void)detailForVenue:(NSNumber *)venueId
			  callback:(FoursquareCallback)callback;

+ (void)addVenue:(NSString *)name 
		 address:(NSString *)address 
	 crossStreet:(NSString *)crossStreet 
			city:(NSString *)city
		   state:(NSString *)state
			 zip:(NSString *)zip
		  cityId:(NSNumber *)cityId
		   phone:(NSString *)phone
		callback:(FoursquareCallback)callback;

+ (void)tipsNearLatitude:(NSString *)geoLat
			   longitude:(NSString *)geoLong
				   limit:(NSNumber *)limit 			
				callback:(FoursquareCallback)callback;

+ (void)addTip:(NSString *)tip 
	  forVenue:(NSNumber *)venueId 
	  callback:(FoursquareCallback)callback;

+ (void)addTodo:(NSString *)todo 
	   forVenue:(NSNumber *)venueId 		
	   callback:(FoursquareCallback)callback;

+ (void)friendRequests:(FoursquareCallback)callback;

+ (void)approveFriendRequest:(NSNumber *)userId 
					callback:(FoursquareCallback)callback;

+ (void)denyFriendRequest:(NSNumber *)userId 
				 callback:(FoursquareCallback)callback;

+ (void)sendFriendRequest:(NSNumber *)userId
				 callback:(FoursquareCallback)callback;

+ (void)findFriendsByName:(NSString *)nameQuery
				 callback:(FoursquareCallback)callback;

+ (void)findFriendsByPhone:(NSString *)phoneNumberQuery
				  callback:(FoursquareCallback)callback;

+ (void)findFriendsByTwitter:(NSString *)twitterQuery
					callback:(FoursquareCallback)callback;

+ (void)setPingsOff:(FoursquareCallback)callback;

+ (void)setPingsOffFor:(NSNumber *)userId callback:(FoursquareCallback)callback;

+ (void)setPingsOn:(FoursquareCallback)callback;

+ (void)setPingsOnFor:(NSNumber *)userId callback:(FoursquareCallback)callback;

+ (void)goodnight:(FoursquareCallback)callback;

+ (void)test:(FoursquareCallback)callback;

+ (NSString *)fullAddressForVenue:(NSDictionary *)venueDict;




@end
