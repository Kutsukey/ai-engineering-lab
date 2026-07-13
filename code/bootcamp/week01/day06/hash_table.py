# hash function and array
class HashTable():
    def __init__(self, length=10) -> None:
        self.length = length
        self.arr = [[] for _ in range(self.length)]


    def get(self,key):
        index = self.__myHashFunction(key)
        for e in self.arr[index]:
            if e[0] == key:
                return e[1]
        raise KeyError(f"'{key}' does not exists!")

    def put(self,key,val):
        index = self.__myHashFunction(key)
        for e in self.arr[index]:
            if e[0] == key:
                e[1] = val
                return self
        self.arr[index].append([key,val])
        return self

    def remove(self,key):
        index = self.__myHashFunction(key)
        for e in self.arr[index]:
            if e[0] == key:
                self.arr[index].remove(e)
                break
        return self

    def contains(self,key):
        index = self.__myHashFunction(key)
        for e in self.arr[index]:
            if e[0] == key:
                return True
        return False

    def __myHashFunction(self, key):
        prime = 31
        sum = 0
        for c in key:
            sum = sum * prime
            sum += ord(c)

        return sum % self.length
        
battery_size_to_power = HashTable(4)

battery_size_to_power.put('A',10)
battery_size_to_power.put('AA',20)
battery_size_to_power.put('AAA',40)
battery_size_to_power.put('AAAA',80)

battery_size_to_power.remove('A')

print(battery_size_to_power.get('AA'))
print(battery_size_to_power.get('AAA'))

battery_size_to_power.put('AA', 999)
print(battery_size_to_power.get('AA'))