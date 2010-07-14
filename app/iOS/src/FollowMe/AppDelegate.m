//
//  AppDelegate.m
//
//  Created by yalo on 7/13/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

@synthesize window;
@synthesize tabBarController;

- (void)dealloc {
	[tabBarController release];
	[window release];
	[super dealloc];
}

- (void)applicationDidFinishLaunching:(UIApplication *)application {	
	// Add the tab bar controller's current view as a subview of the window
	[window addSubview:tabBarController.view];
}

- (void)applicationWillTerminate:(UIApplication *)application {
}


@end
