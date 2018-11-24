from flask import Flask, request, Response
import mysql.connector as mariaDB

app = Flask(__name__)

@app.route("/data/<id>", methods=['POST'])
def test(id):
    data = request.args['state']
    device_id = id
    cnx = mariaDB.connect(user='herdan', password='C907DTKXYFVkDifb', host='einstein.gen3.margau.net', database='herdan', port='3000')
    cursor = cnx.cursor()
    cursor.execute("INSERT INTO `Datenpunkt` (`id`, `time`, `wert`, `sensorid`) VALUES (NULL,current_timestamp(), '{0}', '{1}');".format(data, device_id))
    cnx.commit()
    cursor.close()
    cnx.close()

    return Response('Success')


if __name__ == '__main__':
    app.run(debug=True)
