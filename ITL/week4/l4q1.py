class SubsetGenerator:
    '''Class generates all the subsets of a set.'''
    def __init__(self,a):
        self.a=a
    def generate_subsets(self):
        results = [[]]
        for num in a:
            new_sets = []
            for result in results:
                new_set = result + [num]
                if new_set not in results: #comment this if condition if you want to allow duplicates
                    new_sets.append(new_set)
            results.extend(new_sets)
        return results

a=[int(x) for x in input("Enter set elements : ").split()]
obj=SubsetGenerator(a)
subsets=obj.generate_subsets()
print(subsets)
