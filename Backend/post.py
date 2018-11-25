from flask import Flask, request, Response, jsonify
import mysql.connector as mariaDB
import random
from configparser import SafeConfigParser

#credentials = config()
#cnx = mariaDB.connect(user=credentials['myuser'], password=credentials['mypassword'], host=credentials['myhost'], database='herdan', port=credentials['port'])


app = Flask(__name__)

def config():
    parser = SafeConfigParser()
    parser.read('config.ini')
    user = parser.get('server', 'user')
    password =  parser.get('server', 'password')
    host = parser.get('server', 'host')
    port = parser.get('server', 'port')
    # {'key':'value'}
    return {'myuser':user, 'mypassword':password, 'myhost':host, 'port':port}

@app.route("/data/<id>", methods=['POST'])
def test(id):
    data = request.args['state']
    if 0 <= int(data) <= 1:
        device_id = id
        try:
            #credentials = config()
            #cnx = mariaDB.connect(user=credentials['myuser'], password=credentials['mypassword'], host=credentials['myhost'], database='herdan', port=credentials['port'])
            cursor = cnx.cursor()
            cursor.execute("INSERT INTO `Datenpunkt` (`id`, `time`, `wert`, `sensorid`) VALUES (NULL,current_timestamp(), '{0}', '{1}');".format(data, device_id))
            #cnx.commit()
            cursor.close()
            #cnx.close()
            return Response('Success')
        except mariaDB.error as err :
            print("falsch:{}",format(err))
    else:
        return Response('Einfach nur nein')

@app.route('/<path:path>')
def sample(path):
    #credentials = config()
    #cnx = mariaDB.connect(user=credentials['myuser'], password=credentials['mypassword'], host=credentials['myhost'], database='herdan', port=credentials['port'])
    cursor = cnx.cursor()
    cursor.execute("SELECT d.time, d.sensorid, s.name, s.typ, d.wert FROM Datenpunkt d INNER JOIN Sensor s ON s.id=d.sensorid WHERE d.sensorid = 1 ORDER BY d.time desc LIMIT 1")
    #cnx.commit()
    result = cursor.fetchone()
    print(result)
    cursor.close()
    #cnx.close()
    json = {'an':result[4], 'name':result[2], 'time':result[0], 'sensorid':result[1], 'sensortyp':result[3]}
    return jsonify(json)


if __name__ == '__main__':
    credentials = config()
    cnx = mariaDB.connect(user=credentials['myuser'], password=credentials['mypassword'], host=credentials['myhost'], database='herdan', port=credentials['port'])
    app.run(debug=True, host='0.0.0.0', port=80)
    #parser = SafeConfigParser()
    #parser.read('config.ini')
    #print(parser.get('server', 'user'))
