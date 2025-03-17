🌡️ Medidor de Temperatura e Umidade com ESP32 e DHT22 🌿
Este projeto utiliza o sensor DHT22 🌡️ e o microcontrolador ESP32 🔧 para medir a temperatura 🌡️ e a umidade 💧 do ambiente em tempo real. Os dados são enviados para a plataforma ThingSpeak 🌐 via protocolo MQTT 📡.

Descrição 📜
O sistema se conecta a uma rede Wi-Fi 📶, permitindo a transmissão contínua dos dados de temperatura e umidade para um canal específico no ThingSpeak. As medições são realizadas a cada 2 segundos ⏱️.

🔧 Requisitos
Antes de começar, você precisará de:

ESP32 🔧
Sensor DHT22 🌡️💧
Cabo micro-USB para conectar o ESP32 ao computador 🔌
Arduino IDE 💻 (com a biblioteca do DHT22 instalada)
Conta no ThingSpeak 🌐
Acesso à rede Wi-Fi 📶
🚀 Como Usar
Configuração do ESP32:

Conecte o sensor DHT22 ao ESP32.
No código, insira as credenciais da sua rede Wi-Fi (SSID e senha).
Configure o canal do ThingSpeak (crie um canal na plataforma e insira a chave de escrita).
Upload do Código:

Abra o Arduino IDE 💻.
Selecione a placa ESP32 e a porta correta.
Faça o upload do código para o ESP32.
Verificação dos Dados:

Após o código ser carregado, o ESP32 começará a enviar os dados de temperatura e umidade para o ThingSpeak 🖥️.
Acesse o painel do seu canal no ThingSpeak para visualizar os gráficos em tempo real 📊.
🛠️ Bibliotecas Usadas
DHT Sensor Library para ler os dados do DHT22.
ThingSpeak para enviar os dados para a plataforma.
WiFi para conectar o ESP32 à rede.
⚠️ Avisos
Certifique-se de que o sensor DHT22 está corretamente conectado ao ESP32.
Verifique sua conexão de rede Wi-Fi 📶, pois a comunicação com o ThingSpeak depende disso.
Se os dados não aparecerem, verifique a chave de escrita do ThingSpeak.

