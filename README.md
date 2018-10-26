
# readgpt
readgpt is a tool to read and print gpt layout
```sh
READGPT - 1.0.0         BETA                    Read GUID Partition Table
Usage: readgpt [OPTION...] [FILE...]
readgpt: read GPT from file.

        --help          display this help and exit
        -z, --version   output version information and exit
        -f, --file      The argument following the -f is used to indicate the binary file
```

# The Easiest Way to Install readgpt

## Linux(strongly recommended)
Download the latest version of readgpt
unzip the file
set the appropriate permission missing:
chmod a+x readgpt
copy/move the readgpt to /bin


# How to compile readgpt for Linux
## Software requirements
- GNU/Linux
- make
- g++
Download the source code, git clone https://github.com/yudihirata/readgpt.git
```sh
[~/repo/readgpt]$ make linux
g++ -Wall -fexceptions -Wfatal-errors -Wall -std=gnu++11 -I/home/marco.hirata/repo/readgpt/src/include -O3  -c src/main.cpp \
    -o obj/Release/src/main.o
g++ -Wall -fexceptions -Wfatal-errors -Wall -std=gnu++11 -I/home/marco.hirata/repo/readgpt/src/include -O3  -c src/model/GPT.cpp \
    -o obj/Release/src/model/GPT.o
g++ -Wall -fexceptions -Wfatal-errors -Wall -std=gnu++11 -I/home/marco.hirata/repo/readgpt/src/include -O3  -c src/util/Log.cpp \
    -o obj/Release/src/util/Log.o
g++   obj/Release/src/main.o obj/Release/src/model/GPT.o obj/Release/src/util/Log.o -I/usr/local/include/ -L/usr/local/lib/ -I/usr/include/ -I/home/marco.hirata/repo/readgpt/src/include -o bin/Release/readgpt
Compiling Linux
```
## Usage

```sh
[~/repo/readgpt/bin/Release]$ ./readgpt -f ~/tmp/PrimaryGPT.img
[+] Partition table header
===============================================================================================================
Signature:      EFI PART
Checksum:       0x37F595BB
Revision:       0x10000
GUID    :       98101B32-6EA0-003D-0200-000000000000
[+] GUID Partition Table
Index |        Partition |         Offset          |        Size   |  GUID
    0 |              laf |  0x00000006-0x00003005  |       49152K  |  655798EC-E3AF-E7E5-0600-000000000000
    1 |           lafbak |  0x00003006-0x00006005  |       49152K  |  785BA30C-5B3B-E892-0630-000000000000
    2 |              mpt |  0x00006006-0x00008005  |       32768K  |  1861BBFA-8CC7-8547-0660-000000000000
    3 |              drm |  0x00008006-0x00008A05  |       10240K  |  E0917C94-DB90-AB46-0680-000000000000
    4 |              sns |  0x00008A06-0x00009005  |        6144K  |  24335DE3-316A-8C14-068A-000000000000
    5 |             misc |  0x00009006-0x0000B005  |       32768K  |  0FE146EE-9CBA-70E9-0690-000000000000
    6 |          factory |  0x0000B006-0x0000F205  |       67584K  |  DA55080F-B31B-1BEF-06B0-000000000000
    7 |          encrypt |  0x0000F206-0x0000F285  |         512K  |  81095A05-4F5B-AAA1-06F2-000000000000
    8 |            eksst |  0x0000F286-0x0000F305  |         512K  |  9EF684B3-4632-FBC6-86F2-000000000000
    9 |              rct |  0x0000F306-0x0000F385  |         512K  |  A3A6F25F-73B6-31F1-06F3-000000000000
   10 |              ssd |  0x0000F386-0x0000F405  |         512K  |  1A48FEC1-9945-72E5-86F3-000000000000
   11 |         keystore |  0x0000F406-0x0000F485  |         512K  |  DB04C299-A503-2D18-06F4-000000000000
   12 |          persist |  0x0000F486-0x00011485  |       32768K  |  712513B5-D016-FB03-86F4-000000000000
   13 |           system |  0x00011486-0x0016EC85  |     5726208K  |  1DA83697-853D-5E85-8614-010000000000
   14 |            cache |  0x0016EC86-0x0018EC85  |      524288K  |  8ECD2D0B-9006-26A4-86EC-160000000000
   15 |               OP |  0x0018EC86-0x00201F85  |     1887232K  |  05B2FE5C-BB55-F425-86EC-180000000000
   16 |         userdata |  0x00201F86-0x0075E485  |    22483968K  |  D7FC809E-4208-1060-861F-200000000000
   17 |             grow |  0x0075E486-0x0075EBFA  |        7636K  |  02DF291D-6197-DADC-86E4-750000000000
[~/repo/readgpt/bin/Release]$

```
# How to compile readgpt for Android
## Software requirements
- GNU/Linux
- make
- g++
- Android NDK - https://developer.android.com/ndk/downloads/
```sh
[~/repo/readgpt]$ export CONFIG_ANDROID_NDK_BUILD_TOOL=/home/yudihirata/arm/android-ndk-r17b
[~/repo/readgpt]$ make android
Compiling Android
/home/yudihirata/arm/android-ndk-r17b/ndk-build NDK_APPLICATION_MK=src/Application.mk
make[1]: Entering directory `/home/marco.hirata/repo/readgpt'
[arm64-v8a] Compile++      : readgpt <= main.cpp
[arm64-v8a] Compile++      : readgpt <= GPT.cpp
[arm64-v8a] Compile++      : readgpt <= Log.cpp
[arm64-v8a] Executable     : readgpt
[arm64-v8a] Install        : readgpt => libs/arm64-v8a/readgpt
[x86_64] Compile++      : readgpt <= main.cpp
[x86_64] Compile++      : readgpt <= GPT.cpp
[x86_64] Compile++      : readgpt <= Log.cpp
[x86_64] Executable     : readgpt
[x86_64] Install        : readgpt => libs/x86_64/readgpt
[armeabi-v7a] Compile++ thumb: readgpt <= main.cpp
[armeabi-v7a] Compile++ thumb: readgpt <= GPT.cpp
[armeabi-v7a] Compile++ thumb: readgpt <= Log.cpp
[armeabi-v7a] Executable     : readgpt
[armeabi-v7a] Install        : readgpt => libs/armeabi-v7a/readgpt
[x86] Compile++      : readgpt <= main.cpp
[x86] Compile++      : readgpt <= GPT.cpp
[x86] Compile++      : readgpt <= Log.cpp
[x86] Executable     : readgpt
[x86] Install        : readgpt => libs/x86/readgpt
make[1]: Leaving directory `/home/yudihirata/repo/readgpt'
[~/repo/readgpt]$
```
## Usage

```sh
adb push .\readgpt /data/locat/tmp
adb shell
mcv5a:/ # cd /data/local/tmp
mcv5a:/ # chmod +x readgpt
mcv5a:/data/local/tmp # ./readgpt -f /dev/block/mmcblk0
[+] Partition table header
===============================================================================================================
Signature:      EFI PART
Checksum:       0x3EEACD9
Revision:       0x10000
GUID    :       00000000-0000-0000-0000-020000000000

[+] GUID Partition Table
Index |        Partition |         Offset          |        Size  |GUID
    0 |          proinfo |  0x00000400-0x00001BFF  |       3072K  | F57AD330-39C2-B09B-4300-040000000000
    1 |            misc2 |  0x00001C00-0x00005BFF  |       8192K  | FE686D97-3544-21BE-2500-1C0000000000
    2 |              ftm |  0x00005C00-0x00009BFF  |       8192K  | 1CB143A8-B1A8-51B2-5100-5C0000000000
    3 |            nvram |  0x00009C00-0x0000C3FF  |       5120K  | 3B9E343B-CDC8-A69F-2E00-9C0000000000
    4 |           spare1 |  0x0000C400-0x0000FFFF  |       7680K  | 5F6A2C79-6617-02AC-5A00-C40000000000
    5 |         protect1 |  0x00010000-0x00013FFF  |       8192K  | 4AE2050B-5DB5-D3AA-5300-000100000000
    6 |         protect2 |  0x00014000-0x00017FFF  |       8192K  | 1F9B0939-E16B-BCA5-E900-400100000000
    7 |             lk_a |  0x00018000-0x000187FF  |       1024K  | D722C721-0DEE-838A-CD00-800100000000
    8 |             lk_b |  0x00018800-0x00018FFF  |       1024K  | E02179A8-CEB5-3188-9C00-880100000000
    9 |            laf_a |  0x00019000-0x00026FFF  |      28672K  | 84B09A81-FAD2-0E89-2400-900100000000
   10 |            laf_b |  0x00027000-0x00034FFF  |      28672K  | E8F0A5EF-8D1B-2A9C-D700-700200000000
   11 |             para |  0x00035000-0x000353FF  |        512K  | D5F0E175-A6E1-C094-D000-500300000000
   12 |           boot_a |  0x00035400-0x00040FFF  |      24064K  | 1D9056E1-E139-0B8C-D700-540300000000
   13 |           boot_b |  0x00041000-0x0004CBFF  |      24064K  | 7792210B-B6A8-91AD-ED00-100400000000
   14 |           logo_a |  0x0004CC00-0x00051BFF  |      10240K  | 138A6DB9-1032-E991-8F00-CC0400000000
   15 |           logo_b |  0x00051C00-0x00056BFF  |      10240K  | 756D934C-50E3-46AF-2400-1C0500000000
   16 |            expdb |  0x00056C00-0x0005BBFF  |      10240K  | A3F3C267-5521-24A7-C200-6C0500000000
   17 |           spare2 |  0x0005BC00-0x0005BFFF  |        512K  | 8C68CD2A-CCC9-578B-9B00-BC0500000000
   18 |           seccfg |  0x0005C000-0x0005FFFF  |       8192K  | 6A5CEBF8-54A7-1D8D-1400-C00500000000
   19 |      oemkeystore |  0x00060000-0x00063FFF  |       8192K  | A0D65BF8-E8DE-3494-8C00-000600000000
   20 |            secro |  0x00064000-0x00066FFF  |       6144K  | 46F0C0BB-F227-2FB8-8E00-400600000000
   21 |         keystore |  0x00067000-0x0006AFFF  |       8192K  | FBC2C131-6392-1EB5-6E00-700600000000
   22 |            tee_a |  0x0006B000-0x0006D7FF  |       5120K  | E195A981-E285-2580-3E00-B00600000000
   23 |            tee_b |  0x0006D800-0x0006FFFF  |       5120K  | E29052F8-5D3A-B5AD-2C00-D80600000000
   24 |            eksst |  0x00070000-0x000703FF  |        512K  | 9C3CABD7-A35D-578C-7500-000700000000
   25 |          encrypt |  0x00070400-0x000707FF  |        512K  | E7099731-95A6-E5A1-BA00-040700000000
   26 |       persist_lg |  0x00070800-0x000747FF  |       8192K  | 8273E1AB-846F-99B9-A800-080700000000
   27 |              mpt |  0x00074800-0x000847FF  |      32768K  | D26472F1-9EBC-14BA-9600-480700000000
   28 |             fota |  0x00084800-0x000897FF  |      10240K  | B72CCBE9-2055-67A1-9C00-480800000000
   29 |              rct |  0x00089800-0x00089FFF  |       1024K  | 9C1520F3-C2C5-4282-6100-980800000000
   30 |          factory |  0x0008A000-0x00094BFF  |      22016K  | 902D5F3F-434A-8889-8800-A00800000000
   31 |            efuse |  0x00094C00-0x00094FFF  |        512K  | BECE74C8-D8E2-FE9B-6600-4C0900000000
   32 |          persist |  0x00095000-0x000ACFFF  |      49152K  | FF1342CF-B7BE-5EA2-AD00-500900000000
   33 |            nvcfg |  0x000AD000-0x000B0FFF  |       8192K  | A4DA8F1B-FE07-CB95-F200-D00A00000000
   34 |           nvdata |  0x000B1000-0x000C0FFF  |      32768K  | C2635E15-61AA-409C-BD00-100B00000000
   35 |         metadata |  0x000C1000-0x000D0FFF  |      32768K  | 4D2D1290-36A3-B4AF-8A00-100C00000000
   36 |         md1img_a |  0x000D1000-0x000DCFFF  |      24576K  | FDCE12F0-A7EB-5083-7200-100D00000000
   37 |         md1dsp_a |  0x000DD000-0x000DEFFF  |       4096K  | 0FBBAFA2-4AA9-8389-3200-D00D00000000
   38 |        md1arm7_a |  0x000DF000-0x000E07FF  |       3072K  | A76E4B2F-31CB-6A82-0B00-F00D00000000
   39 |         md1img_b |  0x000E0800-0x000EC7FF  |      24576K  | F54AC030-7004-8194-8200-080E00000000
   40 |         md1dsp_b |  0x000EC800-0x000EE7FF  |       4096K  | C4C310E2-4A7E-1848-D800-C80E00000000
   41 |        md1arm7_b |  0x000EE800-0x000EFFFF  |       3072K  | 3734710F-0F13-4C73-8E00-E80E00000000
   42 |              frp |  0x000F0000-0x000F3FFF  |       8192K  | 85A5B02F-3773-4910-DE00-000F00000000
   43 |            power |  0x000F4000-0x000FFFFF  |      24576K  | 6FCE83A6-5273-4511-EB00-400F00000000
   44 |              els |  0x00100000-0x00107FFF  |      16384K  | 3645E6A3-A7E3-4149-1000-001000000000
   45 |          carrier |  0x00108000-0x0011BFFF  |      40960K  | F60B92B4-0E2F-4AFB-6400-801000000000
   46 |        odmdtbo_a |  0x0011C000-0x0011FFFF  |       8192K  | D05CEDFE-20B7-F259-5300-C01100000000
   47 |         vendor_a |  0x00120000-0x00233FFF  |     565248K  | 54060B67-FA74-1661-1E00-001200000000
   48 |         system_a |  0x00234000-0x008EBFFF  |    3522560K  | C0A128FB-59D1-E8F0-3600-402300000000
   49 |        odmdtbo_b |  0x008EC000-0x008EFFFF  |       8192K  | F5F5A7F8-F8EC-C9CB-7C00-C08E00000000
   50 |         vendor_b |  0x008F0000-0x00A03FFF  |     565248K  | 736D618A-5B79-AC9D-3900-008F00000000
   51 |         system_b |  0x00A04000-0x010BBFFF  |    3522560K  | A2342AC6-4C40-4F51-4600-40A000000000
   52 |            oem_a |  0x010BC000-0x010BFFFF  |       8192K  | 339D6F74-BCB8-4A69-5200-C00B01000000
   53 |            oem_b |  0x010C0000-0x010C3FFF  |       8192K  | 2CD122A3-6142-8812-FB00-000C01000000
   54 |             OP_a |  0x010C4000-0x011EB5C7  |     604900K  | C09B7BD1-5E46-D597-0700-400C01000000
   55 |             OP_b |  0x011EB5C8-0x01312B8F  |     604900K  | 448A65B8-A5D4-EBDD-A3C8-B51E01000000
   56 |         userdata |  0x01312B90-0x07473BFF  |   51054648K  | B1B1E374-8C7F-75D5-A290-2B3101000000
   57 |        flashinfo |  0x07473C00-0x0747BBFF  |      16384K  | 24D37DD4-CAF8-45BE-B000-3C4707000000
mcv5a:/data/local/tmp #
```
# Author
 **Yudi Hirata** - https://www.linkedin.com/in/yudi-hirata/
 Advanced Embedded Software developer with more than 11 years of experience in embedded systems on a
 variety of platforms such as Qualcomm, MediaTek, OMAP, Nvidia, Ericsson, Mbed and Raspberry pi.

## License
[MIT](https://choosealicense.com/licenses/mit/)
