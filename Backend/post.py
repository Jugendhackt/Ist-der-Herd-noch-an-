from flask import Flask, request, Response, jsonify
import mysql.connector as mariaDB
import random
from configparser import SafeConfigParser

app = Flask(__name__)

def config():
    parser = SafeConfigParser()
    parser.read('config.ini')
    user = parser.get('server', 'user')
    password =  parser.get('server', 'password')
    host = parser.get('server', 'host')
    # {'key':'value'}
    return {'myuser':user, 'mypassword':password, 'myhost':host}

@app.route("/data/<id>", methods=['POST'])
def test(id):
    data = request.args['state']
    if 0 <= int(data) <= 1:
        device_id = id
        credentials = config()
        cnx = mariaDB.connect(user=credentials['myuser'], password=credentials['mypassword'], host=credentials['myhost'], database='herdan', port='3306')
        cursor = cnx.cursor()
        cursor.execute("INSERT INTO `Datenpunkt` (`id`, `time`, `wert`, `sensorid`) VALUES (NULL,current_timestamp(), '{0}', '{1}');".format(data, device_id))
        cnx.commit()
        cursor.close()
        cnx.close()
        return Response('Success')
    else:
        return Response('Einfach nur nein')

@app.route('/')
def sample():
    json = {'an':bool(random.getrandbits(1))}
    return jsonify(json)

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=80)
    #parser = SafeConfigParser()
    #parser.read('config.ini')
    #print(parser.get('server', 'user'))
