# Arduino Sparse Peripheral Display

![unity-sparse-peripheral-display-banner-kein-text](https://github.com/marius7600/unity-sparse-peripheral-display/assets/56048471/ba9a7693-6d8c-46ef-b5e3-b710f532049e)



Welcome to the **Arduino Sparse Peripheral Display** repository! This repository provides the Arduino code for the [**Unity Sparse Peripheral Display**](https://github.com/marius7600/unity-sparse-peripheral-display) project.
## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Introduction

This repository is an essential part of the [**Unity Sparse Peripheral Display**](https://github.com/marius7600/unity-sparse-peripheral-display) project which explores a novel approach to enhance the virtual reality experience by utilizing LEDs to extend the field of view (FoV). By intelligently integrating these LEDs and controlling them, the project aims to create a more immersive and engaging VR environment.


## Features

- **LED Control:** Receiving the colour values from Unity and controlling the LEDs.
- **Customizable:** Adapt the LED configuration for a specific type and number of LEDs.

## Installation

### Software Requirements

1. [Visual Studio Code](https://code.visualstudio.com/)
2. [PlatformIO Extension for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

### Hardware Requirements

To use this Arduino code for the Sparse Peripheral Display, you will need the following components:

1. An Arduino board capable of controlling LEDs. For this project the Arudino Nano Every was used.
2. LEDs: The code is configured for 48 WS2812B LEDs. Make sure you have the correct number of LEDs and the appropriate wiring.

   ![circuit](https://github.com/marius7600/arduino-sparse-peripheral-display/assets/56048471/4d592e42-328e-412e-bf8b-7cdb555753c2)


Please ensure that you have the required hardware components before proceeding with this code.

### Clone the Repository

1. Clone this repository to your local machine using:

   ```
   git clone https://github.com/marius7600/arduino-sparse-peripheral-display.git
   ```

## Usage

### Uploading the Code

1. Open the cloned repsoitory in Visual Studio Code.
2. Configure `src/main.cpp` to match the setup of your LEDs.
3. Build and Upload the code to your Arduino board.

## Contributing

Contributions are welcome! To contribute, follow these steps:

1. Fork the repository.
2. Create a new branch for your feature: `git checkout -b feature-name`.
3. Make your changes and commit them.
4. Push to the branch: `git push origin feature-name`.
5. Open a Pull Request detailing your changes.

## License

This project is licensed under the [MIT License](LICENSE).

## Contact

If you have questions, suggestions, or feedback, contact me at [marius@roehm.dev](mailto:marius@roehm.dev).
