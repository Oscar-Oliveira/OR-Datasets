import os
import json
from pprint import pprint

INSTANCE_FOLDER = './instances'
TO_FOLDER = './json'

def convert():
    folders = next(os.walk('./instances'))[1]
    for f in folders:
        folder = os.path.join(INSTANCE_FOLDER, f)
        files = os.listdir(folder)

        to_folder = os.path.join(TO_FOLDER, f)
        if not os.path.exists(to_folder):
            os.makedirs(to_folder)
            pass

        for f in files:
            instance = os.path.join(folder, f)
            with open(instance) as current:
                content = current.readlines()
                content = [x.strip() for x in content]

                w_container, h_container, d_container = content[0].split(" ")

                # n = content[1] # number of boxes

                containers = []

                container = {}
                container['Length'] = int(w_container)
                container['Height'] = int(h_container)
                container['Depth'] = int(d_container)
                container['Stock'] = None
                container['Cost'] = int(w_container) * int(h_container) * int(d_container)

                containers.append(container)

                items = []
                for i in range(2, len(content)):

                    w_item, h_item, d_item = content[i].split(" ")

                    item = {}
                    item['Length'] = int(w_item)
                    item['Height'] = int(h_item)
                    item['Depth'] = int(d_item)
                    item['Demand'] = 1
                    item['DemandMax'] = None
                    item['Value'] = int(w_item) * int(h_item) * int(d_item)

                    items.append(item)

                json_data = {}
                json_data["Name"] = f
                json_data["Objects"] = containers
                json_data["Items"] = items

                #pprint(json_data)
                #json_data = json.dumps(json_data)

                file_name = os.path.join(to_folder, f + ".json")

                with open(file_name, 'w') as outfile:
                    json.dump(json_data, outfile)

                print(file_name, ": done")

if __name__ == "__main__":
    convert()
