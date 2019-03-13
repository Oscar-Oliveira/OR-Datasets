#!/usr/bin/python3

import os
import json
from pprint import pprint

INSTANCE_FOLDER = './original'
TO_FOLDER = './json'

def convert():

    files = os.listdir(INSTANCE_FOLDER)
    for file in files:
        filename = file.split('.')[0]
        to_folder = os.path.join(TO_FOLDER, filename)
        if not os.path.exists(to_folder):
            os.makedirs(to_folder)

        with open(os.path.join(INSTANCE_FOLDER, file)) as current:
            content = current.readlines()
            content = [x.strip() for x in content]

            number_of_instances = int(content[0])
            number_of_item_types = int(content[3])

            for i in range(number_of_instances):
                pos = i * (number_of_item_types + 3) + 1

                w_container, h_container, d_container = content[pos + 1].split(" ")

                containers = []

                container = {}
                container['Length'] = int(w_container)
                container['Height'] = int(h_container)
                container['Depth'] = int(d_container)
                container['Stock'] = None
                container['Cost'] = int(w_container) * int(h_container) * int(d_container)

                containers.append(container)

                items = []

                # The 0/1 after each box dimension (C1 constraint, see
                # Goncalves and Resende (2012) "A parallel multi-population
                # biased random-key genetic algorithm for a container loading
                # problem")indicates whether placement in the vertical
                # orientation is permissible (=1) or not (=0).

                for item in range(0, number_of_item_types):
                    _, w_item, w_c1, d_item, d_c1, h_item, h_c1, demand_item = content[(pos + 3) + item].split(" ")

                    item = {}
                    item['Length'] = int(w_item)
                    item['C1_Length'] = int(w_c1)
                    item['Height'] = int(h_item)
                    item['C1_Height'] = int(h_c1)
                    item['Depth'] = int(d_item)
                    item['C1_Depth'] = int(d_c1)
                    item['Demand'] = int(demand_item)
                    item['DemandMax'] = None
                    item['Value'] = int(w_item) * int(h_item) * int(d_item)

                    items.append(item)

                json_data = {}
                json_data["Name"] = str(i + 1)
                json_data["Objects"] = containers
                json_data["Items"] = items

                out_file_name = os.path.join(to_folder, "{}.json".format(i + 1))

                with open(out_file_name, 'w') as outfile:
                    json.dump(json_data, outfile)

                print(out_file_name, ": done")

if __name__ == "__main__":
    convert()
