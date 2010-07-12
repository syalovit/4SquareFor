//
//  FollowMeAppDelegate.m
//
//  Created by yalo on 7/11/10.
//  Copyright 2010 Deductive Systems Inc. All rights reserved.
//

#import "FollowMeAppDelegate.h"
#import "LocationTableViewController.h"
@implementation FollowMeAppDelegate

@synthesize window;
@synthesize viewController;


- (void)applicationDidFinishLaunching:(UIApplication *)application {    
    
	// Create the navigation and view controllers.
	LocationTableViewController *rootViewController = [[LocationTableViewController alloc] initWithStyle:UITableViewStylePlain];
	UINavigationController *aNavigationController = [[UINavigationController alloc] initWithRootViewController:rootViewController];
	self.viewController = aNavigationController;
	[rootViewController release];
	[aNavigationController release];
    // Override point for customization after app launch    
    [window addSubview:viewController.view];
    [window makeKeyAndVisible];
}


- (void)dealloc {
    [viewController release];
    [window release];
    [super dealloc];
}


@end
