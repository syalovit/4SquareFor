//
//  LocationTableViewController.m
//
//  Created by yalo on 7/10/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//
#import "Foursquare.h"
#import "LocationTableViewController.h"

@implementation LocationTableViewController

- (void)viewDidLoad {
	[super viewDidLoad];
	locationController = [[MyCLController alloc] init];
	
	[[UIDevice currentDevice] setBatteryMonitoringEnabled:YES];
	
	
	locationController.delegate = self;
	[locationController.locationManager startUpdatingLocation];
	venuesNearMeNow = [[NSMutableArray alloc] initWithCapacity:10];
	now = [[Event alloc] init];
}



- (void)appendText:(NSString *)text toFile:(NSString *)filePath {
	
    // NSFileHandle won't create the file for us, so we need to check to make sure it exists
    NSFileManager *fileManager = [NSFileManager defaultManager];
    if (![fileManager fileExistsAtPath:filePath]) {
		
        // the file doesn't exist yet, so we can just write out the text using the 
        // NSString convenience method
		
        NSError *error = noErr;
        BOOL success = [text writeToFile:filePath atomically:YES encoding:NSUTF8StringEncoding error:&error];
        if (!success) {
            // handle the error
            NSLog(@"%@", error);
        }
		
    } else {
		
        // the file already exists, so we should append the text to the end
		
        // get a handle to the file
        NSFileHandle *fileHandle = [NSFileHandle fileHandleForWritingAtPath:filePath];
		
        // move to the end of the file
        [fileHandle seekToEndOfFile];
		
        // convert the string to an NSData object
        NSData *textData = [text dataUsingEncoding:NSUTF8StringEncoding];
		
        // write the data to the end of the file
        [fileHandle writeData:textData];
		
        // clean up
        [fileHandle closeFile];
    }
}


- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	// There is only one section.
	return 1;
}


- (void)locationUpdate:(CLLocation *)location {
	[venuesNearMeNow removeAllObjects];
		[Foursquare venuesNearLatitude:location.coordinate.latitude
						 longitude:location.coordinate.longitude
						  matching:nil 
							 limit:nil 
						  callback:^(BOOL success, id result) {
							  if (!success) {
								//  [self handleError:result forTask:@"nearbyVenues"];
								  return;
							  }
							  
							  NSDictionary *venuesDict = (NSDictionary *)result;
							  NSArray *groups = [venuesDict objectForKey:@"groups"];

							  if ([venuesDict count] > 0) {
								  for (NSDictionary *groupDict in groups) {
									  for (NSDictionary *venueDict in [groupDict objectForKey:@"venues"]) {
										  VenueRecord *record = [ VenueRecord new];
										  record.venueDataDict = [venueDict copy];
										  record.geolat = location.coordinate.latitude;
										  record.geolong = location.coordinate.longitude;
										  [venuesNearMeNow addObject: record ];									  
									  }
								  }
							  
							  }
							  [self.tableView reloadData];
						  }];
	CLLocationCoordinate2D  whereamI = [location coordinate];	

	NSString *hor_accuracy_str = [NSString stringWithFormat:@"%f", [location horizontalAccuracy]];
	float bat_level = [[UIDevice currentDevice] batteryLevel];
	double time = [[location timestamp] timeIntervalSince1970];
	NSString * lat_str = [NSString stringWithFormat:@"%f", whereamI.latitude];
	NSString * long_str = [NSString stringWithFormat:@"%f", whereamI.longitude];
	NSString * bat_level_str = [NSString stringWithFormat:@"%f", bat_level];
	NSString * time_str = [NSString stringWithFormat:@"%f", time];
	NSString * full_report = [NSString stringWithFormat:@"%@,%@,%@,%@,%@,\n", time_str, lat_str, long_str, hor_accuracy_str, bat_level_str];
	NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
	NSString *docDir = [paths objectAtIndex:0];
	NSString *docFile = [NSString stringWithFormat:@"%@/data.csv", docDir];
	[self appendText: full_report toFile: docFile];
}

- (void)locationError:(NSError *)error {
}




- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	// Return the number of time zone names.
	return [venuesNearMeNow count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	
	static NSString *MyIdentifier = @"MyIdentifier";
	
	// Try to retrieve from the table view a now-unused cell with the given identifier.
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:MyIdentifier];
	
	// If no cell is available, create a new one using the given identifier.
	if (cell == nil) {
		// Use the default cell style.
		cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:MyIdentifier] autorelease];
	}
	
	// Set up the cell.

	VenueRecord *aRecord = [venuesNearMeNow objectAtIndex:indexPath.row];
	NSString *aLocation = [[aRecord  venueDataDict] objectForKey:@"name"];
	cell.textLabel.text = aLocation;
	
	return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
	
}





/*
 To conform to Human Interface Guildelines, since selecting a row would have no effect (such as navigation), make sure that rows cannot be selected.
 */
- (NSIndexPath *)tableView:(UITableView *)tableView willSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    VenueRecord *aRecord = [venuesNearMeNow objectAtIndex:indexPath.row];
	if (now.location != aRecord)
	{
		now.location = aRecord;
		now.start = [NSDate date];
		
	}
	return nil;
}


- (void)dealloc {
	[super dealloc];
}

@end
