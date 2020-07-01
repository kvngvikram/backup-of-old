# | ## Importing
import sympy as sp
import numpy as np


# | ### The function
def newton_method_with_sympy_npmpy(
        var_tup, func_tup, initial_x_list,
        max_tolerence=0.0001, max_iterations=100):
    """
    Function that calculates the zero values using Newton-Raphson method.

    Parameters
    ----------
    var_tup : tuple_of_sympy_symbols
        Tuple of sympy symbols (variables).
        Eg. (x1, x2, x3) where x1 = sympy.symbols('x1') etc.
    func_tup : tuple_of_sympy_expressions
        Tuple of sympy functions.
        Eg. (f1, f2, f3) where f1 = sp.cos(x1) + 4 etc.
    initial_x_list : list
        List of guess values of variables. Eg. [0.1, 4, -3.3]
    max_tolerence : float, optional
        Maximum possible adjustment in last step.
    max_iterations : int, optional
        Maximum iterations.

    Returns
    -------
    numpy_column_matrix
        Calculated zero values from newton method. If calculation doesn't
        converge then the last un-converged values will be given.
    int
        The last iteration number (weather converged or not).
    float
        Maximum value of last adjustment.

    Note
    ----
    Number of variables should be more than one. Did not test with number
    of variables and number of functions are not equal. Wrong guess values can
    result in singular matrix error while inverting Jacobian matrix. Jacobian
    matrix is calculated by partial differentiation using sympy.diff(). Did not
    test if derivative can be calculated for any function.
    """

    X = np.matrix(initial_x_list).T

    # Number of functions and variables
    no_func = len(func_tup)
    no_var = len(var_tup)

    # Initialise with a matrix with zeros
    j_sym_matrix = sp.Matrix(
            [[0 for j in range(no_var)] for i in range(no_func)]
            )

    # Assign sympy function terms to Jacobian matrix
    for i in range(no_func):
        for j in range(no_var):
            # diff for partial derivative of first arg with second
            j_sym_matrix[i, j] = sp.diff(func_tup[i], var_tup[j])

    # These are similar to functions given by sympy.lambdify used to
    # evaluate numerical values from symbolic functions
    get_func_values_tuple_from_sympy_functions = sp.lambdify(
            var_tup, func_tup, modules='numpy')
    get_j_values_array_from_sympy_J_matrix = sp.lambdify(
            var_tup, j_sym_matrix, modules='numpy')

    # X as column numpy matrix input and same type as output
    def F(X):
        # input to sympy.lambdify should be tuple, so converting
        my_tuple = tuple(map(float, X))
        return np.matrix(
                get_func_values_tuple_from_sympy_functions(*my_tuple),
                dtype=float).T

    # X as column numpy matrix input and a numpy rectangular matrix as output
    def J(X):
        # input to sympy.lambdify should be tuple, so converting
        my_tuple = tuple(map(float, X))
        return np.matrix(
                get_j_values_array_from_sympy_J_matrix(*my_tuple),
                dtype=float)

    # The Newton-Raphson calculations
    i = 0
    epsilon = np.inf
    while (i < max_iterations and np.abs(epsilon).max() > max_tolerence):
        X_new = X - J(X).I * F(X)
        epsilon = X_new - X
        X = X_new
        i += 1

    return X, i, np.abs(epsilon).max()


# | # Example

# | Defining symbols
x1 = sp.symbols('x1')
x2 = sp.symbols('x2')
x3 = sp.symbols('x3')

# | Defining expressions
f1 = sp.cos(x1) + sp.sin(x2)
f2 = sp.sin(x2) + sp.cos(x3)
f3 = sp.cos(x3)

# | Guess values
initial_x_list = [0.5, 0.5, 0.5]

# | Making a list of variables and functions
var_tup = (x1, x2, x3)
func_tup = (f1, f2, f3)

# | Some more input parameters
max_iterations = 100
max_tolerence = .0001

# | Run and check
if __name__ == "__main__":
    X, iter, adjustment = newton_method_with_sympy_npmpy(
            var_tup, func_tup, initial_x_list, max_tolerence, max_iterations)


# | Print the results
print(X)
print(iter)
print(adjustment)
