function loadBreadcrumb(actualTitle) {
    window.webkit.messageHandlers.loadBreadcrumb.postMessage(actualTitle);
}

function configureBreadcrumb(title, actualStep, totalSteps) {
    let stepFormContainer = document.querySelector(".step-form-counter");
    while (stepFormContainer.firstChild) {
        stepFormContainer.removeChild(stepFormContainer.lastChild);
    }
    
    let stepContainer = document.createElement("div");
    stepContainer.classList.add("step-container");
    for(var i = 1; i <= totalSteps; i++) {
        const step = createBreadcrumbStep(i, title, actualStep);
        stepContainer.appendChild(step);
    }
    stepFormContainer.appendChild(stepContainer);
    
    const stepProgess = createBreadcrumbStepProgress(actualStep, totalSteps);
    stepFormContainer.appendChild(stepProgess);
}

/*
<div class="step current">
  <div class="step-number">
    <span class="number">1</span>
    <div class="tick"></div>
  </div>
  <span class="step-title">Capturar pasaporte</span>
</div>
*/
function createBreadcrumbStep(stepNumber, title, actualStep) {
    let stepDiv = document.createElement("div");
    stepDiv.classList.add("step");
    if (stepNumber === actualStep) stepDiv.classList.add("current");
    
    let stepNumberDiv = document.createElement("div");
    stepNumberDiv.classList.add("step-number");
    
    let spanNumber = document.createElement("span");
    spanNumber.classList.add("number");
    spanNumber.innerHTML = stepNumber;
    
    let divTick = document.createElement("div");
    divTick.classList.add("tick");
    
    stepNumberDiv.appendChild(spanNumber);
    stepNumberDiv.appendChild(divTick);
    
    let spanStepTitle = document.createElement("span");
    spanStepTitle.classList.add("step-title");
    if (stepNumber === actualStep) spanStepTitle.innerHTML = title;
    
    stepDiv.appendChild(stepNumberDiv);
    stepDiv.appendChild(spanStepTitle);
    
    return stepDiv;
}

/*
<div class="step-progress">
  <div class="progress" style="width: 25%;"></div>
</div>
*/
function createBreadcrumbStepProgress(actualStep, totalSteps) {
    let stepProgressDiv = document.createElement("div");
    stepProgressDiv.classList.add("step-progress");
    
    const percent = (100 / totalSteps) * actualStep;
    
    let progressDiv = document.createElement("div");
    progressDiv.classList.add("progress");
    progressDiv.style = `width: ${percent}%`;
    stepProgressDiv.appendChild(progressDiv);
    
    return stepProgressDiv;
}
