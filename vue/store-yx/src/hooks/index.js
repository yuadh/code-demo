import { useIntersectionObserver } from "@vueuse/core"
import { ref } from "vue"


/**
 * 
 * @param {function} apiFn - 网络请求函数
 * @param {boolean} isIntersecting - 是否进入可视区标志位
 * @param {object} observeElement - 监测额元素
 */
export const useDataLazy = (apiFn) => {
    const target = ref(null)
    const result = ref([])
    const { stop } = useIntersectionObserver(
        target,
        ([{ isIntersecting }], observeElement) => {
            if (isIntersecting) {
                stop()
                console.log('懒加载数据开始发送请求')
                apiFn().then(data => {
                    result.value = data.result
                }).catch(err => {
                    console.log(err)
                })
            }
        }, { threshold: 0 }
    )
    return { target, result }
}