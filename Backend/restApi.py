from flask import Flask, request, Response

app = Flask(__name__)

@app.route("/data/<id>", methods=['POST'])
def test(id):
    data = request.args['state']
    device_id = id
    print(data, device_id)
    return Response('Success')


if __name__ == '__main__':
    app.run(debug=True)
