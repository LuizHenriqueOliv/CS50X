-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description
FROM crime_scene_reports
WHERE year = 2024
AND month = 7
AND day = 28
AND street = 'Humphrey Street';
-- O roubo aconteceu na padaria, às 10:15.

SELECT transcript
FROM interviews
WHERE year = 2024
AND month = 7
AND day = 28
AND transcript LIKE '%bakery%';
-- "Em algum momento dentro dos dez minutos após o roubo, eu vi o ladrão entrar em um carro no estacionamento da padaria e sair dirigindo. Se vocês tiverem imagens das câmeras de segurança do estacionamento, talvez queiram verificar quais carros saíram nesse intervalo de tempo."
SELECT license_plate
FROM bakery_security_logs
WHERE year = 2024
AND month = 7
AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 25
AND activity = 'exit';
-- +---------------+
-- | license_plate |
-- +---------------+
-- | 5P2BI95       |
-- | 94KL13X       |
-- | 6P58WS2       |
-- | 4328GD8       |
-- | G412CB7       |
-- | L93JTIZ       |
-- | 322W7JE       |
-- | 0NTHK55       |
-- +---------------+
SELECT name
FROM people
WHERE license_plate
IN
(
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2024
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute BETWEEN 15 AND 25
    AND activity = 'exit'
);
-- SUSPEITOS ATÉ AQUI (Pessoas que saíram da padaria nesse intervalo de tempo) --------------------------
-- +---------+
-- |  name   |
-- +---------+
-- | Vanessa |
-- | Barry   |
-- | Iman    |
-- | Sofia   |
-- | Luca    |
-- | Diana   |
-- | Kelsey  |
-- | Bruce   |
-- +---------+

-- "Eu não sei o nome do ladrão, mas era alguém que eu conhecia. Mais cedo, nesta manhã, antes de eu chegar à padaria da Emma, eu estava passando pelo caixa eletrônico na Rua Leggett e vi o ladrão lá, sacando dinheiro."
SELECT account_number
FROM atm_transactions
WHERE year = 2024
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw'
-- +----------------+
-- | account_number |
-- +----------------+
-- | 28500762       |
-- | 28296815       |
-- | 76054385       |
-- | 49610011       |
-- | 16153065       |
-- | 25506511       |
-- | 81061156       |
-- | 26013199       |
-- +----------------+

SELECT name
FROM people
WHERE id
IN
(
    SELECT person_id
    FROM bank_accounts
    WHERE account_number
    IN
    (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2024
        AND month = 7
        AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
)
-- SUSPEITOS ATÉ AQUI (PESSOAS QUE SACARAM NO CAIXA ELETRÔNICO NO ENDEREÇO INFORMADO) -----------------------------
-- +---------+
-- |  name   |
-- +---------+
-- | Kenny   |
-- | Iman    |
-- | Benista |
-- | Taylor  |
-- | Brooke  |
-- | Luca    |
-- | Diana   |
-- | Bruce   |
-- +---------+

-- "Enquanto o ladrão estava saindo da padaria, ele ligou para alguém, e a conversa durou menos de um minuto. Durante a ligação, ouvi o ladrão dizer que planejava pegar o voo mais cedo saindo de Fiftyville amanhã. Depois disso, ele pediu para a pessoa do outro lado da linha comprar a passagem aérea."
SELECT caller
FROM phone_calls
WHERE year = 2024
AND month = 7
AND day = 28
AND duration < 60;
-- +----------------+
-- |     caller     |
-- +----------------+
-- | (130) 555-0289 |
-- | (499) 555-9472 |
-- | (367) 555-5533 |
-- | (499) 555-9472 |
-- | (286) 555-6063 |
-- | (770) 555-1861 |
-- | (031) 555-6622 |
-- | (826) 555-1652 |
-- | (338) 555-6650 |
-- +----------------+

SELECT name
FROM people
WHERE phone_number
IN
(
    SELECT caller
    FROM phone_calls
    WHERE year = 2024
    AND month = 7
    AND day = 28
    AND duration < 60
);
-- +---------+
-- |  name   |
-- +---------+
-- | Kenny   |
-- | Sofia   |
-- | Benista |
-- | Taylor  |
-- | Diana   |
-- | Kelsey  |
-- | Bruce   |
-- | Carina  |
-- +---------+

SELECT passport_number
FROM passengers
WHERE flight_id =
(
    SELECT id
    FROM flights
    WHERE origin_airport_id =
    (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
    )
    AND year = 2024
    AND month = 7
    AND day = 29
    ORDER BY hour, minute
    LIMIT 1
);
-- +-----------------+
-- | passport_number |
-- +-----------------+
-- | 7214083635      |
-- | 1695452385      |
-- | 5773159633      |
-- | 1540955065      |
-- | 8294398571      |
-- | 1988161715      |
-- | 9878712108      |
-- | 8496433585      |
-- +-----------------+

SELECT name
FROM people
WHERE passport_number
IN
(
    SELECT passport_number
    FROM passengers
    WHERE flight_id =
    (
        SELECT id
        FROM flights
        WHERE origin_airport_id =
        (
            SELECT id
            FROM airports
            WHERE city = 'Fiftyville'
        )
        AND year = 2024
        AND month = 7
        AND day = 29
        ORDER BY hour, minute
        LIMIT 1
    )
)
-- Pessoas que estavam no primeiro voo saíndo da cidade um dia após o roubo
-- +--------+
-- |  name  |
-- +--------+
-- | Kenny  |
-- | Sofia  |
-- | Taylor |
-- | Luca   |
-- | Kelsey |
-- | Edward |
-- | Bruce  |
-- | Doris  |
-- +--------+

-- Cruzando os dados
SELECT name
FROM people
WHERE license_plate
IN
(
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2024
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute BETWEEN 15 AND 25
    AND activity = 'exit'
)
AND id
IN
(
    SELECT person_id
    FROM bank_accounts
    WHERE account_number
    IN
    (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2024
        AND month = 7
        AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
)
AND phone_number
IN
(
    SELECT caller
    FROM phone_calls
    WHERE year = 2024
    AND month = 7
    AND day = 28
    AND duration < 60
)
AND passport_number
IN
(
    SELECT passport_number
    FROM passengers
    WHERE flight_id =
    (
        SELECT id
        FROM flights
        WHERE origin_airport_id =
        (
            SELECT id
            FROM airports
            WHERE city = 'Fiftyville'
        )
        AND year = 2024
        AND month = 7
        AND day = 29
        ORDER BY hour, minute
        LIMIT 1
    )
)
-- Ladrão:
-- +-------+
-- | name  |
-- +-------+
-- | Bruce |
-- +-------+

SELECT city
FROM airports
WHERE id =
(
    SELECT destination_airport_id
    FROM flights
    WHERE origin_airport_id =
    (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
    )
    AND year = 2024
    AND month = 7
    AND day = 29
    ORDER BY hour, minute
    LIMIT 1
);
-- Cidade para onde fugiram:
-- +---------------+
-- |     city      |
-- +---------------+
-- | New York City |
-- +---------------+

SELECT name
FROM people
WHERE phone_number =
(
    SELECT receiver
    FROM phone_calls
    WHERE caller =
    (
        SELECT phone_number
        FROM people
        WHERE name = 'Bruce'
    )
    AND year = 2024
    AND month = 7
    AND day = 28
    AND duration < 60
)
-- Cumplíce (Quem recebeu a ligação de Bruce no dia do roubo e com duração de menos de um minuto)
-- +-------+
-- | name  |
-- +-------+
-- | Robin |
-- +-------+
