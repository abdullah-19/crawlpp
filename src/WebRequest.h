//===----------------------------------------------------------------------===//
//
//                              Crawlpp
//
//===----------------------------------------------------------------------===//
//
//  Copyright (C) 2019. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _WEBREQUEST_
#define _WEBREQUEST_

#include "String.h"
#include "StringBuilder.h"
#include <cpphttplib/httplib.h>

namespace crawlpp {

/// https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers
typedef enum class _http_header_ {
  // Authentication
  WWWAuthenticate,
  Authorization,
  ProxyAuthenticate,
  ProxyAuthorization,
  // Caching
  Age,
  CacheControl,
  ClearSiteData,
  Expires,
  Pragma,
  Warning,
  // Client Hints
  AcceptCH,
  AcceptCHLifetime,
  EarlyData,
  ContentDPR,
  DPR,
  DeviceMemory,
  SaveData,
  ViewportWidth,
  Width,
  // Conditinals
  LastModified,
  ETag,
  IfMatch,
  IfNoneMatch,
  IfModifiedSince,
  IfUnmodifiedSince,
  Vary,
  // Connection Management
  Connection,
  KeepAlive,
  // Content Negotiation
  Accept,
  AcceptCharset,
  AcceptEncoding,
  AcceptLanguage,
  // Controls
  Expect,
  MaxForwards,
  // Cookies
  Cookie,
  SetCookie,
  Cookie2,
  SetCookie2,
  // CORS
  AccessControlAllowOrigin,
  AccessControlAllowCredentials,
  AccessControlAllowHeaders,
  AccessControlAllowMethods,
  AccessControlExposeHeaders,
  AccessControlMaxAge,
  AccessControlRequestHeaders,
  AccessControlRequestMethod,
  Origin,
  ServiceWorkerAllowed,
  TimingAllowOrigin,
  XPermittedCrossDomainPolicies,
  // Do Not Track
  DNT,
  Tk,
  // Downloads
  ContentDisposition,
  // Message Body Information
  ContentLength,
  ContentType,
  ContentEncoding,
  ContentLanguage,
  ContentLocation,
  // Proxies
  Forwarded,
  XForwardedFor,
  XForwardedHost,
  XForwardedProto,
  Via,
  // Redirects
  Location,
  // Request Context
  From,
  Host,
  Referer,
  ReferrerPolicy,
  UserAgent,
  // Response Context
  Allow,
  Server,
  // Range Requests
  AcceptRanges,
  Range,
  IfRange,
  ContentRange,
  // Security
  CrossOriginOpenerPolicy,
  CrossOriginResourcePolicy,
  ContentSecurityPolicy,
  ContentSecurityPolicyReportOnly,
  ExpectCT,
  FeaturePolicy,
  PublicKeyPins,
  PublicKeyPinsReportOnly,
  StrictTransportSecurity,
  UpgradeInsecureRequests,
  XContentTypeOptions,
  XDownloadOptions,
  XFrameOptions,
  XPoweredBy,
  XXSSProtection,
  // Sever-sent Events
  LastEventID,
  NEL,
  PingFrom,
  PingTo,
  ReportTo,
  // Transfer Coding
  TransferEncoding,
  TE,
  Trailer,
  // WebSockets
  SecWebSocketKey,
  SecWebSocketExtensions,
  SecWebSocketAccept,
  SecWebSocketProtocol,
  SecWebSocketVersion,
  // Other
  AcceptPushPolicy,
  AcceptSignature,
  AltSvc,
  Date,
  LargeAllocation,
  Link,
  PushPolicy,
  RetryAfter,
  Signature,
  SignedHeaders,
  ServerTiming,
  SourceMap,
  Upgrade,
  XDNSPrefetchControl,
  XFirefoxSpdy,
  XPingback,
  XRequestedWith,
  XRobotsTag,
  XUACompatible,
} HttpHeaderTypes;

const char *getHeaderStr(HttpHeaderTypes header);
HttpHeaderTypes getHeaderType(const char *str);

/// WebClient Wrapper using httplib
/// https://github.com/yhirose/cpp-httplib
class WebClient {
  httplib::Client Client;
  httplib::Headers Headers;

public:
  WebClient(const String &url);

  static WebClient *Create(const String &url) { return new WebClient(url); }
};

} // namespace crawlpp

#endif