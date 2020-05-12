// find this script
var target_script;
var scripts = document.getElementsByTagName('script');
for (var i=0; i<scripts.length; i++) {
  if (scripts[i].src == 'https://www.sparkfun.com/wish_lists/115606.js') {
    target_script = scripts[i];
    break;
  }
}
var target_parent = target_script.parentNode;

// css
var styles = document.createElement('link');
styles.rel = 'stylesheet';
styles.type = 'text/css';
styles.href = 'https://www.sparkfun.com/css/embed/wish_list.css';
target_parent.insertBefore(styles, target_script);

// wrapper for innerHTML
var wrapper = document.createElement('div');

var html = '<div id="wish-list-115606" class="sfe-wish-list">';

html += '<div class="sfe-title"><a href="https://www.sparkfun.com/wish_lists/115606"><strong>MPU-9150 Hookup Guide</strong> <span class="sfewl">SparkFun Wish List</span></a>';

// only show add to cart if on sparkfun.com
if (document.domain.match(/sparkfun\.com/)) {
  html += '<form action="https://www.sparkfun.com/wish_lists/115606/dump" method="post"><input type=submit value="Add all to cart" class="btn btn-default" /></form>';
}

html += '</div>';

html += '<div class="sfe-inner"><div class="sfe-row"><a href="https://www.sparkfun.com/products/11486"><img width="58" height="58" class="sfe-thumbnail" src="https://cdn.sparkfun.com/r/58-58/assets/parts/7/3/7/6/11486-01.jpg" /><span class="sfe-text"><span class="sfe-item-title">SparkFun 9 Degrees of Freedom Breakout - MPU-9150 <span class="sfe-sku"><span class="sfe-stock sfe-stock-retired" title="Retired"></span> SEN-11486</span></span><span class="sfe-description">The SparkFun 9DOF MPU-9150 is the world’s first 9-axis MotionTracking MEMS device designed for the low power, low cost, and high performance require&hellip;</span></span></a></div><div class="sfe-row"><a href="https://www.sparkfun.com/products/11114"><img width="58" height="58" class="sfe-thumbnail" src="https://cdn.sparkfun.com/r/58-58/assets/parts/6/5/4/0/11114-01a.jpg" /><span class="sfe-text"><span class="sfe-item-title">Arduino Pro Mini 328 - 3.3V/8MHz <span class="sfe-sku"><span class="sfe-stock sfe-stock-in" title="in stock"></span> DEV-11114</span></span><span class="sfe-description">It\'s blue! It\'s thin! It\'s the Arduino Pro Mini! SparkFun\'s minimal design approach to Arduino. This is a 3.3V Arduino running the 8MHz bootloader. Ar&hellip;</span></span></a></div><div class="sfe-row"><a href="https://www.sparkfun.com/products/116"><img width="58" height="58" class="sfe-thumbnail" src="https://cdn.sparkfun.com/r/58-58/assets/parts/1/0/6/00116-02-L.jpg" /><span class="sfe-text"><span class="sfe-item-title">Break Away Headers - Straight <span class="sfe-sku"><span class="sfe-stock sfe-stock-in" title="in stock"></span> PRT-00116</span></span><span class="sfe-description">A row of headers - break to fit. 40 pins that can be cut to any size. Used with custom PCBs or general custom headers.**Features: *** Pin Style: Squar&hellip;</span></span></a></div><div class="sfe-row"><a href="https://www.sparkfun.com/products/12002"><img width="58" height="58" class="sfe-thumbnail" src="https://cdn.sparkfun.com/r/58-58/assets/parts/8/5/0/3/12002-04.jpg" /><span class="sfe-text"><span class="sfe-item-title">Breadboard - Self-Adhesive (White) <span class="sfe-sku"><span class="sfe-stock sfe-stock-in" title="in stock"></span> PRT-12002</span></span><span class="sfe-description">This is your tried and true white solderless breadboard. It has 2 power buses, 10 columns, and 30 rows - a total of 400 tie in points. All pins are sp&hellip;</span></span></a></div><div class="sfe-row"><a href="https://www.sparkfun.com/products/11026"><img width="58" height="58" class="sfe-thumbnail" src="https://cdn.sparkfun.com/r/58-58/assets/parts/3/7/0/4/11026-02.jpg" /><span class="sfe-text"><span class="sfe-item-title">Jumper Wires Standard 7&quot; M/M - 30 AWG (30 Pack) <span class="sfe-sku"><span class="sfe-stock sfe-stock-in" title="in stock"></span> PRT-11026</span></span><span class="sfe-description">If you need to knock up a quick prototype there\'s nothing like having a pile of jumper wires to speed things up, and let\'s face it: sometimes you want&hellip;</span></span></a></div>';

html += '<div class="sfe-footer"><a class="button" href="https://www.sparkfun.com/wish_lists/115606">View <strong>MPU-9150 Hookup Guide</strong> on SparkFun.com</a></div>';

html += '</div>'; // end .sfe-inner

html += '</div>'; // end .sfe-wish-list

wrapper.innerHTML = html;

target_parent.insertBefore(wrapper, target_script);
