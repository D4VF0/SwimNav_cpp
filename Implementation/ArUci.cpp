#include <opencv2/aruco.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // ArUco Dictionary auswählen
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);

    // Board Parameter
    int squaresX = 5;  // Anzahl Marker pro Zeile
    int squaresY = 7;  // Anzahl Marker pro Spalte
    float squareLength = 0.25f;  // Quadratgröße in Metern (25 cm)
    float markerLength = 0.20f;  // Markergröße in Metern (20 cm)

    // ArUco-Board erzeugen
    cv::Ptr<cv::aruco::GridBoard> board = cv::aruco::GridBoard::create(squaresX, squaresY, squareLength, markerLength, dictionary);

    // Bildgröße definieren
    int imageWidth = squaresX * 500;  // 500 px pro Quadrat
    int imageHeight = squaresY * 500;
    cv::Mat boardImage;

    // Board zeichnen
    board->draw(cv::Size(imageWidth, imageHeight), boardImage, 10, 1);

    // Bild speichern
    std::string filename = "aruco_board.png";
    cv::imwrite(filename, boardImage);
    std::cout << "ArUco Board gespeichert als: " << filename << std::endl;

    return 0;
}