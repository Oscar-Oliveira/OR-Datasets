#!/usr/bin/python

import os, json

FOLDER = "./Datasets/"

GROUPS = {
    "ATP": (10, 10, 10, 10),
    "BABU": (1, 1),
    "CHL": (7, 9),
    "FHZ": (11, 11, 11, 11),
    "HIFI1997a": (3, 3),
    "HIFI1997b": (3, 3),
    "HIFI2001": (5, 11),
    "LC": (3, 5),
    "MA": (1, 1),
    "MG": (1, 1),
    "WANG": (3, 2),
}

class Dataset:

    def __init__(self, name):
        self.name = name
        self.counter = 0

        # Objects
        self.k_min = self.k_max = None
        self.e_min = self.e_max = None
        self.c_min = self.c_max = None
        self.L_min = self.L_max = None
        self.H_min = self.H_max = None
        # Items
        self.m_min = self.m_max = None
        self.d_min = self.d_max = None
        self.dm_min = self.dm_max = None
        self.v_min = self.v_max = None
        self.l_min = self.l_max = None
        self.h_min = self.h_max = None

    def __verify(self, value, min, max):
        if isinstance(value, int):
            if (min == None) or min > value: min = value
            if (max == None) or max < value: max = value
        return (min, max)

    def __print_range(self, min, max):
        return f"[{min}, {max}]" if min != max else str(min)

    def add(self, filename):
        self.counter += 1
        with open(filename, 'r') as myfile:
            data = myfile.read()
            obj = json.loads(data)
            self.k_min, self.k_max = self.__verify(len(obj['Objects']), self.k_min, self.k_max)
            for o in obj['Objects']:
                self.e_min, self.e_max = self.__verify(o['Stock'], self.e_min, self.e_max)
                self.c_min, self.c_max = self.__verify(o['Cost'], self.c_min, self.c_max)
                self.L_min, self.L_max = self.__verify(o['Length'], self.L_min, self.L_max)
                self.H_min, self.H_max = self.__verify(o['Height'], self.H_min, self.H_max)
            self.m_min, self.m_max = self.__verify(len(obj['Items']), self.m_min, self.m_max)
            for o in obj['Items']:
                self.d_min, self.d_max = self.__verify(o['Demand'], self.d_min, self.d_max)
                self.dm_min, self.dm_max = self.__verify(o['DemandMax'], self.dm_min, self.dm_max)
                self.v_min, self.v_max = self.__verify(o['Value'], self.v_min, self.v_max)
                self.l_min, self.l_max = self.__verify(o['Length'], self.l_min, self.l_max)
                self.h_min, self.h_max = self.__verify(o['Height'], self.h_min, self.h_max)

    def __str__(self):
        result  = f"\n\nDataset: {self.name}"
        result += f"\nNumber of instances: {self.counter}"

        # Objects
        result += f"\nk: {self.__print_range(self.k_min, self.k_max)}"
        result += f"\ne: {self.__print_range(self.e_min, self.e_max)}"
        result += f"\nc: {self.__print_range(self.c_min, self.c_max)}"
        result += f"\nLxH: {self.__print_range(self.L_min, self.L_max)} x {self.__print_range(self.H_min, self.H_max)}"
        # Itens
        result += f"\nm: {self.__print_range(self.m_min, self.m_max)}"
        result += f"\nd: {self.__print_range(self.d_min, self.d_max)} - {self.__print_range(self.dm_min, self.dm_max)}"
        result += f"\nv: {self.__print_range(self.v_min, self.v_max)}"
        result += f"\nlxh: {self.__print_range(self.l_min, self.l_max)} x {self.__print_range(self.h_min, self.h_max)}"
        return result

class Report:

    def __init__(self):
        self.__datasets = []

    def add(self, dataset):
        self.__datasets.append(dataset)

    def export(self):
        with open('report.txt', 'w') as f:
            print(self, file=f)

    def __str__(self):
        result = ""
        for dataset in self.__datasets:
            result += str(dataset)
        result += f"\n\nDatasets: {len(self.__datasets)}"
        result += f"\nNumber of instances: {sum([d.counter for d in self.__datasets])}"
        return result

if __name__ == "__main__":

    report = Report()
    for subfolder in os.listdir(FOLDER):
        number_of_files = len(os.listdir(FOLDER + subfolder + "/json"))
        if subfolder in GROUPS:
            if (sum(GROUPS[subfolder]) != number_of_files):
                raise Exception("invalid number of chuncks.")
            current_file = 1
            current_chunck = 1
            for chunck in GROUPS[subfolder]:
                dataset = Dataset(subfolder + str(current_chunck))
                for filename in range(current_file, current_file + chunck):
                    dataset.add(f"{FOLDER}{subfolder}/json/{filename}.json")
                report.add(dataset)
                current_file += chunck
                current_chunck += 1
        else:
            dataset = Dataset(subfolder)
            for filename in range(1, number_of_files + 1):
                dataset.add(f"{FOLDER}{subfolder}/json/{filename}.json")
            report.add(dataset)
    #print(report)
    report.export()
