import {
    login,
    getCode,
    getUserInfo,
    getUserProfile,
    changeUserProfile,
    changeUserPhoto,
    getChannels,
    getAllChannels,
    addUserChannel,
    delUserChannel,
} from "./user";
import { getArticles, getArtText } from "./article"
export const loginAPI = login
export const getCodeAPI = getCode
export const getUserInfoAPI = getUserInfo
export const getUserProfileAPI = getUserProfile
export const changeUserProfileAPI = changeUserProfile
export const changeUserPhotoAPI = changeUserPhoto
export const getChannelsAPI = getChannels
export const getArticlesAPI = getArticles
export const getArtTextAPI = getArtText
export const getAllChannelsAPI = getAllChannels
export const addUserChannelAPI = addUserChannel
export const delUserChannelAPI = delUserChannel