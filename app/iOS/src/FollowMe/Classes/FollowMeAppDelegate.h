//
//  FollowMeAppDelegate.h
//
//  Created by yalo on 7/11/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//


#import <UIKit/UIKit.h>

@interface FollowMeAppDelegate : NSObject <UIApplicationDelegate> {
	UIWindow *window;
	UITabBarController *tabBarController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet UITabBarController *tabBarController;

@end
