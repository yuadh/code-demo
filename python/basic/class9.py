
from fileinput import filename
import requests,json

strname ='''https://image.baidu.com/
search/index?tn=baiduimage&ps=1&ct=201326592
&lm=-1&cl=2&nc=1&ie=utf-8&dyTabStr=MCwxLDMsNiw1LDQsNywyLDgsOQ%3D%3D
&word=%E5%91%A8%E6%98%9F%E9%A9%B0'''


headers = {
    "cookie":"l=v; buvid3=CEE50A79-E08C-9B88-4397-5AC8584EAAB716363infoc; _uuid=F1E710D64-9481-3A105-91D2-999D3817ED7317081infoc; buvid4=870FFA31-4379-C8DC-A2D4-7AD142E0E07A04806-022012016-cWjckrPywYP66v2yH5RTdw%3D%3D; CURRENT_BLACKGAP=0; buvid_fp_plain=undefined; fingerprint=2f55b06cc8e102d43bf9397a7ada0103; rpdid=|(um~Ru|uu|m0J'uYR~mlumRk; blackside_state=0; nostalgia_conf=-1; LIVE_BUVID=AUTO3616482083628552; CURRENT_QUALITY=120; i-wanna-go-back=-1; SESSDATA=41b0ab22%2C1663939440%2C57c14%2A31; bili_jct=f6904f5a7dca1851ff13f43233d43789; DedeUserID=27125162; DedeUserID__ckMd5=36f5a442d5492765; sid=bldlofqv; buvid_fp=2f55b06cc8e102d43bf9397a7ada0103; b_ut=5; PVID=1; bp_t_offset_27125162=643021320857059337; CURRENT_FNVAL=4048; b_lsid=B35104232_17FDAB04EF0; bp_video_offset_27125162=643382927043854300; innersign=1"
}
response = requests.get(strname,headers=headers)
obj =  json.loads(response.text)
imgArray = obj.get('data').get('items')
for aimg in imgArray:
    imgURL = aimg.get('pictures')[0].get('img_src')
    img = requests.get(imgURL).content
    filename = 'img\\' + str(aimg.get('doc_id'))+'.jpg'
    
    print('文件名:',filename)
    with open(filename,'wb') as fp:
        fp.write(img)
    print('保存成功')
#[1].get('pictures')[0].get('img_src')