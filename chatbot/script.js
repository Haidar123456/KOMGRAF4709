let faqData = [];

// Memuat data FAQ dari file JSON
fetch("faq.json")
    .then((response) => response.json())
    .then((data) => {
        faqData = data;
    })
    .catch((error) => console.error("Error loading FAQ data:", error));

// Ambil elemen dari DOM
const sendButton = document.getElementById("send-button");
const doneButton = document.getElementById("done-button");
const chatBox = document.getElementById("chat-box");
const userInput = document.getElementById("user-input");
const resultContainer = document.getElementById("mental-health-result");
const healthPercentage = document.getElementById("health-percentage");

// Fungsi untuk menambahkan pesan pengguna ke chat box
function addUserMessage(message) {
    const userMessage = document.createElement("div");
    userMessage.classList.add("user-message");
    userMessage.textContent = message;
    chatBox.appendChild(userMessage);
    chatBox.scrollTop = chatBox.scrollHeight;
}

// Fungsi untuk menambahkan pesan bot ke chat box
function addBotMessage(message) {
    const botMessage = document.createElement("div");
    botMessage.classList.add("bot-message");
    botMessage.textContent = message;
    chatBox.appendChild(botMessage);
    chatBox.scrollTop = chatBox.scrollHeight;
}

// Fungsi untuk mencari jawaban berdasarkan FAQ
function findFaqResponse(userQuestion) {
    let botResponse = "Maaf, saya belum memahami pertanyaan Anda. Cobalah bertanya dengan cara yang berbeda.";

    faqData.forEach((faq) => {
        if (userQuestion.includes(faq.question.toLowerCase())) {
            botResponse = faq.answer;
        }
    });

    return botResponse;
}

// Event listener untuk tombol kirim
sendButton.addEventListener("click", () => {
    const userMessage = userInput.value.trim();

    if (userMessage) {
        addUserMessage(userMessage); // Tambahkan pesan pengguna

        // Cari respons FAQ
        const userQuestion = userMessage.toLowerCase();
        const botResponse = findFaqResponse(userQuestion);

        // Tambahkan respons bot setelah 1 detik
        setTimeout(() => {
            addBotMessage(botResponse);
        }, 1000);

        // Bersihkan input
        userInput.value = "";
    }
});

// Event listener untuk tombol selesai
doneButton.addEventListener("click", () => {
    // Periksa apakah ada pesan pengguna
    const userMessages = document.querySelectorAll(".user-message");

    if (userMessages.length === 0) {
        alert("Anda belum memulai sesi chat. Silakan ajukan pertanyaan terlebih dahulu!");
        return; // Hentikan eksekusi jika belum ada sesi chat
    }

    // Jika ada pesan, tampilkan persentase kesehatan mental
    const healthPercentageValue = Math.floor(Math.random() * 100) + 1; // Persentase acak antara 1-100
    healthPercentage.textContent = `${healthPercentageValue}%`;
    resultContainer.style.display = "block"; // Tampilkan hasil
});

// Fungsi untuk menambahkan sapaan bot saat website dibuka
function greetUser() {
    const greetingMessage = "Hai, bagaimana saya bisa membantu Anda hari ini?";
    addBotMessage(greetingMessage);
}

// Panggil fungsi greetUser saat halaman dimuat
window.addEventListener("DOMContentLoaded", () => {
    greetUser();
});
