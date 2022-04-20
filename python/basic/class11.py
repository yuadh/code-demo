import requests
data = {'name': 'kingname','password': '1234567'}
html_formdata = requests.post('http://exercise.kingname.info/exercise_requests_post', data=data).content.decode()
#用formdata提交数据
print(html_formdata)
