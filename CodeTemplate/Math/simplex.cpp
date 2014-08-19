vector<vector<double> > SetSimplex(vector<double> maxFunction, vector<vector<double> > A, vector<double> b) {
	vector<vector<double> > simplex;

	int numVariables = maxFunction.size();
	int numEquations = A.size();
	int numCols = numVariables + numEquations + 1 + 1;

	for (int iRow = 0; iRow < numEquations; iRow++) {
		vector<double> row(numCols, 0);
		for (int iCol = 0; iCol < numVariables; iCol++) {
			row[iCol] = A[iRow][iCol];
		}
		row[numVariables + iRow] = 1;
		row[numCols - 1] = b[iRow];
		simplex.push_back(row);
	}

	vector<double> lastRow(numCols, 0);
	for (int iVar = 0; iVar < numVariables; iVar++) {
		lastRow[iVar] = 0 - maxFunction[iVar];
	}
	lastRow[numVariables + numEquations] = 1;
	simplex.push_back(lastRow);

	return simplex;
}

bool GetPivots(vector<vector<double> > simplex, int & pivotCol, int & pivotRow, bool & noSolution) {
	int numRows = simplex.size();
	int numCols = simplex[0].size();
	int numVariables = numCols - numRows - 1;

	noSolution = false;
	double min = 0;
	for (int iCol = 0; iCol < numCols - 2; iCol++) {
		double value = simplex[numRows - 1][iCol];
		if (value < min) {
			pivotCol = iCol;
			min = value;
		}
	}

	if (min == 0) return false;

	double minRatio = 0.0;
	bool first = true;
	for (int iRow = 0; iRow < numRows - 1; iRow++) {
		double value = simplex[iRow][pivotCol];
		
		if (value > 0.0) {
			double colValue = simplex[iRow][numCols - 1];
			double ratio = colValue / value;

			if ((first || ratio < minRatio) && ratio >= 0.0) {
				minRatio = ratio;
				pivotRow = iRow;
				first = false;
			}
		}
	}

	noSolution = first;
	return !noSolution;
}

vector<double> DoSimplex(vector<vector<double> > simplex, double &max) {
	int pivotCol, pivotRow;
	int numRows = simplex.size();
	int numCols = simplex[0].size();

	bool noSolution = false;
	while (GetPivots(simplex, pivotCol, pivotRow, noSolution)) {
		double pivot = simplex[pivotRow][pivotCol];

		for (int iCol = 0; iCol < numCols; iCol++) {
			simplex[pivotRow][iCol] /= pivot;
		}

		for (int iRow = 0; iRow < numRows; iRow++) {
			if (iRow != pivotRow) {
				double ratio = -1 * simplex[iRow][pivotCol];
				for (int iCol = 0; iCol < numCols; iCol++) {
					simplex[iRow][iCol] = simplex[pivotRow][iCol] * ratio + simplex[iRow][iCol];
				}
			}
		}
	}

	if (noSolution) {
		vector<double> vec;
		return vec;
	}

	//optimal
	max = simplex[numRows - 1][numCols - 1];
	int numVariables = numCols - numRows - 1;
	vector<double> x(numVariables, 0);

	for (int iCol = 0; iCol < numVariables; iCol++) {
		bool isUnit = true;
		bool first = true;
		double value;
		for (int iRow = 0; iRow < numRows; iRow++) {
			if (simplex[iRow][iCol] == 1.0 && first) {
				first = false;
				value = simplex[iRow][numCols - 1];
			} else if (simplex[iRow][iCol] != 0.0) {
				isUnit = false;
			}
		}

		if (isUnit && !first) {
			x[iCol] = value;
		} else {
			x[iCol] = 0.0;
		}
	}

	return x;
}
