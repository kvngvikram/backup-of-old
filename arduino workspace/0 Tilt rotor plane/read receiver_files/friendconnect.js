window.google = window["google"] || {};google.friendconnect = google.friendconnect_ || {};if (!window['__ps_loaded__']) {/*http://www-a-fc-opensocial.googleusercontent.com/gadgets/js/rpc:core.util.js?c=1*/
window['___jsl'] = window['___jsl'] || {};(window['___jsl']['ci'] = (window['___jsl']['ci'] || [])).push({"rpc":{"commSwf":"//xpc.googleusercontent.com/gadgets/xpc.swf","passReferrer":"p2c:query","parentRelayUrl":"/rpc_relay.html"}});window['___jsl']=window['___jsl']||{};(window['___jsl']['ci'] = (window['___jsl']['ci'] || [])).push({"rpc":{"commSwf":"//xpc.googleusercontent.com/gadgets/xpc.swf","passReferrer":"p2c:query","parentRelayUrl":"/rpc_relay.html"}});
/* [start] feature=taming */
var safeJSON=window.safeJSON;
var tamings___=window.tamings___||[];
var bridge___;
var caja___=window.caja___;
var ___=window.___;;

/* [end] feature=taming */

/* [start] feature=gapi-globals */
var gapi=window.gapi||{};gapi.client=window.gapi&&window.gapi.client||{};
;
;

/* [end] feature=gapi-globals */

/* [start] feature=globals */
var gadgets=window.gadgets||{},shindig=window.shindig||{},osapi=window.osapi=window.osapi||{},google=window.google||{};
;
;

/* [end] feature=globals */

/* [start] feature=core.config.base */
window['___cfg'] = window['___cfg'] || window['___gcfg'];;
if(!window.gadgets["config"]){gadgets.config=function(){var f;
var h={};
var b={};
function c(j,l){for(var k in l){if(!l.hasOwnProperty(k)){continue
}if(typeof j[k]==="object"&&typeof l[k]==="object"){c(j[k],l[k])
}else{j[k]=l[k]
}}}function i(){var j=document.scripts||document.getElementsByTagName("script");
if(!j||j.length==0){return null
}var m;
if(f.u){for(var k=0;
!m&&k<j.length;
++k){var l=j[k];
if(l.src&&l.src.indexOf(f.u)==0){m=l
}}}if(!m){m=j[j.length-1]
}if(!m.src){return null
}return m
}function a(j){var k="";
if(j.nodeType==3||j.nodeType==4){k=j.nodeValue
}else{if(j.innerText){k=j.innerText
}else{if(j.innerHTML){k=j.innerHTML
}else{if(j.firstChild){var l=[];
for(var m=j.firstChild;
m;
m=m.nextSibling){l.push(a(m))
}k=l.join("")
}}}}return k
}function e(k){if(!k){return{}
}var j;
while(k.charCodeAt(k.length-1)==0){k=k.substring(0,k.length-1)
}try{j=(new Function("return ("+k+"\n)"))()
}catch(l){}if(typeof j==="object"){return j
}try{j=(new Function("return ({"+k+"\n})"))()
}catch(l){}return typeof j==="object"?j:{}
}function g(n){var p=window.___cfg;
if(p){c(n,p)
}var o=i();
if(!o){return
}var k=a(o);
var j=e(k);
if(f.f&&f.f.length==1){var m=f.f[0];
if(!j[m]){var l={};
l[f.f[0]]=j;
j=l
}}c(n,j)
}function d(o){for(var l in h){if(h.hasOwnProperty(l)){var n=h[l];
for(var m=0,k=n.length;
m<k;
++m){o(l,n[m])
}}}}return{register:function(l,k,j,m){var n=h[l];
if(!n){n=[];
h[l]=n
}n.push({validators:k||{},callback:j,callOnUpdate:m})
},get:function(j){if(j){return b[j]||{}
}return b
},init:function(k,j){f=window.___jsl||{};
c(b,k);
g(b);
var l=window.___config||{};
c(b,l);
d(function(q,p){var o=b[q];
if(o&&!j){var m=p.validators;
for(var n in m){if(m.hasOwnProperty(n)){if(!m[n](o[n])){throw new Error('Invalid config value "'+o[n]+'" for parameter "'+n+'" in component "'+q+'"')
}}}}if(p.callback){p.callback(b)
}})
},update:function(k,p){var o=(window.gapi&&window.gapi["config"]&&window.gapi["config"]["update"]);
if(!p&&o){o(k)
}var n=[];
d(function(q,j){if(k.hasOwnProperty(q)||(p&&b&&b[q])){if(j.callback&&j.callOnUpdate){n.push(j.callback)
}}});
b=p?{}:b||{};
c(b,k);
for(var m=0,l=n.length;
m<l;
++m){n[m](b)
}}}
}()
}else{gadgets.config=window.gadgets["config"];
gadgets.config.register=gadgets.config.register;
gadgets.config.get=gadgets.config.get;
gadgets.config.init=gadgets.config.init;
gadgets.config.update=gadgets.config.update
};;

/* [end] feature=core.config.base */

/* [start] feature=core.log */
gadgets.log=(function(){var e=1;
var a=2;
var f=3;
var c=4;
var d=function(i){b(e,i)
};
gadgets.warn=function(i){b(a,i)
};
gadgets.error=function(i){b(f,i)
};
gadgets.debug=function(i){};
gadgets.setLogLevel=function(i){h=i
};
function b(k,i){if(k<h||!g){return
}if(k===a&&g.warn){g.warn(i)
}else{if(k===f&&g.error){try{g.error(i)
}catch(j){}}else{if(g.log){g.log(i)
}}}}d.INFO=e;
d.WARNING=a;
d.NONE=c;
var h=e;
var g=window.console?window.console:window.opera?window.opera.postError:undefined;
return d
})();;
;

/* [end] feature=core.log */

/* [start] feature=gapi.util-globals */
gapi.util=window.gapi&&window.gapi.util||{};
;

/* [end] feature=gapi.util-globals */

/* [start] feature=core.config */
(function(){gadgets.config.EnumValidator=function(d){var c=[];
if(arguments.length>1){for(var b=0,a;
(a=arguments[b]);
++b){c.push(a)
}}else{c=d
}return function(f){for(var e=0,g;
(g=c[e]);
++e){if(f===c[e]){return true
}}return false
}
};
gadgets.config.RegExValidator=function(a){return function(b){return a.test(b)
}
};
gadgets.config.ExistsValidator=function(a){return typeof a!=="undefined"
};
gadgets.config.NonEmptyStringValidator=function(a){return typeof a==="string"&&a.length>0
};
gadgets.config.BooleanValidator=function(a){return typeof a==="boolean"
};
gadgets.config.LikeValidator=function(a){return function(c){for(var d in a){if(a.hasOwnProperty(d)){var b=a[d];
if(!b(c[d])){return false
}}}return true
}
}
})();;

/* [end] feature=core.config */

/* [start] feature=core.util.base */
gadgets.util=gadgets.util||{};
(function(){gadgets.util.makeClosure=function(d,f,e){var c=[];
for(var b=2,a=arguments.length;
b<a;
++b){c.push(arguments[b])
}return function(){var g=c.slice();
for(var k=0,h=arguments.length;
k<h;
++k){g.push(arguments[k])
}return f.apply(d,g)
}
};
gadgets.util.makeEnum=function(b){var c,a,d={};
for(c=0;
(a=b[c]);
++c){d[a]=a
}return d
}
})();;

/* [end] feature=core.util.base */

/* [start] feature=core.util.dom */
gadgets.util=gadgets.util||{};
(function(){var c="http://www.w3.org/1999/xhtml";
function b(f,e){var h=e||{};
for(var g in h){if(h.hasOwnProperty(g)){f[g]=h[g]
}}}function d(g,f){var e=["<",g];
var i=f||{};
for(var h in i){if(i.hasOwnProperty(h)){e.push(" ");
e.push(h);
e.push('="');
e.push(gadgets.util.escapeString(i[h]));
e.push('"')
}}e.push("></");
e.push(g);
e.push(">");
return e.join("")
}function a(f){var g="";
if(f.nodeType==3||f.nodeType==4){g=f.nodeValue
}else{if(f.innerText){g=f.innerText
}else{if(f.innerHTML){g=f.innerHTML
}else{if(f.firstChild){var e=[];
for(var h=f.firstChild;
h;
h=h.nextSibling){e.push(a(h))
}g=e.join("")
}}}}return g
}gadgets.util.createElement=function(f){var e;
if((!document.body)||document.body.namespaceURI){try{e=document.createElementNS(c,f)
}catch(g){}}return e||document.createElement(f)
};
gadgets.util.createIframeElement=function(g){var i=gadgets.util.createElement("iframe");
try{var e=d("iframe",g);
var f=gadgets.util.createElement(e);
if(f&&((!i)||((f.tagName==i.tagName)&&(f.namespaceURI==i.namespaceURI)))){i=f
}}catch(h){}b(i,g);
return i
};
gadgets.util.getBodyElement=function(){if(document.body){return document.body
}try{var f=document.getElementsByTagNameNS(c,"body");
if(f&&(f.length==1)){return f[0]
}}catch(e){}return document.documentElement||document
};
gadgets.util.getInnerText=function(e){return a(e)
}
})();;

/* [end] feature=core.util.dom */

/* [start] feature=core.util.event */
gadgets.util=gadgets.util||{};
(function(){gadgets.util.attachBrowserEvent=function(c,b,d,a){if(typeof c.addEventListener!="undefined"){c.addEventListener(b,d,a)
}else{if(typeof c.attachEvent!="undefined"){c.attachEvent("on"+b,d)
}else{gadgets.warn("cannot attachBrowserEvent: "+b)
}}};
gadgets.util.removeBrowserEvent=function(c,b,d,a){if(c.removeEventListener){c.removeEventListener(b,d,a)
}else{if(c.detachEvent){c.detachEvent("on"+b,d)
}else{gadgets.warn("cannot removeBrowserEvent: "+b)
}}}
})();;

/* [end] feature=core.util.event */

/* [start] feature=core.util.onload */
gadgets.util=gadgets.util||{};
(function(){var a=[];
gadgets.util.registerOnLoadHandler=function(b){a.push(b)
};
gadgets.util.runOnLoadHandlers=function(){for(var c=0,b=a.length;
c<b;
++c){a[c]()
}}
})();;

/* [end] feature=core.util.onload */

/* [start] feature=core.util.string */
gadgets.util=gadgets.util||{};
(function(){var a={0:false,10:true,13:true,34:true,39:true,60:true,62:true,92:true,8232:true,8233:true,65282:true,65287:true,65308:true,65310:true,65340:true};
function b(c,d){return String.fromCharCode(d)
}gadgets.util.escape=function(c,g){if(!c){return c
}else{if(typeof c==="string"){return gadgets.util.escapeString(c)
}else{if(typeof c==="Array"){for(var f=0,d=c.length;
f<d;
++f){c[f]=gadgets.util.escape(c[f])
}}else{if(typeof c==="object"&&g){var e={};
for(var h in c){if(c.hasOwnProperty(h)){e[gadgets.util.escapeString(h)]=gadgets.util.escape(c[h],true)
}}return e
}}}}return c
};
gadgets.util.escapeString=function(g){if(!g){return g
}var d=[],f,h;
for(var e=0,c=g.length;
e<c;
++e){f=g.charCodeAt(e);
h=a[f];
if(h===true){d.push("&#",f,";")
}else{if(h!==false){d.push(g.charAt(e))
}}}return d.join("")
};
gadgets.util.unescapeString=function(c){if(!c){return c
}return c.replace(/&#([0-9]+);/g,b)
}
})();;

/* [end] feature=core.util.string */

/* [start] feature=core.util.urlparams */
gadgets.util=gadgets.util||{};
(function(){var a=null;
function b(e){var f;
var c=e.indexOf("?");
var d=e.indexOf("#");
if(d===-1){f=e.substr(c+1)
}else{f=[e.substr(c+1,d-c-1),"&",e.substr(d+1)].join("")
}return f.split("&")
}gadgets.util.getUrlParameters=function(p){var d=typeof p==="undefined";
if(a!==null&&d){return a
}var l={};
var f=b(p||window.location.href);
var n=window.decodeURIComponent?decodeURIComponent:unescape;
for(var h=0,g=f.length;
h<g;
++h){var m=f[h].indexOf("=");
if(m===-1){continue
}var c=f[h].substring(0,m);
var o=f[h].substring(m+1);
o=o.replace(/\+/g," ");
try{l[c]=n(o)
}catch(k){}}if(d){a=l
}return l
};
gadgets.util.getUrlParameters()
})();;

/* [end] feature=core.util.urlparams */

/* [start] feature=gapi.util.getOrigin */
gapi.util.getOrigin=function(a){if(!a)return"";a=a.split("#")[0].split("?")[0];a=a.toLowerCase();0==a.indexOf("//")&&(a=window.location.protocol+a);/^[\w\-]*:\/\//.test(a)||(a=window.location.href);var b=a.substring(a.indexOf("://")+3),c=b.indexOf("/");-1!=c&&(b=b.substring(0,c));a=a.substring(0,a.indexOf("://"));if("http"!==a&&"https"!==a&&"chrome-extension"!==a&&"file"!==a)throw Error("Invalid URI scheme in origin");var c="",d=b.indexOf(":");if(-1!=d){var e=b.substring(d+1),b=b.substring(0,d);if("http"===
a&&"80"!==e||"https"===a&&"443"!==e)c=":"+e}return a+"://"+b+c};
;

/* [end] feature=gapi.util.getOrigin */

/* [start] feature=core.json */
if(window.JSON&&window.JSON.parse&&window.JSON.stringify){gadgets.json=(function(){var a=/___$/;
function b(d,e){var c=this[d];
return c
}return{parse:function(d){try{return window.JSON.parse(d)
}catch(c){return false
}},stringify:function(d){var h=window.JSON.stringify;
function f(e){return h.call(this,e,b)
}var g=(Array.prototype.toJSON&&h([{x:1}])==='"[{\\"x\\": 1}]"')?f:h;
try{return g(d,function(i,e){return !a.test(i)?e:void 0
})
}catch(c){return null
}}}
})()
};;
;
if(!(window.JSON&&window.JSON.parse&&window.JSON.stringify)){gadgets.json=function(){function f(n){return n<10?"0"+n:n
}Date.prototype.toJSON=function(){return[this.getUTCFullYear(),"-",f(this.getUTCMonth()+1),"-",f(this.getUTCDate()),"T",f(this.getUTCHours()),":",f(this.getUTCMinutes()),":",f(this.getUTCSeconds()),"Z"].join("")
};
var m={"\b":"\\b","\t":"\\t","\n":"\\n","\f":"\\f","\r":"\\r",'"':'\\"',"\\":"\\\\"};
function stringify(value){var a,i,k,l,r=/[\"\\\x00-\x1f\x7f-\x9f]/g,v;
switch(typeof value){case"string":return r.test(value)?'"'+value.replace(r,function(a){var c=m[a];
if(c){return c
}c=a.charCodeAt();
return"\\u00"+Math.floor(c/16).toString(16)+(c%16).toString(16)
})+'"':'"'+value+'"';
case"number":return isFinite(value)?String(value):"null";
case"boolean":case"null":return String(value);
case"object":if(!value){return"null"
}a=[];
if(typeof value.length==="number"&&!value.propertyIsEnumerable("length")){l=value.length;
for(i=0;
i<l;
i+=1){a.push(stringify(value[i])||"null")
}return"["+a.join(",")+"]"
}for(k in value){if(/___$/.test(k)){continue
}if(value.hasOwnProperty(k)){if(typeof k==="string"){v=stringify(value[k]);
if(v){a.push(stringify(k)+":"+v)
}}}}return"{"+a.join(",")+"}"
}return""
}return{stringify:stringify,parse:function(text){if(/^[\],:{}\s]*$/.test(text.replace(/\\["\\\/b-u]/g,"@").replace(/"[^"\\\n\r]*"|true|false|null|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?/g,"]").replace(/(?:^|:|,)(?:\s*\[)+/g,""))){return eval("("+text+")")
}return false
}}
}()
};;
gadgets.json.flatten=function(c){var d={};
if(c===null||c===undefined){return d
}for(var a in c){if(c.hasOwnProperty(a)){var b=c[a];
if(null===b||undefined===b){continue
}d[a]=(typeof b==="string")?b:gadgets.json.stringify(b)
}}return d
};;

/* [end] feature=core.json */

/* [start] feature=core.util */
gadgets.util=gadgets.util||{};
(function(){var b={};
var a={};
function c(d){b=d["core.util"]||{}
}if(gadgets.config){gadgets.config.register("core.util",null,c)
}gadgets.util.getFeatureParameters=function(d){return typeof b[d]==="undefined"?null:b[d]
};
gadgets.util.hasFeature=function(d){return typeof b[d]!=="undefined"
};
gadgets.util.getServices=function(){return a
}
})();;

/* [end] feature=core.util */

/* [start] feature=rpc */
gadgets.rpctx=gadgets.rpctx||{};
if(!gadgets.rpctx.wpm){gadgets.rpctx.wpm=function(){var e,d;
var c=true;
function b(h,j,g){if(typeof window.addEventListener!="undefined"){window.addEventListener(h,j,g)
}else{if(typeof window.attachEvent!="undefined"){window.attachEvent("on"+h,j)
}}if(h==="message"){window.___jsl=window.___jsl||{};
var i=window.___jsl;
i.RPMQ=i.RPMQ||[];
i.RPMQ.push(j)
}}function a(h,i,g){if(window.removeEventListener){window.removeEventListener(h,i,g)
}else{if(window.detachEvent){window.detachEvent("on"+h,i)
}}}function f(h){var i=gadgets.json.parse(h.data);
if(!i||!i.f){return
}gadgets.debug("gadgets.rpc.receive("+window.name+"): "+h.data);
var g=gadgets.rpc.getTargetOrigin(i.f);
if(c&&(typeof h.origin!=="undefined"?h.origin!==g:h.domain!==/^.+:\/\/([^:]+).*/.exec(g)[1])){gadgets.error("Invalid rpc message origin. "+g+" vs "+(h.origin||""));
return
}e(i,h.origin)
}return{getCode:function(){return"wpm"
},isParentVerifiable:function(){return true
},init:function(h,i){function g(k){var j=k&&k.rpc||{};
if(String(j.disableForceSecure)==="true"){c=false
}}gadgets.config.register("rpc",null,g);
e=h;
d=i;
b("message",f,false);
d("..",true);
return true
},setup:function(h,g){d(h,true);
return true
},call:function(h,k,j){var g=gadgets.rpc.getTargetOrigin(h);
var i=gadgets.rpc._getTargetWin(h);
if(g){window.setTimeout(function(){var l=gadgets.json.stringify(j);
gadgets.debug("gadgets.rpc.send("+window.name+"): "+l);
i.postMessage(l,g)
},0)
}else{if(h!=".."){gadgets.error("No relay set (used as window.postMessage targetOrigin), cannot send cross-domain message")
}}return true
}}
}()
};;

       gadgets.rpctx.ifpc = gadgets.rpctx.wpm;
    ;
if(!window.gadgets||!window.gadgets["rpc"]){gadgets.rpc=function(){var M="__cb";
var S="";
var T="__ack";
var f=500;
var G=10;
var b="|";
var u="callback";
var g="origin";
var r="referer";
var s="legacy__";
var q={};
var W={};
var D={};
var B={};
var z=0;
var l={};
var m={};
var d={};
var n={};
var E={};
var e=null;
var p=null;
var A=(window.top!==window.self);
var v=window.name;
var J=function(){};
var P=0;
var Y=1;
var a=2;
var x=window.console;
var V=x&&x.log&&function(ae){x.log(ae)
}||function(){};
var R=(function(){function ae(af){return function(){V(af+": call ignored")
}
}return{getCode:function(){return"noop"
},isParentVerifiable:function(){return true
},init:ae("init"),setup:ae("setup"),call:ae("call")}
})();
if(gadgets.util){d=gadgets.util.getUrlParameters()
}function K(){if(d.rpctx=="flash"){return gadgets.rpctx.flash
}if(d.rpctx=="rmr"){return gadgets.rpctx.rmr
}var ae=typeof window.postMessage==="function"?gadgets.rpctx.wpm:typeof window.postMessage==="object"?gadgets.rpctx.wpm:window.ActiveXObject?(gadgets.rpctx.flash?gadgets.rpctx.flash:(gadgets.rpctx.nix?gadgets.rpctx.nix:gadgets.rpctx.ifpc)):navigator.userAgent.indexOf("WebKit")>0?gadgets.rpctx.rmr:navigator.product==="Gecko"?gadgets.rpctx.frameElement:gadgets.rpctx.ifpc;
if(!ae){ae=R
}return ae
}function k(aj,ah){if(n[aj]){return
}var af=H;
if(!ah){af=R
}n[aj]=af;
var ae=E[aj]||[];
for(var ag=0;
ag<ae.length;
++ag){var ai=ae[ag];
ai.t=F(aj);
af.call(aj,ai.f,ai)
}E[aj]=[]
}var I=false,U=false;
function N(){if(U){return
}function ae(){I=true
}if(typeof window.addEventListener!="undefined"){window.addEventListener("unload",ae,false)
}else{if(typeof window.attachEvent!="undefined"){window.attachEvent("onunload",ae)
}}U=true
}function j(ae,ai,af,ah,ag){if(!B[ai]||B[ai]!==af){gadgets.error("Invalid gadgets.rpc token. "+B[ai]+" vs "+af);
J(ai,a)
}ag.onunload=function(){if(m[ai]&&!I){J(ai,Y);
gadgets.rpc.removeReceiver(ai)
}};
N();
ah=gadgets.json.parse(decodeURIComponent(ah))
}function Z(ak,af){if(ak&&typeof ak.s==="string"&&typeof ak.f==="string"&&ak.a instanceof Array){if(B[ak.f]){if(B[ak.f]!==ak.t){gadgets.error("Invalid gadgets.rpc token. "+B[ak.f]+" vs "+ak.t);
J(ak.f,a)
}}if(ak.s===T){window.setTimeout(function(){k(ak.f,true)
},0);
return
}if(ak.c){ak[u]=function(al){var am=ak.g?s:"";
gadgets.rpc.call(ak.f,am+M,null,ak.c,al)
}
}if(af){var ag=t(af);
ak[g]=af;
var ah=ak.r,aj;
try{aj=t(ah)
}catch(ai){}if(!ah||aj!=ag){ah=af
}ak[r]=ah
}var ae=(q[ak.s]||q[S]).apply(ak,ak.a);
if(ak.c&&typeof ae!=="undefined"){gadgets.rpc.call(ak.f,M,null,ak.c,ae)
}}}function t(ag){if(!ag){return""
}ag=((ag.split("#"))[0].split("?"))[0];
ag=ag.toLowerCase();
if(ag.indexOf("//")==0){ag=window.location.protocol+ag
}if(ag.indexOf("://")==-1){ag=window.location.protocol+"//"+ag
}var ah=ag.substring(ag.indexOf("://")+3);
var ae=ah.indexOf("/");
if(ae!=-1){ah=ah.substring(0,ae)
}var aj=ag.substring(0,ag.indexOf("://"));
if(aj!=="http"&&aj!=="https"&&aj!=="chrome-extension"&&aj!=="file"){throw Error("Invalid URI scheme in origin")
}var ai="";
var ak=ah.indexOf(":");
if(ak!=-1){var af=ah.substring(ak+1);
ah=ah.substring(0,ak);
if((aj==="http"&&af!=="80")||(aj==="https"&&af!=="443")){ai=":"+af
}}return aj+"://"+ah+ai
}function C(af,ae){return"/"+af+(ae?b+ae:"")
}function y(ah){if(ah.charAt(0)=="/"){var af=ah.indexOf(b);
var ag=af>0?ah.substring(1,af):ah.substring(1);
var ae=af>0?ah.substring(af+1):null;
return{id:ag,origin:ae}
}else{return null
}}function ad(ag){if(typeof ag==="undefined"||ag===".."){return window.parent
}var af=y(ag);
if(af){return window.top.frames[af.id]
}ag=String(ag);
var ae=window.frames[ag];
if(ae){return ae
}ae=document.getElementById(ag);
if(ae&&ae.contentWindow){return ae.contentWindow
}return null
}function L(ah){var ag=null;
var ae=O(ah);
if(ae){ag=ae
}else{var af=y(ah);
if(af){ag=af.origin
}else{if(ah==".."){ag=d.parent
}else{ag=document.getElementById(ah).src
}}}return t(ag)
}var H=K();
q[S]=function(){V("Unknown RPC service: "+this["s"])
};
q[M]=function(af,ae){var ag=l[af];
if(ag){delete l[af];
ag.call(this,ae)
}};
function X(ag,ae){if(m[ag]===true){return
}if(typeof m[ag]==="undefined"){m[ag]=0
}var af=ad(ag);
if(ag===".."||af!=null){if(H.setup(ag,ae)===true){m[ag]=true;
return
}}if(m[ag]!==true&&m[ag]++<G){window.setTimeout(function(){X(ag,ae)
},f)
}else{n[ag]=R;
m[ag]=true
}}function O(af){var ae=W[af];
if(ae&&ae.substring(0,1)==="/"){if(ae.substring(1,2)==="/"){ae=document.location.protocol+ae
}else{ae=document.location.protocol+"//"+document.location.host+ae
}}return ae
}function ac(af,ae,ag){if(ae&&!/http(s)?:\/\/.+/.test(ae)){if(ae.indexOf("//")==0){ae=window.location.protocol+ae
}else{if(ae.charAt(0)=="/"){ae=window.location.protocol+"//"+window.location.host+ae
}else{if(ae.indexOf("://")==-1){ae=window.location.protocol+"//"+ae
}}}}W[af]=ae;
if(typeof ag!=="undefined"){D[af]=!!ag
}}function F(ae){return B[ae]
}function c(ae,af){af=af||"";
B[ae]=String(af);
X(ae,af)
}function ab(af){var ae=af.passReferrer||"";
var ag=ae.split(":",2);
e=ag[0]||"none";
p=ag[1]||"origin"
}function aa(ae){if(Q(ae)){H=gadgets.rpctx.ifpc||R;
H.init(Z,k)
}}function Q(ae){return String(ae.useLegacyProtocol)==="true"
}function h(af,ae){function ag(aj){var ai=aj&&aj.rpc||{};
ab(ai);
var ah=ai.parentRelayUrl||"";
ah=t(d.parent||ae)+ah;
ac("..",ah,Q(ai));
aa(ai);
c("..",af)
}if(!d.parent&&ae){ag({});
return
}gadgets.config.register("rpc",null,ag)
}function o(af,aj,al){var ai=null;
if(af.charAt(0)!="/"){if(!gadgets.util){return
}ai=document.getElementById(af);
if(!ai){throw new Error("Cannot set up gadgets.rpc receiver with ID: "+af+", element not found.")
}}var ae=ai&&ai.src;
var ag=aj||gadgets.rpc.getOrigin(ae);
ac(af,ag);
var ak=gadgets.util.getUrlParameters(ae);
var ah=al||ak.rpctoken;
c(af,ah)
}function i(ae,ag,ah){if(ae===".."){var af=ah||d.rpctoken||d.ifpctok||"";
h(af,ag)
}else{o(ae,ag,ah)
}}function w(ag){if(e==="bidir"||(e==="c2p"&&ag==="..")||(e==="p2c"&&ag!=="..")){var af=window.location.href;
var ah="?";
if(p==="query"){ah="#"
}else{if(p==="hash"){return af
}}var ae=af.lastIndexOf(ah);
ae=ae===-1?af.length:ae;
return af.substring(0,ae)
}return null
}return{config:function(ae){if(typeof ae.securityCallback==="function"){J=ae.securityCallback
}},register:function(af,ae){if(af===M||af===T){throw new Error("Cannot overwrite callback/ack service")
}if(af===S){throw new Error("Cannot overwrite default service: use registerDefault")
}q[af]=ae
},unregister:function(ae){if(ae===M||ae===T){throw new Error("Cannot delete callback/ack service")
}if(ae===S){throw new Error("Cannot delete default service: use unregisterDefault")
}delete q[ae]
},registerDefault:function(ae){q[S]=ae
},unregisterDefault:function(){delete q[S]
},forceParentVerifiable:function(){if(!H.isParentVerifiable()){H=gadgets.rpctx.ifpc
}},call:function(ae,ag,al,aj){ae=ae||"..";
var ak="..";
if(ae===".."){ak=v
}else{if(ae.charAt(0)=="/"){ak=C(v,gadgets.rpc.getOrigin(window.location.href))
}}++z;
if(al){l[z]=al
}var ai={s:ag,f:ak,c:al?z:0,a:Array.prototype.slice.call(arguments,3),t:B[ae],l:!!D[ae]};
var af=w(ae);
if(af){ai.r=af
}if(ae!==".."&&y(ae)==null&&!document.getElementById(ae)){return
}var ah=n[ae];
if(!ah&&y(ae)!==null){ah=H
}if(ag.indexOf(s)===0){ah=H;
ai.s=ag.substring(s.length);
ai.c=ai.c?ai.c:z
}ai.g=true;
ai.r=ak;
if(!ah){if(!E[ae]){E[ae]=[ai]
}else{E[ae].push(ai)
}return
}if(D[ae]){ah=gadgets.rpctx.ifpc
}if(ah.call(ae,ak,ai)===false){n[ae]=R;
H.call(ae,ak,ai)
}},getRelayUrl:O,setRelayUrl:ac,setAuthToken:c,setupReceiver:i,getAuthToken:F,removeReceiver:function(ae){delete W[ae];
delete D[ae];
delete B[ae];
delete m[ae];
delete n[ae]
},getRelayChannel:function(){return H.getCode()
},receive:function(af,ae){if(af.length>4){H._receiveMessage(af,Z)
}else{j.apply(null,af.concat(ae))
}},receiveSameDomain:function(ae){ae.a=Array.prototype.slice.call(ae.a);
window.setTimeout(function(){Z(ae)
},0)
},getOrigin:t,getTargetOrigin:L,init:function(){if(H.init(Z,k)===false){H=R
}if(A){i("..")
}else{gadgets.config.register("rpc",null,function(af){var ae=af.rpc||{};
ab(ae);
aa(ae)
})
}},_getTargetWin:ad,_parseSiblingId:y,ACK:T,RPC_ID:v||"..",SEC_ERROR_LOAD_TIMEOUT:P,SEC_ERROR_FRAME_PHISH:Y,SEC_ERROR_FORGED_MSG:a}
}();
gadgets.rpc.init()
}else{if(typeof gadgets.rpc=="undefined"||!gadgets.rpc){gadgets.rpc=window.gadgets["rpc"];
gadgets.rpc.config=gadgets.rpc.config;
gadgets.rpc.register=gadgets.rpc.register;
gadgets.rpc.unregister=gadgets.rpc.unregister;
gadgets.rpc.registerDefault=gadgets.rpc.registerDefault;
gadgets.rpc.unregisterDefault=gadgets.rpc.unregisterDefault;
gadgets.rpc.forceParentVerifiable=gadgets.rpc.forceParentVerifiable;
gadgets.rpc.call=gadgets.rpc.call;
gadgets.rpc.getRelayUrl=gadgets.rpc.getRelayUrl;
gadgets.rpc.setRelayUrl=gadgets.rpc.setRelayUrl;
gadgets.rpc.setAuthToken=gadgets.rpc.setAuthToken;
gadgets.rpc.setupReceiver=gadgets.rpc.setupReceiver;
gadgets.rpc.getAuthToken=gadgets.rpc.getAuthToken;
gadgets.rpc.removeReceiver=gadgets.rpc.removeReceiver;
gadgets.rpc.getRelayChannel=gadgets.rpc.getRelayChannel;
gadgets.rpc.receive=gadgets.rpc.receive;
gadgets.rpc.receiveSameDomain=gadgets.rpc.receiveSameDomain;
gadgets.rpc.getOrigin=gadgets.rpc.getOrigin;
gadgets.rpc.getTargetOrigin=gadgets.rpc.getTargetOrigin;
gadgets.rpc._getTargetWin=gadgets.rpc._getTargetWin;
gadgets.rpc._parseSiblingId=gadgets.rpc._parseSiblingId
}};;

/* [end] feature=rpc */
gadgets.config.init({"rpc":{"commSwf":"//xpc.googleusercontent.com/gadgets/xpc.swf","passReferrer":"p2c:query","parentRelayUrl":"/rpc_relay.html"}});
(function(){var j=window['___jsl']=window['___jsl']||{};j['l']=(j['l']||[]).concat(['rpc','core.util']);})();(function(){var j=window['___jsl']=window['___jsl']||{};if(j['c']){j['c']();delete j['c'];}})();var friendconnect_serverBase = "https://www.google.com";var friendconnect_loginUrl = "https://www.google.com/accounts";var friendconnect_gadgetPrefix = "http://www-a-fc-opensocial.googleusercontent.com/gadgets";
var friendconnect_serverVersion = "0.1-d9f87570_ff0243f8_d01f42bf_70753ecd_725a83a6.7";
var friendconnect_imageUrl = "https://www.google.com/friendconnect/scs/images";
var friendconnect_lightbox = true;
var fc,goog=goog||{},fca=this,fcb=function(a,b,c){a=a.split(".");c=c||fca;a[0]in c||!c.execScript||c.execScript("var "+a[0]);for(var d;a.length&&(d=a.shift());)a.length||void 0===b?c=c[d]?c[d]:c[d]={}:c[d]=b},fcaa=function(){},fcc=function(a){var b=typeof a;if("object"==b)if(a){if(a instanceof Array)return"array";if(a instanceof Object)return b;var c=Object.prototype.toString.call(a);if("[object Window]"==c)return"object";if("[object Array]"==c||"number"==typeof a.length&&"undefined"!=typeof a.splice&&
"undefined"!=typeof a.propertyIsEnumerable&&!a.propertyIsEnumerable("splice"))return"array";if("[object Function]"==c||"undefined"!=typeof a.call&&"undefined"!=typeof a.propertyIsEnumerable&&!a.propertyIsEnumerable("call"))return"function"}else return"null";else if("function"==b&&"undefined"==typeof a.call)return"object";return b},fcd=function(a){var b=fcc(a);return"array"==b||"object"==b&&"number"==typeof a.length},fce=function(a){return"string"==typeof a},fcf=function(a){var b=typeof a;return"object"==
b&&null!=a||"function"==b},fcg=function(a){var b=fcc(a);if("object"==b||"array"==b){if(a.clone)return a.clone();var b="array"==b?[]:{},c;for(c in a)b[c]=fcg(a[c]);return b}return a},fcba=function(a,b,c){return a.call.apply(a.bind,arguments)},fcca=function(a,b,c){if(!a)throw Error();if(2<arguments.length){var d=Array.prototype.slice.call(arguments,2);return function(){var c=Array.prototype.slice.call(arguments);Array.prototype.unshift.apply(c,d);return a.apply(b,c)}}return function(){return a.apply(b,
arguments)}},fch=function(a,b,c){fch=Function.prototype.bind&&-1!=Function.prototype.bind.toString().indexOf("native code")?fcba:fcca;return fch.apply(null,arguments)},fci=function(a,b){var c=Array.prototype.slice.call(arguments,1);return function(){var b=c.slice();b.push.apply(b,arguments);return a.apply(this,b)}},fcda=Date.now||function(){return+new Date},fcj=function(a,b){function c(){}c.prototype=b.prototype;a.superClass_=b.prototype;a.prototype=new c;a.prototype.constructor=a;a.base=function(a,
c,f){for(var k=Array(arguments.length-2),l=2;l<arguments.length;l++)k[l-2]=arguments[l];return b.prototype[c].apply(a,k)}};var fck=function(a){if(Error.captureStackTrace)Error.captureStackTrace(this,fck);else{var b=Error().stack;b&&(this.stack=b)}a&&(this.message=String(a))};fcj(fck,Error);fck.prototype.name="CustomError";var fcea=function(a,b){for(var c=a.split("%s"),d="",e=Array.prototype.slice.call(arguments,1);e.length&&1<c.length;)d+=c.shift()+e.shift();return d+c.join("%s")},fcl=String.prototype.trim?function(a){return a.trim()}:function(a){return a.replace(/^[\s\xa0]+|[\s\xa0]+$/g,"")},fcm=function(a,b){var c=String(a).toLowerCase(),d=String(b).toLowerCase();return c<d?-1:c==d?0:1},fcla=function(a,b){if(b)a=a.replace(fcn,"&amp;").replace(fcfa,"&lt;").replace(fcga,"&gt;").replace(fcha,"&quot;").replace(fcia,
"&#39;").replace(fcja,"&#0;");else{if(!fcka.test(a))return a;-1!=a.indexOf("&")&&(a=a.replace(fcn,"&amp;"));-1!=a.indexOf("<")&&(a=a.replace(fcfa,"&lt;"));-1!=a.indexOf(">")&&(a=a.replace(fcga,"&gt;"));-1!=a.indexOf('"')&&(a=a.replace(fcha,"&quot;"));-1!=a.indexOf("'")&&(a=a.replace(fcia,"&#39;"));-1!=a.indexOf("\x00")&&(a=a.replace(fcja,"&#0;"))}return a},fcn=/&/g,fcfa=/</g,fcga=/>/g,fcha=/"/g,fcia=/'/g,fcja=/\x00/g,fcka=/[\x00&<>"']/,fco=function(a,b){return a<b?-1:a>b?1:0},fcma=function(a){return String(a).replace(/\-([a-z])/g,
function(a,c){return c.toUpperCase()})},fcna=function(a,b){var c=fce(b)?String(b).replace(/([-()\[\]{}+?*.$\^|,:#<!\\])/g,"\\$1").replace(/\x08/g,"\\x08"):"\\s",c=c?"|["+c+"]+":"",c=new RegExp("(^"+c+")([a-z])","g");return a.replace(c,function(a,b,c){return b+c.toUpperCase()})};var fcp=function(a,b){b.unshift(a);fck.call(this,fcea.apply(null,b));b.shift()};fcj(fcp,fck);fcp.prototype.name="AssertionError";var fcoa=function(a){throw a;},fcpa=fcoa,fcq=function(a,b,c){if(!a){var d="Assertion failed";if(b)var d=d+(": "+b),e=Array.prototype.slice.call(arguments,2);d=new fcp(""+d,e||[]);fcpa(d)}return a},fcqa=function(a,b){fcpa(new fcp("Failure"+(a?": "+a:""),Array.prototype.slice.call(arguments,1)))};var fcr=Array.prototype.indexOf?function(a,b,c){fcq(null!=a.length);return Array.prototype.indexOf.call(a,b,c)}:function(a,b,c){c=null==c?0:0>c?Math.max(0,a.length+c):c;if(fce(a))return fce(b)&&1==b.length?a.indexOf(b,c):-1;for(;c<a.length;c++)if(c in a&&a[c]===b)return c;return-1},fcra=Array.prototype.forEach?function(a,b,c){fcq(null!=a.length);Array.prototype.forEach.call(a,b,c)}:function(a,b,c){for(var d=a.length,e=fce(a)?a.split(""):a,f=0;f<d;f++)f in e&&b.call(c,e[f],f,a)},fcsa=function(a){var b=
a.length;if(0<b){for(var c=Array(b),d=0;d<b;d++)c[d]=a[d];return c}return[]},fcta=function(a,b,c){fcq(null!=a.length);return 2>=arguments.length?Array.prototype.slice.call(a,b):Array.prototype.slice.call(a,b,c)};var fcua=function(a,b,c){for(var d in a)b.call(c,a[d],d,a)},fcva="constructor hasOwnProperty isPrototypeOf propertyIsEnumerable toLocaleString toString valueOf".split(" "),fcs=function(a,b){for(var c,d,e=1;e<arguments.length;e++){d=arguments[e];for(c in d)a[c]=d[c];for(var f=0;f<fcva.length;f++)c=fcva[f],Object.prototype.hasOwnProperty.call(d,c)&&(a[c]=d[c])}};var fct;a:{var fcwa=fca.navigator;if(fcwa){var fcxa=fcwa.userAgent;if(fcxa){fct=fcxa;break a}}fct=""}var fcu=function(a){var b=fct;return-1!=b.indexOf(a)},fcya=function(a){var b=fct;return-1!=b.toLowerCase().indexOf(a.toLowerCase())};var fcza=fcu("Opera"),fcv=fcu("Trident")||fcu("MSIE"),fcAa=fcu("Edge"),fcw=fcu("Gecko")&&!(fcya("WebKit")&&!fcu("Edge"))&&!(fcu("Trident")||fcu("MSIE"))&&!fcu("Edge"),fcx=fcya("WebKit")&&!fcu("Edge"),fcBa=function(){var a=fct;if(fcw)return/rv\:([^\);]+)(\)|;)/.exec(a);if(fcAa)return/Edge\/([\d\.]+)/.exec(a);if(fcv)return/\b(?:MSIE|rv)[: ]([^\);]+)(\)|;)/.exec(a);if(fcx)return/WebKit\/(\S+)/.exec(a);if(fcza)return/(?:Version)[ \/]?(\S+)/.exec(a)},fcCa=function(){var a=fca.document;return a?a.documentMode:
void 0},fcy;a:{var fcz="",fcA=fcBa();fcA&&(fcz=fcA?fcA[1]:"");if(fcv){var fcB=fcCa();if(null!=fcB&&fcB>parseFloat(fcz)){fcy=String(fcB);break a}}fcy=fcz}
var fcDa=fcy,fcEa={},fcC=function(a){var b;if(!(b=fcEa[a])){var c=a,d=0;b=fcl(String(fcDa)).split(".");for(var c=fcl(String(c)).split("."),e=Math.max(b.length,c.length),f=0;0==d&&f<e;f++){var k=b[f]||"",l=c[f]||"",m=RegExp("(\\d*)(\\D*)","g"),n=RegExp("(\\d*)(\\D*)","g");do{var g=m.exec(k)||["","",""],h=n.exec(l)||["","",""];if(0==g[0].length&&0==h[0].length)break;var d=0==g[1].length?0:parseInt(g[1],10),q=0==h[1].length?0:parseInt(h[1],10),d=fco(d,q)||fco(0==g[2].length,0==h[2].length)||fco(g[2],
h[2])}while(0==d)}b=d;b=fcEa[a]=0<=b}return b},fcFa;var fcGa=fca.document,fcHa=fcCa();fcFa=fcGa&&fcv?fcHa||("CSS1Compat"==fcGa.compatMode?parseInt(fcDa,10):5):void 0;var fcIa=fcFa;var fcJa=function(a){for(var b=[],c=0,d=0;d<a.length;d++){for(var e=a.charCodeAt(d);255<e;)b[c++]=e&255,e>>=8;b[c++]=e}return b};var fcD=null,fcE=null,fcF=null,fcLa=function(a){function b(a){c.push(a)}var c=[];fcKa(a,b);return c},fcKa=function(a,b){function c(b){for(;d<a.length;){var c=a.charAt(d++),e=fcE[c];if(null!=e)return e;if(!/^[\s\xa0]*$/.test(c))throw Error("Unknown base64 encoding at char: "+c);}return b}fcMa();for(var d=0;;){var e=c(-1),f=c(0),k=c(64),l=c(64);if(64===l&&-1===e)break;e=e<<2|f>>4;b(e);64!=k&&(f=f<<4&240|k>>2,b(f),64!=l&&(k=k<<6&192|l,b(k)))}},fcMa=function(){if(!fcD){fcD={};fcE={};fcF={};for(var a=
0;65>a;a++)fcD[a]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=".charAt(a),fcE[fcD[a]]=a,fcF[a]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_.".charAt(a),62<=a&&(fcE["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_.".charAt(a)]=a)}};var fcNa=function(){this.blockSize=-1};var fcG=function(a,b,c){this.blockSize=-1;this.hasher_=a;this.blockSize=c||a.blockSize||16;this.keyO_=Array(this.blockSize);this.keyI_=Array(this.blockSize);this.initialize_(b)};fcj(fcG,fcNa);fc=fcG.prototype;fc.initialize_=function(a){a.length>this.blockSize&&(this.hasher_.update(a),a=this.hasher_.digest(),this.hasher_.reset());for(var b,c=0;c<this.blockSize;c++)b=c<a.length?a[c]:0,this.keyO_[c]=b^92,this.keyI_[c]=b^54;this.hasher_.update(this.keyI_)};fc.reset=function(){this.hasher_.reset();this.hasher_.update(this.keyI_)};
fc.update=function(a,b){this.hasher_.update(a,b)};fc.digest=function(){var a=this.hasher_.digest();this.hasher_.reset();this.hasher_.update(this.keyO_);this.hasher_.update(a);return this.hasher_.digest()};fc.getHmac=function(a){this.reset();this.update(a);return this.digest()};var fcH=function(){this.blockSize=64;this.chain_=[];this.buf_=[];this.W_=[];this.pad_=[];this.pad_[0]=128;for(var a=1;a<this.blockSize;++a)this.pad_[a]=0;this.total_=this.inbuf_=0;this.reset()};fcj(fcH,fcNa);fcH.prototype.reset=function(){this.chain_[0]=1732584193;this.chain_[1]=4023233417;this.chain_[2]=2562383102;this.chain_[3]=271733878;this.chain_[4]=3285377520;this.total_=this.inbuf_=0};
fcH.prototype.compress_=function(a,b){b||(b=0);var c=this.W_;if(fce(a))for(var d=0;16>d;d++)c[d]=a.charCodeAt(b)<<24|a.charCodeAt(b+1)<<16|a.charCodeAt(b+2)<<8|a.charCodeAt(b+3),b+=4;else for(d=0;16>d;d++)c[d]=a[b]<<24|a[b+1]<<16|a[b+2]<<8|a[b+3],b+=4;for(d=16;80>d;d++){var e=c[d-3]^c[d-8]^c[d-14]^c[d-16];c[d]=(e<<1|e>>>31)&4294967295}for(var f=this.chain_[0],k=this.chain_[1],l=this.chain_[2],m=this.chain_[3],n=this.chain_[4],g,d=0;80>d;d++)40>d?20>d?(e=m^k&(l^m),g=1518500249):(e=k^l^m,g=1859775393):
60>d?(e=k&l|m&(k|l),g=2400959708):(e=k^l^m,g=3395469782),e=(f<<5|f>>>27)+e+n+g+c[d]&4294967295,n=m,m=l,l=(k<<30|k>>>2)&4294967295,k=f,f=e;this.chain_[0]=this.chain_[0]+f&4294967295;this.chain_[1]=this.chain_[1]+k&4294967295;this.chain_[2]=this.chain_[2]+l&4294967295;this.chain_[3]=this.chain_[3]+m&4294967295;this.chain_[4]=this.chain_[4]+n&4294967295};
fcH.prototype.update=function(a,b){if(null!=a){void 0===b&&(b=a.length);for(var c=b-this.blockSize,d=0,e=this.buf_,f=this.inbuf_;d<b;){if(0==f)for(;d<=c;)this.compress_(a,d),d+=this.blockSize;if(fce(a))for(;d<b;){if(e[f]=a.charCodeAt(d),++f,++d,f==this.blockSize){this.compress_(e);f=0;break}}else for(;d<b;)if(e[f]=a[d],++f,++d,f==this.blockSize){this.compress_(e);f=0;break}}this.inbuf_=f;this.total_+=b}};
fcH.prototype.digest=function(){var a=[],b=8*this.total_;56>this.inbuf_?this.update(this.pad_,56-this.inbuf_):this.update(this.pad_,this.blockSize-(this.inbuf_-56));for(var c=this.blockSize-1;56<=c;c--)this.buf_[c]=b&255,b/=256;this.compress_(this.buf_);for(c=b=0;5>c;c++)for(var d=24;0<=d;d-=8)a[b]=this.chain_[c]>>d&255,++b;return a};var fcI=function(){this.privateDoNotAccessOrElseSafeHtmlWrappedValue_="";this.SAFE_URL_TYPE_MARKER_GOOG_HTML_SECURITY_PRIVATE_=fcOa};fcI.prototype.implementsGoogStringTypedString=!0;fcI.prototype.toString=function(){return"SafeUrl{"+this.privateDoNotAccessOrElseSafeHtmlWrappedValue_+"}"};var fcPa=/^(?:(?:https?|mailto|ftp):|[^&:/?#]*(?:[/?#]|$))/i,fcOa={},fcQa=function(a){var b=new fcI;b.privateDoNotAccessOrElseSafeHtmlWrappedValue_=a;return b};fcQa("about:blank");var fcJ=function(){this.privateDoNotAccessOrElseSafeHtmlWrappedValue_=""};fcJ.prototype.implementsGoogStringTypedString=!0;fcJ.prototype.toString=function(){return"SafeHtml{"+this.privateDoNotAccessOrElseSafeHtmlWrappedValue_+"}"};fcJ.prototype.initSecurityPrivateDoNotAccessOrElse_=function(a){this.privateDoNotAccessOrElseSafeHtmlWrappedValue_=a;return this};var fcSa=function(a){fcRa();return(new fcJ).initSecurityPrivateDoNotAccessOrElse_(a,null)},fcRa=fcaa;var fcTa=function(a){this.document_=a||{cookie:""}},fcUa=/\s*;\s*/;fc=fcTa.prototype;fc.isEnabled=function(){return navigator.cookieEnabled};fc.isValidName=function(a){return!/[;=\s]/.test(a)};fc.isValidValue=function(a){return!/[;\r\n]/.test(a)};
fc.set=function(a,b,c,d,e,f){if(!this.isValidName(a))throw Error('Invalid cookie name "'+a+'"');if(!this.isValidValue(b))throw Error('Invalid cookie value "'+b+'"');void 0!==c||(c=-1);e=e?";domain="+e:"";d=d?";path="+d:"";f=f?";secure":"";0>c?c="":(c=0==c?new Date(1970,1,1):new Date(fcda()+1E3*c),c=";expires="+c.toUTCString());this.setCookie_(a+"="+b+e+d+c+f)};fc.get=function(a,b){for(var c=a+"=",d=this.getParts_(),e=0,f;f=d[e];e++){if(0==f.lastIndexOf(c,0))return f.substr(c.length);if(f==a)return""}return b};
fc.remove=function(a,b,c){var d=this.containsKey(a);this.set(a,"",0,b,c);return d};fc.getKeys=function(){return this.getKeyValues_().keys};fc.getValues=function(){return this.getKeyValues_().values};fc.getCount=function(){var a=this.document_.cookie;return a?this.getParts_().length:0};fc.containsKey=function(a){return void 0!==this.get(a)};fc.clear=function(){for(var a=this.getKeyValues_().keys,b=a.length-1;0<=b;b--)this.remove(a[b])};fc.setCookie_=function(a){this.document_.cookie=a};
fc.getParts_=function(){return(this.document_.cookie||"").split(fcUa)};fc.getKeyValues_=function(){for(var a=this.getParts_(),b=[],c=[],d,e,f=0;e=a[f];f++)d=e.indexOf("="),-1==d?(b.push(""),c.push(e)):(b.push(e.substring(0,d)),c.push(e.substring(d+1)));return{keys:b,values:c}};var fcK=new fcTa("undefined"==typeof document?null:document);fcK.MAX_COOKIE_LENGTH=3950;var fcVa=function(a,b){var c;c=a.className;c=fce(c)&&c.match(/\S+/g)||[];for(var d=fcta(arguments,1),e=c.length+d.length,f=c,k=0;k<d.length;k++)0<=fcr(f,d[k])||f.push(d[k]);a.className=c.join(" ");return c.length==e};var fcL=function(a,b){this.width=a;this.height=b};fc=fcL.prototype;fc.clone=function(){return new fcL(this.width,this.height)};fc.toString=function(){return"("+this.width+" x "+this.height+")"};fc.ceil=function(){this.width=Math.ceil(this.width);this.height=Math.ceil(this.height);return this};fc.floor=function(){this.width=Math.floor(this.width);this.height=Math.floor(this.height);return this};fc.round=function(){this.width=Math.round(this.width);this.height=Math.round(this.height);return this};
fc.scale=function(a,b){var c="number"==typeof b?b:a;this.width*=a;this.height*=c;return this};var fcWa=!fcv||9<=Number(fcIa);!fcw&&!fcv||fcv&&9<=Number(fcIa)||fcw&&fcC("1.9.1");fcv&&fcC("9");var fcM=function(a,b){return fce(b)?a.getElementById(b):b},fcXa=function(a,b,c,d){a=d||a;var e=b&&"*"!=b?b.toUpperCase():"";if(a.querySelectorAll&&a.querySelector&&(e||c))return c=e+(c?"."+c:""),a.querySelectorAll(c);if(c&&a.getElementsByClassName){b=a.getElementsByClassName(c);if(e){a={};for(var f=d=0,k;k=b[f];f++)e==k.nodeName&&(a[d++]=k);a.length=d;return a}return b}b=a.getElementsByTagName(e||"*");if(c){a={};for(f=d=0;k=b[f];f++){var e=k.className,l;if(l="function"==typeof e.split)e=e.split(/\s+/),
l=0<=fcr(e,c);l&&(a[d++]=k)}a.length=d;return a}return b},fcZa=function(a,b){fcua(b,function(b,d){"style"==d?a.style.cssText=b:"class"==d?a.className=b:"for"==d?a.htmlFor=b:fcYa.hasOwnProperty(d)?a.setAttribute(fcYa[d],b):0==d.lastIndexOf("aria-",0)||0==d.lastIndexOf("data-",0)?a.setAttribute(d,b):a[d]=b})},fcYa={cellpadding:"cellPadding",cellspacing:"cellSpacing",colspan:"colSpan",frameborder:"frameBorder",height:"height",maxlength:"maxLength",nonce:"nonce",role:"role",rowspan:"rowSpan",type:"type",
usemap:"useMap",valign:"vAlign",width:"width"},fc_a=function(a){a=a.document;a="CSS1Compat"==a.compatMode?a.documentElement:a.body;return new fcL(a.clientWidth,a.clientHeight)},fcN=function(a,b,c){var d;d=arguments;var e=String(d[0]),f=d[1];if(!fcWa&&f&&(f.name||f.type)){e=["<",e];f.name&&e.push(' name="',fcla(f.name),'"');if(f.type){e.push(' type="',fcla(f.type),'"');var k={};fcs(k,f);delete k.type;f=k}e.push(">");e=e.join("")}e=document.createElement(e);f&&(fce(f)?e.className=f:"array"==fcc(f)?
e.className=f.join(" "):fcZa(e,f));2<d.length&&fc0a(document,e,d,2);return d=e},fc0a=function(a,b,c,d){function e(c){c&&b.appendChild(fce(c)?a.createTextNode(c):c)}for(;d<c.length;d++){var f=c[d];if(!fcd(f)||fcf(f)&&0<f.nodeType)e(f);else{var k;a:{if(f&&"number"==typeof f.length){if(fcf(f)){k="function"==typeof f.item||"string"==typeof f.item;break a}if("function"==fcc(f)){k="function"==typeof f.item;break a}}k=!1}fcra(k?fcsa(f):f,e)}}};var fc1a="StopIteration"in fca?fca.StopIteration:{message:"StopIteration",stack:""},fcO=function(){};fcO.prototype.next=function(){throw fc1a;};fcO.prototype.__iterator__=function(){return this};var fcP=function(a,b){this.map_={};this.keys_=[];this.version_=this.count_=0;var c=arguments.length;if(1<c){if(c%2)throw Error("Uneven number of arguments");for(var d=0;d<c;d+=2)this.set(arguments[d],arguments[d+1])}else a&&this.addAll(a)};fc=fcP.prototype;fc.getCount=function(){return this.count_};fc.getValues=function(){this.cleanupKeysArray_();for(var a=[],b=0;b<this.keys_.length;b++){var c=this.keys_[b];a.push(this.map_[c])}return a};fc.getKeys=function(){this.cleanupKeysArray_();return this.keys_.concat()};
fc.containsKey=function(a){return fcQ(this.map_,a)};fc.clear=function(){this.map_={};this.version_=this.count_=this.keys_.length=0};fc.remove=function(a){return fcQ(this.map_,a)?(delete this.map_[a],this.count_--,this.version_++,this.keys_.length>2*this.count_&&this.cleanupKeysArray_(),!0):!1};
fc.cleanupKeysArray_=function(){if(this.count_!=this.keys_.length){for(var a=0,b=0;a<this.keys_.length;){var c=this.keys_[a];fcQ(this.map_,c)&&(this.keys_[b++]=c);a++}this.keys_.length=b}if(this.count_!=this.keys_.length){for(var d={},b=a=0;a<this.keys_.length;)c=this.keys_[a],fcQ(d,c)||(this.keys_[b++]=c,d[c]=1),a++;this.keys_.length=b}};fc.get=function(a,b){return fcQ(this.map_,a)?this.map_[a]:b};
fc.set=function(a,b){fcQ(this.map_,a)||(this.count_++,this.keys_.push(a),this.version_++);this.map_[a]=b};fc.addAll=function(a){var b,c;if(a instanceof fcP)b=a.getKeys(),c=a.getValues();else{b=a;var d=[],e=0,f;for(f in b)d[e++]=f;b=d;d=[];e=0;for(c in a)d[e++]=a[c];c=d}for(a=0;a<b.length;a++)this.set(b[a],c[a])};fc.forEach=function(a,b){for(var c=this.getKeys(),d=0;d<c.length;d++){var e=c[d],f=this.get(e);a.call(b,f,e,this)}};fc.clone=function(){return new fcP(this)};
fc.__iterator__=function(a){this.cleanupKeysArray_();var b=0,c=this.version_,d=this,e=new fcO;e.next=function(){if(c!=d.version_)throw Error("The map has changed since the iterator was created");if(b>=d.keys_.length)throw fc1a;var e=d.keys_[b++];return a?e:d.map_[e]};return e};var fcQ=function(a,b){return Object.prototype.hasOwnProperty.call(a,b)};var fcR=function(a,b,c){if(fce(b)){var d=c;(b=fc2a(a,b))&&(a.style[b]=d)}else for(d in b){c=a;var e=b[d],f=fc2a(c,d);f&&(c.style[f]=e)}},fc3a={},fc2a=function(a,b){var c=fc3a[b];if(!c){var d=fcma(b),c=d;void 0===a.style[d]&&(d=(fcx?"Webkit":fcw?"Moz":fcv?"ms":fcza?"O":null)+fcna(d),void 0!==a.style[d]&&(c=d));fc3a[b]=c}return c},fc4a=function(a,b){var c;c=a;fcq(c,"Node cannot be null or undefined.");c=9==c.nodeType?c:c.ownerDocument||c.document;return c.defaultView&&c.defaultView.getComputedStyle&&
(c=c.defaultView.getComputedStyle(a,null))?c[b]||c.getPropertyValue(b)||"":""},fcS=function(a,b,c){if(b instanceof fcL)c=b.height,b=b.width;else if(void 0==c)throw Error("missing height argument");a.style.width=fc5a(b,!0);a.style.height=fc5a(c,!0)},fc5a=function(a,b){"number"==typeof a&&(a=(b?Math.round(a):a)+"px");return a},fc6a=function(a,b){var c;c=b;var d="display";c=fc4a(c,d)||(c.currentStyle?c.currentStyle[d]:null)||c.style&&c.style[d];if("none"!=c)return a(b);c=b.style;var d=c.display,e=c.visibility,
f=c.position;c.visibility="hidden";c.position="absolute";c.display="inline";var k=a(b);c.display=d;c.position=f;c.visibility=e;return k},fc7a=function(a){var b=a.offsetWidth,c=a.offsetHeight,d=fcx&&!b&&!c;if((void 0===b||d)&&a.getBoundingClientRect){var e;a:{try{e=a.getBoundingClientRect()}catch(f){e={left:0,top:0,right:0,bottom:0};break a}fcv&&a.ownerDocument.body&&(a=a.ownerDocument,e.left-=a.documentElement.clientLeft+a.body.clientLeft,e.top-=a.documentElement.clientTop+a.body.clientTop)}return new fcL(e.right-
e.left,e.bottom-e.top)}return new fcL(b,c)};var fc8a={},fc9a={};var fcT=function(a,b,c,d){b=b||"800";c=c||"550";d=d||"friendconnect";a=window.open(a,d,"menubar=no,toolbar=no,dialog=yes,location=yes,alwaysRaised=yes,width="+b+",height="+c+",resizable=yes,scrollbars=1,status=1");window.focus&&a&&a.focus()},fc$a=function(a,b){var c=gadgets.util.getUrlParameters().communityId;gadgets.rpc.call(null,"signin",null,c,a,b)};fcb("goog.peoplesense.util.openPopup",fcT,void 0);fcb("goog.peoplesense.util.finishSignIn",fc$a,void 0);var fcbb=function(a,b){var c=fcU()+"/friendconnect/invite/friends",d=encodeURIComponent(shindig.auth.getSecurityToken());fcab(c,d,a,b)},fcab=function(a,b,c,d){a+="?st="+b;c&&(a+="&customMessage="+encodeURIComponent(c));d&&(a+="&customInviteUrl="+encodeURIComponent(d));b=760;fcv&&(b+=25);fcT(a,String(b),"515","friendconnect_invite")};fcb("goog.peoplesense.util.invite",fcbb,void 0);fcb("goog.peoplesense.util.inviteFriends",fcab,void 0);var fcV=function(a){this.url=a};fcV.prototype.addParam=function(a,b){if(0<=this.url.indexOf("?"+a+"=")||0<=this.url.indexOf("&"+a+"="))throw Error("duplicate: "+a);if(null===b||void 0===b)return this;var c=0<=this.url.indexOf("?")?"&":"?";this.url+=c+a+"="+encodeURIComponent(String(b));return this};fcV.prototype.toString=function(){return this.url};var fcU=function(){return window.friendconnect_serverBase},fcW=function(a,b){var c=gadgets.util.getUrlParameters().psinvite||"",d=new fcV(fcU()+"/friendconnect/signin/home");d.addParam("st",window.shindig.auth.getSecurityToken());d.addParam("psinvite",c);d.addParam("iframeId",a);d.addParam("loginProvider",b);d.addParam("subscribeOnSignin","1");fcT(d.toString());return!1},fccb=function(){var a=gadgets.util.getUrlParameters().communityId;gadgets.rpc.call(null,"signout",null,a)},fceb=function(a,b){var c=
fcU()+"/friendconnect/settings/edit?st="+encodeURIComponent(shindig.auth.getSecurityToken())+(a?"&iframeId="+encodeURIComponent(a):"");b&&(c=c+"&"+b);fcdb(c)},fcfb=function(a){a=fcU()+"/friendconnect/settings/siteProfile?st="+encodeURIComponent(a);fcdb(a)},fcdb=function(a){var b=800;fcv&&(b+=25);fcT(a,String(b),"510")},fcgb=function(a,b){var c=b=b||fch(fcW,null,null,null,null);if(!a)throw"google.friendconnect.renderSignInButton: missing options";var d=a.style||"standard",e=a.text,f=a.version;if("standard"==
d)e=a.text||"Sign in";else if("text"==d||"long"==d)e=a.text||"Sign in with Friend Connect";var k=a.element;if(!k){k=a.id;if(!k)throw"google.friendconnect.renderSignInButton: options[id] and options[element] == null";k=fcM(document,k);if(!k)throw"google.friendconnect.renderSignInButton: element "+a.id+" not found";}k.innerHTML="";var f=f||2,l=null;if("text"==d)l=fcN("div",{"class":"gfc-button-text"},fcN("div",{"class":"gfc-icon"},fcN("a",{href:"javascript:void(0);"},e))),k.appendChild(l);else if("long"==
d||"standard"==d)l=1==f?fcN("div",{"class":"gfc-inline-block gfc-primaryactionbutton gfc-button-base"},fcN("div",{"class":"gfc-inline-block gfc-button-base-outer-box"},fcN("div",{"class":"gfc-inline-block gfc-button-base-inner-box"},fcN("div",{"class":"gfc-button-base-pos"},fcN("div",{"class":"gfc-button-base-top-shadow",innerHTML:"&nbsp;"}),fcN("div",{"class":"gfc-button-base-content"},fcN("div",{"class":"gfc-icon"},e)))))):fcN("table",{"class":"gfc-button-base-v2 gfc-button",cellpadding:"0",cellspacing:"0"},
fcN("tbody",{"class":""},fcN("tr",{"class":""},fcN("td",{"class":"gfc-button-base-v2 gfc-button-1"}),fcN("td",{"class":"gfc-button-base-v2 gfc-button-2"},e),fcN("td",{"class":"gfc-button-base-v2 gfc-button-3"})))),k.appendChild(l),"standard"==d&&(e=fcN("div",{"class":"gfc-footer-msg"},"with Google Friend Connect"),1==f&&k.appendChild(fcN("br")),k.appendChild(e));k=l;window.addEventListener?k.addEventListener("click",c,!1):k.attachEvent("onclick",c)},fchb=function(a,b){gadgets.rpc.call(null,"putReloadViewParam",
null,a,b);var c=gadgets.views.getParams();c[a]=b},fcib=function(a,b){var c=new fcV("/friendconnect/gadgetshare/friends");c.addParam("customMessage",a);c.addParam("customInviteUrl",b);c.addParam("container","glb");var d=310;fcv&&(d+=25);var d=String(d),e="370",f=void 0,k=void 0,d=d||"800",e=e||"550",f=f||"friendconnect",k=k||!1;gadgets.rpc.call(null,"openLightboxIframe",void 0,c.toString(),shindig.auth.getSecurityToken(),d,e,f,void 0,null,null,null,k)};fcb("goog.peoplesense.util.getBaseUrl",fcU,void 0);
fcb("goog.peoplesense.util.finishSignIn",fc$a,void 0);fcb("goog.peoplesense.util.signout",fccb,void 0);fcb("goog.peoplesense.util.signin",fcW,void 0);fcb("goog.peoplesense.util.editSettings",fceb,void 0);fcb("goog.peoplesense.util.editSSProfile",fcfb,void 0);fcb("goog.peoplesense.util.setStickyViewParamToken",fchb,void 0);fcb("google.friendconnect.renderSignInButton",fcgb,void 0);fcb("goog.peoplesense.util.share",fcib,void 0);fcb("goog.peoplesense.util.userAgent.IE",fcv,void 0);var fcjb={},fcX=function(a){this.menus_=new fcP;this.snippetId=a.id;this.site=a.site;a=a["view-params"];var b=a.skin;this.position_=(b?b.POSITION:"top")||"top";this.childView_={allowAnonymousPost:a.allowAnonymousPost||!1,scope:a.scope||"SITE",docId:a.docId||"",features:a.features||"video,comment",startMaximized:"true",disableMinMax:"true",skin:b};this.absoluteBottom=fcv&&!fcC("7");this.fixedIeSizes=fcv;window.addEventListener?window.addEventListener("resize",fch(this.resize_,this),!1):window.attachEvent("onresize",
fch(this.resize_,this));this.checkOptions()};fc=fcX.prototype;fc.checkOptions=function(){if(!this.site)throw Error("Must supply site ID.");if(!this.snippetId)throw Error("Must supply a snippet ID.");};fc.shadowWidth_=10;fc.borderWidth_=1;fc.barPrefix_="fc-friendbar-";fc.barId_=fcX.prototype.barPrefix_+"outer";fc.shadowId_=fcX.prototype.barId_+"-shadow";fc.render=function(){document.write(this.generateCss_());var a=fcM(document,this.snippetId);a.innerHTML=this.generateHtml_()};
fc.getBodyWidth_=function(){var a=fcM(document,this.barId_);return a=fc6a(fc7a,a).width};fc.resize_=function(){for(var a=this.menus_.getKeys(),b=0;b<a.length;b++)this.resizeMenu(a[b]);goog&&fc8a&&fc9a&&fcY&&fckb("resize")};fc.getShadowClass=function(a){return this.barPrefix_+"shadow-"+a};fc.getMenuId=function(a){return this.barPrefix_+"menus-"+a};fc.getTargetId=function(a){return this.barPrefix_+a+"Target"};fc.getDrawerId=function(a){return this.barPrefix_+a+"Drawer"};fc.getTargetClass=function(){return this.getTargetId("")};
fc.getWallpaperClass=function(){return this.barPrefix_+"wallpaper"};fc.getDrawerClass=function(){return this.getDrawerId("")};
fc.generateCss_=function(){var a=window.friendconnect_imageUrl+"/",b=a+"shadow_tc.png",c=a+"shadow_bc.png",d=a+"shadow_bl.png",e=a+"shadow_tl.png",f=a+"shadow_tr.png",k=a+"shadow_br.png",a=a+"shadow_cr.png",l=function(a,b){return fcv?'filter: progid:DXImageTransform.Microsoft.AlphaImageLoader(src="'+a+'", sizingMethod="scale");':"background-image: url("+a+");background-repeat: "+b+"; "},m="position:absolute; top:";"top"!=this.position_&&(m="position:fixed; bottom:",this.absoluteBottom&&(m="position:absolute; bottom:"));
var n=c;"top"!=this.position_&&(n=b);var g=0,h=[];h[g++]='<style type="text/css">';"top"!=this.position_&&this.absoluteBottom&&(h[g++]="html, body {height: 100%; overflow: auto; };");h[g++]="#"+this.barId_+" {";h[g++]="background:#E0ECFF;";h[g++]="left:0;";h[g++]="height: "+(fcv?"35px;":"36px;");"top"!=this.position_&&this.absoluteBottom&&(h[g++]="margin-right: 20px;");h[g++]="padding:0;";h[g++]=m+" 0;";h[g++]="width:100%;";h[g++]="z-index:5000;";h[g++]="}";h[g++]="#"+this.shadowId_+" {";h[g++]=l(n,
"repeat-x");h[g++]="left:0;";h[g++]="height:"+this.shadowWidth_+"px;";"top"!=this.position_&&this.absoluteBottom&&(h[g++]="margin-right: 20px;");h[g++]="padding:0;";h[g++]=m+(fcv?"35px;":"36px;");h[g++]="width:100%;";h[g++]="z-index:4998;";h[g++]="}";h[g++]="."+this.getDrawerClass()+" {";h[g++]="display: block;";h[g++]="padding:0;";h[g++]=m+(fcv?"34px;":"35px;");h[g++]="z-index:4999;";h[g++]="}";h[g++]="."+this.getWallpaperClass()+" {";h[g++]="background: white;";h[g++]="height: 100%;";h[g++]="margin-right: "+
this.shadowWidth_+"px;";h[g++]="}";h[g++]="."+this.getTargetClass()+" {";h[g++]="border: "+this.borderWidth_+"px solid #ccc;";h[g++]="height: 100%;";h[g++]="left: 0;";h[g++]="background-image: url("+window.friendconnect_imageUrl+"/loading.gif);";h[g++]="background-position: center;";h[g++]="background-repeat: no-repeat;";h[g++]="}";h[g++]="."+this.getShadowClass("cr")+" {";h[g++]=l(a,"repeat-y");h[g++]="height: 100%;";h[g++]="position:absolute;";h[g++]="right: 0;";h[g++]="top: 0;";h[g++]="width:"+
this.shadowWidth_+"px;";h[g++]="}";h[g++]="."+this.getShadowClass("bl")+" {";h[g++]=l(d,"no-repeat");h[g++]="height: "+this.shadowWidth_+"px;";h[g++]="position:absolute;";h[g++]="width:"+this.shadowWidth_+"px;";h[g++]="}";h[g++]="."+this.getShadowClass("tl")+" {";h[g++]=l(e,"no-repeat");h[g++]="height: "+this.shadowWidth_+"px;";h[g++]="position:absolute;";h[g++]="left:0px;";h[g++]="width:"+this.shadowWidth_+"px;";h[g++]="}";h[g++]="."+this.getShadowClass("bc")+" {";h[g++]=l(c,"repeat-x");h[g++]="height: "+
this.shadowWidth_+"px;";h[g++]="left: "+this.shadowWidth_+"px;";h[g++]="position:absolute;";h[g++]="right: "+this.shadowWidth_+"px;";h[g++]="}";h[g++]="."+this.getShadowClass("tc")+" {";h[g++]=l(b,"repeat-x");h[g++]="height: "+this.shadowWidth_+"px;";h[g++]="left: "+this.shadowWidth_+"px;";h[g++]="margin-left: "+this.shadowWidth_+"px;";h[g++]="margin-right: "+this.shadowWidth_+"px;";h[g++]="right: "+this.shadowWidth_+"px;";h[g++]="}";h[g++]="."+this.getShadowClass("br")+" {";h[g++]=l(k,"no-repeat");
h[g++]="height: "+this.shadowWidth_+"px;";h[g++]="position:absolute;";h[g++]="right: 0;";h[g++]="width: "+this.shadowWidth_+"px;";h[g++]="}";h[g++]="."+this.getShadowClass("tr")+" {";h[g++]=l(f,"no-repeat");h[g++]="height: "+this.shadowWidth_+"px;";h[g++]="position:absolute;";h[g++]="right: 0;";h[g++]="top: 0;";h[g++]="width: "+this.shadowWidth_+"px;";h[g++]="}";h[g++]="</style>";return h.join("")};
fc.generateHtml_=function(){var a=['<div id="'+this.barId_+'"></div>','<div id="'+this.shadowId_+'"></div>','<div id="'+this.getMenuId(this.menus_.getCount())+'"></div>'];return a.join("")};fc.createMenu=function(a,b,c,d){this.menus_.containsKey(a)||(b=new fclb(this,a,b,c,d),c=this.menus_.getCount(),d=fcM(document,this.getMenuId(c)),d.innerHTML=b.generateHtml_()+'<div id="'+this.getMenuId(c+1)+'"></div>',this.menus_.set(a,b))};
fc.hideMenu=function(a){(a=this.menus_.get(a))&&a.drawer&&(a.drawer.style.display="none")};fc.reloadMenu=function(a){if(a=this.menus_.get(a))a.rendered=!1};fc.refresh=function(){for(var a=this.menus_.getKeys(),b=0;b<a.length;b++){var c=a[b];this.hideMenu(c);this.reloadMenu(c)}};fc.menuStart=function(a){for(var b=this.menus_.getValues(),c=0;c<b.length;c++){var d=b[c];if(d.id==a){d.startComplete();break}}};
fc.menuLoad=function(a){for(var b=this.menus_.getValues(),c=0;c<b.length;c++){var d=b[c];if(d.id==a){d.loadComplete_();break}}};fc.resizeMenu=function(a){(a=this.menus_.get(a))&&a.drawer&&a.isShown()&&(a.evaluateConstraints(),a.fixShadowsForIe_(),a.applySkin())};
fc.showMenu=function(a,b){var c=this.menus_.get(a);if(c){c.drawer||(c.drawer=fcM(document,this.getDrawerId(c.name)),c.target=fcM(document,this.getTargetId(c.name)),c.sha_bc=fcXa(document,"div","top"==this.position_?this.getShadowClass("bc"):this.getShadowClass("tc"),c.drawer)[0],c.sha_cr=fcXa(document,"div",this.getShadowClass("cr"),c.drawer)[0]);for(var d=this.menus_.getKeys(),e=0;e<d.length;e++){var f=d[e];a!==f&&this.hideMenu(f)}c.evaluateConstraints(b);c.drawer.style.display="";window.setTimeout(function(){c.applySkin();
c.fixShadowsForIe_();c.render()},0)}};var fclb=function(a,b,c,d,e){this.id=-1;this.bar=a;this.name=b;this.constraints=d;this.skin=e||{};this.height=this.skin.HEIGHT||"0";this.url=window.friendconnect_serverBase+c;this.sha_bc=this.target=this.drawer=null;this.loaded=this.rendered=!1;this.evaluateConstraints()};fc=fclb.prototype;
fc.evaluateConstraints=function(a){fcs(this.constraints,a||{});fcs(this.skin,this.constraints);if(this.bar.fixedIeSizes&&this.constraints.left&&this.constraints.right){a=this.bar.getBodyWidth_();var b=this.constraints.left,c=this.constraints.right;a-=b+c;a%2&&(--a,this.skin.right+=1);this.skin.width=a;delete this.skin.left}};
fc.applySkin=function(){if(this.drawer){if(this.skin.width){var a=this.bar.borderWidth_,b=this.bar.shadowWidth_,c=fcv?2:0;fcS(this.target,this.skin.width,"");fcS(this.sha_bc,this.skin.width-b+2*a-c,"");this.skin.rightShadow?fcS(this.drawer,this.skin.width+b+2*a-c,""):fcS(this.drawer,this.skin.width+2*a-c,"")}this.skin.right&&(this.drawer.style.right=this.skin.right+0+"px")}};
fc.fixShadowsForIe_=function(){if(fcv&&this.drawer){var a=fc6a(fc7a,this.target),b=a.width-this.bar.shadowWidth_,a=a.height;0>b&&(b=0);this.sha_bc&&this.sha_bc.style&&fcS(this.sha_bc,b,"");this.sha_cr&&this.sha_cr.style&&fcS(this.sha_cr,"",a)}};
fc.generateHtml_=function(){var a="display:none;",b="position: relative; ",c="",d="",e="",f="",k=!!this.skin.rightShadow;k||(c+="display: none; ",e+="display: none; ",d+="right: 0px; ",f+="margin-right: 0px; ");for(var l in this.skin){var m=Number(this.skin[l]);k&&0==fcm(l,"width")&&(m+=this.bar.shadowWidth_);0==fcm(l,"height")&&(b+=l+": "+m+"px; ");"rightShadow"!=l&&(0==fcm(l,"height")&&(m+=this.bar.shadowWidth_),0==fcm(l,"width")&&(m+=2),a+=l+": "+m+"px; ");fcv&&0==fcm(l,"width")&&(m=k?m-2*this.bar.shadowWidth_:
m-this.bar.shadowWidth_,d+=l+": "+m+"px; ")}fcv&&0<(this.height|0)&&(k=(this.height|0)+2,c+="height: "+k+"px; ");k=0;l=[];l[k++]='<div id="'+this.bar.getDrawerId(this.name)+'"class="'+this.bar.getDrawerClass()+'"style="'+a+'"> ';"bottom"==this.bar.position_&&(l[k++]='<div class="'+this.bar.getShadowClass("tl")+'"></div> <div class="'+this.bar.getShadowClass("tc")+'"style="'+d+'"></div> <div class="'+this.bar.getShadowClass("tr")+'"style="'+e+'"></div> ');l[k++]='<div style="'+b+'"> <div class="'+
this.bar.getWallpaperClass()+'"style="'+f+'"><div id="'+this.bar.getTargetId(this.name)+'"class="'+this.bar.getTargetClass()+'"></div> <div class="'+this.bar.getShadowClass("cr")+'"style="'+c+'"></div> </div> </div> ';"top"==this.bar.position_&&(l[k++]='<div class="'+this.bar.getShadowClass("bl")+'"></div> <div class="'+this.bar.getShadowClass("bc")+'"style="'+d+'"></div> <div class="'+this.bar.getShadowClass("br")+'"style="'+e+'"></div> ');l[k++]="</div> ";return l.join("")};
fc.startComplete=function(){this.rendered=this.isShown()};fc.loadComplete_=function(){this.loaded=this.isShown()};fc.isShown=function(){return!!this.drawer&&"none"!=this.drawer.style.display};
fc.render=function(){if(0==this.rendered){var a={};a.url=this.url;a.id=this.bar.getTargetId(this.name);a.site=this.bar.site;a["view-params"]=fcg(this.bar.childView_);"profile"==this.name&&(a["view-params"].profileId="VIEWER");this.skin&&fcs(a["view-params"].skin,this.skin);a["view-params"].menuName=this.name;a["view-params"].opaque="true";a["view-params"].menuPosition=this.bar.position_;a.height="1px";window.google&&fcjb&&fcZ&&(this.id=fcZ.render(a))}};fcb("google.friendconnect.FriendBar",fcX,void 0);var fc_=function(a){this.offsetByte_=this.offsetBit_=0;this.bytes_=a};fc_.prototype.numRemainingBits=function(){return 8*(this.bytes_.length-this.offsetByte_)-this.offsetBit_};
fc_.prototype.nextNBits=function(a){var b=0;if(a>this.numRemainingBits())throw Error();if(0<this.offsetBit_){var b=255>>this.offsetBit_&this.bytes_[this.offsetByte_],c=8-this.offsetBit_,d=Math.min(a%8,c),c=c-d,b=b>>c;a-=d;this.offsetBit_+=d;8==this.offsetBit_&&(this.offsetBit_=0,this.offsetByte_++)}for(;8<=a;)b<<=8,b|=this.bytes_[this.offsetByte_],this.offsetByte_++,a-=8;0<a&&(b<<=a,b|=this.bytes_[this.offsetByte_]>>8-a,this.offsetBit_=a);return b};var fcmb=(new Date).getTime(),fc0=function(){},fcnb=function(){},fcob=function(){},fcpb=function(){};fcj(fcpb,fcob);var fc1=function(a){if(a)for(var b in a)a.hasOwnProperty(b)&&(this[b]=a[b]);if(this.viewParams)for(var c in this.viewParams)/^FC_RELOAD_.*$/.test(c)&&(this.viewParams[c]=null)};
fc1.prototype.render=function(a){var b=this;a&&(b.updateGadgetToken(),this.getContent(function(c){fcR(a,"visibility","hidden");a.innerHTML=c;b.refresh(a,c);c=function(a){fcR(a,"visibility","visible")};c=fci(c,a);setTimeout(c,500);b.chrome=a}))};fc1.prototype.getContent=function(a){return this.getMainContent(a)};var fc2=function(a){fc1.call(this,a);this.serverBase_="../../";this.rpcToken=String(Math.round(2147483647*Math.random()))};fcj(fc2,fc1);fc=fc2.prototype;fc.GADGET_IFRAME_PREFIX_="gfc_iframe_";
fc.SYND="friendconnect";fc.gadgetToken="";fc.rpcRelay="rpc_relay.html";fc.setServerBase=function(a){this.serverBase_=a};fc.updateGadgetToken=function(){return this.gadgetToken=String(Math.round(2147483647*Math.random()))};fc.getIframeId=function(){return this.GADGET_IFRAME_PREFIX_+this.gadgetToken+"_"+this.id};
fc.refresh=function(a,b){var c=fcZ.preferredMethod_,d,e={},f=fcZ.getAuthCookieValue(this.communityId),k=f.split("~"),l=fcZ.dateStamp_;if(l&&1<k.length){d=k[2];var k=k[1],m=[this.specUrl,this.communityId,k,l].join(":");e.sig=fcZ.hash(d,m);e.userId=k;e.dateStamp=l}e.container=this.SYND;e.mid=this.id;e.nocache=fcZ.nocache_;e.view=this.view_;e.parent=fcZ.parentUrl_;this.debug&&(e.debug="1");this.specUrl&&(e.url=this.specUrl);this.communityId&&(l=gadgets.util.getUrlParameters().profileId,e.communityId=
this.communityId,(d=gadgets.util.getUrlParameters().psinvite)&&(e.psinvite=d),l&&(e.profileId=l));e.caller=fcqb();e.rpctoken=this.rpcToken;l=!1;d="";k=/Version\/3\..*Safari/;if((k=fcx&&fct.match(k))||!fcZ.lockedDomains[this.specUrl]&&this.viewParams)e["view-params"]=gadgets.json.stringify(this.viewParams),d="?viewParams="+encodeURIComponent(e["view-params"]),l=!0;this.prefs&&(e.prefs=gadgets.json.stringify(this.prefs));this.viewParams&&this.sendViewParamsToServer&&(e["view-params"]=gadgets.json.stringify(this.viewParams));
this.locale&&(e.locale=this.locale);this.secureToken&&(e.st=this.secureToken);k=fcZ.getLockedDomain(this.specUrl);d=k+"ifr"+d+(this.hashData?"&"+this.hashData:"");1!=fcZ.enableProxy_||l||f||this.secureToken?f&&!e.sig&&(e.fcauth=f):e.sig||(c="get");f=this.getIframeId();fcrb(f,d,c,e,a,b,this.rpcToken)};var fc3=function(){this.gadgets_={};this.parentUrl_="http://"+document.location.host;this.view_="default";this.nocache_=1};fcj(fc3,fcnb);fc=fc3.prototype;fc.gadgetClass=fc1;fc.layoutManager=new fcpb;
fc.setNoCache=function(a){this.nocache_=a};fc.enableProxy=function(a){this.enableProxy_=a};fc.getGadgetKey_=function(a){return"gadget_"+a};fc.getGadget=function(a){return this.gadgets_[this.getGadgetKey_(a)]};fc.createGadget=function(a){return new this.gadgetClass(a)};fc.addGadget=function(a){a.id=this.getNextGadgetInstanceId();this.gadgets_[this.getGadgetKey_(a.id)]=a};fc.nextGadgetInstanceId_=0;fc.getNextGadgetInstanceId=function(){return this.nextGadgetInstanceId_++};
var fc5=function(){fc3.call(this);this.layoutManager=new fc4};fcj(fc5,fc3);fc5.prototype.gadgetClass=fc2;fc5.prototype.setParentUrl=function(a){a.match(/^http[s]?:\/\//)||(a=document.location.href.match(/^[^?#]+\//)[0]+a);this.parentUrl_=a};fc5.prototype.renderGadget=function(a){var b=this.layoutManager.getGadgetChrome(a);a.render(b)};var fc4=function(){this.gadgetChromeIds_={}};fcj(fc4,fcob);
fc4.prototype.addGadgetChromeIds=function(a,b){this.gadgetChromeIds_[a]=b;var c=document.getElementById(b).className;c||0!=c.length||(document.getElementById(b).className="gadgets-gadget-container")};fc4.prototype.getGadgetChrome=function(a){return(a=this.gadgetChromeIds_[a.id])?document.getElementById(a):null};var fc6=function(a){fc2.call(this,a);a=a||{};this.view_=a.view||"profile"};fcj(fc6,fc2);fc6.prototype.canvasHtml_="canvas.html";fc6.prototype.embedHtml_="/friendconnect/embed/";
var fcqb=function(){var a="1"==gadgets.util.getUrlParameters().canvas||"1"==gadgets.util.getUrlParameters().embed,b=null;a&&(b=gadgets.util.getUrlParameters().caller);b||(a=document.location,b=a.search.replace(/([&?]?)psinvite=[^&]*(&?)/,function(a,b,e){return e?b:""}),b=a.protocol+"//"+a.hostname+(a.port?":"+a.port:"")+a.pathname+b);return b};fc=fc6.prototype;fc.setView=function(a){this.view_=a};fc.getBodyId=function(){return this.getIframeId()+"_body"};
fc.getMainContent=function(a){var b=this.specUrl;void 0===b&&(b="");var b=(fcZ.getLockedDomain(b)||this.serverBase_)+this.rpcRelay,c=this.getIframeId();gadgets.rpc.setRelayUrl(c,b);b='<div id="'+this.getBodyId()+'"><iframe id="'+c+'" name="'+c;b=0==this.height?b+'" style="width:1px; height:1px;':b+'" style="width:100%;';this.viewParams.opaque&&(b+="background-color:white;");b+='"';b+=' frameborder="0" scrolling="no"';this.viewParams.opaque||(b+=' allowtransparency="true"');b+=this.height?' height="'+
this.height+'"':"";b+=this.width?' width="'+this.width+'"':"";b+="></iframe>";this.showEmbedThis&&(b+='<a href="javascript:void(0);" onclick="google.friendconnect.container.showEmbedDialog(\''+this.divId+"'); return false;\">Embed this</a>");b+="</div>";a(b)};
fc.getCanvasUrl=function(){var a=fcqb(),a="canvas=1&caller="+encodeURIComponent(a),b=gadgets.util.getUrlParameters().psinvite;b&&(a+="&psinvite="+encodeURIComponent(b));a+="&site="+encodeURIComponent(this.communityId);b=fcg(this.viewParams);if(null!=b.skin)for(var c="BG_IMAGE BG_COLOR FONT_COLOR BG_POSITION BG_REPEAT ANCHOR_COLOR FONT_FACE BORDER_COLOR CONTENT_BG_COLOR CONTENT_HEADLINE_COLOR CONTENT_LINK_COLOR CONTENT_SECONDARY_TEXT_COLOR CONTENT_SECONDARY_LINK_COLOR CONTENT_TEXT_COLOR ENDCAP_BG_COLOR ENDCAP_LINK_COLOR ENDCAP_TEXT_COLOR CONTENT_VISITED_LINK_COLOR ALTERNATE_BG_COLOR".split(" "),
d=0;d<c.length;d++)delete b.skin[c[d]];b=encodeURIComponent(gadgets.json.stringify(b));b=b.replace("\\","%5C");return fcZ.parentUrl_+this.canvasHtml_+"?url="+encodeURIComponent(this.specUrl)+(a?"&"+a:"")+"&view-params="+b};fc.getEmbedUrl=function(a){a=a||friendconnect_serverBase+this.embedHtml_+this.communityId;return this.getEmbedUrl_(a,"embed=1")};fc.getEmbedHtml=function(a){return'<iframe src="'+this.getEmbedUrl(a)+'" style="height:500px" scrolling="no" allowtransparency="true" border="0" frameborder="0" ></iframe>'};
fc.getEmbedUrl_=function(a,b){var c=encodeURIComponent(gadgets.json.stringify(this.viewParams)),c=c.replace("\\","%5C");return a+"?url="+encodeURIComponent(this.specUrl)+(b?"&"+b:"")+"&view-params="+c};fc.getProfileUrl=function(){var a="1"==gadgets.util.getUrlParameters().canvas||"1"==gadgets.util.getUrlParameters().embed,b=null;a&&((b=gadgets.util.getUrlParameters().caller)||(b="javascript:history.go(-1)"));return b};
fc.getUrlForView=function(a){if("canvas"==a)a=this.getCanvasUrl();else if("profile"==a)a=this.getProfileUrl();else return null;a instanceof fcI||(a=a.implementsGoogStringTypedString?a.privateDoNotAccessOrElseSafeHtmlWrappedValue_:String(a),fcPa.test(a)||(a="about:invalid#zClosurez"),a=fcQa(a));a instanceof fcI&&a.constructor===fcI&&a.SAFE_URL_TYPE_MARKER_GOOG_HTML_SECURITY_PRIVATE_===fcOa?a=a.privateDoNotAccessOrElseSafeHtmlWrappedValue_:(fcqa("expected object of type SafeUrl, got '"+a+"' of type "+
fcc(a)),a="type_error:SafeUrl");return a};
var fc8=function(){fc5.call(this);gadgets.rpc.register("signin",fc0.prototype.signin);gadgets.rpc.register("signout",fc0.prototype.signout);gadgets.rpc.register("resize_iframe",fc0.prototype.setHeight);gadgets.rpc.register("set_title",fc0.prototype.setTitle);gadgets.rpc.register("requestNavigateTo",fc0.prototype.requestNavigateTo);gadgets.rpc.register("api_loaded",fc0.prototype.apiLoaded_);gadgets.rpc.register("createFriendBarMenu",fc0.prototype.createFriendBarMenu);gadgets.rpc.register("showFriendBarMenu",
fc0.prototype.showFriendBarMenu);gadgets.rpc.register("hideFriendBarMenu",fc0.prototype.hideFriendBarMenu);gadgets.rpc.register("putReloadViewParam",fc0.prototype.putReloadViewParam);gadgets.rpc.register("getViewParams",fc0.prototype.deliverViewParams);gadgets.rpc.register("getContainerBaseTime",fc0.prototype.deliverContainerBaseTime);gadgets.rpc.register("openLightboxIframe",fc0.prototype.openLightboxIframeRpcEntry);gadgets.rpc.register("showMemberProfile",fc0.prototype.showMemberProfile_);gadgets.rpc.register("closeLightboxIframe",
fch(this.closeLastLightBoxDialog,this));gadgets.rpc.register("setLightboxIframeTitle",fch(this.setLightboxIframeTitle,this));gadgets.rpc.register("refreshAndCloseIframeLightbox",fch(this.refreshAndCloseLightboxIframe,this));fc7.register();fc7.subscribeContainer(this,"load",this.handleGadgetLoad);fc7.subscribeContainer(this,"start",this.handleGadgetStart);this.serverBase_="../../";this.setParentUrl("");this.setNoCache(0);this.enableProxy(1);this.lockedDomainSuffix_=null;this.apiVersion="0.8";this.openSocialSecurityToken=
null;this.serverVersion_="";this.currentAuthToken_={};this.lightboxCssIsLoaded_=null;this.lightBoxJsIsLoaded_=!1;this.dateStamp_=this.locale_=this.lastIframeLightboxOpenArguments=this.lastLightboxCallback=this.lastLightboxDialog=null;this.preferredMethod_="post"};fcj(fc8,fc5);fc=fc8.prototype;fc.setDateStamp_=function(a){this.dateStamp_=a};fc.gadgetClass=fc6;fc.lockedDomains={};fc.setLockedDomainSuffix=function(a){this.lockedDomainSuffix_=a};
fc.getLockedDomain=function(a){var b=fc8.prototype.lockedDomains[a];if(!b)if(0!==this.lockedDomainSuffix_.indexOf("https://")){var b=this.computeLockedDomain_(a),c="//";0==a.indexOf("https://")?c="https://":0==a.indexOf("http://")&&(c="http://");b=[c,b,this.lockedDomainSuffix_].join("")}else b=this.lockedDomainSuffix_;return b};
fc.computeLockedDomain_=function(a){var b=new fcH;a=fcJa(a);b.update(a);b=b.digest();b=new fc_(b);if(b.numRemainingBits()%5)throw Error();a=[];for(var c=0;0<b.numRemainingBits();c++)a[c]="0123456789abcdefghijklmnopqrstuv".charAt(b.nextNBits(5));return b=a.join("")};
var fc9=function(a,b){var c=b?b:window.top,d=c.frames;try{if(c.frameElement.id==a)return c}catch(f){}for(c=0;c<d.length;++c){var e=fc9(a,d[c]);if(e)return e}return null},fcrb=function(a,b,c,d,e,f,k){var l="gfc_load_"+a;b='<html><head><style type="text/css">body {background:transparent;}</style>'+(fcv?'<script type="text/javascript">window.goback=function(){history.go(-1);};setTimeout("goback();", 0);\x3c/script>':"")+"</head><body><form onsubmit='window.goback=function(){};return false;' style='margin:0;padding:0;' id='"+
l+"' method='"+c+"' ' action='"+gadgets.util.escapeString(b)+"'>";for(var m in d)b+="<input type='hidden' name='"+gadgets.util.escapeString(m)+"' value='' >";b+="</form></body></html>";c=fc9(a);var n;try{n=c.document||c.contentWindow.document}catch(g){e&&f&&(e.innerHTML="",e.innerHTML=f,c=fc9(a),n=c.document||c.contentWindow.document)}k&&gadgets.rpc.setAuthToken(a,k);n.open();n.write(b);n.close();a=n.getElementById(l);for(m in d)a[m].value=d[m];if(fcv)a.onsubmit();a.submit()};fc=fc8.prototype;
fc.executeFcInitFunctions_=function(){var a=gadgets.util.getUrlParameters().fcsite,b=gadgets.util.getUrlParameters().fcprofile;a&&b&&fcZ.showMemberProfile(b,a)};fc.setDomain=function(a,b){this.lockedDomains[a]=b};
fc.refreshGadgets=function(){var a=/Version\/3\..*Safari/;if(a=fcx&&fct.match(a))document.location.reload();else{null!=fcZ.friendbar_&&fcZ.friendbar_.refresh();for(var b in fcZ.gadgets_)a=fcZ.gadgets_[b],this.renderGadget(a);null!=this.lastIframeLightboxOpenArguments&&(b=this.lastIframeLightboxOpenArguments,this.closeLastLightBoxDialog(),this.openLightboxIframe.apply(this,b))}};
fc.setParentUrl=function(a){a.match(/^http[s]?:\/\//)||(a=a&&0<a.length&&"/"==a.substring(0,1)?document.location.href.match(/^http[s]?:\/\/[^\/]+\//)[0]+a.substring(1):document.location.href.match(/^[^?#]+\//)[0]+a);this.parentUrl_=a};fc.getAuthCookieName=function(a){return"fcauth"+a};fc.getSessionAuthCookieName=function(a){return"fcauth"+a+"-s"};
fc.hash=function(a,b){var c=new fcH,d=fcLa(a,!0),c=new fcG(c,d,64),d=fcJa(b),c=c.getHmac(d);fcq(fcd(c),"encodeByteArray takes an array as a parameter");fcMa();for(var d=fcF,e=[],f=0;f<c.length;f+=3){var k=c[f],l=f+1<c.length,m=l?c[f+1]:0,n=f+2<c.length,g=n?c[f+2]:0,h=k>>2,k=(k&3)<<4|m>>4,m=(m&15)<<2|g>>6,g=g&63;n||(g=64,l||(m=64));e.push(d[h],d[k],d[m],d[g])}return c=e.join("")};
fc.getAuthCookieValue=function(a){return a=fcK.get(this.getAuthCookieName(a))||fcK.get(this.getSessionAuthCookieName(a))||this.currentAuthToken_[a]||""};fc.setServerBase=function(a){this.serverBase_=a};fc.setServerVersion=function(a){this.serverVersion_=a};fc.createGadget=function(a){a=new this.gadgetClass(a);a.setServerBase(this.serverBase_);return a};fc.setLocale=function(a){this.locale_=a};var fc$=function(a){return(a=a.match(/_([0-9]+)$/))?parseInt(a[1],10):null};fc=fc8.prototype;
fc.showLightBoxDialog=function(a,b,c,d,e,f){this.containerCssIsLoaded_||(this.addCssFile_(window.friendconnect_serverBase+"/friendconnect/styles/container.css?d="+this.serverVersion_),this.containerCssIsLoaded_=!0);var k=fcsb(d);this.lightboxCssIsLoaded_!=(k?"rtl":"ltr")&&(this.addCssFile_(window.friendconnect_serverBase+"/friendconnect/styles/lightbox"+(k?"-rtl":"")+".css?d="+this.serverVersion_),this.lightboxCssIsLoaded_=k?"rtl":"ltr");this.lightBoxJsIsLoaded_||(this.addJsFile_(window.friendconnect_serverBase+
"/friendconnect/script/lightbox.js?d="+this.serverVersion_),this.lightBoxJsIsLoaded_=!0);b=b||0;if(goog.ui&&goog.ui.Dialog){this.closeLastLightBoxDialog();b=new goog.ui.Dialog("lightbox-dialog",!0);var l=this;goog.events.listen(b,goog.ui.Dialog.EventType.AFTER_HIDE,function(){l.lastLightboxCallback&&l.lastLightboxCallback();l.cleanupLightboxState()});b.setDraggable(!0);b.setDisposeOnHide(!0);b.setBackgroundElementOpacity(.5);b.setButtonSet(new goog.ui.Dialog.ButtonSet);this.lastLightboxDialog=b;this.lastLightboxCallback=
c||null;c=b.getDialogElement();e=e||702;fcR(c,"width",String(e)+"px");f&&fcR(c,"height",String(f)+"px");a(b);b.getDialogElement().style.direction=k?"rtl":"ltr"}else if(5>b)b++,a=fch(this.showLightBoxDialog,this,a,b,c,d,e,f),setTimeout(a,1E3);else throw this.cleanupLightboxState(),Error("lightbox.js failed to load");};
fc.closeLastLightBoxDialog=function(a){var b=this.lastLightboxDialog,c=this.lastLightboxCallback;this.lastLightboxCallback=null;null!=b&&(this.lastLightboxDialog.dispatchEvent(goog.ui.Dialog.EventType.AFTER_HIDE),b.dispose(),null!=c&&c(a))};fc.cleanupLightboxState=function(){this.lastIframeLightboxOpenArguments=this.lastLightboxCallback=this.lastLightboxDialog=null};fc.setLightboxIframeTitle=function(a){this.lastLightboxDialog&&this.lastLightboxDialog.setTitle(a)};
fc.refreshAndCloseLightboxIframe=function(){this.closeLastLightBoxDialog();this.refreshGadgets()};
fc0.prototype.requestNavigateTo=function(a,b){var c=fc$(this.f),c=fcZ.getGadget(c),d=fcg(c.originalParams);b&&(d["view-params"]=d["view-params"]||{},d["view-params"]=b);d.locale=c.locale;if(c.useLightBoxForCanvas)d.presentation=a,null!=fcZ.lastLightboxDialog?fcZ.closeLastLightBoxDialog():fcZ.showLightboxGadget_(d);else if((c=c.getUrlForView(a))&&document.location.href!=c)if("1"==gadgets.util.getUrlParameters().embed)try{window.parent.location=c}catch(e){window.top.location=c}else document.location.href=
c};
fc8.prototype.showLightboxGadget_=function(a,b){a=a||{};var c=a.locale,d=fcsb(c),e=this;this.closeLastLightBoxDialog();this.showLightBoxDialog(function(b){var c=fcN("div",{},fcN("div",{id:"gadget-signin",style:"background-color:#ffffff;height:32px;"}),fcN("div",{id:"gadget-lb-canvas",style:"background-color:#ffffff;"}));b.getTitleTextElement().appendChild(fcN("div",{id:"gfc-canvas-title",style:"color:#000000;"}));b.getContentElement().appendChild(c);b.setVisible(!0);var c=fcg(a),l=fc_a(window),m=
Math.round(.7*l.height),l={BORDER_COLOR:"#cccccc",ENDCAP_BG_COLOR:"#e0ecff",ENDCAP_TEXT_COLOR:"#333333",ENDCAP_LINK_COLOR:"#0000cc",ALTERNATE_BG_COLOR:"#ffffff",CONTENT_BG_COLOR:"#ffffff",CONTENT_LINK_COLOR:"#0000cc",CONTENT_TEXT_COLOR:"#333333",CONTENT_SECONDARY_LINK_COLOR:"#7777cc",CONTENT_SECONDARY_TEXT_COLOR:"#666666",CONTENT_HEADLINE_COLOR:"#333333"};c.id="gadget-lb-canvas";c.height=Math.min(498,m)+"px";c.maxHeight=m;c.keepMax&&(c.height=m,fcR(b.getContentElement(),"height",m+35+"px"));c["view-params"]=
c["view-params"]||{};c["view-params"].opaque=!0;c["view-params"].skin=c["view-params"].skin||{};var m=c["view-params"].skin,n=l,g;for(g in n)m[g]=n[g];e.render(c);g={id:"gadget-signin",presentation:"canvas"};g.site=c.site;g.titleDivId="gfc-canvas-title";g["view-params"]={};g["view-params"].opaque=!0;g.keepMax=c.keepMax;c.securityToken&&(g.securityToken=c.securityToken);c=fcg(l);c.ALIGNMENT=d?"left":"right";e.renderSignInGadget(g,c);b.reposition()},void 0,b,c)};
fc0.prototype.showFriendBarMenu=function(a,b){null!=fcZ.friendbar_&&fcZ.friendbar_.showMenu(a,b)};fc0.prototype.hideFriendBarMenu=function(a){null!=fcZ.friendbar_&&fcZ.friendbar_.hideMenu(a)};fc0.prototype.openLightboxIframeRpcEntry=function(a,b,c,d,e,f,k,l,m,n){var g=this.f;a=a+(0<=a.indexOf("?")?"&":"?")+"iframeId="+g;fcZ.openLightboxIframe(a,b,c,d,e,f,k,l,m,n,this.callback)};
fc8.prototype.openLightboxIframe=function(a,b,c,d,e,f,k,l,m,n,g){var h=fc_a(window);null==d&&(d=Math.round(.7*h.height));null==c&&(c=Math.round(.7*h.width));for(var q=[],h=0;h<arguments.length&&10>h;h++)q.push(arguments[h]);if("/"!=a[0])throw Error("lightbox iframes must be relative to fc server");var v=this,p=f?fcg(f):{},t=String(Math.round(2147483647*Math.random())),r="gfc_lbox_iframe_"+t;gadgets.rpc.setAuthToken(r,t);b||(b=fcZ.openSocialSecurityToken);var u=fcZ.openSocialSiteId;fcZ.showLightBoxDialog(function(c){v.lastIframeLightboxOpenArguments=
q;var f="st="+encodeURIComponent(b)+"&parent="+encodeURIComponent(fcZ.parentUrl_)+"&rpctoken="+encodeURIComponent(t);l||(p.iframeId=r,p.iurl=a,a=friendconnect_serverBase+"/friendconnect/lightbox");var g=d-54;p.height=g;var h='<iframe id="'+r,h=h+('" width="100%" height="'+g+'" frameborder="0" scrolling="auto"></iframe>');c.setSafeHtmlContent(fcSa(h));e&&(c.setTitle(e),n&&(g=c.getTitleTextElement(),fcVa(g,"lightbox-dialog-title-small-text")));c.setVisible(!0);m||(p.fcauth=fcZ.getAuthCookieValue(u));
a+=(0<=a.indexOf("?")?"&":"?")+f+"&communityId="+u;fcrb(r,a,"POST",p,null,null,null)},void 0,g,void 0,c,d)};fc0.prototype.deliverViewParams=function(){var a=fc$(this.f),a=fcZ.getGadget(a);return a.viewParams};fc0.prototype.deliverContainerBaseTime=function(){return fcmb};fc0.prototype.putReloadViewParam=function(a,b){var c=fc$(this.f),c=fcZ.getGadget(c);c.viewParams[a]=b};fc8.prototype.handleGadgetLoad=function(a,b){null!=fcZ.friendbar_&&fcZ.friendbar_.menuLoad(b)};
fc8.prototype.handleGadgetStart=function(a,b){null!=fcZ.friendbar_&&fcZ.friendbar_.menuStart(b)};fc0.prototype.createFriendBarMenu=function(a,b,c,d){null!=fcZ.friendbar_&&fcZ.friendbar_.createMenu(a,b,c,d)};fc8.prototype.renderGadget=function(a){var b=this.layoutManager.getGadgetChrome(a);a.render(b);this.layoutManager.postProcessGadget&&this.layoutManager.postProcessGadget(a)};
fc0.prototype.signout=function(a){fcZ.removeCookie_(fcZ.getAuthCookieName(a));fcZ.removeCookie_(fcZ.getSessionAuthCookieName(a));fcZ.currentAuthToken_={};fcZ.refreshGadgets();return!1};fc8.prototype.removeCookie_=function(a){for(var b=document.location.pathname,b=b.split("/"),c=0;c<b.length;c++){for(var d=Array(c+1),e=0;e<c+1;e++)d[e]=b[e];fcK.remove(a,d.join("/")+"/")}};
fc0.prototype.setHeight=function(a){var b=document.getElementById(this.f);b&&0<a&&(b.style.height=a+"px");(b=document.getElementById(this.f+"_body"))&&0<a&&(b.style.height=a+"px");if(b=fc$(this.f)){var c=fcZ.getGadget(b);c&&((b=document.getElementById(c.divId))&&0<a&&(c&&c.maxHeight&&c.maxHeight<a&&(a=c.maxHeight,b.style.overflowY="auto"),b.style.height=a+"px"),!c.keepMax&&"canvas"==c.view_&&fcZ.lastLightboxDialog&&fcZ.lastLightboxDialog.reposition(),fcR(c.chrome,"visibility","visible"))}};
fc0.prototype.setTitle=function(a){var b=fc$(this.f),b=fcZ.getGadget(b);if(b=b.titleDivId)document.getElementById(b).innerHTML=gadgets.util.escapeString(a)};fc0.prototype.signin=function(a,b,c){fcK.set(fcZ.getAuthCookieName(a),b,31104E3,c);fcK.set(fcZ.getSessionAuthCookieName(a),b,-1,c);fcZ.currentAuthToken_[a]=b;fcZ.refreshGadgets()};var fcub=function(a){fcgb(a,fctb)};fc=fc8.prototype;
fc.renderMembersGadget=function(a,b){b&&this.addSkinToOptions_(b,a);var c={};c.url=friendconnect_serverBase+"/friendconnect/gadgets/members.xml";this.render(this.addDefaults_(a,c))};fc.renderReviewGadget=function(a,b){b&&this.addSkinToOptions_(b,a);var c={};c.url=friendconnect_serverBase+"/friendconnect/gadgets/review.xml";c["view-params"]={startMaximized:"true",disableMinMax:"true",features:"review"};this.render(this.addDefaults_(a,c))};
fc.renderCommentsGadget=function(a,b){b&&this.addSkinToOptions_(b,a);var c={};c.url=friendconnect_serverBase+"/friendconnect/gadgets/wall.xml";c["view-params"]={startMaximized:"true",disableMinMax:"true",features:"comment"};this.render(this.addDefaults_(a,c))};fc.renderSignInGadget=function(a,b){b&&this.addSkinToOptions_(b,a);var c={};c.url=friendconnect_serverBase+"/friendconnect/gadgets/signin.xml";c.height=32;this.render(this.addDefaults_(a,c))};
fc.renderAdsGadget=function(a,b){b&&this.addSkinToOptions_(b,a);a.prefs=a.prefs||{};a.sendViewParamsToServer=!0;a.prefs.hints=window.google_hints;var c={};c.url=friendconnect_serverBase+"/friendconnect/gadgets/ads.xml";c.height=90;this.render(this.addDefaults_(a,c))};
fc.renderSocialBar=function(a,b){if(a.id){b&&this.addSkinToOptions_(b,a);a["view-params"]=a["view-params"]||{};a["view-params"].opaque="true";this.friendbar_=new fcX(a);this.friendbar_.render();var c={};c.url=friendconnect_serverBase+"/friendconnect/gadgets/friendbar.xml";a.id=this.friendbar_.barId_;a.height="1";this.render(this.addDefaults_(a,c))}};fc.renderFriendBar=fc8.prototype.renderSocialBar;
fc.renderEmbedSignInGadget=function(a,b){a=a||{};a.url=friendconnect_serverBase+"/friendconnect/gadgets/signin.xml";a.site=a.site||gadgets.util.getUrlParameters().site;a.height=32;this.renderEmbedGadget(a,b)};fc.renderCanvasSignInGadget=fc8.prototype.renderEmbedSignInGadget;fc.renderWallGadget=fc8.prototype.renderCommentsGadget;fc.addSkinToOptions_=function(a,b){var c=b["view-params"];c||(c={},b["view-params"]=c);c.skin=a};
fc.addDefaults_=function(a,b){var c=this.mixInDefaults_(b,a);if(b["view-params"]){var d=b["view-params"];a["view-params"]&&(d=this.mixInDefaults_(d,a["view-params"]));c["view-params"]=d}return c};fc.renderOpenSocialGadget=function(a,b){b&&this.addSkinToOptions_(b,a);this.render(a)};fc.mixInDefaults_=function(a,b){var c={},d;for(d in b)c[d]=b[d];for(d in a)"undefined"==typeof c[d]&&(c[d]=a[d]);return c};
fc.render=function(a){this.openSocialSiteId=a.site;a["view-params"]=a["view-params"]||{};var b=this.createGadget({divId:a.id,specUrl:a.url,communityId:a.site,height:a.height,locale:a.locale||this.locale_,secureToken:a.securityToken,titleDivId:a.titleDivId,showEmbedThis:a.showEmbedThis,useLightBoxForCanvas:a.useLightBoxForCanvas||"undefined"==typeof a.useLightBoxForCanvas&&window.friendconnect_lightbox,viewParams:a["view-params"],prefs:a.prefs,originalParams:a,debug:a.debug,maxHeight:a.maxHeight,sendViewParamsToServer:a.sendViewParamsToServer,
keepMax:a.keepMax});a.presentation&&b.setView(a.presentation);this.addGadget(b);this.layoutManager.addGadgetChromeIds(b.id,a.id);setTimeout(function(){fcZ.renderGadget(b)},0);return b.id};fc.renderUrlCanvasGadget=function(a,b){a=a||{};a.presentation="canvas";this.renderUrlEmbedGadget(a,b)};
fc.renderUrlEmbedGadget=function(a,b,c){a=a||{};a.url=gadgets.util.getUrlParameters().url;a.site=gadgets.util.getUrlParameters().site||a.site;var d=gadgets.util.getUrlParameters()["view-params"];d&&(a["view-params"]=gadgets.json.parse(decodeURIComponent(d)));c&&(a["view-params"]=a["view-params"]||{},a["view-params"].useFixedHeight=!0,a["view-params"].height=c,b=b||{},b.HEIGHT=String(c));this.renderEmbedGadget(a,b)};
fc.renderEmbedGadget=function(a,b){a=a||{};b&&this.addSkinToOptions_(b,a);"1"==gadgets.util.getUrlParameters().canvas?a.presentation="canvas":"1"==gadgets.util.getUrlParameters().embed&&(a.presentation="embed");fcZ.render(a)};
fc.goBackToSite=function(){var a=gadgets.util.getUrlParameters().caller;a&&document.location.href!=a&&8<a.length&&("http://"==a.substr(0,7).toLowerCase()||"https://"==a.substr(0,8).toLowerCase())?document.location.href=a:(a=gadgets.util.getUrlParameters().site)?document.location.href=friendconnect_serverBase+"/friendconnect/directory/site?id="+a:window.history.go(-1)};fc.openSocialApiIframeId="";fc.getOpenSocialApiIframeId=function(){return this.openSocialApiIframeId};
fc.setApiVersion=function(a){this.apiVersion=a};fc.addCssFile_=function(a){var b=document.createElement("link");b.setAttribute("rel","stylesheet");b.setAttribute("type","text/css");b.setAttribute("href",a);document.getElementsByTagName("head")[0].appendChild(b)};fc.addJsFile_=function(a){var b=document.createElement("script");b.setAttribute("src",a);b.setAttribute("type","text/javascript");document.getElementsByTagName("head")[0].appendChild(b)};
fc.callFunctionOnPageLoad_=function(a){document.body?a():window.addEventListener?window.addEventListener("load",a,!1):window.attachEvent("onload",a)};fc.initOpenSocialApi=function(a){if(!a.site)throw"API not loaded, please pass in a 'site'";this.addCssFile_(window.friendconnect_serverBase+"/friendconnect/styles/container.css?d="+this.serverVersion_);this.openSocialSiteId=a.site;this.apiLoadedCallback=a.onload;this.callFunctionOnPageLoad_(fch(this.loadOpenSocialApi_,this,a,"fc-opensocial-api"))};
fc.loadOpenSocialApi=fc8.prototype.initOpenSocialApi;fc.invokeOpenSocialApiViaIframe=function(a){var b={};b.site=this.openSocialSiteId;b["view-params"]={txnId:a};this.loadOpenSocialApi_(b,"gfc-"+a)};fc.removeOpenSocialApiViaIframe=function(a){var b={},c;for(c in this.gadgets_){var d=this.gadgets_[c];if(d.viewParams&&d.viewParams.txnId==a)break;else b[c]=d}this.gadgets_=b;(a=document.getElementById("gfc-"+a))&&a.parentNode&&a.parentNode.removeChild&&a.parentNode.removeChild(a)};
var fcvb=function(a){var b;if(a.multiple){b=[];for(var c=0;c<a.options.length;c++)a.options[c].selected&&b.push(a.options[c].value);c=a.getAttribute("x-max");try{c*=1}catch(e){c=0}if(c&&b.length>c&&a["x-selected"])for(b=a["x-selected"],c=0;c<a.options.length;c++){a.options[c].selected=!1;for(var d=0;d<b.length;d++)if(a.options[c].value==b[d]){a.options[c].selected=!0;break}}}else b=a.options[a.selectedIndex].value;a["x-selected"]=b;(c=a.getAttribute("x-var"))&&window.opensocial.data&&window.opensocial.data.getDataContext().putDataSet(c,
b);if(c=a.getAttribute("x-onselect"))if(window[c]&&"function"==typeof window[c])window[c](b);else a["x-onselect-fn"]?a["x-onselect-fn"].apply(a):a["x-onselect-fn"]=new Function(c)};
fc8.prototype.loadOpenSocialApi_=function(a,b){window.opensocial.template.Loader.loadContent("<Templates xmlns:os='http://ns.opensocial.org/2008/markup'><Namespace prefix='os' url='http://ns.opensocial.org/2008/markup'/><Template tag='os:Name'>  <span if='${!My.person.profileUrl}'>${My.person.displayName}</span>  <a if='${My.person.profileUrl}' href='${My.person.profileUrl}'>      ${My.person.displayName}</a></Template><Template tag='os:Badge'>  <div><img if='${My.person.thumbnailUrl}' src='${My.person.thumbnailUrl}'/>   <os:Name person='${My.person}'/></div></Template><Template tag='os:PeopleSelector'>  <select onchange='google.friendconnect.PeopleSelectorOnChange(this)' name='${My.inputName}'          multiple='${My.multiple}' x-var='${My.var}' x-max='${My.max}'          x-onselect='${My.onselect}'>    <option repeat='${My.group}' value='${Cur.id}' selected='${Cur.id == My.selected}'>        ${Cur.displayName}    </option>  </select></Template></Templates>");window.opensocial.template.Loader.loadContent("<Templates xmlns:fc='http://www.google.com/friendconnect/makeThisReal'>  <Namespace prefix='fc' url='http://www.google.com/friendconnect/makeThisReal'/>  <Template tag='fc:signIn'>    <div onAttach='google.friendconnect.renderSignInButton({element: this})'></div>  </Template></Templates>");
window.opensocial.data.processDocumentMarkup();var c=document.createElement("div");c.id=b;c.style.height="0px";c.style.width="0px";c.style.position="absolute";c.style.visibility="hidden";document.body.appendChild(c);var d={};d.url=friendconnect_serverBase+"/friendconnect/gadgets/osapi-"+this.apiVersion+".xml";d.height=0;d.id=c.id;d.site=a.site;d["view-params"]=a["view-params"];this.render(d)};
fc0.prototype.apiLoaded_=function(){fcZ.openSocialApiIframeId=this.f;fcZ.openSocialSecurityToken=this.a[0];var a=fcZ.openSocialSecurityToken;window.opensocial.data.executeRequests();window.opensocial.template.process();fcZ.apiLoadedCallback&&(a=fci(fcZ.apiLoadedCallback,a),setTimeout(a,0))};fc8.prototype.getGadgetByDivId=function(a){var b=null,c;for(c in this.gadgets_)if(this.gadgets_[c].divId==a){b=this.gadgets_[c];break}return b};
fc8.prototype.getEmbedUrl=function(a,b){var c=this.getGadgetByDivId(a),d=null;c&&(d=c.getEmbedUrl(b));return d};fc8.prototype.getEmbedHtml=function(a,b){var c=this.getGadgetByDivId(a),d=null;c&&(d=c.getEmbedHtml(b));return d};
fc8.prototype.showEmbedDialog=function(a,b){this.showLightBoxDialog(function(c){var d=document.createTextNode("Copy & paste this code into your site.");c.getContentElement().appendChild(d);c.getContentElement().appendChild(document.createElement("br"));var d=fcZ.getEmbedHtml(a,b),e=document.createElement("textarea");e.innerHTML=d;e.setAttribute("style","width:500px;");c.getContentElement().appendChild(e);c.setVisible(!0)})};
var fcwb="ar dv fa iw he ku pa sd tk ug ur yi".split(" "),fcsb=function(a){a?(a=a.split("_")[0],a=0<=fcr(fcwb,a)):a=(a=fc4a(document.body,"direction"))&&"rtl"==a;return a};fc0.prototype.showMemberProfile_=function(a,b){var c=0,d=null;try{var e=fc$(this.f),f=fcZ.getGadget(e),d=f.secureToken,c=f.communityId}catch(k){}b&&(c=b);fcZ.showMemberProfile(a,c,this.callback,d)};
fc8.prototype.showMemberProfile=function(a,b,c,d){b=b||this.openSocialSiteId;a={keepMax:!0,presentation:"canvas",url:friendconnect_serverBase+"/friendconnect/gadgets/members.xml",site:b,"view-params":{profileId:a}};d&&(a.securityToken=d);this.showLightboxGadget_(a,c)};fc8.prototype.getGadgetSecurityToken=function(a){var b=null;(a=this.getGadgetByDivId(a))&&a.secureToken&&(b=a.secureToken);return b};
fc8.prototype.getGadgetCommunityId=function(a){var b=null;(a=this.getGadgetByDivId(a))&&a.communityId&&(b=a.communityId);return b};var fctb=function(a){fcZ.openSocialApiIframeId&&fcW(fcZ.openSocialApiIframeId,a)},fcxb=function(){fc0.prototype.signout(fcZ.openSocialSiteId)},fcyb=function(){fceb(fcZ.openSocialApiIframeId)},fczb=function(a,b){fcbb(a,b)},fcY=function(){this.subscribers_={}};
fcY.prototype.register=function(){gadgets.rpc.register("subscribeEventType",fc0.prototype.subscribe);gadgets.rpc.register("publishEvent",fc0.prototype.publish)};fc0.prototype.subscribe=function(a){fc7.subscribers_[a]=fc7.subscribers_[a]||[];a=fc7.subscribers_[a];a[a.length]={frameId:this}};fcY.prototype.subscribeContainer=function(a,b,c){var d=this;d.subscribers_[b]=d.subscribers_[b]||[];b=d.subscribers_[b];b[b.length]={container:a,callback:c}};
fc0.prototype.publish=function(a){var b=0;this.f&&(b=fc$(this.f));fc7.subscribers_[a]=fc7.subscribers_[a]||[];for(var c=fc7.subscribers_[a],d=0;d<c.length;d++)c[d].container?c[d].callback.call(c[d].container,a,b):gadgets.rpc.call(c[d].frameId,a,null,a,b)};var fckb=fch(fc0.prototype.publish,new fc0),fc7=new fcY,fcZ=new fc8;fcZ.callFunctionOnPageLoad_(fcZ.executeFcInitFunctions_);fcb("google.friendconnect.container",fcZ,void 0);
fcb("google.friendconnect.container.refreshGadgets",fcZ.refreshGadgets,void 0);fcb("google.friendconnect.container.setParentUrl",fcZ.setParentUrl,void 0);fcb("google.friendconnect.container.setServerBase",fcZ.setServerBase,void 0);fcb("google.friendconnect.container.setServerVersion",fcZ.setServerVersion,void 0);fcb("google.friendconnect.container.createGadget",fcZ.createGadget,void 0);fcb("google.friendconnect.container.openLightboxIframe",fcZ.openLightboxIframe,void 0);
fcb("google.friendconnect.container.renderGadget",fcZ.renderGadget,void 0);fcb("google.friendconnect.container.render",fcZ.render,void 0);fcb("google.friendconnect.container.goBackToSite",fcZ.goBackToSite,void 0);fcb("google.friendconnect.container.renderMembersGadget",fcZ.renderMembersGadget,void 0);fcb("google.friendconnect.container.renderReviewGadget",fcZ.renderReviewGadget,void 0);fcb("google.friendconnect.container.renderCommentsGadget",fcZ.renderCommentsGadget,void 0);
fcb("google.friendconnect.container.renderSignInGadget",fcZ.renderSignInGadget,void 0);fcb("google.friendconnect.container.renderFriendBar",fcZ.renderFriendBar,void 0);fcb("google.friendconnect.container.renderSocialBar",fcZ.renderSocialBar,void 0);fcb("google.friendconnect.container.renderCanvasSignInGadget",fcZ.renderCanvasSignInGadget,void 0);fcb("google.friendconnect.container.renderUrlCanvasGadget",fcZ.renderUrlCanvasGadget,void 0);
fcb("google.friendconnect.container.renderEmbedSignInGadget",fcZ.renderEmbedSignInGadget,void 0);fcb("google.friendconnect.container.renderUrlEmbedGadget",fcZ.renderUrlEmbedGadget,void 0);fcb("google.friendconnect.container.renderEmbedGadget",fcZ.renderEmbedGadget,void 0);fcb("google.friendconnect.container.renderWallGadget",fcZ.renderWallGadget,void 0);fcb("google.friendconnect.container.renderAdsGadget",fcZ.renderAdsGadget,void 0);
fcb("google.friendconnect.container.renderOpenSocialGadget",fcZ.renderOpenSocialGadget,void 0);fcb("google.friendconnect.container.setNoCache",fcZ.setNoCache,void 0);fcb("google.friendconnect.container.enableProxy",fcZ.enableProxy,void 0);fcb("google.friendconnect.container.setDomain",fcZ.setDomain,void 0);fcb("google.friendconnect.container.setLockedDomainSuffix",fcZ.setLockedDomainSuffix,void 0);fcb("google.friendconnect.container.setLocale",fcZ.setLocale,void 0);
fcb("google.friendconnect.container.loadOpenSocialApi",fcZ.loadOpenSocialApi,void 0);fcb("google.friendconnect.container.initOpenSocialApi",fcZ.initOpenSocialApi,void 0);fcb("google.friendconnect.container.getOpenSocialApiIframeId",fcZ.getOpenSocialApiIframeId,void 0);fcb("google.friendconnect.container.setApiVersion",fcZ.setApiVersion,void 0);fcb("google.friendconnect.container.getEmbedUrl",fcZ.getEmbedUrl,void 0);fcb("google.friendconnect.container.getEmbedHtml",fcZ.getEmbedHtml,void 0);
fcb("google.friendconnect.container.getGadgetSecurityToken",fcZ.getGadgetSecurityToken,void 0);fcb("google.friendconnect.container.getGadgetCommunityId",fcZ.getGadgetCommunityId,void 0);fcb("google.friendconnect.container.showEmbedDialog",fcZ.showEmbedDialog,void 0);fcb("google.friendconnect.container.showMemberProfile",fcZ.showMemberProfile,void 0);fcb("google.friendconnect.requestSignIn",fctb,void 0);fcb("google.friendconnect.requestSignOut",fcxb,void 0);
fcb("google.friendconnect.requestSettings",fcyb,void 0);fcb("google.friendconnect.requestInvite",fczb,void 0);fcb("google.friendconnect.renderSignInButton",fcub,void 0);fcb("google.friendconnect.container.invokeOpenSocialApiViaIframe",fcZ.invokeOpenSocialApiViaIframe,void 0);fcb("google.friendconnect.container.removeOpenSocialApiViaIframe",fcZ.removeOpenSocialApiViaIframe,void 0);fcb("google.friendconnect.userAgent.WEBKIT",fcx,void 0);fcb("google.friendconnect.userAgent.IE",fcv,void 0);
fcb("google.friendconnect.PeopleSelectorOnChange",fcvb,void 0);fcb("google.friendconnect.container.setDateStamp_",fcZ.setDateStamp_,void 0);
google.friendconnect.container.setServerBase('http://www-a-fc-opensocial.googleusercontent.com/ps/');google.friendconnect.container.setServerVersion('0.1-d9f87570_ff0243f8_d01f42bf_70753ecd_725a83a6.7');google.friendconnect.container.setApiVersion('0.8');
google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/activities.xml', 'https://umvqpbsra7b9da3v73i9b1f1h35v9875-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/ask.xml', 'https://c5n5mdkbldclvs9c4cmka1i473qj7347-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/friendbar.xml', 'https://tc1gsfg1bpg3dh74e58frg31jhrlijmb-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/content_reveal.xml', 'https://vpkdf3e9ad3mo1u6rf6q8mkvlfh4nhb8-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/donate.xml', 'https://gdp3j78c303214vet22si9nv69isi5so-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/lamegame.xml', 'https://6odruuecb3fkc62vkrn46k05ar324r65-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/map.xml', 'https://42v8m9qahgskau24qus2aa8llgtoj86r-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/members.xml', 'https://4t4qjto8n6vcba9cabf6v2lrng9ast6r-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/newsletterSubscribe.xml', 'https://grcrlo3milo17raaukkj6qnod5edu0v0-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/poll.xml', 'https://0a3ga3vn4gfsdhlqn7pruh1qtq66jpl4-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/recommended_pages.xml', 'https://9pn9h0ef3oqan95jq679oms4lbrhvqkf-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/review.xml', 'https://bvb14dk05gfgdvof7iqdkoufuclkqhg6-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/sample.xml', 'https://kl1m4ltugaae61po1k12eouge39oohh6-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/signin.xml', 'https://9fruo8jik01ke9p21si44s2pu0vt6kk4-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/wall.xml', 'https://fp8527dih8ahqgno54vjfjeju73lvgf4-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setDomain('https://www.google.com/friendconnect/gadgets/osapi-0.8.xml', 'https://3lijfq2nn4jrph2q8dn9vdup48cr0vv5-a-fc-opensocial.googleusercontent.com/ps/');

google.friendconnect.container.setLockedDomainSuffix('-a-fc-opensocial.googleusercontent.com/ps/');
window['__ps_loaded__'] = true; 
 }google.friendconnect_ = google.friendconnect;
google.friendconnect.container.setDateStamp_('155df0fcf52');