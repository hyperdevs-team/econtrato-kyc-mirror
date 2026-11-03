function botonAbrirCamara(){
    var messgeToPost = {'ButtonId':'botonAbrirCamara'};
    window.webkit.messageHandlers.abrirCamaraClicked.postMessage(messgeToPost);
}

function botonAbrirCamaraPasaporte(){
    var messgeToPost = {'ButtonId':'botonAbrirCamaraPasaporte'};
    window.webkit.messageHandlers.botonAbrirCamaraPasaporteClicked.postMessage(messgeToPost);
}

function botonVolver(){
    var messgeToPost = {'ButtonId':'botonVolver'};
    window.webkit.messageHandlers.volverClicked.postMessage(messgeToPost);
}

function botonVolverPasaporte(){
    var messgeToPost = {'ButtonId':'botonVolverPasaporte'};
    window.webkit.messageHandlers.volverClicked.postMessage(messgeToPost);
}
