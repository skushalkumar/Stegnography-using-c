# 🔐 Image Steganography using C

### 📝 Project Overview

Image Steganography is a C programming project that demonstrates how to hide secret information inside a BMP image without noticeably changing its appearance.

This project uses the **Least Significant Bit (LSB)** technique to encode secret text file data into image bytes. The hidden information can later be extracted from the encoded image through the decoding process.

### ✨ Features

- 🔒 Hide secret text files inside BMP images.
- 🔓 Extract hidden information from encoded images.
- 🖼️ BMP image file handling.
- 💡 LSB-based encoding and decoding.
- 🔑 Magic string verification.
- 📄 Secret file extension encoding and decoding.
- 📏 Secret file size encoding and decoding.
- ⚙️ Image capacity validation.
- 💻 Command-line argument handling.
- 🧩 Modular programming using functions and structures.

### 🛠️ Technologies and Concepts Used

- 💻 Programming Language: C
- 📂 File Handling: fopen(), fread(), fwrite(), fseek(), ftell(), rewind()
- 🔢 Bitwise Operators: AND (&), OR (|), NOT (~), Right Shift (>>)
- 🧱 Structures and Enumerations
- 👉 Pointers and Functions
- 🔤 String Handling
- ⚙️ Command-Line Arguments
- 🖼️ BMP Image File Format

### 🔄 Project Workflow

#### 🔒 Encoding Process

1. Validate command-line arguments.
2. Open the source BMP image and secret text file.
3. Calculate image capacity and secret file size.
4. Copy the BMP header into the output image.
5. Encode the magic string.
6. Encode the secret file extension size and extension.
7. Encode the secret file size.
8. Hide secret file data using LSB manipulation.
9. Copy the remaining image data into the output image.

#### 🔓 Decoding Process

1. Validate command-line arguments.
2. Open the encoded BMP image.
3. Skip the BMP header.
4. Decode and verify the magic string.
5. Decode the secret file extension size and extension.
6. Decode the secret file size.
7. Extract the hidden secret file data.
8. Store the decoded information in the output file.

### 🚀 How to Compile

```bash
gcc *.c -o steganography
```

### ▶️ How to Run

**🔒 Encoding**

```bash
./steganography -e source.bmp secret.txt output.bmp
```

The output image filename is optional. If omitted, the program uses `stego.bmp`.

**🔓 Decoding**

```bash
./steganography -d stego.bmp decoded.txt
```

The output text filename is optional. If omitted, the program uses `output.txt`.

### 📚 Learning Outcomes

- Understanding image steganography concepts.
- Practical implementation of LSB encoding and decoding.
- Working with BMP image files.
- Improving C programming skills.
- Understanding pointers, structures and file handling.
- Applying bitwise operations in a real-world project.

### 🎯 Project Information

- **Project:** Image Steganography
- **Language:** C
- **Technique:** Least Significant Bit (LSB)
- **Image Format:** BMP
- **Domain:** Embedded C / Systems Programming

### 👨‍💻 Author

**S. Kushal Kumar**

### ⭐ Acknowledgement

This project was developed as part of my C programming and Embedded Systems training at Emertxe.

Image-Steganography-in-C/
│
├── main.c
├── encode.c
├── encode.h
├── decode.c
├── decode.h
├── types.h
├── common.h
├── README.md
├── Makefile
│
├── images/
│   └── source.bmp
│
└── .gitignore
