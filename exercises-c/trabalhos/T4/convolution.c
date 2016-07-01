//k is the mask size (kxk)
//coeffs[k][k] is a 2D array of integer coefficients
//scale is a scalling factor to normalise the filter again

/*
	for each image row in input image:
		for each pixel in image row:
			
			set accumulator to zero

			for each mask row in mask1:
				for each element in mask1 row:

					if element position corresponding*
						to pixel position then
						multiply element value corresponding*
									to pixel value
						add result to accumulator
					endif

				set output image pixel to accumulator

	*corresponding input image pixels are found relative 
	 to the mask's origin
*/

// find center position of kernel (half of kernel size)
kCenterX = kCols / 2;
kCenterY = kRows / 2;

for(i=0; i < rows; ++i)              // rows
{
    for(j=0; j < cols; ++j)          // columns
    {
        for(m=0; m < kRows; ++m)     // kernel rows
        {
            mm = kRows - 1 - m;      // row index of flipped kernel

            for(n=0; n < kCols; ++n) // kernel columns
            {
                nn = kCols - 1 - n;  // column index of flipped kernel

                // index of input signal, used for checking boundary
                ii = i + (m - kCenterY);
                jj = j + (n - kCenterX);

                // ignore input samples which are out of bound
                if( ii >= 0 && ii < rows && jj >= 0 && jj < cols )
                    out[i][j] += in[ii][jj] * kernel[mm][nn];
            }
        }
    }
}