#include <reg51.h>
#include <ctype.h>   // for atoi()

sbit TX = P3^1;      // UART TX to Bluetooth
sbit RX = P3^0;      // UART RX from Arduino

char buffer[30];     // buffer to store incoming data
unsigned char idx = 0; // index for buffer position

// ===============================
// UART Initialization (9600 baud)
// ===============================
void UART_Init() {
    TMOD = 0x20;     // Timer1, Mode2
    TH1 = 0xFD;      // Baud rate 9600
    SCON = 0x50;     // 8-bit UART, REN enabled
    TR1 = 1;         // Start Timer1
}

// ===============================
// Send String over UART (Bluetooth)
// ===============================
void UART_SendString(char *str) {
    while (*str) {
        SBUF = *str;
        while (!TI);   // Wait for TX completion
        TI = 0;
        str++;
    }
}

// ===============================
// Parse & Classify Flex Sensor Data
// Incoming format expected: CSV of 5 values
// ===============================
void parse_and_classify(char *csv) {
    char temp[6];
    int values[5];
    int i = 0, j = 0, f1, f2, f3, f4, f5;

    // Parse incoming CSV data
    while (*csv && i < 5) {
        if (*csv == ',') {
            temp[j] = '\0';
            values[i++] = atoi(temp);
            j = 0;
        }
        else {
            temp[j++] = *csv;
        }
        csv++;
    }

    // Save last value
    temp[j] = '\0';
    values[i] = atoi(temp);

    // Assign to variables
    f1 = values[0];
    f2 = values[1];
    f3 = values[2];
    f4 = values[3];
    f5 = values[4];

    // ===============================
    // Gesture Classification Logic
    // ===============================

    if ((f1 < 1020 && f1 > 1000) &&
        (f2 < 1020 && f2 > 1000) &&
        (f3 < 1020 && f3 > 1000) &&
        (f4 < 1020 && f4 > 1000)) {
        UART_SendString("Hello!\n");
    }

    else if (f1 < 1010 && f2 < 1010 && f3 < 1010 && f4 < 1010) {
        UART_SendString("Okay!\n");
    }

    else if (f1 > 1010 && f2 > 1010 && f3 > 1010 && f4 > 1010) {
        UART_SendString("Peace!\n");
    }

    else {
        UART_SendString("Unknown\n");
    }
}

// ===============================
// UART Interrupt Handler
// ===============================
void serial_ISR(void) interrupt 4 {
    char ch;

    if (RI) {
        ch = SBUF;
        RI = 0;

        if (ch == '\n') {         // End of data packet
            buffer[idx] = '\0';
            parse_and_classify(buffer);
            idx = 0;
        }
        else {
            if (idx < sizeof(buffer) - 1) {
                buffer[idx++] = ch;
            }
        }
    }
}

// ===============================
// Main Program
// ===============================
void main() {
    UART_Init();
    EA = 1;      // Enable global interrupts
    ES = 1;      // Enable serial interrupt

    while (1);   // Wait for incoming data
}
