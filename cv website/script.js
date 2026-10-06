function toggleMenu() {
    const menu = document.querySelector(".menu-links");
    const icon = document.querySelector(".hamburger-icon");
    menu.classList.toggle("open");
    icon.classList.toggle("open");
}

const observer = new IntersectionObserver((entries) => {
    entries.forEach((entry) => {
        if (entry.isIntersecting) {
            entry.target.classList.add('show');
        } else {
            entry.target.classList.remove('show');
        }
    });
}, {
    threshold: 0.15
});

const hiddenElements = document.querySelectorAll('.hidden');
hiddenElements.forEach((el) => observer.observe(el));

document.addEventListener('mousemove', (e) => {
    const x = (window.innerWidth / 2 - e.clientX) / 30;
    const y = (window.innerHeight / 2 - e.clientY) / 30;

    const blob = document.querySelector('.background-blob');
    if (blob) {
        blob.style.transform = `translate(${x}px, ${y}px)`;
    }
});

document.addEventListener('DOMContentLoaded', () => {
    // Typewriter effect handling
    const bookContainer = document.querySelector('.comic-book-container');
    const typewriterElements = document.querySelectorAll('.typewriter-text');
    const activeTimers = new Map();

    function startTypewriter() {
        typewriterElements.forEach((el, index) => {
            if (activeTimers.has(index)) {
                clearInterval(activeTimers.get(index));
            }

            const fullText = el.getAttribute('data-text');
            el.textContent = '';
            let charIndex = 0;

            const timer = setInterval(() => {
                if (charIndex < fullText.length) {
                    el.textContent += fullText.charAt(charIndex);
                    charIndex++;
                } else {
                    clearInterval(timer);
                    activeTimers.delete(index);
                }
            }, 25);

            activeTimers.set(index, timer);
        });
    }

    function clearTypewriter() {
        typewriterElements.forEach((el, index) => {
            if (activeTimers.has(index)) {
                clearInterval(activeTimers.get(index));
                activeTimers.delete(index);
            }
            el.textContent = '';
        });
    }

    if (window.innerWidth > 768) {
        bookContainer.addEventListener('mouseenter', startTypewriter);
        bookContainer.addEventListener('mouseleave', clearTypewriter);
    } else {
        // Run full text immediately on mobile view
        typewriterElements.forEach(el => {
            el.textContent = el.getAttribute('data-text');
        });
    }

    // Mobile Navigation controls
    const page1 = document.getElementById("page1");
    const page2 = document.getElementById("page2");
    const prevBtn = document.getElementById("prevPageBtn");
    const nextBtn = document.getElementById("nextPageBtn");
    const indicator = document.getElementById("pageIndicator");

    let currentPage = 1;

    function updatePages() {
        if (currentPage === 1) {
            page1.classList.add("active-page");
            page2.classList.remove("active-page");
            indicator.textContent = "1/2";
        } else {
            page1.classList.remove("active-page");
            page2.classList.add("active-page");
            indicator.textContent = "2/2";
        }
    }

    if (nextBtn && prevBtn) {
        nextBtn.addEventListener("click", function () {
            currentPage = currentPage === 1 ? 2 : 1;
            updatePages();
        });

        prevBtn.addEventListener("click", function () {
            currentPage = currentPage === 2 ? 1 : 2;
            updatePages();
        });
    }
});