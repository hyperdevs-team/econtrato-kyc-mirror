function continueFromLifeTest(){
    console.log('onclick continueFromLifeTest');
    var messgeToPost = {'ButtonId':'continueFromLifeTest'};
    window.webkit.messageHandlers.continueFromLifeTest.postMessage(messgeToPost);
}


function backFromLifeTest(){
    console.log('onclick backFromLifeTest');
    var messgeToPost = {'ButtonId':'backFromLifeTest'};
    window.webkit.messageHandlers.backFromLifeTest.postMessage(messgeToPost);
}
