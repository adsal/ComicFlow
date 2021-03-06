//  Copyright (C) 2010-2014 Pierre-Olivier Latour <info@pol-online.net>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#import "GCDWebUploader.h"
#import "GCDWebServerConnection.h"

@class WebServer;

@protocol WebServerDelegate <NSObject>
- (void) webServerDidConnect:(WebServer*)server;
- (void) webServerDidUploadComic:(WebServer*)server;
- (void) webServerDidDownloadComic:(WebServer*)server;
- (void) webServerDidUpdate:(WebServer*)server;
- (void) webServerDidDisconnect:(WebServer*)server;
@end

@interface WebServer : GCDWebUploader <GCDWebUploaderDelegate> {
@private
  id<WebServerDelegate> _serverDelegate;
}
@property(nonatomic, assign) id<WebServerDelegate> serverDelegate;
@end

@interface WebServerConnection : GCDWebServerConnection
@end
