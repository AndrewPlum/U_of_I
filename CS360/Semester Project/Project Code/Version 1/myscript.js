document.addEventListener("DOMContentLoaded", function () {
    const createButton = document.getElementById("createButton");
    const rowContainer = document.getElementById("row-container");

    createButton.addEventListener("click", function () {
        // Clone the first row (excluding the "Create New Row" button)
        const newRow = rowContainer.firstElementChild.cloneNode(true);
        
        // Clear checkbox inputs in the new row
        const checkboxes = newRow.querySelectorAll("input[type='checkbox']");
        checkboxes.forEach(function (checkbox) {
            checkbox.checked = false;
        });

        // Append the new row to the container
        rowContainer.appendChild(newRow);
    });
});
