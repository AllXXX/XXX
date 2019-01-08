// AllXXX 01.20180
// Плагин для загрузки FS https://github.com/esp8266/arduino-esp8266fs-plugin/releases/tag/0.3.0

#include <ESP8266WiFi.h>             //Содержится в пакете для работы с ESP8266
// Подробнее читайте https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html
//######
// Класс Generic
// Описание https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/generic-class.html
// Примеры https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/generic-examples.html
/*------
    WiFi.mode (m) Установит режим WIFI_AP , WIFI_STA , WIFI_AP_STA или WIFI_OFF
    WiFi.getMode () Возвращает текущий режим Wi-Fi (один из четырех режимов выше)
    WiFi.persistent (persistent) После WiFi.persistent(false) (WiFi.begin , WiFi.disconnect , WiFi.softAP или WiFi.softAPdisconnect) сохроняют текущие настройки Wi-Fi только в памяти а не во флэш-памяти (уменьшить износ флэш-памяти)
-------*/
/*===== Взято из ESP8266WiFiGeneric.h
    // Note: this function is deprecated. Use one of the functions below instead.
    void onEvent(WiFiEventCb cb, WiFiEvent_t event = WIFI_EVENT_ANY) __attribute__((deprecated));
    // Subscribe to specific event and get event information as an argument to the callback
    WiFiEventHandler onStationModeConnected(std::function<void(const WiFiEventStationModeConnected&)>);
    WiFiEventHandler onStationModeDisconnected(std::function<void(const WiFiEventStationModeDisconnected&)>);
    WiFiEventHandler onStationModeAuthModeChanged(std::function<void(const WiFiEventStationModeAuthModeChanged&)>);
    WiFiEventHandler onStationModeGotIP(std::function<void(const WiFiEventStationModeGotIP&)>);
    WiFiEventHandler onStationModeDHCPTimeout(std::function<void(void)>);
    WiFiEventHandler onSoftAPModeStationConnected(std::function<void(const WiFiEventSoftAPModeStationConnected&)>);
    WiFiEventHandler onSoftAPModeStationDisconnected(std::function<void(const WiFiEventSoftAPModeStationDisconnected&)>);
    WiFiEventHandler onSoftAPModeProbeRequestReceived(std::function<void(const WiFiEventSoftAPModeProbeRequestReceived&)>);
    // WiFiEventHandler onWiFiModeChange(std::function<void(const WiFiEventModeChange&)>);
    int32_t channel(void);
    bool setSleepMode(WiFiSleepType_t type, uint8_t listenInterval = 0);
    WiFiSleepType_t getSleepMode();
    uint8_t getListenInterval ();
    bool isSleepLevelMax ();
    bool setPhyMode(WiFiPhyMode_t mode);
    WiFiPhyMode_t getPhyMode();
    void setOutputPower(float dBm);
    void persistent(bool persistent);
    bool mode(WiFiMode_t);
    WiFiMode_t getMode();
    bool enableSTA(bool enable);
    bool enableAP(bool enable);
    bool forceSleepBegin(uint32 sleepUs = 0);
    bool forceSleepWake();
    static void preinitWiFiOff (); //meant to be called in user-defined preinit()
======*/
//######
// Класс Station
// Описание https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/station-class.html
// Примеры https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/station-examples.html
/*------
    WiFi.begin (ssid ,password, channel, bssid, connect) Подключаться к определенной точке доступа.
        ssid - строка содержащая SSID точки доступа, к которой мы хотим подключиться, может содержать до 32 символов
        password - пароль к точке доступа, символьная строка длиной не менее 8 символов и не более 64 символов
        channel - № канала (необязателен)
        bssid - MAC-адрес точки доступа (необязателен)
        connect - параметр, если установлено в false, будут сохранены параметры без установления соединения с точкой доступа  (необязателен)
    WiFi.config (local_ip, gateway, subnet, dns1, dns2) Вернет true если изменение конфигурации будет успешно применено, false если модуль не находится в режиме станции или станции + программной точки доступа
        local_ip - IP-адрес, который вы хотите назначить интерфейсу станции ESP
        gateway - должен содержать IP-адрес шлюза (роутера) для доступа к внешним сетям
        subnet - это маска, определяющая диапазон IP-адресов локальной сети
        dns1 , dns2 - необязательные параметры, которые определяют IP-адреса серверов доменных имен (DNS), которые поддерживают каталог доменных имен (например, www.google.co.uk ) и переводят их для нас в IP-адреса 
    WiFi.reconnect () Переподключить станцию.
    WiFi.disconnect (wifioff) Устанавливает текущие настроенные SSID и пароль равными null и отключает станцию ​​от точки доступа.
    WiFi.isConnected () true есть подключение к точке доступа, false если нет
-------*/
/*===== Взято из ESP8266WiFiSTA.h
    wl_status_t begin(const char* ssid, const char *passphrase = NULL, int32_t channel = 0, const uint8_t* bssid = NULL, bool connect = true);
    wl_status_t begin(char* ssid, char *passphrase = NULL, int32_t channel = 0, const uint8_t* bssid = NULL, bool connect = true);
    wl_status_t begin();
    //The argument order for ESP is not the same as for Arduino. However, there is compatibility code under the hood 
    //to detect Arduino arg order, and handle it correctly. Be aware that the Arduino default value handling doesn't 
    //work here (see Arduino docs for gway/subnet defaults). In other words: at least 3 args must always be given.
    bool config(IPAddress local_ip, IPAddress gateway, IPAddress subnet, IPAddress dns1 = (uint32_t)0x00000000, IPAddress dns2 = (uint32_t)0x00000000);
    bool reconnect();
    bool disconnect(bool wifioff = false);
    bool isConnected();
    bool setAutoConnect(bool autoConnect);
    bool getAutoConnect();
    bool setAutoReconnect(bool autoReconnect);
    bool getAutoReconnect();
    uint8_t waitForConnectResult();
    // STA network info
    IPAddress localIP();
    uint8_t * macAddress(uint8_t* mac);
    String macAddress();
    IPAddress subnetMask();
    IPAddress gatewayIP();
    IPAddress dnsIP(uint8_t dns_no = 0);
    String hostname();
    bool hostname(char* aHostname);
    bool hostname(const char* aHostname);
    bool hostname(const String& aHostname);
    // STA WiFi info
    wl_status_t status();
    String SSID() const;
    String psk() const;
    uint8_t * BSSID();
    String BSSIDstr();
    int32_t RSSI();
    static void enableInsecureWEP (bool enable = true) { _useInsecureWEP = enable; }
======*/

//######
// Класс Soft Access Point
// Описание https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/soft-access-point-class.html
// Примеры https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/soft-access-point-examples.html
/*------
-------*/
/*===== Взято из ESP8266WiFiAP.h
    bool softAP(const char* ssid, const char* passphrase = NULL, int channel = 1, int ssid_hidden = 0, int max_connection = 4);
    bool softAPConfig(IPAddress local_ip, IPAddress gateway, IPAddress subnet);
    bool softAPdisconnect(bool wifioff = false);
    uint8_t softAPgetStationNum();
    IPAddress softAPIP();
    uint8_t* softAPmacAddress(uint8_t* mac);
    String softAPmacAddress(void);
    String softAPSSID() const;
    String softAPPSK() const;
======*/
//######
// Класс Scan
// Описание https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/scan-class.html
// Примеры https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/scan-examples.html
/*------
-------*/
/*===== Взято из ESP8266WiFiScan.h
    int8_t scanNetworks(bool async = false, bool show_hidden = false, uint8 channel = 0, uint8* ssid = NULL);
    void scanNetworksAsync(std::function<void(int)> onComplete, bool show_hidden = false);
    int8_t scanComplete();
    void scanDelete();
    // scan result
    bool getNetworkInfo(uint8_t networkItem, String &ssid, uint8_t &encryptionType, int32_t &RSSI, uint8_t* &BSSID, int32_t &channel, bool &isHidden);
    String SSID(uint8_t networkItem);
    uint8_t encryptionType(uint8_t networkItem);
    int32_t RSSI(uint8_t networkItem);
    uint8_t * BSSID(uint8_t networkItem);
    String BSSIDstr(uint8_t networkItem);
    int32_t channel(uint8_t networkItem);
    bool isHidden(uint8_t networkItem);
======*/
//######
// Класс Client
// Описание https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/client-class.html
// Для WiFiClient(), connected(), connect(), write(), print(), println(), available(), read(), flush(), stop()
// https://www.arduino.cc/en/Reference/WiFi
// Примеры https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/client-examples.html
/*------
-------*/
/*===== Взято из 
    WiFiClient();
    virtual ~WiFiClient();
    WiFiClient(const WiFiClient&);
    WiFiClient& operator=(const WiFiClient&);
    uint8_t status();
    virtual int connect(CONST IPAddress& ip, uint16_t port);
    virtual int connect(const char *host, uint16_t port);
    virtual int connect(const String& host, uint16_t port);
    virtual size_t write(uint8_t);
    virtual size_t write(const uint8_t *buf, size_t size);
    virtual size_t write_P(PGM_P buf, size_t size);
    size_t write(Stream& stream);
    // This one is deprecated, use write(Stream& instead)
    size_t write(Stream& stream, size_t unitSize) __attribute__ ((deprecated));
    virtual int available();
    virtual int read();
    virtual int read(uint8_t *buf, size_t size);
    virtual int peek();
    virtual size_t peekBytes(uint8_t *buffer, size_t length);
    size_t peekBytes(char *buffer, size_t length) {return peekBytes((uint8_t *) buffer, length);}
    virtual bool flush(unsigned int maxWaitMs = 0);
    virtual bool stop(unsigned int maxWaitMs = 0);
    virtual uint8_t connected();
    virtual operator bool();
    IPAddress remoteIP();
    uint16_t  remotePort();
    IPAddress localIP();
    uint16_t  localPort();
    static void setLocalPortStart(uint16_t port) { _localPort = port; }
    size_t availableForWrite();
    friend class WiFiServer;
    using Print::write;
    static void stopAll();
    static void stopAllExcept(WiFiClient * c);
    void     keepAlive (uint16_t idle_sec = TCP_DEFAULT_KEEPALIVE_IDLE_SEC, uint16_t intv_sec = TCP_DEFAULT_KEEPALIVE_INTERVAL_SEC, uint8_t count = TCP_DEFAULT_KEEPALIVE_COUNT);
    bool     isKeepAliveEnabled () const;
    uint16_t getKeepAliveIdle () const;
    uint16_t getKeepAliveInterval () const;
    uint8_t  getKeepAliveCount () const;
    void     disableKeepAlive () { keepAlive(0, 0, 0); }
    // default NoDelay=False (Nagle=True=!NoDelay)
    // Nagle is for shortly delaying outgoing data, to send less/bigger packets
    // Nagle should be disabled for telnet-like/interactive streams
    // Nagle is meaningless/ignored when Sync=true
    static void setDefaultNoDelay (bool noDelay);
    static bool getDefaultNoDelay ();
    bool getNoDelay() const;
    void setNoDelay(bool nodelay);
    // default Sync=false
    // When sync is true, all writes are automatically flushed.
    // This is slower but also does not allocate
    // temporary memory for sending data
    static void setDefaultSync (bool sync);
    static bool getDefaultSync ();
    bool getSync() const;
    void setSync(bool sync);
======*/
//######
// Класс Server
// Описание https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/server-class.html
// Для WiFiServer(), begin(), available(), write(), print(), println()
// https://www.arduino.cc/en/Reference/WiFi
// Примеры https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/server-examples.html
/*------
-------*/
/*===== Взято из WiFiServer.h
    WiFiServer(const IPAddress& addr, uint16_t port);
    WiFiServer(uint16_t port);
    virtual ~WiFiServer() {}
    WiFiClient available(uint8_t* status = NULL);
    bool hasClient();
    void begin();
    void begin(uint16_t port);
    void setNoDelay(bool nodelay);
    bool getNoDelay();
    virtual size_t write(uint8_t);
    virtual size_t write(const uint8_t *buf, size_t size);
    uint8_t status();
    void close();
    void stop();
======*/
//######
// Класс UDP
// Описание https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/udp-class.html
// Примеры https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/udp-examples.html
/*------
-------*/
/*===== Взято из WiFiUdp.h
======*/



//######
// Класс 
// Описание 
// Примеры 
/*------
-------*/
/*===== Взято из 
======*/
//######
// Класс 
// Описание 
// Примеры 
/*------
-------*/
/*===== Взято из 
======*/



#include <ESP8266WebServer.h>        //Содержится в пакете для работы с сервером
//#include <ESP8266SSDP.h>             //Содержится в пакете
#include <FS.h>                      //Содержится в пакете для работы с файловой системой
// Подробнее читайте https://arduino-esp8266.readthedocs.io/en/latest/filesystem.html
// Класс FS
/*===== Взято из FS.h
    bool begin();
    void end();
    bool format();
    bool info(FSInfo& info);
    File open(const String& path, const char* mode);
    bool exists(const String& path);
    Dir openDir(const String& path);
    bool remove(const String& path);
    bool rename(const String& pathFrom, const String& pathTo);
======*/
// path должен быть абсолютным путем, начинающимся с косой черты (например, /dir/filename.txt ).
// SPIFFS.begin ()          Монтирует файловую систему SPIFFS. Возвращает true, если файловая система была смонтирована успешно, иначе false.
// SPIFFS.end ()            Размонтирует файловую систему SPIFFS
// SPIFFS.format ()         Форматирует файловую систему. Может быть вызван до или после begin. Возвращает true, если форматирование прошло успешно.
// SPIFFS.exists (path)     Возвращает true, если файл с указанным путем существует, в противном случае - false .
// SPIFFS.rename (pathFrom, pathTo) Переименовывает файл из pathFrom в pathTo. Возвращает true, если файл был успешно переименован.
// SPIFFS.remove (path)     Удаляет файл. Возвращает true, если файл был успешно удален.
// SPIFFS.open (path, mode) Открывает файл.
//      mode - строка, определяющая режим доступа.
//          r   Открыть для чтения. Позиця в начале файла.
//          r+  Открыть для чтения/записи. Позиця в начале файла.
//          w   Очистить или создать если нет. Позиця в начале файла.
//          w+  Очистить и открыть для записи или создать если нет. Позиця в начале файла.
//          a   Открыть для записи. Позиця в конце  файла.
//          a+  Открыть для чтения/записи. Позиця в конце  файла.
// SPIFFS.open () Возвращает объект File . Чтобы проверить, был ли файл открыт успешно, используйте логический оператор.
// File f = SPIFFS . open ( "/f.txt" , "w" );
//  if ( ! f ) {
//    Serial . println ( "Ошибка открытия файла" );
//  }
// SPIFFS.openDir (path)    Открывает каталог. Возвращает объект Dir.
// Класс Dir
/*===== Взято из FS.h
    File openFile(const char* mode);
    String fileName();
    size_t fileSize();
    bool next();
======*/



//#include <ESP8266HTTPUpdateServer.h> //Содержится в пакете
//ESP8266HTTPUpdateServer httpUpdater;
//#include <ESP8266httpUpdate.h>       //Содержится в пакете
File fsUploadFile;
ESP8266WebServer HTTP(80);
ESP8266WebServer HTTPWAN(8080);
