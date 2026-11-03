function cerrarReintentar() {
    var messgeToPost = {'ButtonId':'cerrarReintentar'};
    window.webkit.messageHandlers.cerrarReintentarClicked.postMessage(messgeToPost);
}

function reintentarResult() {
    var messgeToPost = {'ButtonId':'reintentarResult'};
    window.webkit.messageHandlers.reintentarClicked.postMessage(messgeToPost);
}

function aceptResult(){
    var messgeToPost = {'ButtonId':'aceptResult'};
    window.webkit.messageHandlers.aceptResultClicked.postMessage(messgeToPost);
}

function aceptResultError(){
    var messgeToPost = {'ButtonId':'aceptResultError'};
    window.webkit.messageHandlers.aceptResultErrorClicked.postMessage(messgeToPost);
}

function aceptResultKO(){
    var messgeToPost = {'ButtonId':'aceptResultKO'};
    window.webkit.messageHandlers.aceptResultClicked.postMessage(messgeToPost);
}
