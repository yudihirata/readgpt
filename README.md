
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
[~/repo/readgpt/bin/Release]$ ./readgpt -f ~/tmp/gpt.bin
[+] Partition table header
===============================================================================================================
Signature:      EFI PART
Checksum:       0x6136A16C
Revision:       0x10000
GUID    :       98101B32-6EA0-003D-0200-000000000000
[+] GUID Partition Table
Index |        Partition |         Offset          |        Size   |  GUID
    0 |            modem |  0x00000100-0x000320FF  |      102400K  |  4098648B-89E3-EF9E-0001-000000000000
    1 |             sbl1 |  0x00032100-0x000323FF  |         384K  |  88FE4602-47C8-7897-0021-030000000000
    2 |              DDR |  0x00032500-0x0003253F  |          32K  |  42AAB25B-362C-DE17-0025-030000000000
    3 |            aboot |  0x00032600-0x00032DFF  |        1024K  |  6F29EC23-3259-4F28-0026-030000000000
    4 |              rpm |  0x000331B8-0x000333B7  |         256K  |  1B39767E-6CA6-4015-B831-030000000000
    5 |               tz |  0x000335A0-0x000338BF  |         400K  |  DA95A567-3F1F-AD40-A035-030000000000
    6 |              sdi |  0x00033988-0x000339C7  |          32K  |  B3653879-D30E-5F9B-8839-030000000000
    7 |            utags |  0x000339C8-0x00033DC7  |         512K  |  1F29B04B-7872-A468-C839-030000000000
    8 |             logs |  0x00033DC8-0x00034DC7  |        2048K  |  5978BD4B-8D5E-F414-C83D-030000000000
    9 |     factorytune1 |  0x00034DC8-0x000365C7  |        3072K  |  D0B2579F-F8F6-7C19-C84D-030000000000
   10 |             padA |  0x000365C8-0x00037FFF  |        3356K  |  48A23B7D-529F-65B0-C865-030000000000
   11 |      abootBackup |  0x00038000-0x000387FF  |        1024K  |  AC583963-6DDC-0847-0080-030000000000
   12 |        rpmBackup |  0x00038BB8-0x00038DB7  |         256K  |  F0B4420A-51F2-E555-B88B-030000000000
   13 |         tzBackup |  0x00038FA0-0x000392BF  |         400K  |  33346205-2B1E-8C7F-A08F-030000000000
   14 |      utagsBackup |  0x00039388-0x00039787  |         512K  |  9C0364EE-D009-C342-8893-030000000000
   15 |              frp |  0x00039800-0x00039BFF  |         512K  |  DC0CDC98-17F8-B59D-0098-030000000000
   16 |             padB |  0x00039C00-0x0003BFFF  |        4608K  |  8CAFF73D-DFD6-165D-009C-030000000000
   17 |         modemst1 |  0x0003C000-0x0003CBFF  |        1536K  |  6402A956-57E3-F749-00C0-030000000000
   18 |         modemst2 |  0x0003CC00-0x0003D7FF  |        1536K  |  D84CF569-3C15-74AD-00CC-030000000000
   19 |              hob |  0x0003D800-0x0003DBCF  |         488K  |  F5193435-407A-5879-00D8-030000000000
   20 |             dhob |  0x0003DBD0-0x0003DC0F  |          32K  |  45C3C618-3971-98BD-D0DB-030000000000
   21 |              fsg |  0x0003DD00-0x0003E8FF  |        1536K  |  C6BD84D1-7D98-5E70-00DD-030000000000
   22 |              fsc |  0x0003E900-0x0003E901  |           1K  |  F3336C60-CA88-2FF3-00E9-030000000000
   23 |              ssd |  0x0003E902-0x0003E911  |           8K  |  6BB896AD-84AE-6A6F-02E9-030000000000
   24 |               sp |  0x0003E912-0x0003F111  |        1024K  |  4FF48071-BA35-74C0-12E9-030000000000
   25 |              cid |  0x0003F112-0x0003F211  |         128K  |  D4A41FA3-9B3D-8729-12F1-030000000000
   26 |              pds |  0x0003F212-0x00040A11  |        3072K  |  7DE4DB03-2EFE-F71A-12F2-030000000000
   27 |             misc |  0x00040A12-0x00040E11  |         512K  |  9208D04B-71C2-77FE-120A-040000000000
   28 |             logo |  0x00040E12-0x00042E11  |        4096K  |  B5518038-88CC-B1BD-120E-040000000000
   29 |            clogo |  0x00042E12-0x00045E11  |        6144K  |  31CEA552-0493-C00F-122E-040000000000
   30 |          persist |  0x00045F00-0x00049EFF  |        8192K  |  63CC9D46-7B0F-E73A-005F-040000000000
   31 |             kpan |  0x00049F00-0x0004DEFF  |        8192K  |  1830267A-80AD-03BF-009F-040000000000
   32 |             boot |  0x0004DF00-0x00052EAF  |       10200K  |  BEA3652C-723C-4CA0-00DF-040000000000
   33 |         recovery |  0x00052EB0-0x00057EFF  |       10280K  |  080BBFC6-B920-F4ED-B02E-050000000000
   34 |     factorytune2 |  0x00057F00-0x0005CF6F  |       10296K  |  17038089-BF97-EC80-007F-050000000000
   35 |        customize |  0x0005CF70-0x0008EF6F  |      102400K  |  D0DAF2A8-DCFF-4A2E-70CF-050000000000
   36 |            cache |  0x0008EF70-0x00337FFF  |     1394760K  |  1FED6EBE-024F-CDFA-70EF-080000000000
   37 |           system |  0x00338000-0x0089FFFF  |     2834432K  |  6EC83223-BD52-F493-0080-330000000000
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
