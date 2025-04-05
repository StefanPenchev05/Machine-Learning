class MathUtils:
    @staticmethod
    def calculate_mean(values):
        return sum(values) / len(values)

    @staticmethod
    def calculate_covariance(x_values, y_values):
        mean_x = MathUtils.calculate_mean(x_values)
        mean_y = MathUtils.calculate_mean(y_values)
        
        covariance = sum((x - mean_x) * (y - mean_y) for x, y in zip(x_values, y_values))
        return covariance / (len(x_values) - 1)
    
    @staticmethod
    def calculate_variance(values):
        mean = MathUtils.calculate_mean(values)
        variance = sum((x - mean) ** 2 for x in values)
        return variance / (len(values) - 1)