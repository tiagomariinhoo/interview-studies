const fs = require('fs');
const path = require('path');

function findListSchemaFiles(directory) {
    const foundFiles = [];
    const files = fs.readdirSync(directory);

    for (const file of files) {
        const filePath = path.join(directory, file);
        const stats = fs.statSync(filePath);

        if (stats.isFile() && file === 'list-schema.json') {
            foundFiles.push(filePath);
        } else if (stats.isDirectory()) {
            foundFiles.push(...findListSchemaFiles(filePath));
        }
    }

    return foundFiles;
}

function updateListSchema(filePath) {
    const data = JSON.parse(fs.readFileSync(filePath, 'utf-8'));
    // Add your conditions here
    // In my case, I had to find the Columns properties and add a new field in each one of them
    if ('columns' in data) {
        const columns = data['columns'];
        columns.forEach((column, idx) => {
            // Add new property to each column
            column['fieldTest'] = true;  
        });
    }

    fs.writeFileSync(filePath, JSON.stringify(data, null, 2));
}

function processListSchemaFiles(directory) {
    const listSchemaFiles = findListSchemaFiles(directory);
    for (const filePath of listSchemaFiles) {
        updateListSchema(filePath);
        console.log(`Updated ${filePath}`);
    }
}

// Replace '.' with the actual path to your project directory
// Or just put it into the root folder
const projectDirectory = '.';

processListSchemaFiles(projectDirectory);