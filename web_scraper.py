import requests
from bs4 import BeautifulSoup

response = requests.get('https://www.ecb.europa.eu/stats/policy_and_exchange_rates/euro_reference_exchange_rates/html/index.en.html')
#print(response.text)  # Вывод HTML-кода страницы

# как говориться, напильник это круто, так что просто создам файл
# так как мне лень разбираться в коде, и вообще этот код напечатал
# gemini, так что этот код выглядит немного не доработанным до конца
# поэтому вы можете заметить в этом коде костыли, увы

with open("/home/slava/Documents/source_code/convert_money/" + "my_file.txt", 'w'): # костыль
    print("")# костыль

soup = BeautifulSoup(response.text, 'html.parser')
# Поиск тегов <br> с нужной информацией
for br_tag in soup.find_all('td'):
    text = br_tag.get_text(strip=True) + "\n"  # Получение текста внутри <br>
    if text:  # Проверка, что текст не пустой
        def save_to_file(filename, content):
            try:
                with open("/home/slava/Documents/source_code/convert_money/" + filename, 'a') as file: # костыль
                    file.write(content)# костыль
                print(f"Содержимое успешно сохранено в файл {filename}")
            except IOError as e:
                print(f"Ошибка при сохранении в файл: {e}")

        # Пример использования:
        filename = "my_file.txt"
        save_to_file(filename, text)

