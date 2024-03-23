import math
Pi = math.pi

class Circulo:
    def __init__(self,radio):
        self.radio=radio

    def area(self):
        return Pi * self.radio ** 2

C1 = Circulo(5)
print(f"El area del circulo será de ",C1.area())