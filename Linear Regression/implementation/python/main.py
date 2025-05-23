import DataCollection, LinearRegression

if __name__ == "__main__":
    data = [
        (50.0, 145.0),
        (54.1, 146.0),
        (58.2, 161.2),
        (62.2, 177.3),
        (66.3, 167.0),
        (70.4, 174.4),
        (74.5, 199.9),
        (78.6, 199.1),
        (82.7, 194.1),
        (86.7, 211.5),
        (90.8, 208.8),
        (94.9, 216.2),
        (99.0, 230.6),
        (103.1, 216.4),
        (107.1, 225.6),
        (111.2, 244.6),
        (115.3, 247.4),
        (119.4, 268.0),
        (123.5, 263.2),
        (127.6, 265.5),
        (131.6, 301.6),
        (135.7, 292.0),
        (139.8, 302.3),
        (143.9, 294.7),
        (148.0, 310.9),
        (152.0, 324.8),
        (156.1, 319.5),
        (160.2, 342.1),
        (164.3, 339.7),
        (168.4, 350.1),
        (172.4, 354.4),
        (176.5, 386.3),
        (180.6, 375.0),
        (184.7, 371.9),
        (188.8, 398.0),
        (192.9, 384.9),
        (196.9, 406.6),
        (201.0, 392.2),
        (205.1, 405.9),
        (209.2, 428.5),
        (213.3, 441.3),
        (217.3, 442.9),
        (221.4, 447.4),
        (225.5, 452.9),
        (229.6, 448.5),
        (233.7, 463.4),
        (237.8, 473.4),
        (241.8, 495.9),
        (245.9, 496.1),
        (250.0, 482.4)
    ]
    
    collection = DataCollection.DataCollection(data)
    
    # Create a LinearRegression object and fit the line
    model = LinearRegression.LinearRegression()
    model.fit(collection)
    
    # Output the equation of the best-fitting line
    print(f"Equation of the line: y = {model.slope}x + {model.intercept}")

    # Predict a value
    x = 120.0
    predicted_y = model.predict(x)
    print(f"Predicted value for x = {x}: y = {predicted_y}")