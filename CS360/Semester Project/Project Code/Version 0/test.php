<!DOCTYPE html>
<html>
<head>
    <style>
        .container {
            display: flex;
            flex-direction: column;
        }

        .row {
            display: flex;
            align-items: center;
        }

        .checkbox {
            margin-right: 10px;
        }

        .arrow {
            margin: 0 10px;
            font-size: 24px;
        }

        .button-container {
            display: flex;
            justify-content: space-between;
        }
    </style>
</head>
<body>
    <div class="container" id="container">
    </div>

    <div class="button-container">
        <button id="createButton">Create a New Row</button>
        <button id="submitButton">Submit</button>
    </div>

    <script>
        const container = document.getElementById('container');
        const createButton = document.getElementById('createButton');
        const submitButton = document.getElementById('submitButton');
        let allowCreation = true;

        function createRow() {
            if (!allowCreation) {
                return;
            }

            const row = document.createElement('div');
            row.className = 'row';

            const checkboxes = ['A', 'B', 'C', 'D', 'E'];
            checkboxes.forEach((label, index) => {
                const checkbox = document.createElement('input');
                checkbox.type = 'checkbox';
                checkbox.className = 'checkbox';
                checkbox.id = `checkbox${index + 1}`;
                const checkboxLabel = document.createElement('label');
                checkboxLabel.setAttribute('for', `checkbox${index + 1}`);
                checkboxLabel.textContent = label;
                row.appendChild(checkbox);
                row.appendChild(checkboxLabel);
            });

            const arrow = document.createElement('span');
            arrow.className = 'arrow';
            arrow.textContent = '->';
            row.appendChild(arrow);

            checkboxes.forEach((label, index) => {
                const checkbox = document.createElement('input');
                checkbox.type = 'checkbox';
                checkbox.className = 'checkbox';
                checkbox.id = `checkbox${index + 6}`;
                const checkboxLabel = document.createElement('label');
                checkboxLabel.setAttribute('for', `checkbox${index + 6}`);
                checkboxLabel.textContent = label;
                row.appendChild(checkbox);
                row.appendChild(checkboxLabel);
            });

            container.appendChild(row);
        }

        createButton.addEventListener('click', createRow);
        submitButton.addEventListener('click', () => {
            allowCreation = false;
        });
    </script>
</body>
</html>
