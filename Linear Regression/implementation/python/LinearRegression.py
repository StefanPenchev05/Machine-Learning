import MathUtils

class LinearRegression:
    def __init__(self):
        self.slope = 0
        self.intercept = 0

    def fit(self, data_collection):
        x_values = data_collection.get_x_values()
        y_values = data_collection.get_y_values()

        covariance = MathUtils.MathUtils.calculate_covariance(x_values, y_values)
        variance_x = MathUtils.MathUtils.calculate_variance(x_values)

        self.slope = covariance / variance_x
        self.intercept = MathUtils.MathUtils.calculate_mean(y_values) - self.slope * MathUtils.MathUtils.calculate_mean(x_values)

    def predict(self, x):
        return self.slope * x + self.intercept