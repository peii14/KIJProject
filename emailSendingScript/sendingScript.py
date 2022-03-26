from email.message import EmailMessage
import imghdr
import smtplib

EMAIL_ADDRESS = 'satriaadam04@gmail.com'
EMAIL_PASSWORD = '*Adamsatria123'

msg = EmailMessage()
msg['Subject'] = 'sending from python'
msg['From'] = EMAIL_ADDRESS
msg['To'] = 'gayuh14@yahoo.com'

msg.set_content('sending picture')

files = ['Screenshot 2022-03-21 172522.png', '737400.jpg']
for file in files :
    with open(file, 'rb') as f:
        data = f.read()
        data_name = f.name
        data_type = imghdr.what(data_name)
        print(data_type)

    msg.add_attachment(data, maintype = 'image', subtype = data_type, filename = data_name)

with smtplib.SMTP_SSL('smtp.gmail.com', 465) as smtp:
    smtp.login(EMAIL_ADDRESS, EMAIL_PASSWORD)
    smtp.send_message(msg)
