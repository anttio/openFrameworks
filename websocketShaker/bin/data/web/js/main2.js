var socket, shaking;
var debug = document.getElementById('debug');


function get_appropriate_ws_url() {
    var pcol;
    var u = document.URL;

    if (u.substring(0, 5) == "https") {
        pcol = "wss://";
        u = u.substr(8);
    } else {
        pcol = "ws://";
        if (u.substring(0, 4) == "http") {
            u = u.substr(7);
        }
    }

    u = u.split('/');

    return pcol + u[0];
}


function setupSocket() {
    socket = new WebSocket(get_appropriate_ws_url());

    try {
        socket.onopen = function() {
            debug.innerHTML = 'WebSocket connection opened';
        };
        socket.onmessage = function got_packet(msg) {
            debug.innerHTML = msg.data + '<br>' + debug.innerHTML;
        };
        socket.onclose = function() {
            debug.innerHTML = 'WebSocket connection closed';
        };
    } catch(exception) {
        debug.innerHTML = 'Error ' + exception;
    }
}
setupSocket();


function shakeEventDidOccur() {
    socket.send('shake');

    // var point = {point:{x:x,y:y},id:id,color:color};
    // socket.send(JSON.stringify(point));
}

function setupShake() {
    shaking = new Shake({
        // threshold: 15,
        // timeout: 1000
    });
    shaking.start();
    window.addEventListener('shake', shakeEventDidOccur, false);
}
setupShake();


function handleOrientation(event) {
    var alpha    = Math.ceil(event.alpha);
    var beta     = Math.ceil(event.beta);
    var gamma    = Math.ceil(event.gamma);

    socket.send(JSON.stringify({ alpha: alpha, beta: beta, gamma: gamma }));

    debug.innerHTML = alpha + '<br>' + beta + '<br>' + gamma;
}
window.addEventListener("deviceorientation", handleOrientation, true);
