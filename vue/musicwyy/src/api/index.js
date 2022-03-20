//统一 api 导出

import { recommendMusic, newMusic } from '@/api/Home'
import { searchHot, cloudSearch } from './Search'
import { getSongById, getLyricById } from './Play'

export const recommendMusicAPI = recommendMusic
export const newMusicAPI = newMusic
export const searchHotAPI = searchHot
export const cloudSearchAPI = cloudSearch
export const getSongByIdAPI = getSongById // 歌曲 - 播放地址
export const getLyricByIdAPI = getLyricById // 歌曲 - 歌词数据