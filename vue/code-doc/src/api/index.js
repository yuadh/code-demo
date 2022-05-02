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
    followerUser,
    unFollowerUser,
    collectArticle,
    unCollectArticle,
    likeArt,
    unLikeArt
} from "./user";
import { 
    getArticles, 
    getArtText,
    getArtComments,
    likeComment,
    unLikeComment
} from "./article"
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
export const followerUserAPI = followerUser
export const unFollowerUserAPI = unFollowerUser
export const collectArticleAPI = collectArticle
export const unCollectArticleAPI = unCollectArticle
export const likeArtAPI = likeArt
export const unLikeArtAPI = unLikeArt
export const getArtCommentsAPI = getArtComments
export const likeCommentAPI = likeComment
export const unLikeCommentAPI = unLikeComment