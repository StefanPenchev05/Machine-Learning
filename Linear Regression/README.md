# Linear Regression

Linear Regression is fundamental machine learning algorithm used for predictive modeling. It established a relationship between a dependent variable (target) and one or more independet variables (features) by fitting a linear equation to the observed data.

## Key Concepts

1. **Simple Linear Regression**: Involves one independet variable and one dependent variable. The relationship is modeled as:

$$
y = b + mx
$$

**Where:**
- `y` is the dependent variable (target, possible outcome).
- `x` is the independent variable (feature).
- `m` is the slope of the line (coefficient).
- `b` is the y-intercept.

2. **Multiple Linear Regression**: Involves multiple independent variables. The relationship is modeled as:

$$
y = b_0 + b_1 x^1 + \dots + b_n x^n
$$


**Where:**
- `y` is the dependent variable.
- `x1, x2, ..., xn` are the independent variables.
- `b0` is the intercept.
- `b1, b2, ..., bn` are the coefficients for each independent variable.

## Formulas 

1. **Cost Function (Mean Squared Error)**:
The cost function measures the error between predicted and actual values:
$$
\theta_j := \theta_j - \alpha \cdot \frac{1}{m} \sum_{i=1}^{m} \left( h_\theta(x^{(i)}) - y^{(i)} \right) \cdot x_j^{(i)}
$$

**Where:**

- $\theta_j$ is the parameter being updated.  
- $\alpha$ is the learning rate.  
- $x_j^{(i)}$ is the feature value for the $i$-th data point and $j$-th parameter.
