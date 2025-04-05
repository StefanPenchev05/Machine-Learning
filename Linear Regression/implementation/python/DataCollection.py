class DataCollection:
    def __init__(self, data):
        self.data = data
    
    def get_x_values(self):
        return [point[0] for point in self.data]
    
    def get_y_values(self):
        return [point[1] for point in self.data]
    
    def get_size(self):
        return len(self.data)