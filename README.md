En:

# Tic-Tac-Toe in C

A simple yet intelligent **Tic-Tac-Toe game implemented in C**, where the player competes against a computer-controlled opponent.

The project was developed as a console-based application to demonstrate fundamental C programming concepts, game logic, input validation, and basic Artificial Intelligence using the **Minimax algorithm**.

## Features

* 🎮 Player vs Computer gameplay
* 🤖 Computer opponent powered by the **Minimax algorithm**
* 🧠 Strategic move selection
* ⚡ Detects immediate winning moves
* 🛡️ Blocks the player's immediate winning moves
* 🎯 Prioritizes the center position in specific game situations
* ✅ Validates player input
* 🔄 Automatically detects wins and draws
* 💻 Lightweight console-based interface
* 📦 No external libraries or dependencies required

## How It Works

The game uses a `3×3` board represented by a two-dimensional character array.

The player plays as **X**, while the computer plays as **O**.

After every player move, the computer determines its best possible move using a combination of tactical checks and the **Minimax algorithm**.

The computer's decision process includes:

1. Checking whether it can win immediately.
2. Checking whether the player can win on the next move and blocking it.
3. Selecting strategic positions when applicable.
4. Evaluating possible future game states using Minimax.
5. Choosing the move with the highest evaluated score.

The Minimax implementation recursively explores possible game states and assigns scores based on the final outcome. Winning states for the computer receive a positive score, while winning states for the player receive a negative score. The search depth is also considered so that the AI prefers quicker wins and delays losses when possible.

## Game Rules

* The player uses **X**.
* The computer uses **O**.
* The player always makes the first move.
* Players take turns placing their symbol on an empty cell.
* The first player to create a row, column, or diagonal of three matching symbols wins.
* If all cells are filled without a winner, the game ends in a draw.

## Input

The player enters the row and column of the desired cell using numbers from `1` to `3`.

Example:

```text
Enter your move (satr and soton: 1-3 1-3): 2 3
```

The program checks for invalid input, out-of-range coordinates, and already occupied cells.

## Technologies

* **Language:** C
* **Interface:** Command Line / Console
* **AI Algorithm:** Minimax
* **Libraries:** `stdio.h`, `stdbool.h`

## Project Structure

```text
tic-tac-toe-c/
│
├── xo_game.c
├── xo_game.exe
└── README.md
```

## Compilation

You can compile the source code using GCC:

```bash
gcc xo_game.c -o xo_game
```

Then run the program:

### Windows

```bash
xo_game.exe
```

### Linux / macOS

```bash
./xo_game
```

## Example Gameplay

```text
Game -XO-: You (X) vs Computer (O)
You start first...

    |   |  
---|---|---
    |   |  
---|---|---
    |   |  

Enter your move (satr and soton: 1-3 1-3): 1 1

 X |   |  
---|---|---
   | O |  
---|---|---
   |   |  

Computer plays at (2,2)
```

## Purpose

This project was created as a practical implementation of:

* C programming fundamentals
* Functions and control flow
* Two-dimensional arrays
* Recursion
* Game-state evaluation
* Input validation
* Algorithmic problem solving
* Basic Artificial Intelligence concepts

## Future Improvements

Possible improvements for future versions include:

* Adding difficulty levels
* Implementing Player vs Player mode
* Improving the graphical interface
* Adding a scoreboard
* Adding replay functionality
* Improving the AI decision-making system
* Separating the project into multiple source and header files
* Adding automated tests

## License

This project is available for educational and personal use.

---

**Made with C ❤️**
-----------------------------------------------

fa:

# بازی دوز (Tic-Tac-Toe) با زبان C

یک بازی **Tic-Tac-Toe (دوز)** ساده و هوشمند که با زبان **C** پیاده‌سازی شده است. در این پروژه، بازیکن در مقابل کامپیوتر بازی می‌کند و کامپیوتر برای انتخاب حرکت مناسب از الگوریتم **Minimax** استفاده می‌کند.

این پروژه به‌صورت یک برنامه کنسولی طراحی شده و علاوه بر منطق بازی، مفاهیمی مانند برنامه‌نویسی ساختاریافته در C، آرایه‌های دوبعدی، بازگشت (Recursion)، اعتبارسنجی ورودی و هوش مصنوعی مقدماتی را پیاده‌سازی می‌کند.

## امکانات

* 🎮 بازی بازیکن در برابر کامپیوتر
* 🤖 هوش مصنوعی مبتنی بر الگوریتم **Minimax**
* 🧠 انتخاب حرکت بهینه توسط کامپیوتر
* ⚡ تشخیص حرکت فوری برای پیروزی
* 🛡️ جلوگیری از حرکت منجر به پیروزی بازیکن
* 🎯 اولویت دادن به خانه مرکزی در شرایط مشخص
* ✅ اعتبارسنجی ورودی بازیکن
* 🔄 تشخیص خودکار برنده و مساوی
* 💻 رابط کاربری مبتنی بر کنسول
* 📦 بدون نیاز به کتابخانه یا وابستگی خارجی

## نحوه عملکرد

صفحه بازی به‌صورت یک آرایه دوبعدی `3×3` در برنامه ذخیره شده است.

بازیکن با نماد **X** و کامپیوتر با نماد **O** بازی می‌کند.

پس از هر حرکت بازیکن، کامپیوتر ابتدا وضعیت بازی را بررسی می‌کند و سپس بهترین حرکت ممکن را انتخاب می‌کند.

فرآیند تصمیم‌گیری کامپیوتر شامل مراحل زیر است:

1. بررسی امکان پیروزی فوری کامپیوتر.
2. بررسی امکان پیروزی بازیکن و مسدود کردن آن.
3. بررسی بعضی موقعیت‌های استراتژیک مانند خانه مرکزی.
4. بررسی حالت‌های مختلف آینده بازی با استفاده از Minimax.
5. انتخاب حرکتی که بهترین امتیاز را دارد.

در الگوریتم Minimax، وضعیت‌های مختلف بازی به‌صورت بازگشتی بررسی می‌شوند و بر اساس نتیجه نهایی، برای هر وضعیت امتیاز در نظر گرفته می‌شود. پیروزی کامپیوتر امتیاز مثبت و پیروزی بازیکن امتیاز منفی دارد. همچنین عمق جستجو در امتیازدهی در نظر گرفته شده است.

## قوانین بازی

* بازیکن با **X** بازی می‌کند.
* کامپیوتر با **O** بازی می‌کند.
* بازیکن بازی را شروع می‌کند.
* بازیکنان به‌ترتیب یک خانه خالی را انتخاب می‌کنند.
* اولین بازیکنی که سه نماد مشابه را در یک ردیف، ستون یا قطر قرار دهد، برنده است.
* در صورتی که تمام خانه‌ها پر شوند و هیچ برنده‌ای وجود نداشته باشد، بازی مساوی می‌شود.

## نحوه ورود حرکت

بازیکن باید شماره سطر و ستون خانه موردنظر را از `1` تا `3` وارد کند.

برای مثال:

```text
Enter your move (satr and soton: 1-3 1-3): 2 3
```

برنامه ورودی نامعتبر، شماره‌های خارج از محدوده و خانه‌های اشغال‌شده را بررسی می‌کند.

## تکنولوژی‌های استفاده‌شده

* **زبان برنامه‌نویسی:** C
* **رابط کاربری:** Console / Command Line
* **الگوریتم هوش مصنوعی:** Minimax
* **کتابخانه‌ها:** `stdio.h` و `stdbool.h`

## ساختار پروژه

```text
tic-tac-toe-c/
│
├── xo_game.c
├── xo_game.exe
└── README.md
```

## کامپایل و اجرا

برای کامپایل پروژه با استفاده از GCC:

```bash
gcc xo_game.c -o xo_game
```

سپس برنامه را اجرا کنید.

### Windows

```bash
xo_game.exe
```

### Linux / macOS

```bash
./xo_game
```

## نمونه اجرای بازی

```text
Game -XO-: You (X) vs Computer (O)
You start first...

    |   |  
---|---|---
    |   |  
---|---|---
    |   |  

Enter your move (satr and soton: 1-3 1-3): 1 1

 X |   |  
---|---|---
   | O |  
---|---|---
   |   |  

Computer plays at (2,2)
```

## هدف پروژه

این پروژه با هدف تمرین و پیاده‌سازی مفاهیم زیر ایجاد شده است:

* مبانی زبان C
* توابع و کنترل جریان برنامه
* آرایه‌های دوبعدی
* برنامه‌نویسی بازگشتی (Recursion)
* ارزیابی وضعیت بازی
* اعتبارسنجی ورودی
* حل مسئله الگوریتمی
* مفاهیم مقدماتی هوش مصنوعی

## قابلیت‌های پیشنهادی برای نسخه‌های آینده

* اضافه کردن درجه سختی مختلف
* اضافه کردن حالت Player vs Player
* طراحی رابط گرافیکی
* اضافه کردن سیستم امتیازدهی
* امکان شروع مجدد بازی
* بهبود سیستم تصمیم‌گیری هوش مصنوعی
* تفکیک کد به فایل‌های `.c` و `.h`
* اضافه کردن تست‌های خودکار

## مجوز

این پروژه برای استفاده آموزشی و شخصی در دسترس است.

---

**ساخته شده با C ❤️**
