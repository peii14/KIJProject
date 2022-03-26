import os
from imbox import Imbox
import traceback

host = "imap.gmail.com"
username = "satriaadam04@gmail.com"
password = '*Adamsatria123'
download_folder = "C:\\Users\\satri\\Downloads"

if not os.path.isdir(download_folder):
    os.makedirs(download_folder, exist_ok=True)

mail = Imbox(host, username=username, password=password, ssl=True, ssl_context=None, starttls=False)
messages = mail.messages(sent_from='savieralavenia@gmail.com')  # inbox filter

for (uid, message) in messages:
    mail.mark_seen(uid)  # optional, mark message as read

    for idx, attachment in enumerate(message.attachments):
        try:
            att_fn = attachment.get('filename')
            download_path = f"{download_folder}/{att_fn}"
            print(download_path)
            with open(download_path, "wb") as fp:
                fp.write(attachment.get('content').read())
        except:
            print(traceback.print_exc())

mail.logout()