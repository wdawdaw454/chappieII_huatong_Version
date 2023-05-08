/**
 * @file ChappieSD.hpp
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-03-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <Arduino.h>
#include <FS.h>
#include <SD.h>

#define CHAPPIE_SD_PIN_MISO     42
#define CHAPPIE_SD_PIN_MOSI     41
#define CHAPPIE_SD_PIN_CLK      40
#define CHAPPIE_SD_PIN_CS       48

class ChappieSD {
    private:
        bool _inited;

    public:
        inline ChappieSD() : _inited(false) {}
        inline ~ChappieSD() {}

        /**
         * @brief 
         * 
         * @return true Success
         * @return false Failed
         */
        inline bool init()
        {
            /* Init spi */
            SPIClass* sd_spi = new SPIClass(HSPI);
            sd_spi->begin(CHAPPIE_SD_PIN_CLK, CHAPPIE_SD_PIN_MISO, CHAPPIE_SD_PIN_MOSI, CHAPPIE_SD_PIN_CS);
            bool ret = SD.begin(CHAPPIE_SD_PIN_CS, *sd_spi, 40000000);
            
            if (!ret) {
                printf("[SD] init failed\n");
                return ret;
            }
            printf("[SD] init success, ");

            /* Get SD card info */
            uint8_t cardType = SD.cardType();
            if (cardType == CARD_MMC)
                printf("MMC");
            else if(cardType == CARD_SD)
                printf("SDSC");
            else if(cardType == CARD_SDHC)
                printf("SDHC");
            printf(" %dGB\n", (SD.cardSize() / 1073741824));

             Serial.println("SD card Ready!");
  printf("SD.cardSize = %lld \r\n", SD.cardSize());
  printf("SD.totalBytes = %lld \r\n", SD.totalBytes());
  printf("SD.usedBytes = %lld \r\n", SD.usedBytes());
  printf("SD.cardType = %d \r\n", SD.cardType());
  printf("is there /test.txt? :%d \r\n", SD.exists("/sd/doc1/test.txt"));
  printf("SD.mkdir doc1 OK? :");printf("%d\r\n",SD.mkdir("/doc1"));
  printf("is there /doc1? :%d \r\n", SD.exists("/doc1"));
  printf("is there /test.txt? :%d \r\n", SD.exists("/test.txt"));
  File file = SD.open("/test.txt", FILE_WRITE);
  printf("is there /test.txt? :%d \r\n", SD.exists("/test.txt"));
  file.printf("hello!!!");
  file.close();
  file = SD.open("/test.txt", FILE_READ);
  //Serial.println(file.readString());
  file.close();
  printf("is there /doc1/test1.txt? :%d \r\n", SD.exists("/doc1/test1.txt"));
  File file2 = SD.open("/doc1/test1.txt", FILE_WRITE);
  printf("is there /doc1/test1.txt? :%d \r\n", SD.exists("/doc1/test1.txt"));
  file2.printf("hello!!!");
  file2.close();
  //file2 = SD.open("/test.txt", FILE_READ);
  //Serial.println(file2.readString());
  //file2.close();
  SD.end();

            _inited = true;
            return ret;
        }

        inline bool isInited() { return _inited; }

};

