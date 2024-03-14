import json
import os

def lowercase_keys(data):
    if isinstance(data, dict):
        return {key.lower(): lowercase_keys(value) for key, value in data.items()}
    elif isinstance(data, list):
        return [lowercase_keys(item) for item in data]
    else:
        return data

# Input and output directories
input_directory = "/path/to/input/directory"
output_directory = "/path/to/output/directory"

# Input JSON file name
input_file = "input_data.json"

# Construct full paths
input_file_path = os.path.join(input_directory, input_file)
output_file_path = os.path.join(output_directory, "transformed_data.json")

# Open and read input JSON file
with open(input_file_path, "r") as f:
    json_data = json.load(f)

# Convert keys to lowercase
json_data_lowercase = lowercase_keys(json_data)

# Write transformed JSON to a new file
with open(output_file_path, "w") as f:
    json.dump(json_data_lowercase, f, indent=4)

print(f"Transformed JSON data has been written to '{output_file_path}'")