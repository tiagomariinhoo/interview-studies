import os
import json

def find_list_schema_files(directory):
    found_files = []
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file == 'list-schema.json':
                file_path = os.path.join(root, file)
                found_files.append(file_path)
    return found_files

def update_list_schema(file_path):
    with open(file_path, 'r') as file:
        data = json.load(file)

    # Assuming 'columns' is a key at the top level of the JSON structure
    if 'columns' in data:
        columns = data['columns']
        for idx, column in enumerate(columns):
            # Add new property to each column
            column['defaultHidden'] = True  # Change 'your_new_value' as needed
            column['defaultOrder'] = idx  # Change 'your_new_value' as needed

    with open(file_path, 'w') as file:
        json.dump(data, file, indent=2)

def process_list_schema_files(directory):
    list_schema_files = find_list_schema_files(directory)
    for file_path in list_schema_files:
        update_list_schema(file_path)
        print(f"Updated {file_path}")

# Replace 'path/to/your/project' with the actual path to your project directory
project_directory = '.'

process_list_schema_files(project_directory)