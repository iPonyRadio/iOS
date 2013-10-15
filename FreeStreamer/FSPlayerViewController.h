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

@class FSPlaylistItem;
@class FSAudioController;

@interface FSPlayerViewController : UIViewController {
    FSPlaylistItem *_selectedPlaylistItem;
    
    // State
    BOOL _paused;
    BOOL _shouldStartPlaying;
    
    
    // UI
    UISlider *_progressSlider;
    NSTimer *_progressUpdateTimer;
    UIActivityIndicatorView *_activityIndicator;
    UILabel *_statusLabel;
    UILabel *_currentPlaybackTime;
    NSTimer *_playbackSeekTimer;
    double _seekToPoint;
}

@property (nonatomic,assign) BOOL shouldStartPlaying;
@property (nonatomic,strong) FSPlaylistItem *selectedPlaylistItem;

@property (nonatomic,strong) IBOutlet UIButton *playButton;
@property (nonatomic,strong) IBOutlet UIButton *pauseButton;
@property (nonatomic,strong) IBOutlet UISlider *progressSlider;
@property (nonatomic,strong) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (nonatomic,strong) IBOutlet UILabel *statusLabel;
@property (nonatomic,strong) IBOutlet UILabel *currentPlaybackTime;

@property (nonatomic,strong) IBOutlet FSAudioController *audioController;

- (void)audioStreamStateDidChange:(NSNotification *)notification;  
- (IBAction)play:(id)sender;
- (IBAction)pause:(id)sender;
- (IBAction)seek:(id)sender;

@end
