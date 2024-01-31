
function toggleMenu() {
    const menu = document.querySelector('.menu');
    menu.classList.toggle('show');
}

function toggleDropdown(menu) {
    const dropdown = document.getElementById(`${menu}Dropdown`);
    const submenu = document.querySelector(`.${menu}`);

    dropdown.style.display = dropdown.style.display === 'block' ? 'none' : 'block';
    submenu.classList.toggle('active');
}

document.addEventListener('click', function (event) {
    const menu = document.querySelector('.menu');
    const menuIcon = document.querySelector('.menu-icon');

    if (!menu.contains(event.target) && !menuIcon.contains(event.target)) {
        menu.classList.remove('show');
    }
});

document.querySelector('.menu-icon').addEventListener('click', function (event) {
    event.stopPropagation();
    toggleMenu();
});

document.addEventListener('DOMContentLoaded', function () {
    const loginForm = document.getElementById('loginForm');
    const signupForm = document.getElementById('signupForm');

    loginForm.addEventListener('submit', function (e) {
        e.preventDefault();
        const username = document.getElementById('loginUsername').value;
        const password = document.getElementById('loginPassword').value;

        
        if (username === 'user' && password === 'password') {
            alert('Login successful!');
        } else {
            alert('Invalid username or password');
        }
    });

    signupForm.addEventListener('submit', function (e) {
        e.preventDefault();
        const username = document.getElementById('signupUsername').value;
        const password = document.getElementById('signupPassword').value;
        const confirmPassword = document.getElementById('confirmPassword').value;

        if (password === confirmPassword) {
            alert('Registration successful!');
        } else {
            alert('Passwords do not match');
        }
    });

    const formContainer = document.querySelector('.form-container');
    formContainer.addEventListener('click', function () {
        loginForm.classList.toggle('inactive');
        signupForm.classList.toggle('inactive');
    });
});
