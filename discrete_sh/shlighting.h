#pragma once

/**
 
Copyright (c) 2017 Christopher Pugh

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
**/

inline void calculateSHLightingMatrix(Eigen::Matrix4f& shMat, float* coeffs, std::size_t stride)
{
    const float c1 = .429043;
    const float c2 = .511664;
    const float c3 = .743125;
    const float c4 = .886227;
    const float c5 = .247708;

    const float& L00 = *coeffs;
    const float& L1m1 = coeffs[1 * stride];
    const float& L10 = coeffs[2 * stride];
    const float& L11 = coeffs[3 * stride];
    const float& L2m2 = coeffs[4 * stride];
    const float& L2m1 = coeffs[5 * stride];
    const float& L20 = coeffs[6 * stride];
    const float& L21 = coeffs[7 * stride];
    const float& L22 = coeffs[8 * stride];

    shMat.col(0) = Eigen::Vector4f(c1 * L22,
        c1 * L2m2,
        c1 * L21,
        c2 * L11);
    shMat.col(1) = Eigen::Vector4f(c1 * L2m2,
        -c1 * L22,
        c1 * L2m1,
        c2 * L1m1);
    shMat.col(2) = Eigen::Vector4f(c1 * L21,
        c1 * L2m1,
        c3 * L20,
        c2 * L10);
    shMat.col(3) = Eigen::Vector4f(c2 * L11,
        c2 * L1m1,
        c2 * L10,
        c4 * L00 - c5 * L20
    );
}

/*
calculateSHLightingMatrix(shR, (float*)coefficients, 3);
    calculateSHLightingMatrix(shG, (float*)coefficients+1, 3);
    calculateSHLightingMatrix(shB, (float*)coefficients+2, 3);
    */

    // grace cathedral SH coefficients.  Taken directly from the original Ramamoorthi paper
        /***float coefficients[27] = {.79, .44, .54,
                                        .39, .35, .6,
                                        -.34, -.18, -.27,
                                        -.29, -.06, .01,
                                        -.11, -.05, -.12,
                                        -.26, -.22, -.47,
                                        -.16, -.09, -.15,
                                        .56, .21, .14,
                                        .21, -.05, -.3

        };***/

