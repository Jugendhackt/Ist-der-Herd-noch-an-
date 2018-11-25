import urllib.request
import urllib.parse


url = 'https://api.spotify.com/v1/search?type=artist&q=snoop'
f = urllib.request.urlopen(url)
print(f.read().decode('utf-8'))
