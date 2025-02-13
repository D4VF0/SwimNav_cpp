#include <opencv2/opencv.hpp>
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudawarping.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <iostream>
#include "Camera.hpp"

int main() {
    // GetNodeMap() gibt eine Referenz auf die Node Map des Geräts zurück mit GenICam-Features (Kameraparameter).
    Arena::SetNodeValue(pDevice->GetNodeMap(), "PtpEnable", true); // In order to enable PTP, set “PtpEnable” node to true.
    GenICam::gcstring ptpStatus = Arena::GetNodeValue(pDevice->GetNodeMap(), "PtpStatus"); // Make sure that the PTPStatus node has been set to either “Master” or “Slave”.
    // Set acquisition start mode to “PTPSync”.
    std::cout << TAB3 << "Set acquisition start mode to 'PTPSync'\n";
    Arena::SetNodeValue(pDevice->GetNodeMap(), "AcquisitionStartMode", "PTPSync")

    //  Maximize AcquisitionFrameRate

    GenApi::CFloatPtr pAcquisitionFrameRate = pDevice->GetNodeMap()->GetNode("AcquisitionFrameRate"); // GenApi::CFloatPtr Smart Pointer aus der GenICam API und speziell für Float-Werte gedacht.
    pAcquisitionFrameRate->SetValue(pAcquisitionFrameRate->GetMax());
    

    // Set PTPSyncFrameRate

    GenApi::CFloatPtr pPTPSyncFrameRate = pDevice->GetNodeMap()->GetNode("PTPSyncFrameRate");
    pPTPSyncFrameRate->SetValue(PTPSYNC_FRAME_RATE);                                            

    // Set the desired StreamChannelPacketDelay and StreamChannelFrameTransmissionDelay for each camera

    GenApi::CIntegerPtr pStreamChannelPacketDelay = pDevice->GetNodeMap()->GetNode("GevSCPD");
    pStreamChannelPacketDelay->SetValue(240000);


    GenApi::CIntegerPtr pStreamChannelFrameTransmissionDelay = pDevice->GetNodeMap()->GetNode("GevSCFTD");
    pStreamChannelFrameTransmissionDelay->SetValue(80000);

    /*
    try {
        std::string videoPath = "Pixel_Fabi_20250131_103429295_short.mp4";
        Camera cam(videoPath);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cam.selectROI();

        while (true) {
            cam.getFrameWithTimestamp();
            cam.applyPerspectiveTransformCUDA();
            char key = cv::waitKey(1);
            if (key == 27) break;
            if (key == 'p' || key == 'P') {
                if (cam.getCameraThread().isPaused()) {
                    cam.getCameraThread().resume();
                    std::cout << "Resume capture..\n";
                } else {
                    cam.getCameraThread().pause();
                    std::cout << "Pausing capture..\n";
                }
            }

            std::cout << "Frame captured at: " << cam.getTimestamp() << "seconds. \n";
            //cv::imshow("Live Frame", frame);
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
    
    // Öffne Videodatei
    std::string videoPath = "Pixel_20241213_111249601_short.mp4";
    cv::VideoCapture cap(videoPath);
    if (!cap.isOpened()) {
        std::cerr << "Fehler: Konnte das Video nicht �ffnen!" << std::endl;
        return -1;
    }

    // Video-Speicheroptionen
    int frame_width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(cv::CAP_PROP_FPS);
    std::cout << "FPS: " << fps << std::endl;

    cv::VideoWriter writer("output.mp4",
        cv::VideoWriter::fourcc('H', '2', '6', '4'), // Codec
        fps,
        cv::Size(frame_width, frame_height));

    if (!writer.isOpened()) {
        std::cerr << "Fehler: Konnte das Video nicht speichern!" << std::endl;
        return -1;
    }

    cv::Mat frame;
    cv::cuda::GpuMat gpuFrame, gpuGray;

    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        // Frame auf GPU hochladen
        gpuFrame.upload(frame);

        // Bildverarbeitung mit CUDA (z.B. Graustufen-Umwandlung)
        cv::cuda::cvtColor(gpuFrame, gpuGray, cv::COLOR_BGR2GRAY);

        // Graustufenbild zur�ck zur CPU �bertragen
        cv::Mat grayFrame;
        gpuGray.download(grayFrame);

        // Anzeige
        cv::imshow("CUDA Video", grayFrame);
        if (cv::waitKey(1) == 27) break;

        // Video speichern (als Graustufen BGR umwandeln, da Writer BGR erwartet)
        cv::cvtColor(grayFrame, grayFrame, cv::COLOR_GRAY2BGR);
        writer.write(grayFrame);
    }

    cap.release();
    writer.release();
    cv::destroyAllWindows();
    return 0;
    */
}