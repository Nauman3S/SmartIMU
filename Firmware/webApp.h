void liveAPI();
void handleRoot();
void sendRedirect(String uri);
void handleGPIO();

void liveAPI()
{

    String page = PSTR(
        "<html>"
        "</head>"
        "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
        "<style type=\"text/css\">"
        "body {"
        "-webkit-appearance:none;"
        "-moz-appearance:none;"
        "font-family:'Arial',sans-serif;"
        "text-align:center;"
        "}"
        ".menu > a:link {"
        "position: absolute;"
        "display: inline-block;"
        "right: 12px;"
        "padding: 0 6px;"
        "text-decoration: none;"
        "}"
        ".button {"
        "display:inline-block;"
        "border-radius:7px;"
        "background:#73ad21;"
        "margin:0 10px 0 10px;"
        "padding:10px 20px 10px 20px;"
        "text-decoration:none;"
        "color:#000000;"
        "}"
        "</style>"
        "</head>"
        "<body>"
        "<div class=\"menu\">" AUTOCONNECT_LINK(BAR_24) "</div>"
                                                        "Live API<br>");

    page += String(F("{\n\""));
    page += String((hostName));
    page += String(F("\":{\n"));
    page += String(F("{\n\"Timestamp\":"));
    page += String((getTimestamp()));
    page += String(F(",\n\"IMU\":"));
    page += String((getMPU6050Data()));
    page += String(F("\n}\n}"));

    page += String(F("<p><br><a class=\"button\" href=\"/api-now\">Refresh</a></p>"));

    page += String(F("</body></html>"));
    server.send(200, "text/html", page);
}
void redirectToHome()
{
    server.sendHeader("Location", "/", true);
    server.send(302, "text/plain", "");
}
void dataTable()
{
    redirectToHome();
}
void live()
{
    String page = PSTR(
        "<html>"
        "</head>"
        "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
        "<style type=\"text/css\">"
        "body {"
        "-webkit-appearance:none;"
        "-moz-appearance:none;"
        "font-family:'Arial',sans-serif;"
        "text-align:center;"
        "}"
        ".menu > a:link {"
        "position: absolute;"
        "display: inline-block;"
        "right: 12px;"
        "padding: 0 6px;"
        "text-decoration: none;"
        "}"
        ".button {"
        "display:inline-block;"
        "border-radius:7px;"
        "background:#73ad21;"
        "margin:0 10px 0 10px;"
        "padding:10px 20px 10px 20px;"
        "text-decoration:none;"
        "color:#000000;"
        "}"
        "</style>"
        "</head>"
        "<body>"
        "<div class=\"menu\">" AUTOCONNECT_LINK(BAR_24) "</div>"
                                                        "Accelerometer Sensing<br>");

    page += String(F("<h1>Live Device Values</h1>"));
    page += String(F("<h2>DeviceName: "));
    page += String((hostName));
    page += String(F("</h2>"));
    page += String(F("<h2>Device Data</h2>"));
    page += String(F("<h3>"));
    page += String(F("Timestamp: "));
    page += String((getTimestamp()));
    page += String(F("</h3>"));
    page += String(F("<h3>"));
    page += String(F("IMU Data(ACCx, ACCy, ACCz, GYRx, GYRy, GYRz): "));
    page += String((getMPU6050Data()));
    page += String(F("</h3>"));
    page += String(F("<h3>"));
    page += String(F("<br><br><h3>Data is being published to MQTT Topic: "));
    String dTopic = "ACC/" + hostName;
    page += String((dTopic));
    page += String(F("</h3>"));
    page += String(F("<p><br><a class=\"button\" href=\"/LiveSensors\">Refresh</a></p>"));

    page += String(F("</body></html>"));

    server.send(200, "text/html", page);
}
void sendRedirect(String uri)
{
    server.sendHeader("Location", uri, true);
    server.send(302, "text/plain", "");
    server.client().stop();
}
void handleCON()
{
    String argV = String(server.arg("v"));
    if (argV == "wifi")
    {
        connectionMode = "WiFi";
    }

    redirectToHome();
}
void handleDEV()
{
    String argV = String(server.arg("v"));
    Serial.println(argV);
    selectedDeviceIndex = argV.toInt();
    redirectToHome();
}
