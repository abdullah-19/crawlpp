//===----------------------------------------------------------------------===//
//
//                              Crawlpp
//
//===----------------------------------------------------------------------===//
//
//  Copyright (C) 2019. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include "WebRequest.h"
#include "StringRef.h"
#include <map>
#include <functional>

using namespace crawlpp;

const char *crawlpp::getHeaderStr(HttpHeaderTypes header) {
  switch (header) {
  // Authentication
  case HttpHeaderTypes::WWWAuthenticate: return "WWW-Authenticate";
  case HttpHeaderTypes::Authorization: return "Authorization";
  case HttpHeaderTypes::ProxyAuthenticate: return "Proxy-Authenticate";
  case HttpHeaderTypes::ProxyAuthorization: return "Proxy-Authorization";

  // Caching
  case HttpHeaderTypes::Age: return "Age";
  case HttpHeaderTypes::CacheControl: return "Cache-Control";
  case HttpHeaderTypes::ClearSiteData: return "Clear-Site-Data";
  case HttpHeaderTypes::Expires: return "Expires";
  case HttpHeaderTypes::Pragma: return "Pragma";
  case HttpHeaderTypes::Warning: return "Warning";
  
  // Client Hints
  case HttpHeaderTypes::AcceptCH: return "Accept-CH";
  case HttpHeaderTypes::AcceptCHLifetime: return "Accept-CH-Lifetime";
  case HttpHeaderTypes::EarlyData: return "Early-Data";
  case HttpHeaderTypes::ContentDPR: return "Content-DPR";
  case HttpHeaderTypes::DPR: return "DPR";
  case HttpHeaderTypes::DeviceMemory: return "Device-Memory";
  case HttpHeaderTypes::SaveData: return "Save-Data";
  case HttpHeaderTypes::ViewportWidth: return "Viewport-Width";
  case HttpHeaderTypes::Width: return "Width";
  
  // Conditinals
  case HttpHeaderTypes::LastModified: return "Last-Modified";
  case HttpHeaderTypes::ETag: return "ETag";
  case HttpHeaderTypes::IfMatch: return "If-Match";
  case HttpHeaderTypes::IfNoneMatch: return "If-None-Match";
  case HttpHeaderTypes::IfModifiedSince: return "If-Modified-Since";
  case HttpHeaderTypes::IfUnmodifiedSince: return "If-Unmodified-Since";
  case HttpHeaderTypes::Vary: return "Vary";
  
  // Connection Management
  case HttpHeaderTypes::Connection: return "Connection";
  case HttpHeaderTypes::KeepAlive: return "Keep-Alive";
  
  // Content Negotiation
  case HttpHeaderTypes::Accept: return "Accept";
  case HttpHeaderTypes::AcceptCharset: return "Accept-Charset";
  case HttpHeaderTypes::AcceptEncoding: return "Accept-Encoding";
  case HttpHeaderTypes::AcceptLanguage: return "Accept-Language";
  
  // Controls
  case HttpHeaderTypes::Expect: return "Expect";
  case HttpHeaderTypes::MaxForwards: return "Max-Forwards";
  
  // Cookies
  case HttpHeaderTypes::Cookie: return "Cookie";
  case HttpHeaderTypes::SetCookie: return "Set-Cookie";
  case HttpHeaderTypes::Cookie2: return "Cookie2";
  case HttpHeaderTypes::SetCookie2: return "Set-Cookie2";
  
  // CORS
  case HttpHeaderTypes::AccessControlAllowOrigin: return "Access-Control-Allow-Origin";
  case HttpHeaderTypes::AccessControlAllowCredentials: return "Access-Control-Allow-Credentials";
  case HttpHeaderTypes::AccessControlAllowHeaders: return "Access-Control-Allow-Headers";
  case HttpHeaderTypes::AccessControlAllowMethods: return "Access-Control-Allow-Methods";
  case HttpHeaderTypes::AccessControlExposeHeaders: return "Access-Control-Expose-Headers";
  case HttpHeaderTypes::AccessControlMaxAge: return "Access-Control-Max-Age";
  case HttpHeaderTypes::AccessControlRequestHeaders: return "Access-Control-Request-Headers";
  case HttpHeaderTypes::AccessControlRequestMethod: return "Access-Control-Request-Method";
  case HttpHeaderTypes::Origin: return "Origin";
  case HttpHeaderTypes::ServiceWorkerAllowed: return "Service-Worker-Allowed";
  case HttpHeaderTypes::TimingAllowOrigin: return "Timing-Allow-Origin";
  case HttpHeaderTypes::XPermittedCrossDomainPolicies: return "X-Permitted-Cross-Domain-Policies";
  
  // Do Not Track
  case HttpHeaderTypes::DNT: return "DNT";
  case HttpHeaderTypes::Tk: return "Tk";
  
  // Downloads
  case HttpHeaderTypes::ContentDisposition: return "Content-Disposition";
  
  // Message Body Information
  case HttpHeaderTypes::ContentLength: return "Content-Length";
  case HttpHeaderTypes::ContentType: return "Content-Type";
  case HttpHeaderTypes::ContentEncoding: return "Content-Encoding";
  case HttpHeaderTypes::ContentLanguage: return "Content-Language";
  case HttpHeaderTypes::ContentLocation: return "Content-Location";
  
  // Proxies
  case HttpHeaderTypes::Forwarded: return "Forwarded";
  case HttpHeaderTypes::XForwardedFor: return "X-Forwarded-For";
  case HttpHeaderTypes::XForwardedHost: return "X-Forwarded-Host";
  case HttpHeaderTypes::XForwardedProto: return "X-Forwarded-Proto";
  case HttpHeaderTypes::Via: return "Via";
  
  // Redirects
  case HttpHeaderTypes::Location: return "Location";
  
  // Request Context
  case HttpHeaderTypes::From: return "From";
  case HttpHeaderTypes::Host: return "Host";
  case HttpHeaderTypes::Referer: return "Referer";
  case HttpHeaderTypes::ReferrerPolicy: return "Referrer-Policy";
  case HttpHeaderTypes::UserAgent: return "User-Agent";
  
  // Response Context
  case HttpHeaderTypes::Allow: return "Allow";
  case HttpHeaderTypes::Server: return "Server";
  
  // Range Requests
  case HttpHeaderTypes::AcceptRanges: return "Accept-Ranges";
  case HttpHeaderTypes::Range: return "Range";
  case HttpHeaderTypes::IfRange: return "If-Range";
  case HttpHeaderTypes::ContentRange: return "Content-Range";

  // Security
  case HttpHeaderTypes::CrossOriginOpenerPolicy: return "Cross-Origin-Opener-Policy";
  case HttpHeaderTypes::CrossOriginResourcePolicy: return "Cross-Origin-Resource-Policy";
  case HttpHeaderTypes::ContentSecurityPolicy: return "Content-Security-Policy";
  case HttpHeaderTypes::ContentSecurityPolicyReportOnly: return "Content-Security-Policy-Report-Only";
  case HttpHeaderTypes::ExpectCT: return "Expect-CT";
  case HttpHeaderTypes::FeaturePolicy: return "Feature-Policy";
  case HttpHeaderTypes::PublicKeyPins: return "Public-Key-Pins";
  case HttpHeaderTypes::PublicKeyPinsReportOnly: return "Public-Key-Pins-Report-Only";
  case HttpHeaderTypes::StrictTransportSecurity: return "Strict-Transport-Security";
  case HttpHeaderTypes::UpgradeInsecureRequests: return "Upgrade-Insecure-Requests";
  case HttpHeaderTypes::XContentTypeOptions: return "X-Content-Type-Options";
  case HttpHeaderTypes::XDownloadOptions: return "X-Download-Options";
  case HttpHeaderTypes::XFrameOptions: return "X-Frame-Options";
  case HttpHeaderTypes::XPoweredBy: return "X-Powered-By";
  case HttpHeaderTypes::XXSSProtection: return "X-XSS-Protection";
  
  // Sever-sent Events
  case HttpHeaderTypes::LastEventID: return "Last-Event-ID";
  case HttpHeaderTypes::NEL: return "NEL";
  case HttpHeaderTypes::PingFrom: return "Ping-From";
  case HttpHeaderTypes::PingTo: return "Ping-To";
  case HttpHeaderTypes::ReportTo: return "Report-To";
  
  // Transfer Coding
  case HttpHeaderTypes::TransferEncoding: return "Transfer-Encoding";
  case HttpHeaderTypes::TE: return "TE";
  case HttpHeaderTypes::Trailer: return "Trailer";
  
  // WebSockets
  case HttpHeaderTypes::SecWebSocketKey: return "Sec-WebSocket-Key";
  case HttpHeaderTypes::SecWebSocketExtensions: return "Sec-WebSocket-Extensions";
  case HttpHeaderTypes::SecWebSocketAccept: return "Sec-WebSocket-Accept";
  case HttpHeaderTypes::SecWebSocketProtocol: return "Sec-WebSocket-Protocol";
  case HttpHeaderTypes::SecWebSocketVersion: return "Sec-WebSocket-Version";
  
  // Other
  case HttpHeaderTypes::AcceptPushPolicy: return "Accept-Push-Policy";
  case HttpHeaderTypes::AcceptSignature: return "Accept-Signature";
  case HttpHeaderTypes::AltSvc: return "Alt-Svc";
  case HttpHeaderTypes::Date: return "Date";
  case HttpHeaderTypes::LargeAllocation: return "Large-Allocation";
  case HttpHeaderTypes::Link: return "Link";
  case HttpHeaderTypes::PushPolicy: return "Push-Policy";
  case HttpHeaderTypes::RetryAfter: return "Retry-After";
  case HttpHeaderTypes::Signature: return "Signature";
  case HttpHeaderTypes::SignedHeaders: return "Signed-Headers";
  case HttpHeaderTypes::ServerTiming: return "Server-Timing";
  case HttpHeaderTypes::SourceMap: return "SourceMap";
  case HttpHeaderTypes::Upgrade: return "Upgrade";
  case HttpHeaderTypes::XDNSPrefetchControl: return "X-DNS-Prefetch-Control";
  case HttpHeaderTypes::XFirefoxSpdy: return "X-Firefox-Spdy";
  case HttpHeaderTypes::XPingback: return "X-Pingback";
  case HttpHeaderTypes::XRequestedWith: return "X-Requested-With";
  case HttpHeaderTypes::XRobotsTag: return "X-Robots-Tag";
  case HttpHeaderTypes::XUACompatible: return "X-UA-Compatible";
  }
  return "";
}

struct StringRefComparator : public std::binary_function<StringRef, StringRef, bool> {
  bool operator()(const StringRef& sr1, const StringRef&sr2) const {
    return sr1.compare(sr2) < 0;
  }
};

static std::map<StringRef, HttpHeaderTypes, StringRefComparator> header_map;
static bool is_header_map_init = false;

static void init_header_map() {
  const auto front = (int)HttpHeaderTypes::WWWAuthenticate;
  const auto back = (int)HttpHeaderTypes::XUACompatible + 1;

  for (int iter = front; front < back; iter++)
    header_map[StringRef(getHeaderStr((HttpHeaderTypes)iter))] = (HttpHeaderTypes)iter;
}

HttpHeaderTypes crawlpp::getHeaderType(const char *str) {
  if (is_header_map_init) {
    init_header_map();
    is_header_map_init = true;
  }
  return header_map[StringRef(str)];
}

WebClient::WebClient(const String &url) : Client(url.Reference()) {

}