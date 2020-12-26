/*

Name:   gram_schmidt.c
        
Author: Sanghyeon Kim(Student ID: 20181605)

Date:   10/02/2020

----------------------------------------------------------------

Input:  Takes two row vectors in three-dimensional space
        as input. Each row vector is entered elementwise.

Process:Following the Gram-Schmidt orthonormalization, vector
        v_1 is set as u_1 and orthogonal vector u_2 is found
        using v_2 and u_1. Then, u_1 and u_2 are normalized
        to length 1 into orthonormal vectors c_1 and c_2.

Output: Prints two orthonormalized row vectors c_1 and c_2.

*/

#include <stdio.h>
#include <math.h>

void normalize(float V[], int size);
float dot_product(float v1[], float v2[], int size);

int main(){
    float V[2][3] = {{0}};
    float lambda;

    printf("<Input two row vectors(v_1, v_2) in three-dimensional space>\n\n");

    for(int row = 0; row < 2; row++){
        printf("Enter the elements of v_%d: ", row+1);
        for(int col = 0; col < 3; ++col){
            scanf("%f", *(V+row)+col);
        }
    }

    // Find lambda(the coordinate) of the projection of v_2 onto u_1(v_1)
    lambda = dot_product(V[1], V[0], 3)/dot_product(V[0], V[0], 3);

    // The second orthogonal vector u_2 replaces v_2
    for(int col = 0; col < 3; ++col){
        V[1][col] = V[1][col] - lambda*V[0][col];
    }

    printf("\n");

    // Print the orthonormalized vectors c_1 and c_2
    for(int row = 0; row < 2; ++row){
        normalize(V[row], 3); // Normalizes each of the orthogonal vectors
        printf("c_%d: (", row+1);
        for(int col = 0; col < 3; ++col){
            printf("%f, ", V[row][col]);
        }
        printf("\b\b)\n");
    }

    return 0;
}

// Normalizes the vector V to length 1.
void normalize(float V[], int size){
    float sum, root;

    sum = dot_product(V, V, size);

    root = sqrt(sum);

    for(int i = 0; i < size; ++i){
        V[i] /= root;
    }

    return;
}

/*
    Performs a dot product of two vectors v1, v2
    and returns the result
*/
float dot_product(float v1[], float v2[], int size){
    float result = 0;

    for(int i = 0; i < size; ++i){
        result += v1[i]*v2[i];
    }

    return result;
} 