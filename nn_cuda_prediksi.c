#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_FEATURES 4
#define OUTPUT_NEURONS 2
#define THRESHOLD_LULUS 12.0

float relu(float x) {
    return fmaxf(0.0f, x);
}

int main() {
    float input[INPUT_FEATURES];

    // Bobot (disesuaikan agar skor tidak terlalu kecil)
    float weights[INPUT_FEATURES][OUTPUT_NEURONS] = {
        {0.04, 0.06},  // Matematika
        {0.04, 0.06},  // Bahasa Inggris
        {0.03, 0.05},  // Fisika
        {0.02, 0.04}   // Kimia
    };

    float bias[OUTPUT_NEURONS] = {0.0, 0.0};
    float output[OUTPUT_NEURONS];

    // Input pengguna
    printf("=== Masukkan Nilai Siswa ===\n");
    printf("1. Nilai Matematika (0-100): ");
    scanf("%f", &input[0]);
    printf("2. Nilai Bahasa Inggris (0-100): ");
    scanf("%f", &input[1]);
    printf("3. Nilai Fisika (0-100): ");
    scanf("%f", &input[2]);
    printf("4. Nilai Kimia (0-100): ");
    scanf("%f", &input[3]);

    // Forward pass
    for (int o = 0; o < OUTPUT_NEURONS; o++) {
        float sum = bias[o];
        for (int i = 0; i < INPUT_FEATURES; i++) {
            sum += input[i] * weights[i][o];
        }
        output[o] = relu(sum);
    }

    // Tampilkan hasil
    printf("\n=== HASIL PREDIKSI ===\n");
    printf("Skor Tidak Lulus: %.2f\n", output[0]);
    printf("Skor Lulus      : %.2f\n", output[1]);

    // Keputusan dengan threshold
    if (output[1] > output[0] && output[1] >= THRESHOLD_LULUS)
        printf("Keputusan       : LULUS\n");
    else
        printf("Keputusan       : TIDAK LULUS\n");

    return 0;
}
