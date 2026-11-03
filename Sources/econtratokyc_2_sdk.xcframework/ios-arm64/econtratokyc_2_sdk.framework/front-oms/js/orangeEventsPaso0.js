function changeTypeDocIdSelected(typeDocId){
    var sel = document.getElementById('selectorDocumentacion');
    var opts = sel.options;
    for (var opt, j = 0; opt = opts[j]; j++) {
        if (opt.value == typeDocId) {
          sel.selectedIndex = j;
            sel.disabled = true;
            break;
        }
    }
}

window.onload = function() {
    
    var botonComenzar = document.getElementById("botonComenzar");
    botonComenzar.addEventListener("click", function() {
        ocultarMensajesError();
        if(validEntrada()){
            var docType = document.getElementById("selectorDocumentacion").value;
            var messgeToPost = {'ButtonId':'botonComenzar', 'documentType': docType};
            window.webkit.messageHandlers.comenzarClicked.postMessage(messgeToPost);
        }
    },false);
    
    var botonVolver = document.getElementById("botonVolver");
    botonVolver.addEventListener("click", function() {
        var messgeToPost = {'ButtonId':'botonVolver'};
        window.webkit.messageHandlers.volverClicked.postMessage(messgeToPost);
    },false);
    
    function validEntrada() {
        var isValidDocType = validSeleccionDocumento();
        var isValidPolicyTerms = validCheckPoliticaPrivacidad();
        if ( isValidDocType && isValidPolicyTerms ) {
            return true;
        } else {
            return false;
        }
    }

    function validSeleccionDocumento() {
        var seleccion = document.getElementById("selectorDocumentacion");
        var result = parseFloat(seleccion.options[seleccion.selectedIndex].value);
        if (result === 0) {
            displayBlockElement(document.getElementById("errorSelectorDocumentacion"));
            return false;
        } else {
            return true;
        }
    }
    
    function validCheckPoliticaPrivacidad(){
        if( !document.getElementById("checkboxTratamientoInfo").checked ){
            displayBlockElement(document.getElementById("errorCheckboxTratamientoInfo"));
            return false;
        } else {
            return true;
        }
    }
    
    function ocultarMensajesError(){
        displayNoneElement(document.getElementById("errorSelectorDocumentacion"));
        displayNoneElement(document.getElementById("errorCheckboxTratamientoInfo"));
    }
    
    function displayBlockElement(htmlElement){
        htmlElement.style.display = "flex";
    }
    
    function displayNoneElement(htmlElement){
        htmlElement.style.display = "none";
    }
    
    var messgeToPost = {'checkTypeDocId':'checkTypeDocId'};
    window.webkit.messageHandlers.validateTypeDocId.postMessage(messgeToPost);
}
