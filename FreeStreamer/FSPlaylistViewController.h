/*
 * This file is part of the FreeStreamer project,
 * (C)Copyright 2011 Matias Muhonen <mmu@iki.fi>
 * See the file ''LICENSE'' for using the code.
 */

#import <UIKit/UIKit.h>
#import "MMAdView.h"
#import "FSAppDelegate.h"

#define MILLENNIAL_IPHONE_AD_VIEW_FRAME CGRectMake(0, 0, 320, 50)
#define MILLENNIAL_IPAD_AD_VIEW_FRAME CGRectMake(0, 0, 728, 90)
#define MILLENNIAL_AD_VIEW_FRAME ((UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) ? MILLENNIAL_IPAD_AD_VIEW_FRAME : MILLENNIAL_IPHONE_AD_VIEW_FRAME)

@class FSPlayerViewController;
@class FSParsePlaylistFeedRequest;

@interface FSPlaylistViewController : UITableViewController<UITableViewDataSource,UITableViewDelegate> {
    NSMutableArray *_playlistItems;
    UINavigationController *_navigationController;
    FSPlayerViewController *_playerViewController;
    FSParsePlaylistFeedRequest *_request;
}

@property (nonatomic,strong) NSMutableArray *playlistItems;
@property (nonatomic,strong) IBOutlet UINavigationController *navigationController;
@property (nonatomic,strong) IBOutlet FSPlayerViewController *playerViewController;

@end
