class Solution {
    public static String convert(String s, int numRows) {
        if (numRows == 1){
            return s;
        }
        int numColumn = calculateNumColumn(s, numRows);

        char[][] a = new char[numRows][numColumn];
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColumn; j++) {
                a[i][j] = ' ';
            }
        }

        int iterationRow = 0;
        int iterationColumn = 0;
        int iterationChar = 0;
        int stringLengthLeft = s.length();
        while (stringLengthLeft > 0) {
            if (stringLengthLeft > numRows) {
                for (int i = 0; i < numRows; i++) {
                    a[i][iterationColumn] = s.charAt(iterationChar);
                    iterationChar++;
                }
                stringLengthLeft -= numRows;
            } else {
                for (int i = 0; i < stringLengthLeft; i++) {
                    a[i][iterationColumn] = s.charAt(iterationChar);
                    iterationChar++;
                }
                stringLengthLeft = 0;
            }
            iterationColumn += 1;
            iterationRow = numRows - 2;

            if (stringLengthLeft <= 0) {
                break;
            }

            if (stringLengthLeft > numRows - 2) {
                for (int i = 0; i < numRows - 2; i++) {
                    a[iterationRow][iterationColumn] = s.charAt(iterationChar);
                    iterationColumn++;
                    iterationRow--;
                    iterationChar++;
                }
                stringLengthLeft -= numRows - 2;
            } else {
                for (int i = 0; i < stringLengthLeft; i++) {
                    a[iterationRow][iterationColumn] = s.charAt(iterationChar);
                    iterationColumn++;
                    iterationRow--;
                    iterationChar++;
                }
                stringLengthLeft = 0;
            }
        }
        String r = "";

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColumn; j++) {
                if (a[i][j] != ' '){
                    r += a[i][j];
                }
            }
        }

        return r;
    }

    private static int calculateNumColumn(String s, int numRows) {
        int stringLengthLeft = s.length();
        int numColumn = 0;
        while (stringLengthLeft > 0) {
            numColumn += 1;
            stringLengthLeft -= numRows;

            if (stringLengthLeft <= 0) {
                break;
            }

            if (stringLengthLeft > numRows - 2) {
                numColumn += numRows - 2;
                stringLengthLeft -= numRows - 2;
            } else {
                numColumn += stringLengthLeft;
                stringLengthLeft = 0;
            }
        }
        return numColumn;
    }
}