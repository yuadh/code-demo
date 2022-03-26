# 1.2.2-response.content
import requests 

# 目标url
url = 'https://api.vc.bilibili.com/link_draw/v1/doc/doc_list?uid=6823116&page_num=0&page_size=30&biz=all' 

# 向目标url发送get请求
headers = {
    "cookie":"l=v; buvid3=CEE50A79-E08C-9B88-4397-5AC8584EAAB716363infoc; _uuid=F1E710D64-9481-3A105-91D2-999D3817ED7317081infoc; buvid4=870FFA31-4379-C8DC-A2D4-7AD142E0E07A04806-022012016-cWjckrPywYP66v2yH5RTdw%3D%3D; CURRENT_BLACKGAP=0; buvid_fp_plain=undefined; fingerprint=2f55b06cc8e102d43bf9397a7ada0103; SESSDATA=62249c04%2C1663503252%2Ceede2%2A31; bili_jct=8519d7f7d188d982ceea8d6d8819b51e; DedeUserID=27125162; DedeUserID__ckMd5=36f5a442d5492765; sid=702i7em3; b_ut=5; buvid_fp=2f55b06cc8e102d43bf9397a7ada0103; i-wanna-go-back=2; rpdid=|(um~Ru|uu|m0J'uYR~mlumRk; CURRENT_QUALITY=112; blackside_state=0; bp_video_offset_27125162=640729410344845300; nostalgia_conf=-1; CURRENT_FNVAL=4048; bp_t_offset_27125162=640763748611522576; innersign=0; b_lsid=B631048A2_17FB69FCCFC; PVID=2; bsource=search_baidu"
}
response=requests.get(url,timeout=4,headers=headers).text

with open('BUG/img/text.txt', 'w') as f:
    f.write('Hello, world!')


# 打印响应内容
# print(response.text)
print(response) # 注意这里！