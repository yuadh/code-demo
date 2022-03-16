//统一 api 导出

import { recommendMusic, newMusic } from '@/api/Home'
import { searchHot,cloudSearch } from './Search'

export const recommendMusicAPI = recommendMusic
export const newMusicAPI = newMusic
export const searchHotAPI = searchHot
export const cloudSearchAPI = cloudSearch