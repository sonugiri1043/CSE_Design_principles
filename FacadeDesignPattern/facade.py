"""
# execute using 'python facade.py'
Facade pattern example.
"""

# Complex computer parts
class CPU(object):
    """
    Simple CPU representation.
    """
    def freeze(self):
        print("Freezing processor.")
        
    def jump(self, position):
        print("Jumping to:", position)

    def execute(self):
        print("Executing.")


class Memory(object):
    """
    Simple memory representation.
    """
    def load(self, position, data):
        print("Loading from {0} data: '{1}'.".format(position, data))


class SolidStateDrive(object):
    """
    Simple solid state drive representation.
    """
    def read(self, lba, size):
        return "Some data from sector {0} with size {1}".format(lba, size)


class ComputerFacade(object):
    """
    Represents a facade for various computer parts.
    """
    def __init__(self):
        self.cpu = CPU()
        self.memory = Memory()
        self.ssd = SolidStateDrive()

    def start(self):
        self.cpu.freeze()
        self.memory.load("0x00", self.ssd.read("100", "1024"))
        self.cpu.jump("0x00")
        self.cpu.execute()


computer_facade = ComputerFacade()
computer_facade.start()
