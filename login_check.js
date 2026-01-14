function validateLogin(name, email, password) {
    // 1. Name Check (Khali nahi hona chahiye)
    if (name.trim() === "") {
        return "Error: Name cannot be empty.";
    }

    // 2. Email Format Check (Regex use karke)
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (!emailRegex.test(email)) {
        return "Error: Invalid email format.";
    }

    // 3. Password Check (Kam az kam 8 characters)
    if (password.length < 8) {
        return "Error: Password must be at least 8 characters long.";
    }

    return "Success: Login Details are Valid!";
}

// Check karne ke liye:
console.log(validateLogin("Moon Tariq", "test@example.com", "pass12345"));
